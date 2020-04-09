#include <ESP8266WiFi.h>                                    
//To setup Dummy AP
IPAddress local_IP(192,168,4,22);

IPAddress gateway(192,168,4,9);

IPAddress subnet(255,255,255,0);

 
//=======================================================================
//                     SETUP
//=======================================================================
void setup() {
  Serial.begin(115200);
  Serial.println(""); //Remove garbage
 
  // Set WiFi to station and  AP mode
  WiFi.mode(WIFI_AP_STA);
  WiFi.disconnect();  //ESP has tendency to store old SSID and PASSword and tries to connect
  delay(100);
 
  WiFi.softAPConfig(local_IP, gateway, subnet);
  Serial.println("WiFi Netwoek Scan Started");
  WiFi.softAP("RED");//or GREEN Flag to identify
  
}
 
//=======================================================================
//                        LOOP
//=======================================================================
void loop() {
 
  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
   
  Serial.println("Scan done");
  
  if (n == 0)
    Serial.println("Safe Zone");
  else
  {
    for (int i = 0; i < n; ++i)
    {
      Serial.print(); //Signal Strength
      //-55 is a dummy value can be caliberated according to distance and RED is Flag for a particular person
      	if(WiFi.RSSI(i)>-55 || WiFi.SSID(i)=="RED")
	    {
		      Serial.println("Warning!!!!!! Maintain Distance (and Turn on Buzzer need to be connected )");
		      delay(3000);
      }
      delay(10);
    }
  }
  Serial.println("");
 
  // Wait a bit before starting New scanning again
  delay(3000);
}
