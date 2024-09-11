#define FR 6
#define FL 4
#define BR 7
#define BL 5
#define PR 9
#define PL 10

#define IRA 11
#define IRB 12
#define IRC 13
#define volt A5
#define PT A0 
#define BZ 8

bool READA = LOW;
bool READB = LOW;
bool READC= LOW;

int PTread;
int Speed;
int speed;
int presentage;

int Case;
int no1=1;
int no2=2;

void setup()
{
  digitalWrite(volt,HIGH);
  pinMode(volt,OUTPUT);
  
  Serial.begin(9600);
  pinMode(FR,OUTPUT);
  pinMode(FL,OUTPUT);
  pinMode(BR,OUTPUT);
  pinMode(BL,OUTPUT);
  pinMode(PR,OUTPUT);
  pinMode(PL,OUTPUT);
  
  pinMode(IRA,INPUT);
  pinMode(IRB,INPUT);
  pinMode(IRC,INPUT);
  
  
  pinMode(BZ,OUTPUT);
  stop('A');
  delay(3000);
  tone(BZ,3333);
   delay(700);
   noTone(BZ);
  delay(2000);


}

void loop()
 { 
  
  IRread();
  
  if(READB==HIGH )
  {
   Case=0;
  }
  
  else if(READB==LOW )
  {
  Case=1;
  }
  
  IRread();
  
  if(READA==HIGH && READC==HIGH )
  {  
    
      if(no1<no2)
      {
        no1++;
        Case=2;
      }
      else if(no1=no2)
      {
        no2+=2;
        no1++;
         IRread();
  while(READC==HIGH && READA==HIGH )
  {
    IRread();
      stop('A');
    FORWARD();
  }
    IRread();
  while(READB==LOW)
  {
    IRread();
    stop('R');
    LEFT();
  }
      }
    
  }
  switch(Case)
  {
  
    case 0:
      stop('A');
    FORWARD();
    break;

    case 1:
    IRread();
    while(READA==LOW && READC==LOW)
    {
       IRread();
         stop('A');
       FORWARD();
    }
    IRread();
    if(READA==HIGH)
    {
      while(READB==LOW)
      {
        IRread();
        stop('R');
        LEFT();
        tone(BZ,2900,100);
      }
    }else if(READC==HIGH)
    {
       while(READB==LOW)
      {
        IRread();
        stop('L');
        RIGHT();
        tone(BZ,3000,100);
      }
    }
    break;

    case 2:
   stop('A');
  for(int s=0;s<3;s++)
  { 
   tone(BZ,3333);
   delay(500);
   noTone(BZ);
   delay(500);
  }
  IRread();
  while(READC==HIGH && READA==HIGH )
  {
    IRread();
      stop('A');
    FORWARD();
  }
    IRread();
  while(READB==LOW)
  {
    IRread();
    stop('R');
    LEFT();
  }
    break;

    default:
    stop('A');
  }
 }














void IRread()
{
  READA=digitalRead(IRA);
  READB=digitalRead(IRB);
  READC=digitalRead(IRC);
}

void FORWARD()
{
  
  SPEED();
  analogWrite(PR,speed);
  digitalWrite(FR,HIGH);
  analogWrite(PL,speed);
  digitalWrite(FL,HIGH);
  Serial.println("x");
}
void stop(char state)
{
  if(state == 'R')        pinMode(FR,LOW);
  else if ( state == 'L') pinMode(FL,LOW); 
  else 
  {
    pinMode(FR,LOW);
    pinMode(FL,LOW); 
    pinMode(BR,LOW);
    pinMode(BL,LOW);
  }
}
void RIGHT()
{
  SPEED();
  analogWrite(PR,speed);
  digitalWrite(FR,HIGH);
  analogWrite(PL,20);
  digitalWrite(BL,HIGH);
}
void LEFT ()
{
  SPEED();
  analogWrite(PL,speed);
  digitalWrite(FL,HIGH);
  analogWrite(PR,20);
  digitalWrite(BR,HIGH);
}
void SPEED()
{
   PTread=analogRead(PT);
   Speed=PTread*255.0/1001.0;
   speed=constrain(Speed,70,255);
   presentage=map(speed,70,255,0,100);
  // Serial.println(PTread);
  // Serial.println('%');
  
}
