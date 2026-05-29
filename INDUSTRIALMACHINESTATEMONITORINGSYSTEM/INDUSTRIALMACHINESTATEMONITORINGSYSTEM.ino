


#include "ThingSpeak.h"
#include <WiFi.h>
#include "DHT.h"
// #define WIFI_NAME "testwifi"
// #define WIFI_PASSWORD "00000000"

// Replace with your network credentials
#define TRIGGER 27
#define ECHO 32
#define CHANNEL_ID 3342402
#define API_KEY "ZR0ST5TYV8E07CZA"
#define POTENTIO 36
#define LDR 39
#define DHTPIN 14
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
#define PIR 25



const char* ssid = "testwifi";
const char* password = "00000000";
const char *ssid1= "password";
const char *password1 = "12345678";

WiFiClient client;



void setup() {
  Serial.begin(9600);

  // Start Wi-Fi in station mode
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.println("Connecting to WiFi...");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Connected
  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());



  WiFi.softAP(ssid1, password1);

  Serial.println("WiFi Access Point started");
  Serial.print("SSID: ");
  Serial.println(ssid1);
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());

   ThingSpeak.begin(client);


   pinMode(TRIGGER,OUTPUT);
   pinMode(ECHO,INPUT);
   pinMode(POTENTIO,INPUT);
   pinMode(PIR,INPUT);

   dht.begin();
  



}    

void loop() 
{
  // You can add code here to run once Wi-Fi is connected
  
 delay(2000);
  digitalWrite(TRIGGER,LOW);
   delayMicroseconds(2);
   digitalWrite(TRIGGER,HIGH);
   delayMicroseconds(10);
   digitalWrite(TRIGGER,LOW);
//digitalWrite(ECHO,HIGH);
   int duration=pulseIn(ECHO,HIGH);
   duration=(duration*0.034)/2;
    Serial.println("ultrasonic");
   Serial.println(duration);
   ThingSpeak.setField(1,duration);

   int ret1=ThingSpeak.writeFields(CHANNEL_ID,API_KEY);
   if(ret1==200)
   {
    Serial.println("uploaded successfull");
   }
   else
   {
    Serial.println("error");
   }

   int result=analogRead(POTENTIO);
   ThingSpeak.setField(2,result);
   Serial.print("Potentio: ");
   Serial.println(result);

   
    

   int ldresult=analogRead(LDR);
   ThingSpeak.setField(3,ldresult);
   Serial.print("LDR: ");
   Serial.println(ldresult);

   float humidity=dht.readHumidity();
   float temperature=dht.readTemperature();
   ThingSpeak.setField(4,temperature);
   ThingSpeak.setField(5,humidity);

   if(isnan(humidity)||isnan(temperature))
   {
    Serial.println("DHT error");
   }

   Serial.println(humidity);
   Serial.println(temperature);


   int pirresult=digitalRead(PIR);

   ThingSpeak.setField(6,pirresult);
  Serial.print("PIR = ");
  Serial.println(pirresult);

   

delay(15000);



}


