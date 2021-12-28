/*******************************************************************
 *  Push Notificaiton Demo                                         *
 *  Using IFTTT and Telegram to send alerts to your phone          *
 *                                                                 *
 *  Telegram Library:                                              *
 *  https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot *
 *                                                                 *
 *  IFTTT Maker Library:                                           *
 *  https://github.com/witnessmenow/arduino-ifttt-maker            *
 *                                                                 *
 *  By Brian Lough                                                 *
 *******************************************************************/

//Including the two libraries

#include <IFTTTMaker.h>

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

//------- WiFi Settings -------
char ssid[] = "Coolpad 8676_I02_5CF1";       // your network SSID (name)
char password[] = "6447vwhw";  // your network key

#define IFTTT_BUTTON_PIN D6


// ------- IFTTT Maker config --------
#define KEY "oARDWyJc1gqhWd0deIJhf3zJqFJbi8bcYwSkdWfRujU"  // Get it from this page https://ifttt.com/services/maker/settings
#define EVENT_NAME "fire_estinguished" // Name of your event name, set when you are creating the applet



// SSL client needed for both libraries
WiFiClientSecure client;

IFTTTMaker ifttt(KEY, client);

String ipAddress = "";


volatile bool iftttButtonPressedFlag = false;

void setup() {

  Serial.begin(115200);

  // Initlaze the buttons

  pinMode(IFTTT_BUTTON_PIN, INPUT);

  // NOTE:
  // It is important to use interupts when making network calls in your sketch
  // if you just checked the status of te button in the loop you might
  // miss the button press.

  attachInterrupt(IFTTT_BUTTON_PIN, iftttButtonPressed, RISING);

  // Set WiFi to station mode and disconnect from an AP if it was Previously
  // connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);

  ipAddress = ip.toString();

}

void iftttButtonPressed() {
  Serial.println("iftttButtonPressed");
  int button = digitalRead(IFTTT_BUTTON_PIN);
  if(button == HIGH)
  {
    iftttButtonPressedFlag = true;
  }
  return;
}

void triggerIftttEvent() {
  if(ifttt.triggerEvent(EVENT_NAME, ssid, ipAddress)){
    Serial.println("IFTTT Successfully sent");
  }
  iftttButtonPressedFlag = false;
}



void loop() {
  if ( iftttButtonPressedFlag ) {
    triggerIftttEvent();
  }

 
}
