#ifndef ARABIC_RESHAPER_H
#define ARABIC_RESHAPER_H

#include <Arduino.h>

#define N_DISTINCT_CHARACTERS 62

typedef struct prGlyph {
  int AsciiCode;
  char* codeGlyph;
  char* isoGlyph;
  char* iniGlyph;
  char* midGlyph;
  char* endGlyph;
};

const prGlyph prForms[] PROGMEM = {
    {193, "\u0621", "\uFE80", "\uFE80", "\uFE80", "\uFE80" }, {194, "\u0622", "\uFE81", "\uFE81", "\uFE82", "\uFE82" },
    {195, "\u0623", "\uFE83", "\uFE83", "\uFE84", "\uFE84" }, {196, "\u0624", "\uFE85", "\uFE85", "\uFE86", "\uFE86" },
    {197, "\u0625", "\uFE87", "\uFE87", "\uFE88", "\uFE88" }, {198, "\u0626", "\uFE89", "\uFE8B", "\uFE8C", "\uFE8A" },
    {199, "\u0627", "\uFE8D", "\uFE8D", "\uFE8E", "\uFE8E" }, {200, "\u0628", "\uFE8F", "\uFE91", "\uFE92", "\uFE90" },
    {555, "\u0629", "\uFE93", "\uFE93", "\uFE94", "\uFE94" }, {202, "\u062A", "\uFE95", "\uFE97", "\uFE98", "\uFE96" },
    {203, "\u062B", "\uFE99", "\uFE9B", "\uFE9C", "\uFE9A" }, {204, "\u062C", "\uFE9D", "\uFE9F", "\uFEA0", "\uFE9E" },
    {205, "\u062D", "\uFEA1", "\uFEA3", "\uFEA4", "\uFEA2" }, {206, "\u062E", "\uFEA5", "\uFEA7", "\uFEA8", "\uFEA6" },
    {207, "\u062F", "\uFEA9", "\uFEA9", "\uFEAA", "\uFEAA" }, {208, "\u0630", "\uFEAB", "\uFEAB", "\uFEAC", "\uFEAC" },
    {209, "\u0631", "\uFEAD", "\uFEAD", "\uFEAE", "\uFEAE" }, {210, "\u0632", "\uFEAF", "\uFEAF", "\uFEB0", "\uFEB0" },
    {184, "\u0698", "\uFB8A", "\uFB8A", "\uFB8B", "\uFB8B" }, {211, "\u0633", "\uFEB1", "\uFEB3", "\uFEB4", "\uFEB2" },
    {212, "\u0634", "\uFEB5", "\uFEB7", "\uFEB8", "\uFEB6" }, {213, "\u0635", "\uFEB9", "\uFEBB", "\uFEBC", "\uFEBA" },
    {214, "\u0636", "\uFEBD", "\uFEBF", "\uFEC0", "\uFEBE" }, {215, "\u0637", "\uFEC1", "\uFEC3", "\uFEC4", "\uFEC2" },
    {216, "\u0638", "\uFEC5", "\uFEC7", "\uFEC8", "\uFEC6" }, {217, "\u0639", "\uFEC9", "\uFECB", "\uFECC", "\uFECA" },
    {218, "\u063A", "\uFECD", "\uFECF", "\uFED0", "\uFECE" }, {160, "\u0640", "\u0640", "\u0640", "\u0640", "\u0640" },
    {161, "\u0641", "\uFED1", "\uFED3", "\uFED4", "\uFED2" }, {162, "\u0642", "\uFED5", "\uFED7", "\uFED8", "\uFED6" },
    {163, "\u0643", "\uFED9", "\uFEDB", "\uFEDC", "\uFEDA" }, {164, "\u0644", "\uFEDD", "\uFEDF", "\uFEE0", "\uFEDE" },
    {165, "\u0645", "\uFEE1", "\uFEE3", "\uFEE4", "\uFEE2" }, {228, "\u0646", "\uFEE5", "\uFEE7", "\uFEE8", "\uFEE6" },
    {167, "\u0647", "\uFEE9", "\uFEEB", "\uFEEC", "\uFEEA" }, {168, "\u0648", "\uFEED", "\uFEED", "\uFEEE", "\uFEEE" },
    {169, "\u0649", "\uFEEF", "\uFEEF", "\uFEF0", "\uFEF0" }, {170, "\u064A", "\uFEF1", "\uFEF3", "\uFEF4", "\uFEF2" },
    {172, "\u06CC", "\uFBFC", "\uFBFE", "\uFBFF", "\uFBFD" }, {141, "\u0686", "\uFB7A", "\uFB7C", "\uFB7D", "\uFB7B" },
    {222, "\u067E", "\uFB56", "\uFB58", "\uFB59", "\uFB57" }, {144, "\u06AF", "\uFB92", "\uFB94", "\uFB95", "\uFB93" },
    {201, "\u06A9", "\uFB8E", "\uFB90", "\uFB91", "\uFB8F" }, {32, "\u0020", "\u0020", "\u0020", "\u0020", "\u0020" },
    {44, "\u060C", "\u060C", "\u060C", "\u060C", "\u060C" }, {20, "\u200C", "\u200C", "\u200C", "\u200C","\u200C" },
    {58, "\u003A", "\u003A", "\u003A", "\u003A", "\u003A" }, {187, "\u061B", "\u061B", "\u061B", "\u061B", "\u061B" },
    {46, "\u002E", "\u002E", "\u002E", "\u002E", "\u002E" }, {191, "\u061F", "\u061F", "\u061F", "\u061F", "\u061F" },
    {48, "\u06F0", "\u06F0", "\u06F0", "\u06F0", "\u06F0" }, {49, "\u06F1", "\u06F1", "\u06F1", "\u06F1", "\u06F1" },
    {50, "\u06F2", "\u06F2", "\u06F2", "\u06F2", "\u06F2" }, {51, "\u06F3", "\u06F3", "\u06F3", "\u06F3", "\u06F3" },
    {52, "\u06F4", "\u06F4", "\u06F4", "\u06F4", "\u06F4" }, {53, "\u06F5", "\u06F5", "\u06F5", "\u06F5", "\u06F5" },
    {54, "\u06F6", "\u06F6", "\u06F6", "\u06F6", "\u06F6" }, {55, "\u06F7", "\u06F7", "\u06F7", "\u06F7", "\u06F7" },
    {56, "\u06F8", "\u06F8", "\u06F8", "\u06F8", "\u06F8" }, {57, "\u06F9", "\u06F9", "\u06F9", "\u06F9", "\u06F9" },
    {41, "\u0028", "\u0028", "\u0028", "\u0028", "\u0028" }, {40, "\u0029", "\u0029", "\u0029", "\u0029", "\u0029" }
};

inline bool isFromTheSet1(unsigned char ch) {
  const unsigned char theSet1[18] = {32, '\0', 199, 194, 207, 208, 209, 210, 184, 168, 191, 40, 41, 46, 33, 44, 58, 248};
  for (int i = 0; i < 18; i++) if (ch == theSet1[i]) return true;
  return false;
}

inline bool isFromTheSet2(unsigned char ch) {
  const unsigned char theSet1[10] = {32, '\0', 191, 40, 41, 46, 33, 44, 58, 248};
  for (int i = 0; i < 10; i++) if (ch == theSet1[i]) return true;
  return false;
}

inline int FindGlyph(unsigned char chFind) {
  for (int i = 0; i < N_DISTINCT_CHARACTERS; i++) {
    if (pgm_read_word(&(prForms[i].AsciiCode)) == chFind) return i;
  }
  return -1;
}

inline void utf8rev(char *str) {
  char *scanl, *scanr, *scanr2, c;
  for (scanl = str, scanr = str + strlen(str); scanl < scanr;)
    c = *scanl, *scanl++ = *--scanr, *scanr = c;
  for (scanl = scanr = str; c = *scanr++;) {
    if ((c & 0x80) == 0) scanl = scanr;
    else if ((c & 0xc0) == 0xc0) {
      scanr2 = scanr;
      switch (scanr - scanl) {
        case 4: c = *scanl, *scanl++ = *--scanr, *scanr = c;
        case 3: c = *scanl, *scanl++ = *--scanr, *scanr = c;
        case 2: c = *scanl, *scanl++ = *--scanr, *scanr = c;
      }
      scanr = scanl = scanr2;
    }
  }
}
// Change "inline String prReshaper" to just "String prReshaper" 
// to prevent register pressure.
String prReshaper(char *Text) {
  String prBuffer = "";
  int stat = 0;
  unsigned char pLetter = ' ', letter, nLetter, temp;

  while (temp = *Text++) {
    yield(); // Keep the ESP8266 watchdog happy
    
    // Process current letter
    if (temp >= '0' && temp <= '9') { 
      letter = temp; 
    }
    else if (temp >= 128) {
      letter = *Text++;
      letter += 32; temp += 32;
      if (letter == 207 && (temp == 218 || temp == 250)) letter = 144;
      else if (letter == 166) {
        if (temp == 218 || temp == 250) letter = 141;
        else letter = 228;
      }
    } else {
      letter = temp;
    }

    if (letter == 172 && (temp == 248 || temp == 32)) letter = 44;

    // Look ahead for next letter
    temp = *Text++;
    if (temp >= 128) {
      nLetter = *Text++; nLetter += 32; temp += 32;
      if (nLetter == 207 && (temp == 218 || temp == 250)) nLetter = 144;
      else if (nLetter == 166) {
        if (temp == 218 || temp == 250) nLetter = 141;
        else nLetter = 228;
      }
      Text -= 2;
    } else {
      nLetter = temp;
      Text--;
    }

    if (nLetter == 172 && (temp == 248 || temp == 32)) nLetter = 44;

    // Determine state
    if (isFromTheSet1(pLetter)) 
      stat = isFromTheSet2(nLetter) ? 0 : 1;
    else 
      stat = isFromTheSet2(nLetter) ? 2 : 3;

    int number = FindGlyph(letter);
    if (number >= 0) {
      switch (stat) {
        case 0: prBuffer += (char*)(prForms[number].isoGlyph); break;
        case 1: prBuffer += (char*)(prForms[number].iniGlyph); break;
        case 2: prBuffer += (char*)(prForms[number].endGlyph); break;
        case 3: prBuffer += (char*)(prForms[number].midGlyph); break;
      }
      pLetter = letter;
    }
  }

  // Finalize string
  int len = prBuffer.length();
  char *buf = new char[len + 1];
  strcpy(buf, prBuffer.c_str());
  utf8rev(buf);
  String finalStr = String(buf);
  delete[] buf; // Clean up memory
  return finalStr;
}
#endif