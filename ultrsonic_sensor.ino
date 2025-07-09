# define trigPin  9
#define echoPin  10 
long duration; 
float distance;  

void setup () 
{ 
   pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT); 

  Serial.begin (9600); // Initiates serial communication at 9600 baud 
} 

void loop () 
{ 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH);//reading time taken for sound to come back to the source from echo pin 
  // Calculating the distance 
  distance = duration * 340.00/(1000 * 2);//considering speed of sound in air 340 m/s which changes with temperature  
  Serial.print("distance"); 
  Serial.print("      "); 
  Serial.println(distance); 
  delay (200);                  // Delay of 200ms 
}
