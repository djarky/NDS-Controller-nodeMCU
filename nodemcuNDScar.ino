#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#define J_A 1
#define J_B 2
#define J_SELECT 4
#define J_START 8
#define J_RIGHT 16
#define J_LEFT 32
#define J_UP 64
#define J_DOWN 128
#define J_R 256
#define J_L 512
#define J_X 1024
#define J_Y 2048
#define J_TOUCH 4096

const char* nombre ="arky";


unsigned int localPort = 3210;      // local port to listen on

unsigned char packetBuffer[8]; //buffer to hold incoming packet

WiFiUDP Udp;
            
int controller_data=0;

void setup(){
    /*
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    
    digitalWrite(5,LOW); 
    digitalWrite(6,LOW); 
    digitalWrite(7,LOW); 
    digitalWrite(8,LOW); 
    */

//WiFi.softAP(nombre, password, channel);
    
//WiFi.softAP(nombre,"", channel);
    
  WiFi.softAP(nombre);

  Serial.begin(9600);
  
  Udp.begin(localPort); 

  delay(1000);
    
  Serial.println("iniciado");
    
  while(!NDSJoy());

}

void loop(){
delay(100);
controller_data=NDSJoy();
    
if(controller_data ==  J_A)
  {
    digitalWrite(5,HIGH); 
    pinMode(6, INPUT);   
  }else{
        digitalWrite(5,LOW);
        pinMode(6, OUTPUT);
        }
if(controller_data ==  J_B)
  {
    digitalWrite(6,HIGH); 
    pinMode(5, INPUT);        
  }else{
        digitalWrite(6,LOW);
        pinMode(5, OUTPUT);
        }

if(controller_data &  J_LEFT)
  {
    digitalWrite(7,HIGH);   
  }else{digitalWrite(7,LOW);}
if(controller_data &  J_RIGHT)
  {
    digitalWrite(8,HIGH);  
  }else{digitalWrite(8,LOW);}

}

int NDSJoy() {
    int joypad=0;
    // if there's data available, read a packet
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    
  for(int i=0;i<8;i++){
     packetBuffer[i]=0;
   }

    // read the packet into packetBufffer
    Udp.read(packetBuffer, 255);
    joypad=(packetBuffer[2]*256)+packetBuffer[3];  
  } 

return joypad;  
}

  

