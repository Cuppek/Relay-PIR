// At the begining relay is "open" (there is a signal going to it).
// After specified time when there is no move around, program will close relay.
// If any move appear counting to end starts from beginning

int PIR = 2; // Motion sensor
int led = 3; // LED signals relay is open
int relay = 4; // Relay

int moveFound;

unsigned long myTime; 
unsigned long endTime;
unsigned long ONTime = 5000; // After that time relay will close

void setup() 
{
  Serial.begin(9600);
  pinMode(PIR, INPUT);
  pinMode(led, OUTPUT);
  pinMode(relay, OUTPUT);
}

void loop() 
{
  myTime = millis();
  endTime = millis() + ONTime;
  
  digitalWrite(led, HIGH);
  digitalWrite(relay, HIGH);
  Serial.println("Open");
  
  while (myTime < endTime) 
  {
    myTime = millis();
    moveFound = digitalRead(PIR);
    if (moveFound == HIGH)
      {
        endTime = millis() + ONTime;
      }
  } 
 
  digitalWrite(led, LOW);
  digitalWrite(relay, LOW);
  Serial.println("Closed");

  moveFound = digitalRead(PIR);
  while(moveFound == LOW)
  {
    moveFound = digitalRead(PIR);
  }
}
