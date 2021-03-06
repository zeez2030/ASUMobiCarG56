                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 const int ENA = 10;
const int ENB = 5;
const int In1 = 9;
const int In2 = 8;
const int In3 = 7;
const int In4 = 6;

int max_speed = 255;
String command;
long delay_time ;
long delay_timel;
long delay_time2;
String distance;
float time_now;
float time_total;
long lateral;
long half;
 int maxspeed=40 ;
 long forwardspeed;
 long rightspeed;
void setup() {
Serial.begin(9600);

//pins for motor controller
pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT);
pinMode(In1, OUTPUT);
pinMode(In2, OUTPUT);
pinMode(In3, OUTPUT);
pinMode(In4, OUTPUT);

}
 
void loop() {
if(Serial.available() > 0){
command = Serial.readString();
Stop();

distance = command.substring(1); 
delay_time = (distance.toInt())*0.016*1000;
delay_timel= (distance.toInt()) *10.4;//10.9 
delay_time2= (distance.toInt()) *9.44 ;


Serial.println(delay_time);

  
switch(command[0]){
  case 'f':
    time_now=millis();
    forward();
     while(millis()<time_now+delay_time){
      
      }
     Stop();
    break;
   case 'b':
   time_now=millis();
     backward();
     while(millis()<time_now+delay_time){
    
      }
     Stop();
     break;
   case 'r': //turn right
   time_now=millis();
     right();
     if(distance.toInt()>=90){
    while(millis()<time_now+delay_timel-200){
      }}
      else{
         while(millis()<time_now+delay_timel-100){
      }
        }
      
     Stop();
     break;
     case 'l':
     time_now=millis();
     left();
     if(distance.toInt()>=90){
     while(millis()<time_now+delay_time2-200){
      }}
      else{
         while(millis()<time_now+delay_time2-100){
      }
        
        }
     Stop();
     break;
     case 'I': //infinity shape
     lateral=(sqrt(2*distance.toInt()*distance.toInt()));
     half=((distance.toInt())/2);
        time_now=millis();
        right();
        while(millis()<time_now+490.5){}
        time_now=millis();
        forward();
        while(millis()<time_now+(lateral*16)){}
        Stop();
        delay(500);
        time_now=millis();
       left();
        while(millis()<time_now+850){}
          time_now=millis();
         forward();
        while(millis()<time_now+(half*16)){}
        Stop();
        delay(500);
        time_now=millis();
       left();
        while(millis()<time_now+830){}
         time_now=millis();
        forward();
        while(millis()<time_now+(half*16)){}
        Stop();
        delay(500);
        time_now=millis();
        left();
        while(millis()<time_now+850){}
        time_now=millis();
        forward();
        while(millis()<time_now+(lateral*16)){}
        Stop();
        delay(500);
        time_now=millis();
        right();
        while(millis()<time_now+763){}
          time_now=millis();
        forward();
        while(millis()<time_now+(half*16)){}
        Stop();
        delay(500);
         time_now=millis();
        right();
        while(millis()<time_now+763){}
          time_now=millis();
        forward();
        while(millis()<time_now+(half*16)+100){}
          Stop();
        delay(500);
         time_now=millis();
        right();
        while(millis()<time_now+400){}
        Stop();
        break;
   case 'a'://right rectangle
   
                for(int i=1 ; i<=4 ; i++){
                time_now=millis();
                forward();
                while(millis()<time_now+delay_time){}
                Stop();
                delay(500);
                time_now=millis();
                right();
                int p=0;
                while(millis()<time_now+730-(i*20)){}
                Stop();
                delay(500); 
                p++;
                }

                Stop();
                break;


   case'c'://left rectangle
      
         for(int i=1 ; i<=4 ; i++){
                time_now=millis();
                forward();
                while(millis()<time_now+delay_time){}
                Stop();
                delay(500);
                time_now=millis();
                left();
                while(millis()<time_now+790){}
                Stop();
                delay(500);
                
                }   
        
        
            Stop();
            break;
   case'q'://forward right with angle 
          time_now=millis();
          right();
          while(millis()<time_now+delay_timel){}
          Stop();
          delay(500);
          time_now=millis();
          forward();
          while(millis()<time_now+500){}
          Stop();
          break;

   default:
     Stop();
     break;
   
   }
  

 }
}
 
// function for driving straight
void forward(){
digitalWrite(In1, HIGH);
digitalWrite(In2, LOW);
 
digitalWrite(In3, HIGH);
digitalWrite(In4, LOW);
 
analogWrite(ENA, max_speed/2);
analogWrite(ENB, max_speed/2);
}
 
//function for reversing
void backward(){
 
digitalWrite(In1, LOW);
digitalWrite(In2, HIGH);
 
digitalWrite(In3, LOW);
digitalWrite(In4, HIGH);
 
analogWrite(ENA,max_speed/2);
analogWrite(ENB, max_speed/2);
}
 
//function for turning left
void right(){
digitalWrite(In3, LOW);
digitalWrite(In4, LOW);
 
digitalWrite(In1, HIGH);
digitalWrite(In2, LOW);
 
analogWrite(ENB, 0);
analogWrite(ENA, max_speed/2);
}
 
//function for turning right
void left(){
digitalWrite(In3, HIGH);
digitalWrite(In4, LOW);
 
digitalWrite(In1, LOW);
digitalWrite(In2, LOW);
 
analogWrite(ENB, 170);
analogWrite(ENA, 0);
}

//function for moving forward right
void forward_right(long forwardsp ){
digitalWrite(In3, HIGH);
digitalWrite(In4, LOW);
 
digitalWrite(In1, HIGH);
digitalWrite(In2, LOW);
 
analogWrite(ENB,90+ forwardsp);//90
analogWrite(ENA,180);//180
}

 //function for moving forward left
void forward_left(){
digitalWrite(In3, HIGH);
digitalWrite(In4, LOW);
  
digitalWrite(In1, HIGH);
digitalWrite(In2, LOW);
 
analogWrite(ENB, 200);
analogWrite(ENA,max_speed/2);
}

//function for moving backward right
void backward_right(){
digitalWrite(In4, HIGH);
digitalWrite(In3, LOW);
 
digitalWrite(In1, LOW);
digitalWrite(In2, HIGH);
 
analogWrite(ENB,max_speed/2);
analogWrite(ENA, max_speed);
}

//function for moving backward left
void backward_left(){
digitalWrite(In4, HIGH);
digitalWrite(In3, LOW);
 
digitalWrite(In1, LOW);
digitalWrite(In2, HIGH);
 
analogWrite(ENB,max_speed);
analogWrite(ENA, max_speed/2);
}
 
//function for stopping motors
void Stop(){
 
digitalWrite(In1, LOW);
digitalWrite(In2, LOW);

digitalWrite(In3,LOW);
digitalWrite(In4, LOW);
 
analogWrite(ENA, 0);
analogWrite(ENB, 0);
}
