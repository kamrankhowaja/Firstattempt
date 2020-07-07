#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "wHmY4pqCCIeCQEo-wHNfVDrLhb-Hd_gX";
char ssid[] = "RAK";
char pass[] = "KTKkamoo";
#define a D1
#define b D2
#define c D4

WidgetLED Relay1(V1);
WidgetLED Relay2(V2);
WidgetLED Relay3(V3);

WidgetTerminal terminal1(V0);
WidgetLCD lcd(V8);

//#define LED1 D5
//#define LED2 D6
//#define LED3 D4

void setup() {
  Blynk.begin(auth,ssid,pass);
  pinMode(a,INPUT);
  pinMode(b,INPUT);
  pinMode(c,INPUT);
//  pinMode(LED1,OUTPUT);
//  pinMode(LED2,OUTPUT);
//  pinMode(LED3,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  lcd.print(0,0," Three  Phase");
  lcd.print(0,1,"   Controller ");

  Serial.println("Last Phase:");
  Serial.print(c);
  
  
     if (digitalRead(a)==HIGH)
          {
              Relay1.on();
              Blynk.virtualWrite(V5, 220);
                }

     else if(digitalRead(a)==LOW)
          {
              
              Relay1.off();
              Blynk.virtualWrite(V5, 0);
              terminal1.println("Phase 1 Down");
              terminal1.flush();
              Blynk.notify("Error Phase 1 Down");
              Blynk.email("Phase Down","Phase 1 Down");
                }
//PHASE 2
     if (digitalRead(b)==HIGH)
          {
              Relay2.on();
              Blynk.virtualWrite(V6, 220);
              
                }

     else if(digitalRead(b)==LOW)
          {
              Relay2.off();
              Blynk.virtualWrite(V6, 0);
              terminal1.println("Phase 2 Down");
              terminal1.flush();
              Blynk.notify("Error Phase 2 Down");
              Blynk.email("Phase Down","Phase 2 Down");
                }
//PHASE 3
      if (digitalRead(c)==HIGH)
          {
              Relay3.on();
              Blynk.virtualWrite(V7,0);
                }

     else if(digitalRead(c)==LOW)
          {
              Relay3.off();
              Blynk.virtualWrite(V7,255);
              terminal1.println("Phase 3 Down");
              terminal1.flush();
              Blynk.notify("Error Phase 3 Down");
              Blynk.email("Phase Down","Phase 3 Down");
                }

        if(digitalRead(a)==HIGH && digitalRead(b)==HIGH && digitalRead(c)==HIGH)
        {

          digitalWrite(D5,HIGH);
                  }

         else if(digitalRead(a)==LOW || digitalRead(b)==LOW || digitalRead(c)==LOW)
         {

          digitalWrite(D5,LOW);
                  }
}
