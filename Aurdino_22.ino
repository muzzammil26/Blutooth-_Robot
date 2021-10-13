int left_sensor = 2;
int right_sensor = 3;
int left_motor_forward = 4;
int left_motor_backward = 5;
int right_motor_forward = 6;
int right_motor_backward = 7;

void setup() {
  
  

  Serial.begin(9600);

  pinMode(left_sensor, INPUT);
  pinMode(right_sensor, INPUT);
  pinMode(left_motor_forward, OUTPUT);
  pinMode(left_motor_backward, OUTPUT);
  pinMode(right_motor_forward, OUTPUT);
  pinMode(right_motor_backward, OUTPUT);

}

void loop() {
  
  if(digitalRead(left_sensor < 500) && digitalRead(right_sensor < 500)){
    digitalWrite(left_motor_forward, 255);
    digitalWrite(right_motor_forward, 255);
  }
  else if(digitalRead(left_sensor > 500) && digitalRead(right_sensor < 500)){
    digitalWrite(left_motor_forward, 0);
    digitalWrite(right_motor_forward, 255); 
  }
  else if(digitalRead(right_sensor > 500) && digitalRead(left_sensor < 500)){
    digitalWrite(left_motor_forward, 255);
    digitalWrite(right_motor_forward, 0);
  }
  else{
    digitalWrite(left_motor_forward, 0);
    digitalWrite(right_motor_forward, 0);
  }
 

}
