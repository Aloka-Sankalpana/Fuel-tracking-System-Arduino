#include <HTTPClient.h>
#include <WiFi.h>

// const char *ssid = "Dialog 4G 330";
// const char *password = "9Cb848d1";
const char *ssid = "Nokia 2.1";
const char *password = "Aloka2003@";

NetworkServer server = NetworkServer(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(2000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}
const int potPin = 34;
int potvalue = 0;
String countNo;
void loop() {

  potvalue = analogRead(potPin);
  String resister = String(potvalue);
  NetworkClient client  = server.accept();
   HTTPClient request = HTTPClient();
  
  Serial.println(countNo);
 
   request.begin("http://192.168.8.108:8080/FuelMonitor/GetFuelValue?name="+ String(resister) + "&countNo=" + String(countNo));
   int status = request.GET();
  
  if(countNo == "first"){
    countNo = "second";
  }else{
    countNo = "first";
  }
   Serial.println(countNo);
   
   if(client){
   
   if(status > 0){
    if(status == HTTP_CODE_OK){
      String responseText = request.getString();
    
    }
   }else{
    Serial.println("Error");
   }
     
   }
   delay(10000);
    request.end();
  }