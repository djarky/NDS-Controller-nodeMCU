#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* nombre ="arky";


unsigned int localPort = 3210;      // local port to listen on

unsigned char packetBuffer[255]; //buffer to hold incoming packet
char  ReplyBuffer[] = "acknowledged";       // a string to send back

WiFiUDP Udp;
            



void setup(){

//WiFi.softAP(nombre, password, channel);
    
//WiFi.softAP(nombre,"", channel);
    
  WiFi.softAP(nombre);

  Serial.begin(9600);
  
  Udp.begin(localPort); 

  delay(1000);
    
  Serial.println("iniciado");
}

void loop() {
    // if there's data available, read a packet
  delay(1000);
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
    Serial.print("From ");
    IPAddress remoteIp = Udp.remoteIP();
    Serial.print(remoteIp);
    Serial.print(", port ");
    Serial.println(Udp.remotePort());
for(int i=0;i<packetSize;i++){
        packetBuffer[i] = 0;
    }
    // read the packet into packetBufffer
       int len = Udp.read(packetBuffer, 255);
    if (len > 0) {
      packetBuffer[len] = 0;
    }
    Serial.println("Contents:");
    //Serial.println(packetBuffer);
    for(int i=0;i<packetSize;i++){
Serial.print(i); 
Serial.print(":");
unsigned char a = packetBuffer[i]; 
int b=a;            Serial.println(b) ; 
delay(10);
    }

    // send a reply, to the IP address and port that sent us the packet we received
        /*
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write(ReplyBuffer);
    Udp.endPacket();
        */
  }
}

  

