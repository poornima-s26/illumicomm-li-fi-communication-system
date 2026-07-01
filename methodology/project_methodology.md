# System Methodology

This document explains the complete working methodology of the **ILLUMICOMM Li-Fi Communication System**.

The project implements **Visible Light Communication (VLC)** for wireless transmission of **text, image, and audio** using optical communication instead of conventional RF communication.

---

## Step 1: Signal Acquisition and Input

The system supports three different communication inputs.

### Text / Image Input

- ESP32-CAM captures image or receives text input.
- Image is compressed into an **8×8 pixel matrix**.
- Pixel values are converted into binary values (0 or 1).
- Text characters are converted into **ASCII codes** and binary bitstream.

### Audio Input

- Microphone module captures analog audio signal.
- The signal is weak and requires amplification.
- LM358 amplifier boosts the analog signal before modulation.

**Output of this stage**

- Digital bitstream for text and image transmission.
- Analog waveform for audio transmission.

---

## Step 2: Data Encoding and Modulation (Transmitter Side)

### Digital Encoding (Text + Image)

- ESP32-CAM processes image data.
- Image converted into grayscale.
- Thresholding converts pixels into binary values.
- 64-bit pixel array is generated.
- Text characters converted into ASCII binary representation.
- Data stored inside transmission buffer.

### Analog Encoding (Audio)

- Microphone output passed through LM358 amplifier.
- Analog audio waveform prepared for optical transmission.

**Output of this stage**

- Encoded digital or analog data ready for modulation.

---

## Step 3: Optical Modulation

Two modulation methods are used.

### Digital Modulation (Text + Image)

**Technique Used: ON-OFF Keying (OOK)**

- Laser ON represents binary 1.
- Laser OFF represents binary 0.
- Used for digital transmission.

### Analog Modulation (Audio)

- Laser brightness changes according to audio amplitude.
- Analog signal directly controls laser intensity.

**Output of this stage**

- Laser beam now carries encoded digital or analog information.

---

## Step 4: Optical Transmission Channel

- Laser diode transmits modulated optical signal.
- NPN transistor works as laser driver circuit.
- Signal propagates through free space.
- Communication uses **Visible Light Communication (VLC)**.

### Advantages

- No RF interference.
- Secure directional communication.
- High-speed transmission.
- Stable communication.

**Testing Distance**

- Approximately 30 cm line-of-sight tested.

---

## Step 5: Signal Detection (Receiver Side)

At receiver section:

- Photodiode detects incoming laser beam.
- Converts optical signal into electrical signal.
- Generated signal is very weak (millivolt range).

### Photodiode Operation

- Light intensity → electrical current
- Current converted into voltage signal

**Output of this stage**

- Weak electrical signal representing transmitted data.

---

## Step 6: Signal Conditioning and Processing

Receiver signal passes through multiple stages.

### A. Amplification Stage (LM358)

- Photodiode signal is very weak.
- LM358 amplifier boosts the signal.

### Gain Equation

Gain = 1 + (Rf / Rin)

Example:

Rf = 100kΩ  
Rin = 10kΩ  

Gain = 11

### B. Noise Filtering

- RC low-pass filter removes noise.
- Removes unwanted room light disturbances.
- Prevents random false digital pulses.

### C. Comparator Stage (LM393)

- LM393 compares signal voltage with reference voltage.
- Converts analog signal into clean digital pulses.

Logic:

- HIGH → signal > reference voltage
- LOW → signal < reference voltage

**Output of this stage**

- Clean digital square wave for decoding.

---

## Step 7: Decoding and Output Generation

### Text Decoding

Inside ESP32 receiver:

- Reads each 8-bit binary block.
- Converts binary into ASCII characters.
- Displays text on serial monitor.

### Image Decoding

- Collects 64 binary bits.
- Maps binary values into pixel matrix.
- Reconstructs original 8×8 image.
- Displays image on webpage or laptop.

### Audio Output

- LM386 power amplifier drives speaker.
- Original audio waveform reproduced.

**Output of this stage**

- Successful recovery of transmitted data.
-----

## System Validation

Testing successfully completed for:

- Text transmission
- Image transmission
- Audio transmission
- Distance and stability testing

System performance observed:

- Stable communication
- Low interference
- Reliable decoding
- Secure optical transmission

---

## Summary

The ILLUMICOMM system successfully demonstrates **multi-modal Li-Fi communication** using **Visible Light Communication technology**.

Communication modes implemented:

- Text Transmission
- Image Transmission
- Audio Transmission

The system proves that optical wireless communication can provide secure, interference-free, and effective short-range data communication without using conventional radio frequency channels.
