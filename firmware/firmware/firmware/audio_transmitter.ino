#include <Arduino.h>
#include "driver/ledc.h"   // For LEDC PWM driver

const int micPin = 34;       // Microphone input pin
const int laserPin = 18;     // Laser output (connected via transistor)
const int pwmChannel = 0;    // PWM channel
const int pwmFreq = 5000;    // Frequency in Hz
const int pwmResolution = 8; // 8-bit (0–255)

void setup() {
  Serial.begin(115200);
  delay(1000);

  // ✅ Initialize PWM channel manually (compatible with ESP32 3.1.1)
  ledc_channel_config_t ledc_channel = {
    .gpio_num   = laserPin,
    .speed_mode = LEDC_HIGH_SPEED_MODE,
    .channel    = LEDC_CHANNEL_0,
    .intr_type  = LEDC_INTR_DISABLE,
    .timer_sel  = LEDC_TIMER_0,
    .duty       = 0,
    .hpoint     = 0
  };

  ledc_timer_config_t ledc_timer = {
    .speed_mode       = LEDC_HIGH_SPEED_MODE,
    .duty_resolution  = LEDC_TIMER_8_BIT,
    .timer_num        = LEDC_TIMER_0,
    .freq_hz          = pwmFreq,
    .clk_cfg          = LEDC_AUTO_CLK
  };

  ledc_timer_config(&ledc_timer);
  ledc_channel_config(&ledc_channel);

  pinMode(micPin, INPUT);
  Serial.println("Laser Audio Transmitter Ready...");
}

void loop() {
  int micValue = analogRead(micPin);              // 0–4095
  int pwmValue = map(micValue, 0, 4095, 0, 255);  // 8-bit scale
  ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, pwmValue);
  ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0);
}
