#define trigPin 7
#define echoPin 6
#define MAX_LEVEL 255
#define MAX_DISTANCE 10
#define MIN_DISTANCE 2
#define ledPin1 9
#define buzzerPin 8
float distance;
int duration;


void setup() {
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  pinMode (ledPin1, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  Serial.println ("Started...");
}

void loop() {

   long duration, distance_cm;
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
  
   duration = pulseIn(echoPin, HIGH);

   distance_cm = microsecondsToCentimeters(duration);

   delay(100);
   int level = (float)(distance_cm-MIN_DISTANCE)/MAX_DISTANCE*MAX_LEVEL;
   
   setVariableBrightness(level, ledPin1);

   if (level == 0){
    digitalWrite(buzzerPin, HIGH);
   }
   else{
    digitalWrite(buzzerPin, LOW);
   }
}
void setVariableBrightness(int level, int pin){
  Serial.println("level");
  Serial.println(level);
  if (level > MAX_LEVEL){
    level = MAX_LEVEL;
  }
  if (level < 0){
    level = 0;
  }
  int brightness = int(255 - (float)level/MAX_LEVEL*255);
  Serial.println("brightness");
  Serial.println(brightness);
  analogWrite(pin, brightness);
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
