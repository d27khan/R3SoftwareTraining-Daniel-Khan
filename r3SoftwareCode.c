{\rtf1\ansi\ansicpg1252\cocoartf2513
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 int motorPin13 = 11; //13 on the IC, 11 on the arduino\
int motorPin10 = 10; //10 on the IC, 10 on the arduino\
int motorPin2  = 9;  //2 on the IC,  6 on the arduino\
int motorPin7  = 6;  //7 on the IC, 5 on the arduino\
int dip1 = 2;\
int dip2 = 3;\
int dip3 = 4;\
int dip4 = 5;\
int potPin = 0;\
\
void setup()\
\{\
  pinMode(motorPin13, OUTPUT);// setting all the pins as output\
  pinMode(motorPin10, OUTPUT);// to send signals to the motor Controller\
  pinMode(motorPin2 , OUTPUT);\
  pinMode(motorPin7 , OUTPUT);\
  pinMode(dip1, INPUT_PULLUP);\
  pinMode(dip2, INPUT_PULLUP);\
  pinMode(dip3, INPUT_PULLUP);\
  pinMode(dip4, INPUT_PULLUP);\
\}\
\
\
void loop()\{	\
 \
  int speed = analogRead(potPin);\
  \
  if(digitalRead(dip1) == LOW)\{\
    fwd(speed);\
  \}else if(digitalRead(dip2) == LOW)\{\
  	rev(speed);\
  \}else if(digitalRead(dip3) == LOW)\{\
  	rightTurn(speed);\
  \}else if(digitalRead(dip4) == LOW)\{\
	leftTurn(speed);  \
  \}else\{\
  motorStop();\
  \}\
  \
\}\
\
\
void fwd(int Mspeed)\{\
  	analogWrite(motorPin13, Mspeed);\
  	analogWrite(motorPin10, !Mspeed);\
  	analogWrite(motorPin2 , Mspeed);\
  	analogWrite(motorPin7 , !Mspeed);\
 	\
\}\
void rev(int Mspeed)\{\
  	analogWrite(motorPin13, !Mspeed);\
  	analogWrite(motorPin10, Mspeed);\
  	analogWrite(motorPin2 , !Mspeed);\
  	analogWrite(motorPin7 , Mspeed);\
  	\
\}\
void rightTurn(int Mspeed)\{\
  	analogWrite(motorPin13, !Mspeed);\
  	analogWrite(motorPin10, Mspeed);\
  	analogWrite(motorPin2 , Mspeed);\
  	analogWrite(motorPin7 , !Mspeed);\
  	\
\}\
void leftTurn(int Mspeed)\{\
  	analogWrite(motorPin13, Mspeed);\
  	analogWrite(motorPin10, !Mspeed);\
  	analogWrite(motorPin2 , !Mspeed);\
  	analogWrite(motorPin7 , Mspeed);\
  	\
\}\
\
void motorStop()\{\
	digitalWrite(motorPin13, LOW);\
  	digitalWrite(motorPin10, LOW);\
  	digitalWrite(motorPin2 , LOW);\
  	digitalWrite(motorPin7 , LOW);\
\}\
}