# Arduino-Arabic-font
Arduino Arabic font header file to use for OLED display

use it to display Arabic fornts in Arduino IDE or others

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

 
By, Hussein Alyami
Saudi Arabia
