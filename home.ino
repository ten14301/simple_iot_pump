
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

//รหัสเชื่อมต่อ Line token
#define LINE_TOKEN "jcLaNOzMv1YZocKizQf0Al10HtDJ1veqlSjE4jBQNTS"


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "hheMIjaxdt37oSNlrZsGLK1iuIKmC_W9";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "jangasivi";
char pass[] = "0614646485";

WidgetLCD lcd(V0);

void setup()
{
  WiFi.begin(ssid, pass);
  Serial.begin(9600);  
  pinMode(15,OUTPUT);
  digitalWrite(15, HIGH);
  Blynk.begin(auth, ssid, pass);
}
BLYNK_WRITE(V2)
 {
 if(param.asInt()==1)
  {
      lcd.clear();
     digitalWrite(15, LOW);
     lcd.print(0, 0, "PUMP ON");


  }
  else
  {
      lcd.clear();
     digitalWrite(15, HIGH);
     lcd.print(0, 0, "PUMP OFF");


  }
 }

void loop()
{
  
  Blynk.run();
}
