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
  pinMode(FR,OUTPUT);
  pinMode(FL,OUTPUT);
  pinMode(BR,OUTPUT);
  pinMode(BL,OUTPUT);
  pinMode(PR,OUTPUT);
  pinMode(PL,OUTPUT);
  pinMode(IR,INPUT);

}

void loop()
{ 
 while(CP1)
 {
  
  READ=digitalRead(IR);
  RIGHT();
  
  if(READ==HIGH)
  {
     delay(50);
     
     while(READ==HIGH)
     {
      READ=digitalRead(IR);
      RIGHT();
     }
     
     stop();
     CP1=false;
     CP2=true;
  }
  
 }

while(CP2)
 {
  
  READ=digitalRead(IR);
  LEFT();
  
  if(READ==HIGH)
  {
     delay(50);
     
     while(READ==HIGH)
     {
      READ=digitalRead(IR);
      LEFT();
     }
     
     stop();
     CP1=true;
     CP2=false;
  }
  
 }

















}
void RIGHT()
{
  SPEED();
  analogWrite(PR,speed);
  digitalWrite(FR,HIGH);
}
void stop()
{
  pinMode(FR,LOW);
  pinMode(FL,LOW);
  pinMode(BR,LOW);
  pinMode(BL,LOW);
}
void LEFT ()
{
  SPEED();
  analogWrite(PL,speed);
  digitalWrite(FL,HIGH);
}
void SPEED()
{
   PTread=analogRead(PT);
   Speed=PTread*255.0/1001.0;
   speed=constrain(Speed,70,255);
   presentage=map(speed,70,255,0,100);
  Serial.print(presentage);
  Serial.println('%');
  
}
