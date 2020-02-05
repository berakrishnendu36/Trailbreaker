const int LP1 = 7;
const int LP2 = 6;
const int RP2 = 5;
const int RP1 = 4;

const int LPWM = 9;
const int RPWM = 3;

const int irPins[8]={A0, A1, 13, 12, 11, 10, 8, 2};
const int irSensorDigital[]={0, 0, 0, 0, 0, 0, 0, 0};
int irSensors = B00000000;
String irValues = "00000000";
//D7: 02
//D6: 08
//D5: 10
//D4: 11
//D3: 12
//D2: 13
//D1: A1
//D0: A0

void hard_left(){
      digitalWrite(motorLpin1, HIGH);
      digitalWrite(motorLpin2, LOW);
      digitalWrite(motorRpin1, LOW);
      digitalWrite(motorRpin2, HIGH);
}

void soft_left(){
      digitalWrite(motorLpin1, HIGH);
      digitalWrite(motorLpin2, LOW);
      digitalWrite(motorRpin1, LOW);
      digitalWrite(motorRpin2, LOW);
}

void forward(){
      digitalWrite(motorLpin1, HIGH);
      digitalWrite(motorLpin2, LOW);
      digitalWrite(motorRpin1, HIGH);
      digitalWrite(motorRpin2, LOW);
}

void backward(){
      digitalWrite(motorLpin1, LOW);
      digitalWrite(motorLpin2, HIGH);
      digitalWrite(motorRpin1, LOW);
      digitalWrite(motorRpin2, HIGH);
}

void hard_right(){
      digitalWrite(motorLpin1, LOW);
      digitalWrite(motorLpin2, HIGH);
      digitalWrite(motorRpin1, HIGH);
      digitalWrite(motorRpin2, LOW);
}

void soft_right(){
      digitalWrite(motorLpin1, LOW);
      digitalWrite(motorLpin2, LOW);
      digitalWrite(motorRpin1, HIGH);
      digitalWrite(motorRpin2, LOW);
}

void stopMotion(){
      digitalWrite(motorLpin1, LOW);
      digitalWrite(motorLpin2, LOW);
      digitalWrite(motorRpin1, LOW);
      digitalWrite(motorRpin2, LOW);
}



void full_left(){
      forward();
      delay(100);
      hard_left();
      delay(200);
      stopMotion();
      delay(200);
}

void full_right(){
      forward();
      delay(100);
      hard_right();
      delay(200);
      stopMotion();
      delay(200);
}

void full_forward(){
      forward();
      delay(50);
      stopMotion();
      delay(150);
}

void correct_left(){
      backward();
      delay(70);;
      soft_left();
      delay(50);
      stopMotion();
      delay(100);
}

void correct_right(){
      backward();
      delay(70);
      soft_right();
      delay(50);
      stopMotion();
      delay(100);

void scanIrSensor(){
  for(byte count =0; count<8; count++){
    bitWrite(irSensors, count, !digitalRead(irPins[count]));
    irValues[count]=digitalRead(irPins[count])+'0';
  }
}

void scanIrSensorBW(){
  for(byte count =0; count<8; count++){
    bitWrite(irSensors, count, !digitalRead(irPins[count]));
    irValues[count]=!digitalRead(irPins[count])+'0';
  }
  Serial.println(irValues);
}


void setup() {

  Serial.begin(9600);

  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  // put your setup code here, to run once:

  //IR sensors Pin Mode
    for(int i=0; i<8; i++){
      pinMode(irPins[i], INPUT);}

}

void loop() {
  scanIrSensorBW();
  analogWrite(ENA, 70);
  analogWrite(ENB, 70); 
if(irValues=="11111111") stopMotion();
    else if(irValues[7]=='0' && irValues[6]=='0' && irValues[5]=='0'){
      full_left();
    }else if(irValues[0]=='0' && irValues[1]=='0' && irValues[2]=='0'){
      full_right();
    }
    else if(irValues[7]=='0' || irValues[6]=='0'){
      correct_left();
    }else if(irValues[0]=='0' || irValues[1]=='0'){
      correct_right();
    }
  
  // put your main code here, to run repeatedly:

}
