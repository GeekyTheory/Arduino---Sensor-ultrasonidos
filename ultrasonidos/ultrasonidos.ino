/*
     Arduino Digital Camera
	
Mario Pérez Esteso
http://www.geekytheory.com
https://www.youtube.com/user/telecoreference

https://twitter.com/geekytheory

Facebook page! Join us with a LIKE!
https://www.facebook.com/geekytheory
*/

#include "Ultrasonic.h" //Se incluye la librería

Ultrasonic ultrasonic(6,7); //(Trigger pin,Echo pin) 

int Piezo_Pin=9;
int dist_cm=0;

void setup(){  
  pinMode(Piezo_Pin,OUTPUT);
  Serial.begin(9600);
}

void PIEZO_BUZZ(unsigned char delay_milis,int pwm1,int pwm2){
  analogWrite(9, pwm1);      
  delay(delay_milis);          
  analogWrite(9, pwm2);       
  delay(delay_milis);  
} 
/*
  Para utilizar la función PIEZO_BUZZ(), tendremos que 
  pasar 3 parámetros: delay_milis, pwm1 y pwm2. El primer
  parámetro es para ver la cantidad de tiempo que queremos
  que pase entre pitidos. El segundo parámetro, pwm1, es para
  modificar el tono del piezoeléctrico. Podemos darle valores
  entre 0 y 255, así que escoged el que mejor os parezca. El 
  último parámetro, pwm2, sirve para lo mismo que pwm1.
*/

void loop(){
   
  dist_cm=ultrasonic.Ranging(CM); //Medimos la distancia en cm.
  
  Serial.println(dist_cm);

  if (dist_cm<5){
    PIEZO_BUZZ(800, 130, 0);
  } else if (dist_cm<10){
    PIEZO_BUZZ(50, 130, 0);
  } else if (dist_cm<17){
    PIEZO_BUZZ(100, 130, 0);
  } else if (dist_cm<23){
    PIEZO_BUZZ(400, 130, 0);
  } else if (dist_cm<30){
    PIEZO_BUZZ(1500, 130, 0);
  } else {
    PIEZO_BUZZ(0, 0, 0);
  }
}
