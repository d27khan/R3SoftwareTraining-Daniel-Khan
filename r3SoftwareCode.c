int motorPin13 = 11; //13 on the IC, 11 on the arduino
int motorPin10 = 10; //10 on the IC, 10 on the arduino
int motorPin2  = 9;  //2 on the IC,  6 on the arduino
int motorPin7  = 6;  //7 on the IC, 5 on the arduino
int dip1 = 2;
int dip2 = 3;
int dip3 = 4;
int dip4 = 5;
int potPin = 0;

void setup()
{
  pinMode(motorPin13, OUTPUT);// setting all the pins as output
  pinMode(motorPin10, OUTPUT);// to send signals to the motor Controller
  pinMode(motorPin2 , OUTPUT);
  pinMode(motorPin7 , OUTPUT);
  pinMode(dip1, INPUT_PULLUP);
  pinMode(dip2, INPUT_PULLUP);
  pinMode(dip3, INPUT_PULLUP);
  pinMode(dip4, INPUT_PULLUP);
}


void loop(){	
 
  int speed = analogRead(potPin);
  
  if(digitalRead(dip1) == LOW){
    fwd(speed);
  }else if(digitalRead(dip2) == LOW){
  	rev(speed);
  }else if(digitalRead(dip3) == LOW){
  	rightTurn(speed);
  }else if(digitalRead(dip4) == LOW){
	leftTurn(speed);  
  }else{
  motorStop();
  }
  
}


void fwd(int Mspeed){
  	analogWrite(motorPin13, Mspeed);
  	analogWrite(motorPin10, !Mspeed);
  	analogWrite(motorPin2 , Mspeed);
  	analogWrite(motorPin7 , !Mspeed);
 	
}
void rev(int Mspeed){
  	analogWrite(motorPin13, !Mspeed);
  	analogWrite(motorPin10, Mspeed);
  	analogWrite(motorPin2 , !Mspeed);
  	analogWrite(motorPin7 , Mspeed);
  	
}
void rightTurn(int Mspeed){
  	analogWrite(motorPin13, !Mspeed);
  	analogWrite(motorPin10, Mspeed);
  	analogWrite(motorPin2 , Mspeed);
  	analogWrite(motorPin7 , !Mspeed);
  	
}
void leftTurn(int Mspeed){
  	analogWrite(motorPin13, Mspeed);
  	analogWrite(motorPin10, !Mspeed);
  	analogWrite(motorPin2 , !Mspeed);
  	analogWrite(motorPin7 , Mspeed);
  	
}

void motorStop(){
	digitalWrite(motorPin13, LOW);
  	digitalWrite(motorPin10, LOW);
  	digitalWrite(motorPin2 , LOW);
  	digitalWrite(motorPin7 , LOW);
}
