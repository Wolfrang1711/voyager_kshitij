#define IN1 8
#define IN2 7
#define ENA 6
#define ENB 5

int ir[6]={13,16,11,12,14,9}; // S6 S5 S4 S3 S8 S1

#define IN3 4
#define IN4 3

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(13,INPUT);
  pinMode(16,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(14,INPUT);
  pinMode(9,INPUT);
  
}

void straight(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,140);
  analogWrite(ENB,140);
}

void left(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,130); //Right
  analogWrite(ENB,110);//Left
}

void right(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,110);//Right
  analogWrite(ENB,130);  //Left
}
void right_turn(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,0); //Right
  analogWrite(ENB,110);  //Left
  delay(1000);
}

void left_turn(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,110); //Right
  analogWrite(ENB,0);  //Left
  delay(1000);
}
void pause(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  analogWrite(ENA,0);
  analogWrite(ENB,0);
}

int ir_val[6];

void loop() {
  // put your main code here, to run repeatedly:
  int decision ;
  for(int i=0;i<=5;i++){
  ir_val[i]=digitalRead(ir[i]);
        }
  while (ir_val[4]==0 && ir_val[5]==0)
  {
    if (ir_val[0] == 0 && ir_val[1]  == 1 && ir_val[2]  == 1 && ir_val[3]  == 0 ) 
      {
        straight();
      }
      
    else if (ir_val[0] == 1 && ir_val[1]  == 1 && ir_val[2]  == 0 && ir_val[3]  == 0) 
    {
      left();
    }
      
    else if (ir_val[0] == 0 && ir_val[1]  == 0 && ir_val[2]  == 1 && ir_val[3]  == 1) 
    {
      right();
    } 
      
    else
    {
      straight();
    } 
    
    for(int i=0;i<=5;i++){
      ir_val[i]=digitalRead(ir[i]);
      Serial.println(ir_val[i];
        }
    
  }  
  
  pause();
 
  for(int i=0;i<=5;i++)
  {
    ir_val[i]=digitalRead(ir[i]);
  }
  delay(2000);
   
  if (ir_val[4]==1)decision=1;
  
  else if (ir_val[5]==1)decision=0;
  
  if(decision==0)left_turn();
  
  else right_turn();

  for(int i=0;i<=5;i++)
  {
      ir_val[i]=digitalRead(ir[i]);
  } 
}
