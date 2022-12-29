//1) wibracji
#include <Arduino.h>
#include <stdio.h>

#define ON HIGH
#define OFF LOW

#define Sensor_Out_Pin A5
#define LED_Pin  13
 
int present_condition = 0;
int previous_condition = 0;

void setup() {
pinMode(Sensor_Out_Pin, INPUT);
pinMode(LED_Pin, OUTPUT);
}
 

void LED_Pin_blink(void);
 
void loop() {
previous_condition = present_condition;
present_condition = digitalRead(Sensor_Out_Pin); 
 
if (previous_condition != present_condition) {
LED_Pin_blink();
 
} else {
digitalWrite(LED_Pin, OFF);
}
}
 
void LED_Pin_blink(void) {
digitalWrite(LED_Pin, ON);
delay(250);
digitalWrite(LED_Pin, OFF);
delay(250);
digitalWrite(LED_Pin, ON);
delay(250);
digitalWrite(LED_Pin, OFF);
delay(250);
}
void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");
  server.begin();
  Serial.println("Server started");
  Serial.print("Use this URL : ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

//wiatrak i pompa
  pinMode(wiatrak_pin, OUTPUT);
  pinMode(pompa_pin, OUTPUT);
}
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  String request = client.readStringUntil('\r');

  //sprawdzanie linku dla wiatraka
  if (request.indexOf("GET /fan/on") >= 0)
  {
    stan_wiatraka = HIGH;
    digitalWrite(wiatrak_pin, stan_wiatraka);
  }
  else if (request.indexOf("GET /fan/off") >= 0)
  {
    stan_wiatraka = LOW;
    digitalWrite(wiatrak_pin, stan_wiatraka);
  }
  
  //sprawdzanie linku dla pompy
  if (request.indexOf("GET /pump/on") >= 0)
  {
    stan_pompy = HIGH;
    digitalWrite(pompa_pin, stan_pompy);
  }
  else if (request.indexOf("GET /pump/off") >= 0)
  {
    stan_pompy = LOW;
    digitalWrite(pompa_pin, stan_pompy);
  }
  Serial.println(request);
  client.flush();
   client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connnection: close");
  client.println();
  client.println("<!DOCTYPE HTML>");
  client.println("<html><head>");
  client.println("<meta http-equiv=\"refresh\" content=\"5\">");
  client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
  client.println("<meta charset=\"UTF-8\"/>");
  client.println("<style>body{ background-color: #FFFFFF; font-family: Arial, Helvetica, Calibri; Color: #000088; }</style>\n");
  client.println("</head><body>");
  client.println("<br />"); 
  client.println(""); //  do not forget this one
  float moisture_percentage;
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  float sensorValue;
  float rainDigitalValium = 1 - digitalRead(rainDigital);

  if (isnan(h) || isnan(t) || isnan(f)) 
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  client.println("<h1>Projekt Szklarni</h1>");
  client.println("<br />"); 
  
  moisture_percentage = ( 100.00 - ( (analogRead(sensor_pin)/1023.00) * 100.00 ) );
  client.print("Wilgotnosc gleby (%): ");
          client.println(moisture_percentage, 2);  
          client.println("<br />");   
          client.print("Temperatura (C): ");
          client.println(t, 1);  
          client.println("<br />");  
          client.print("Poziom wody (%): ");
          client.println(sensorValue);  
          client.println("<br />");  
          client.print("Informacja o pogodzie: ");
          client.println(rainDigitalValium);
          if (rainDigitalValium == 1){
           client.print("Pada ");
          }
          else {
           client.print("Nie pada ");
          }  
          client.println("<br />");  
 
          client.print("Wilgotnosc powietrza (%): ");
          client.println(h, 0);  
          client.println("<br />"); 
          if (rainDigitalValium == 1){
           client.print("Pada ");
          }
          else {
           client.print("Nie pada ");
          }  
          client.println("<br />"); 

        
        //wiatrak
          client.println("<p>Wiatrak");
          if (stan_wiatraka == LOW) {
            client.println(" jest wyłączony &nbsp;");
            client.println("<a href=\"/fan/on\"><button>ON</button></a>");
          } else {
            client.println(" jest włączony &nbsp;");
            client.println("<a href=\"/fan/off\"><button>OFF</button></a>");
          }  
          client.println("</p>");
          client.println("<br />"); 
          
          //pompa
          client.println("<p>Pompa");
          if (stan_pompy == LOW) {
            client.println(" jest wyłączona &nbsp;");
            client.println("<a href=\"/pump/on\"><button>ON</button></a>");
          } else {
            client.println(" jest włączona &nbsp;");
            client.println("<a href=\"/pump/off\"><button>OFF</button></a>");
          }  
          client.println("</p>");
          client.println("<br />"); 

  
          client.println("</body></html>");

  Serial.println("Client disconnected");

  delay(1000);
}
