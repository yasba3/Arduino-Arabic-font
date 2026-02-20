#include <Arduino.h>
#include <U8g2lib.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "ArabicReshaper.h" // Your new file!

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ D2, /* data=*/ D1, /* reset=*/ U8X8_PIN_NONE);

const char* ssid = "stcm";
const char* password = "333333112233";

ESP8266WebServer server(80);
String currentMsg = "أهلاً بك";

void updateOLED(String rawText) {
  String reshaped = prReshaper((char*)rawText.c_str());
  u8g2.clearBuffer();
  u8g2.enableUTF8Print();
  u8g2.setFont(u8g2_font_ganj_nameh_sans16_t_all); 
  u8g2.setCursor((128 - u8g2.getUTF8Width(reshaped.c_str())) / 2, 35);
  u8g2.print(reshaped);
  
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setCursor(0, 62);
  u8g2.print(WiFi.localIP().toString());
  u8g2.sendBuffer();
}

void handleRoot() {
  String html = "<!DOCTYPE html><html lang='ar' dir='rtl'><head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<style>body{font-family:sans-serif;text-align:center;background:#eee;padding:20px;} .card{background:#fff;padding:20px;border-radius:10px;box-shadow:0 2px 5px rgba(0,0,0,0.1);max-width:400px;margin:auto;} input{width:90%;padding:10px;margin:10px 0;font-size:16px;} button{background:#28a745;color:#fff;border:none;padding:10px 20px;border-radius:5px;cursor:pointer;width:100%;font-size:16px;}</style></head>";
  html += "<body><div class='card'><h2>تحديث شاشة OLED</h2>";
  html += "<form action='/set' method='POST'><input type='text' name='t' placeholder='اكتب هنا...' required><br><button type='submit'>إرسال</button></form>";
  html += "</div></body></html>";
  server.send(200, "text/html", html);
}

void handleSet() {
  if (server.hasArg("t")) {
    currentMsg = server.arg("t");
    updateOLED(currentMsg);
  }
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  u8g2.begin();
  WiFi.begin(ssid, password);
  updateOLED("جاري الاتصال...");
  while (WiFi.status() != WL_CONNECTED) { delay(500); }
  server.on("/", handleRoot);
  server.on("/set", HTTP_POST, handleSet);
  server.begin();
  updateOLED(currentMsg);
}

void loop() {
  server.handleClient();
  yield();
}