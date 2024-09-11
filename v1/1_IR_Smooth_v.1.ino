#define FR 6
#define FL 4
#define BR 7
#define BL 5
#define PR 9
#define PL 10
#define IR 11
#define S 150

bool CP1 = true;
bool CP2 = true;
bool READ = LOW;
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
  analogWrite(PR,S);
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
  analogWrite(PL,S);
  digitalWrite(FL,HIGH);
}
