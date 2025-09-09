//www.elegoo.com
//2016.12.08
byte leds = 0;


byte numDigits = 1;
byte digitPins[] = {2,3,4,5};
int counter = 0;
byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};


void setup() 
{
  int buttonIncrementpin = 2;
  int buttonDecrementpin = 3;


  pinMode(ledPin, OUTPUT);
  pinMode(buttonIncrementpin, INPUT_PULLUP);  
  pinMode(buttonDecrementpin, INPUT_PULLUP);  
}

void loop() 
{
  // LOW means button is pressed
  /*
  *
  * Want to increment number when correct button is pressed, decrement on other button press
  *
  */
  if (digitalRead(buttonIncrementpin) == LOW)
  {
    counter++;
    // Increment number
    // digitalWrite(ledPin, HIGH);
  }
  if (digitalRead(buttonDecrementpin) == LOW)
  {
    counter--;
    // Decrement number
    // digitalWrite(ledPin, LOW);
  }
}
