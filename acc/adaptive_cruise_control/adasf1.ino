#define MR 13     //right motor
#define in1 23
#define in2 22
#define ML 12     //left motor
#define in3 24
#define in4 25

#define EL 27     //echo 
#define TL 26     //trig
#define EM 29
#define TM 28
#define ER 30
#define TR 31

int motorspeedA = 0;
int motorspeedB = 0;
int count=0;

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int trigPin,echoPin;

unsigned long starttime;

int distM;
int distL;
int distR;


void setup() 
{
  pinMode(ML, OUTPUT);
  pinMode(MR, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(TR, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(ER, INPUT); // Sets the echoPin as an INPUT
  pinMode(TM, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(EM, INPUT); // Sets the echoPin as an INPUT
  pinMode(TL, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(EL, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  
  
}


void loop() 
{
    oc();
    analogWrite(MR, motorspeedA); // Send PWM signal to motor A
    analogWrite(ML, motorspeedB); // Send PWM signal to motor B


//    distancef('R');
//    distancef('M');
//    distancef('L');
//    delay(1000);
//    Serial.println();
//    forward();
//      rotateleft();
//   
//      rotateright();
   
}
