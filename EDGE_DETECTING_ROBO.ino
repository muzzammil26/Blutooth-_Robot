int motor1_ena = 3;
int motor1_in1 = 4;
int motor1_in2 = 5;

int motor2_enb = 9;
int motor2_in3 = 10;
int motor2_in4 = 11;

const int trigPin = 12;
const int echoPin = 13;
int distance;
long duration;

void setup() {
  pinMode(motor1_ena, OUTPUT);
  pinMode(motor1_in1, OUTPUT);
  pinMode(motor1_in2, OUTPUT);

  pinMode(motor2_enb, OUTPUT);
  pinMode(motor2_in3, OUTPUT);
  pinMode(motor2_in4, OUTPUT);

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

Serial.println(distance);

  if(distance > 9){
    analogWrite(motor1_ena, 75);
    analogWrite(motor2_enb, 75);

    digitalWrite(motor1_in1, LOW);
    digitalWrite(motor1_in2, LOW);

    digitalWrite(motor2_in3, LOW);
    digitalWrite(motor2_in4, LOW);
    delay(2000);

    digitalWrite(motor1_in1, LOW);
    digitalWrite(motor1_in2, HIGH);

    digitalWrite(motor2_in3, HIGH);
    digitalWrite(motor2_in4, LOW);

    delay(1000);
    
    digitalWrite(motor1_in1, LOW);
    digitalWrite(motor1_in2, HIGH);

    digitalWrite(motor2_in3, LOW);
    digitalWrite(motor2_in4, HIGH);

    


    delay(1000);
  }
  else{
    analogWrite(motor1_ena, 75);
    analogWrite(motor2_enb, 75);
    
    digitalWrite(motor1_in1, HIGH);
    digitalWrite(motor1_in2, LOW);

    digitalWrite(motor2_in3, LOW);
    digitalWrite(motor2_in4, HIGH);
  }

}
