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
  pinMode(motorPin13, OUTPUT);// setting all the motor 
  pinMode(motorPin10, OUTPUT);// pins as output
  pinMode(motorPin2 , OUTPUT);// to send signals to the 
  pinMode(motorPin7 , OUTPUT);// motor Controller
  
  pinMode(dip1, INPUT_PULLUP);//assigning Dip Switch
  pinMode(dip2, INPUT_PULLUP);//to input pullup
  pinMode(dip3, INPUT_PULLUP);
  pinMode(dip4, INPUT_PULLUP);
}


void loop(){	
 
  int speed = analogRead(potPin);// reads the position of the potentiometer
  
  if(digitalRead(dip1) == LOW && digitalRead(dip2) == HIGH
     && digitalRead(dip3) == HIGH && digitalRead(dip4) == HIGH)//if dip switch 1 is on then go fwd
  {
    	fwd(speed);
  }else if(digitalRead(dip1) == HIGH && digitalRead(dip2) == LOW 
     	&& digitalRead(dip3) == HIGH && digitalRead(dip4) == HIGH)//if dip switch 2 is on then go rev
  {
  		rev(speed);
  }else if(digitalRead(dip1) == HIGH && digitalRead(dip2) == HIGH 
     	&& digitalRead(dip3) == LOW && digitalRead(dip4) == HIGH)//if dip switch 3 is on then go right
    {
  		rightTurn(speed);
  }else if(digitalRead(dip1) == HIGH && digitalRead(dip2) == HIGH 
     	&& digitalRead(dip3) == HIGH && digitalRead(dip4) == LOW)//if dip switch 4 is on then go left
    {
		leftTurn(speed);  
  }else{// if all dip switches are off do nothing
 		 motorStop(); 
  }
  
}


void fwd(int Mspeed){// turns on motor and spins Clockwise
  	analogWrite(motorPin13, Mspeed);
  	analogWrite(motorPin10, !Mspeed);
  	analogWrite(motorPin2 , Mspeed);
  	analogWrite(motorPin7 , !Mspeed);
 	
}
void rev(int Mspeed){// turns on motor and spins CC
  	analogWrite(motorPin13, !Mspeed);
  	analogWrite(motorPin10, Mspeed);
  	analogWrite(motorPin2 , !Mspeed);
  	analogWrite(motorPin7 , Mspeed);
  	
}
void rightTurn(int Mspeed){// motor on top is the right motor*
  	analogWrite(motorPin13, !Mspeed);
  	analogWrite(motorPin10, Mspeed);
  	analogWrite(motorPin2 , Mspeed);
  	analogWrite(motorPin7 , !Mspeed);
  	
}
void leftTurn(int Mspeed){// bottom motor is left motor**
  	analogWrite(motorPin13, Mspeed);
  	analogWrite(motorPin10, !Mspeed);
  	analogWrite(motorPin2 , !Mspeed);
  	analogWrite(motorPin7 , Mspeed);
  	
}

void motorStop(){// Keeps everything off
	digitalWrite(motorPin13, LOW);
  	digitalWrite(motorPin10, LOW);
  	digitalWrite(motorPin2 , LOW);
  	digitalWrite(motorPin7 , LOW);
}
