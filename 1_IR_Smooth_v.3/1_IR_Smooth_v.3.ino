#define FR 6
#define FL 4
#define BR 7
#define BL 5
#define PR 9
#define PL 10
#define IR 11
#define PT A0

bool CP1 = true;
bool CP2 = true;
bool READ = LOW;

int PTread;
int Speed;
int speed;
int presentage;
void setup()
{
  Serial.begin(9600);
  pinMode(FR, OUTPUT);
  pinMode(FL, OUTPUT);
  pinMode(BR, OUTPUT);
  pinMode(BL, OUTPUT);
  pinMode(PR, OUTPUT);
  pinMode(PL, OUTPUT);
  pinMode(IR, INPUT);

}

void loop()
{

  READ = digitalRead(IR);
  RIGHT();

  if (READ == HIGH)
  {
  while(READ == HIGH)
  {
    
    READ = digitalRead(IR);
    LEFT();
    Serial.println('e');
  }
  LEFT();
  delay(100);
  }

















}
void RIGHT()
{
  SPEED();
  analogWrite(PR, 100);
  digitalWrite(FR, HIGH);
  analogWrite(PL, 20);
  digitalWrite(FL, HIGH);
}
void stop()
{
  pinMode(FR, LOW);
  pinMode(FL, LOW);
  pinMode(BR, LOW);
  pinMode(BL, LOW);
}
void LEFT ()
{
  SPEED();
  analogWrite(PL, 100);
  digitalWrite(FL, HIGH);
  analogWrite(PR, 20);
  digitalWrite(FR, HIGH);
}
void SPEED()
{
  PTread = analogRead(PT);
  Speed = PTread * 255.0 / 1001.0;
  speed = constrain(Speed, 70, 255);
  presentage = map(speed, 70, 255, 0, 100);
  //Serial.print(presentage);
  //Serial.println('%');

}
