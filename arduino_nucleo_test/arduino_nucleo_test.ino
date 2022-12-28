/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13 through 220 ohm resistor
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInput
*/

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
double sensorValue = 0;  // variable to store the value coming from the sensor
double sum = 0;
double sumv = 0;
double amps = 0;
double cal = 0;
double multiplier = 0.00120987607;
void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  analogReadResolution(16);
  int i=10000;
  sum = 0;
  while(i>0){
    i--;
    sensorValue = analogRead(sensorPin);
    amps = (sensorValue*multiplier);
    sum = sum + amps;
  }
  cal = sum/10000;
  Serial.println(cal);
}

void loop() {
  // read the value from the sensor:
  
  // turn the ledPin on
  int i=1000;
  sum = 0;
  sumv = 0;
  while(i>0){
    i--;
    sensorValue = analogRead(sensorPin);
    amps = (sensorValue*multiplier)-cal;
    sum = sum + amps;
    sumv = sumv + analogRead(A1)*0.00005493164;
  }
  amps = sum/1000;
  double volts = sumv/1000;
  Serial.print("I: ");
  Serial.print(amps);
  Serial.print("   V: ");
  Serial.print(volts);
  Serial.print("   R: ");
  Serial.println(volts/amps);
}
