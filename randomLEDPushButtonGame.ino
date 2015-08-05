//Arduino program
//Created  y Angeliki Beyko on 2014.12.20

const int maxcount = 4; 
const int button[] = { 4,5,6,7};  
const int led[] = { 9,10,11,12};  
int lightedled = -1;  
int speed = 1000; 
 
unsigned long start, finished, elapsed; 
 
void setup(){  
  // Set all pins as output 
  for(int i=0; i < maxcount; i++) {  
    pinMode(led[i], OUTPUT); 
  } 
  // Set all buttons as input 
  for(int i=0; i < maxcount; i++) { 
    pinMode(button[i], INPUT); 
    Serial.begin(9600); 
  } 
}

 
//clears all the leds on the bus 
void clearleds() 
{ 
  for(int f=0; f <maxcount; f++)  
  { 
    digitalWrite (led[f], LOW);
  } 
  lightedled = -1; 
    delay(speed);
} 
 
void lightrandom() 
{ 
  lightedled = random(maxcount); 
  digitalWrite(led[lightedled], HIGH); 
}

 
//returns the index of the first pressed button, blocks until a button is pressed. 
int readbutton()  
{ 
    while(true) 
    { 
        for(int x = 0; x < maxcount; x++) 
        { 
            
                        if(!digitalRead(button[x])) 
            { 
                return x; 
                Serial.println(x) 
            } 
        } 
    }
}

 
void loop(){ 
  clearleds(); 
  lightrandom(); 
  start = millis(); 
  int button = readbutton(); 
  finished = millis();  
  if(button == lightedled) 
  { 
      Serial.println("true"); 
        elapsed = finished - start;  
        Serial.print(elapsed); 
        Serial.println(" milliseconds elapsed"); 
        Serial.println(); 
  } 
  if(button!=lightedled)
  {
    Serial.println("Try again!");
    elapsed = finished - start;
    Serial.println(elapsed + " This is how long it took you in ms");
    Serial.println();
  } 
  delay(speed); 
}

