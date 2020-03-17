// Arduino program
// Last modified by Angeliki Beyko on 2020.03.17

const int maxcount = 4; 
const int button[] = { 4,5,6,7};  
const int led[] = { 9,10,11,12};  
 
unsigned long start, finished, elapsed; 
 
void setup() {  
  // Set all led pins as outputs 
  for (int i = 0; i < maxcount; i++) {  
    pinMode(led[i], OUTPUT); 
  } 
  
  // Set all button pins as inputs 
  for (int i = 0; i < maxcount; i++) { 
    pinMode(button[i], INPUT);   
  }

  // Start the serial monitor to view output
  Serial.begin(9600);
}

void loop() {
  
  // generate a random number and store it in a variable
  int randNumber = random(maxcount);

  // clear the leds
  for (int i = 0; i < maxcount; i++) {
    digitalWrite(led[i], LOW);
  }

  // start the timer
  start = millis();

  // enter while loop
  while (digitalRead(button[randNumber]) == LOW) {
    // random led will stay on until button is pressed
    digitalWrite(led[randNumber], HIGH);
  }

  // exit while loop, correct button pressed
  // record end time
  finished = millis();

  // store how many ms it took for user to press correct button
  elapsed = finished - start;

  // Print out how many ms ellapsed
  if (elapsed > 100) {
    Serial.print(elapsed);
    Serial.println(" ms have passed");
  }
}
