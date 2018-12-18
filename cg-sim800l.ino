/*    This is a bare bone library for communicating with SIM800
 *    It's barebone in that - it only provides basic functunaitlites while still 
 *    maintaining strong performance and being memory friendly.
 *    It currently supports GSM(sending and reading SMS), 
 *    GPRS connectivity(sending and receiving TCP) with Time and Location
 *     
 *    This library is writing by  Ayo Ayibiowu.
 *    charlesayibiowu@hotmail.com
 *    Designed to work with the GSM Sim800l module,
 *    and possibily other SIMxxx modules(not tested with others)
 *  
 *    This library use AltSoftSerial, and the pins has already be defined
 *    be sure that GND is attached to arduino too. 
 *    The RESET_PIN is not used for this Library, you can leave it un-connected
 *    
 *    To Enable Debugging - Go to <BareBoneSim800.h file and change the
 *    #define DEBUG 0 to #define DEBUG 1
 *         
 *    PINOUT: 
 *        _____________________________
 *       |  ARDUINO UNO >>>   SIM800L  |
 *        -----------------------------
 *            GND      >>>   GND
 *        RX  8       >>>   TX    
 *        TX  9       >>>   RX
 *      
 *                 
 *   POWER SOURCE 4.2V (MAX) >>> VCC
 *
 *        Created on: Oct 24, 2017
 *        Author: Ayo Ayibiowu
 *        Email: charlesayibiowu@hotmail.com
 *        Version: v1.0
 *        
 *
*/

#include <BareBoneSim800.h>

BareBoneSim800 sim800("gpinternet");  //to declare the library with an APN
//BareBoneSim800 sim800("gloworld");

// username and password has been set to "" in the Library Code


void setup() {
  Serial.begin(9600);
  sim800.begin();
  while(!Serial);

  Serial.println("Testing GSM module For Time Reading and Location");
  delay(8000); // this delay is necessary, it helps the device to be ready and connect to a network

  Serial.println("Should be ready by now");
    bool deviceAttached = sim800.isAttached();
  if (deviceAttached)
    Serial.println("Device is Attached");
  else
    Serial.println("Not Attached");

   delay(5000); // let it sleep for about 5secs
  // disable sleep mode
  
  bool disableSleep = sim800.disableSleep();
    if(disableSleep)
    Serial.println("Sleep Mode/Low Power Disabled");
  else
    Serial.println("Sleep not Disbaled");

String simNumber = sim800.readSIMNumber();
Serial.print("Sim number is: "+simNumber);

    //Send sms
//    bool isSmsSent = sim800.sendSMS("8801794620787", "Hello");
//    if(isSmsSent)
//    Serial.println("Sms is sent");
//  else
//    Serial.println("Sms is not sent");
//
//    delay(5000); // let it sleep for about 5secs

 // Testing for Time Reading and Location
// String time1 = "";
// String location = "";
// time1 = sim800.getTime();
// delay(100);
// location = sim800.getLocation();
// Serial.print("Time received in GMT is: ");
// Serial.println(time1);
// Serial.print("Location is: ");
// Serial.println(location);
}

void loop() {
  //zZZzz

}
