// ===========================================================
//   COMBINED TEXT + IMAGE Li-Fi TRANSMITTER (Timing Mode)
//   2 minutes image → 1 minute text → repeat
// ===========================================================

const int LASER_PIN = 12;
const unsigned int BIT_US = 3000;

// TEXT MESSAGE
const char *TEXT_MSG = "WELCOME TO LIFI DEMONSTRATION";

// ========================
// IMAGE DEFINITIONS (8×8)
// ========================

// SMILEY
uint8_t IMG_SMILEY[8] = {
  0b00111100,
  0b01000010,
  0b10100101,
  0b10000001,
  0b10100101,
  0b10011001,
  0b01000010,
  0b00111100
};

// ARROW
uint8_t IMG_ARROW[8] = {
  0b00011000,
  0b00011000,
  0b00011000,
  0b11111111,
  0b01111110,
  0b00111100,
  0b00011000,
  0b00000000
};

// SINE
uint8_t IMG_SINE[8] = {
  0b00011000,
  0b00111100,
  0b01100110,
  0b11000011,
  0b11000011,
  0b01100110,
  0b00111100,
  0b00011000
};

// WIFI
uint8_t IMG_WIFI[8] = {
  0b00111100,
  0b01000010,
  0b10011001,
  0b10100101,
  0b10100101,
  0b10011001,
  0b01000010,
  0b00111100
};

// NRZ ENCODING
void sendBit(bool b) {
  digitalWrite(LASER_PIN, b ? HIGH : LOW);
  delayMicroseconds(BIT_US);
}

void sendByte(uint8_t b) {
  sendBit(0);
  for (int i = 0; i < 8; i++)
    sendBit((b >> i) & 1);
  sendBit(1);
  delayMicroseconds(BIT_US);
}

// SEND TEXT
void sendTextSentence() {
  const char *p = TEXT_MSG;
  while (*p) {
    sendByte((uint8_t)*p);
    delay(5);
    p++;
  }
  sendByte('\n');
  Serial.println(TEXT_MSG);
}

// SEND IMAGE
void sendImage(uint8_t img[8], unsigned long ms) {
  unsigned long start = millis();
  while (millis() - start < ms) {
    for (int i = 0; i < 8; i++) {
      sendByte(img[i]);
      delay(100);
    }
  }
}

void setup() {
  pinMode(LASER_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("Transmitter READY");
}

void loop() {

  // ----- IMAGE MODE: 2 minutes -----
  Serial.println("=== IMAGE TRANSMISSION STARTED ===");
  unsigned long startImg = millis();
  while (millis() - startImg < 120000) {   // CHANGED 180000 → 120000
    sendImage(IMG_SMILEY, 30000);
    sendImage(IMG_ARROW,  30000);
    sendImage(IMG_SINE,   30000);
    sendImage(IMG_WIFI,   30000);
  }

  // ----- TEXT MODE: 1 minute -----
  Serial.println("=== TEXT TRANSMISSION STARTED ===");
  unsigned long startText = millis();
  while (millis() - startText < 60000) {   // CHANGED 120000 → 60000
    sendTextSentence();
    delay(300);
  }
}
