#include <Servo.h>
#include<math.h>

//int x = 5;
//int z = 5;


const int joy1XPin = A0; //for changing  x
const int joy1YPin = A1; //for changing  z
const int joy2XPin = A3; //for changing  y

Servo servo1,servo2,servo3;

void setup() {
  // put your setup code here, to run once:
servo1.attach(6); //shoulder
servo2.attach(5); //elbow
servo3.attach(2); //wrist
Serial.begin(9600);

servo1.write(90); //to set home position
servo2.write(0);  // 
servo3.write(90); //


}

void loop() {
//to give input to x,y,z
  int joy1X = analogRead(joy1XPin); 
  int joy1Y = analogRead(joy1YPin);
  int joy2X = analogRead(joy2XPin);

//double is used because int datatype can't handle the data 
 double x,z,y,r,r1,phi1,phi2,theta2,theta1,theta3,Theta3,Theta1,Theta2,pi; 
 pi=22/7;

//code to increase and decrease the x,y,z using joystick
 if (joy1X>800){
    x = x +1;
   // servo1.write(angle1);
    delay(250);
  }
  else if (joy1X<200){
    x = x-1;
   // servo1.write(angle1);
    delay(250);
  }
  if (joy1Y<200){
    z = z-1;
    // servo2.write(angle2);
     delay(250);
  }
  else if (joy1Y>800){
    z = z+1;
    // servo2.write(angle2);
     delay(250);
  }
  if (joy2X<200){
    y = y-1;
    // servo2.write(angle2);
     delay(250);
  }
  else if (joy2X>800){
    y = y+1;
    // servo2.write(angle2);
     delay(250);
  }


 
// the calculation
 r1 = sqrt(sq(x)+sq(y)); 
 r=sqrt(sq(z)+sq(r1));
 
 if (sq(r) < 288 ) 
 {
    theta3= atan2(y,x);
    phi2=atan(z/r1);
    theta2= acos((288-sq(r))/288);
    phi1=(pi-theta2)/2;
    theta1=phi1+phi2;
  
    Theta3= theta3*(180/pi);
    Theta1=theta1*(180/pi);
    Theta2=theta2*(180/pi);
    servo1.write(Theta1);
    servo2.write(Theta2);
    servo3.write(Theta3+90);
 }
 //else {

//  servo1.write(90);
//   servo2.write(0);
//  //exit(0);
 //continue();
 //}
 Serial.print("Theta1 = ");
 Serial.println(Theta1);
 Serial.print(" Theta2 = ");
 Serial.println(Theta2);
 Serial.print(" Theta3 = ");
 Serial.println(Theta3);
 Serial.print(" x = ");
 Serial.println(x);
 Serial.print(" z = ");
 Serial.println(z);
 Serial.print(" y = ");
 Serial.println(y);



}