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

//WiFi.softAP(nombre, password, channel);
    
//WiFi.softAP(nombre,"", channel);
    
  WiFi.softAP(nombre);

  Serial.begin(9600);
  
  Udp.begin(localPort); 

  delay(1000);
    
  Serial.println("iniciado");
}

void loop(){
delay(100);
controller_data=NDSJoy();
    
if(controller_data &  J_A)
  {Serial.println("J_A");}
if(controller_data &  J_B)
  {Serial.println("J_B");}
if(controller_data &  J_X)
  {Serial.println("J_X");}
if(controller_data &  J_Y)
  {Serial.println("J_Y");}
if(controller_data &  J_R)
  {Serial.println("J_R");}    
if(controller_data &  J_L)
  {Serial.println("J_L");}
if(controller_data &  J_TOUCH)
  {Serial.println("J_TOUCH");}
if(controller_data &  J_UP)
  {Serial.println("J_UP");}
if(controller_data &  J_DOWN)
  {Serial.println("J_DOWN");}    
if(controller_data &  J_UP)
  {Serial.println("J_UP");}
if(controller_data &  J_LEFT)
  {Serial.println("J_LEFT");}
if(controller_data &  J_RIGHT)
  {Serial.println("J_RIGHT");}
if(controller_data &  J_START)
  {Serial.println("J_START");}
if(controller_data &  J_SELECT)
  {Serial.println("J_SELECT");}    

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

  

