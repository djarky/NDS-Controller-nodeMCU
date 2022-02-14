This sketch are a hack of NDS Controller app : https://github.com/Louisvh/NDS-Controller
to control Nodemcu things with Nintendo DS

nodemcuNDSpuente.ino 
is a first sketch for understand the UPD protrocol that use NDS Controller app

nodemcuNDScontroller.ino
 is a second sketch that define buttons that use the 1st Controller, there are 4 Controllers avalible if want use it you need mod  the indexes of this line( that read from the buffer) 
joypad=(packetBuffer[2]*256)+packetBuffer[3] ;
to [4][5] or else  

nodemcuNDScar.ino
 is a implement of the second sketch to control motors (and their drive) of a Car conected to nodemcu see my YouTube video :
https://youtube.com/shorts/lSqSVhsI_Cs?feature=share