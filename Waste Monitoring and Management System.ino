#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define TRIGGERPIN 2
#define ECHOPIN    0
#define minimum 8
// You should get Auth Token in the Blynk App.
char auth[] = "x-HTyi9DznUXHxGjpoSDzHLXMkwye7sO";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "POCO PHONE";
char pass[] = "gvdks296";

WidgetLCD lcd(V1);


void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  Blynk.begin(auth, ssid, pass);

}

void loop()
{
  Blynk.run();
  lcd.clear();
  lcd.print(0, 0, "Area left"); 
  long duration, distance;
  digitalWrite(TRIGGERPIN, LOW);  
  delayMicroseconds(3); 
  
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(12); 
  
  digitalWrite(TRIGGERPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  distance = duration*0.034 / 2;
  Serial.print(distance);
  Serial.println("Cm");
  lcd.print(7, 1, distance);
  if(distance <=minimum )
  {
    Blynk.notify("Go and pick from bin");
  }
  delay(100);
  
   
}
