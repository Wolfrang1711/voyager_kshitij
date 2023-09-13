#define IN1 8
#define IN2 7
#define ENA 6
#define ENB 5

int ir[6]={13,16,11,12,14,9}; // S6 S5 S4 S3 S8 S1

#define IN3 4
#define IN4 3

void setup() 
{
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(9,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  pinMode(14,INPUT);
  pinMode(16,INPUT);
  
}

void straight()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,140);
  analogWrite(ENB,140);
}

void right()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,160); //Right
  analogWrite(ENB,0);//Left
}

void left()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,0);//Right
  analogWrite(ENB,160);  //Left
}

void right_turn()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,0); //Right
  analogWrite(ENB,110);  //Left
  delay(1000);
}

void left_turn()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,110); //Right
  analogWrite(ENB,0);  //Left
  delay(1000);
}

void pause()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  analogWrite(ENA,0);
  analogWrite(ENB,0);
}

int ir_val[6];

void loop()
{
  int decision ;
  
  for(int i=0;i<=5;i++)
  {
    ir_val[i]=digitalRead(ir[i]);
  }
  
  while(1)
  {
    for(int i=0;i<=5;i++)
    {
        ir_val[i]=digitalRead(ir[i]);
    }
    
    if(ir_val[1]==1 && ir_val[3] ==1 && ir_val[2]==1)
    {
      left();
      delay(80);
    }
      
    else if(ir_val[1]==1)
    {
      left();
      delay(20);
      pause();
    }
 
    else if(ir_val[1]==0 )
    {
      right();
      delay(20);
    } 
  }
}
