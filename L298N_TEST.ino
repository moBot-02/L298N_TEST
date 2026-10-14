//set PWM pin
int ENA = 3;
int ENB = 10;
//set Digital Pin_A
int IN1 = 4;
int IN2 = 5;
//set Digital Pin_B
int IN3 = 9;
int IN4 = 8;


void setup()
{

   Serial.begin(9600);
   pinMode(ENA,OUTPUT);
   pinMode(IN1,OUTPUT);
   pinMode(IN2,OUTPUT);

   pinMode(ENB,OUTPUT);
   pinMode(IN3,OUTPUT);
   pinMode(IN4,OUTPUT);

}
//there are 4 cases
// IN1 IN2 StateMent -  L(LOW) H(High)
//  L   L    STOP
//  L   H    REVERSE
//  H   L    FORWARD
//  H   H    BRAKE

void loop() 
{ 
   //For checking Forward -> STOP -> Reverse -> Brake -> Turn Left -> Turn Right
   int MaxSpeed = 150;
   int delayTime =3000; // wait for 1 seconds..

   // < Forward >
   Serial.println("START Forward");
   analogWrite(ENA,MaxSpeed);
   analogWrite(ENB,MaxSpeed);
   digitalWrite(IN1,HIGH);
   digitalWrite(IN2,LOW);
   //motor B
   digitalWrite(IN3,HIGH);
   digitalWrite(IN4,LOW);
   delay(delayTime);

   // < STOP >
   Serial.println("STOP");
   //motor A 
   digitalWrite(IN1,LOW);
   digitalWrite(IN2,LOW);
   //motor B
   digitalWrite(IN3,LOW);
   digitalWrite(IN4,LOW);
   delay(delayTime);

   // < Move Back >
   Serial.println("MOVE BACK");
   analogWrite(ENA,MaxSpeed);
   analogWrite(ENB,MaxSpeed);
   //motor A 
   digitalWrite(IN1,LOW);
   digitalWrite(IN2,HIGH);
   //motor B
   digitalWrite(IN3,LOW);
   digitalWrite(IN4,HIGH);
   delay(delayTime);

   // < BRAKE >
   Serial.println("BRAKE");
   //motor A 
   digitalWrite(IN1,HIGH);
   digitalWrite(IN2,HIGH);
   //motor B
   digitalWrite(IN3,HIGH);
   digitalWrite(IN4,HIGH);
   delay(delayTime);

   // < TURN LEFT >
   Serial.println("TURN LEFT");
   analogWrite(ENA,MaxSpeed);
   analogWrite(ENB,MaxSpeed);
   //motor A 
   digitalWrite(IN1,HIGH);
   digitalWrite(IN2,LOW);
   //motor B
   digitalWrite(IN3,HIGH);
   digitalWrite(IN4,HIGH);
   delay(delayTime);

   // < TURN RIGHT >
   Serial.println("TURN RIGHT");
   analogWrite(ENA,MaxSpeed);
   analogWrite(ENB,MaxSpeed);
   //motor A 
   digitalWrite(IN1,HIGH);
   digitalWrite(IN2,LOW);
   //motor B
   digitalWrite(IN3,LOW);
   digitalWrite(IN4,LOW);
   delay(delayTime);

   Serial.println("END");

}