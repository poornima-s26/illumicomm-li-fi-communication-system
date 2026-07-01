/************************************************************
          COMBINED Li-Fi RECEIVER (IMAGE → TEXT)
   IMAGE → Webpage (2 min)
   TEXT → Serial Monitor (1 min)
************************************************************/

#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "......";
const char* password = ".......";

WebServer server(80);

const int RX_PIN = 4;
const unsigned int BIT_US = 3000;
const int SAMPLES = 5;
const int SAMPLE_SPACING_US = 40;

char image[8][9];
int rowIndex = 0;

unsigned long modeStart = 0;

// DECODING
int stableRead() {
  int s = 0;
  for (int i = 0; i < SAMPLES; i++) {
    s += digitalRead(RX_PIN);
    delayMicroseconds(SAMPLE_SPACING_US);
  }
  return (s > SAMPLES / 2);
}

void waitForStartBit() {
  while (digitalRead(RX_PIN) == HIGH)
    delayMicroseconds(20);
}

uint8_t readByteNRZ() {
  delayMicroseconds(BIT_US + BIT_US / 2);
  uint8_t v = 0;
  for (int i = 0; i < 8; i++) {
    if (stableRead()) v |= (1 << i);
    delayMicroseconds(BIT_US);
  }
  delayMicroseconds(BIT_US);
  return v;
}

// TEXT MODE
void handleTextMode() {
  waitForStartBit();
  uint8_t c = readByteNRZ();

  if (c == '\n') {
    Serial.println("WELCOME TO LIFI DEMONSTRATION");
  }
}

// REFERENCES
const char REF1[8][9] = {
  "00111100","01000010","10100101","10000001",
  "10100101","10011001","01000010","00111100"
};

const char REF2[8][9] = {
  "00011000","00011000","00011000","11111111",
  "01111110","00111100","00011000","00000000"
};

const char REF3[8][9] = {
  "00011000","00111100","01100110","11000011",
  "11000011","01100110","00111100","00011000"
};

const char REF4[8][9] = {
  "00111100","01000010","10011001","10100101",
  "10100101","10011001","01000010","00111100"
};

const char (*getReference())[9] {
  unsigned long t = (millis() / 30000) % 4;
  if (t == 0) return REF1;
  if (t == 1) return REF2;
  if (t == 2) return REF3;
  return REF4;
}

// WEBPAGE
String makeHTML() {
  String page = "<html><head><meta http-equiv='refresh' content='1'>";
  page += "<style>.pix{display:inline-block;width:22px;height:22px;margin:1px;}";
  page += ".on{background:black;} .off{background:white;border:1px solid #aaa;}";
  page += "</style></head><body>";

  page += "<h2>8×8 Li-Fi Image (Live vs Reference)</h2><table><tr><td><h3>RECEIVED</h3>";

  for(int r=0;r<8;r++){
    for(int c=0;c<8;c++){
      page += (image[r][c]=='1') ? "<span class='pix on'></span>" :
                                   "<span class='pix off'></span>";
    }
    page += "<br>";
  }

  page += "</td><td style='padding-left:50px'><h3>REFERENCE</h3>";

  const char (*REF)[9] = getReference();

  for(int r=0;r<8;r++){
    for(int c=0;c<8;c++){
      page += (REF[r][c]=='1') ? "<span class='pix on'></span>" :
                                 "<span class='pix off'></span>";
    }
    page += "<br>";
  }

  page += "</td></tr></table></body></html>";
  return page;
}

void handleRoot(){ server.send(200,"text/html",makeHTML()); }

void setup() {
  Serial.begin(115200);
  pinMode(RX_PIN, INPUT);

  for(int i=0;i<8;i++) strcpy(image[i], "00000000");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);

  server.on("/", handleRoot);
  server.begin();

  modeStart = millis();
  Serial.println("Receiver READY");
}

void loop() {

  server.handleClient();

  unsigned long elapsed = millis() - modeStart;

  // ----- IMAGE MODE: 2 minutes -----
  if (elapsed < 120000) {   // CHANGED 180000 → 120000

    waitForStartBit();
    uint8_t b = readByteNRZ();

    for (int i = 0; i < 8; i++)
      image[rowIndex][i] = ((b >> i) & 1) ? '1' : '0';

    image[rowIndex][8] = '\0';
    rowIndex = (rowIndex + 1) % 8;
  }

  // ----- TEXT MODE: 1 minute -----
  else if (elapsed < 180000) {  // CHANGED 300000 → 180000

    handleTextMode();
  }

  else {
    modeStart = millis();
  }
}
