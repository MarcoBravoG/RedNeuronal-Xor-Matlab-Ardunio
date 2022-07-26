#include "math.h"  
byte p1 , p2 ; 
float n1 , n2 , n3 ; 
float a1 , a2 ; 
float e=2.7182818 ; 

void setup() { 
   pinMode (7 , INPUT); 
   pinMode (8 , INPUT); 
   pinMode (13 , OUTPUT);
   Serial.begin(9600);
  }

  
void loop()
{
   p1=digitalRead ( 7 );
   p2=digitalRead ( 8 ) ; 
   Serial.print(p1);
   Serial.print(" ");
   Serial.print(p2);
   Serial.print(" ");
   
   n1= p1 * ( 2.9936 ) + p2 * ( -3.8426 ) + ( - 3.1467 ) ;
   n2 = p1 * ( - 3.8638 ) + p2 * ( 3.0818 ) + ( - 3.0739 ) ; 
   a1 = tansig ( n1 ) ; 
   a2 = tansig ( n2 );
   n3 = a1 * ( 1.1852 ) + a2 * ( 0.9973 ) + ( 2.1773 ) ; 
   n3=round(n3); //redondeamos para que no salga - negativos 
   digitalWrite ( 13 , n3 );
   Serial.println(n3);


}


// funcion tansig
float tansig ( float x ) { 
  float a ; 
  a = ( pow ( e , x ) -pow ( e , -x ) ) / ( pow ( e , x ) + pow ( e , -x ) ) ; 
  return a ; 
  }
