#include <Arduino.h>
#include "driver/ledc.h"

const int micPin = 34;     // MAX4466 output
const int laserPin = 18;   // Laser transistor control

void setup() {
  Serial.begin(115200);
  Serial.println("Laser Audio Transmitter (New LEDC API)");

  // Configure LEDC PWM
  ledc_timer_config_t timerConf = {
    .speed_mode = LEDC_LOW_SPEED_MODE,
    .duty_resolution = LEDC_TIMER_8_BIT,
    .timer_num = LEDC_TIMER_0,
    .freq_hz = 5000,
    .clk_cfg = LEDC_AUTO_CLK
  };
  ledc_timer_config(&timerConf);

  ledc_channel_config_t channelConf = {
    .gpio_num = laserPin,
    .speed_mode = LEDC_LOW_SPEED_MODE,
    .channel = LEDC_CHANNEL_0,
    .intr_type = LEDC_INTR_DISABLE,
    .timer_sel = LEDC_TIMER_0,
    .duty = 0,
    .hpoint = 0
  };
  ledc_channel_config(&channelConf);
}

void loop() {
  int micValue = analogRead(micPin);        // Read audio
  micValue = constrain(micValue, 500, 3500);
  int duty = map(micValue, 500, 3500, 0, 255);

  ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, duty);
  ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
}
