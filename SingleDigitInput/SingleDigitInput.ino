// Button pins
int buttonIncrementPin = 2;
int buttonDecrementPin = 3;

// Seven segment display pins (a, b, c, d, e, f, g, dp)
byte segmentPins[] = {4, 5, 6, 7, 8, 9, 10, 11};

// Counter variable
int counter = 0;

// Button state tracking for debouncing
bool lastIncrementState = HIGH;
bool lastDecrementState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

// What each segment pin activates
  // 0 is decimal place
  // 1 is bottom right segment
  // 2 is top right
  // 3 is top mid
  // 4 is top left
  // 5 is middle
  // 6 is bottom left
  // 7 is bottom mid
// Seven segment patterns for digits 0-9
// Format: {a, b, c, d, e, f, g, dp}
byte digitPatterns[10][8] = {
  {0, 1, 1, 1, 1, 0, 1, 1}, // 0
  {0, 1, 1, 0, 0, 0, 0, 0}, // 1
  {0, 0, 1, 1, 0, 1, 1, 1}, // 2
  {0, 1, 1, 1, 0, 1, 0, 1}, // 3
  {0, 1, 1, 0, 1, 1, 0, 0}, // 4
  {0, 1, 0, 1, 1, 1, 0, 1}, // 5
  {0, 1, 0, 1, 1, 1, 1, 1}, // 6
  {0, 1, 1, 1, 0, 0, 0, 0}, // 7
  {0, 1, 1, 1, 1, 1, 1, 1}, // 8
  {0, 1, 1, 1, 1, 1, 0, 1}  // 9
};

void setup() {
  // Initialize button pin actions
  pinMode(buttonIncrementPin, INPUT_PULLUP);  
  pinMode(buttonDecrementPin, INPUT_PULLUP);
  
  // Initialize segment pins
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  
  // // Initialize serial for debugging
  Serial.begin(9600);
  
  // Display initial counter value

  displayDigit(counter);
}

void loop() {
  if (digitalRead(buttonIncrementPin) == LOW)
  {
    Serial.println("Increment button pressed down");
    if(counter < 9){
      counter++;
      displayDigit(counter);
      
      delay(200);
    }
  }
  if (digitalRead(buttonDecrementPin) == LOW)
  {
    Serial.println("Decrement button pressed down");
    if(counter > 0){
      counter--;
      displayDigit(counter);
      delay(200);
    }
    
  }
}

void displayDigit(int digit) {
  // Make sure digit is within valid range
  if (digit < 0 || digit > 9) return;
  
  // Set each segment according to the pattern
  for (int i = 0; i < 8; i++) {
    digitalWrite(segmentPins[i], digitPatterns[digit][i]);
  }
}
