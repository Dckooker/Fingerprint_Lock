

#include "FPS_GT511C3.h"
#include "SoftwareSerial.h"
#include <Servo.h>
#define LED 12




Servo myservo;
int unlock = 0; 
int lock = 180; 

int tracker = 0;

FPS_GT511C3 fps(5, 4); 

 

void setup() 
{
  Serial.begin(9600); 
  delay(100);
  pinMode(LED,OUTPUT);          
  fps.Open();
  fps.SetLED(true);

   myservo.attach(9);
  
  

}

void loop() 
{  


 
  if (fps.IsPressFinger())
  {
    
    fps.CaptureFinger(false);
    int id = fps.Identify1_N();
     fps.SetLED(false);
    

      

    
     if (id < 200 )
     {
     
     
      digitalWrite(LED, HIGH);
      delay(1100);
      digitalWrite(LED, LOW);

      if (tracker == 0){
      tracker = tracker +1;
      delay(15);
      
        myservo.attach(9);
          delay(15); 
          myservo.write(unlock);
          delay(15); 
          myservo.detach();  
          delay(500); 
      }

      else if (tracker == 1)
      {
       tracker = tracker - 1;
       delay(15);
          
        myservo.attach(9);
          delay(15); 
          myservo.write(lock);
          delay(15); 
          myservo.detach(); 
           

    }
    
myservo.detach();
      
     }  

       

    else
     {
     myservo.detach(); 
      digitalWrite(LED, HIGH);
      delay(100);
      digitalWrite(LED, LOW);
       delay(100);
       digitalWrite(LED, HIGH);
      delay(100);
      digitalWrite(LED, LOW);
       delay(100);
       digitalWrite(LED, HIGH);
      delay(100);
      digitalWrite(LED, LOW);
    }

    myservo.detach(); 

 }


  else {
 myservo.detach();
   fps.SetLED(true);
   
 
}

    

delay(10);
     
}
