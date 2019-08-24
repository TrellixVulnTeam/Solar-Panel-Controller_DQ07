/*
  Serial Event example

  When new serial data arrives, this sketch adds it to a String.
  When a newline is received, the loop prints the string and clears it.

  A good test for this is to try it with a GPS receiver that sends out
  NMEA 0183 sentences.

  NOTE: The serialEvent() feature is not available on the Leonardo, Micro, or
  other ATmega32U4 based boards.

  created 9 May 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/SerialEvent
*/

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
int Disyuntor1 = 13;
int Disyuntor2 = 12;
int DisTest1 = 8;
int DisTest2 = 7;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  pinMode(Disyuntor1,OUTPUT);
  pinMode(DisTest1,OUTPUT);
  pinMode(Disyuntor2,OUTPUT);
  pinMode(DisTest2,OUTPUT);
  
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() {
  // print the string when a newline arrives:
if (Serial.read()>0)
{
  String Read = "";
  Read = Serial.read();
  Serial.println(Read);
}


  
}


/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
     char input = (char)Serial.read();
    if (input == 'E')
      {
        Serial.println("Desconectando lineas");
        Disyuntor1 = LOW;
        Disyuntor2 = LOW;
        stringComplete = true;
      }
    }
  }
