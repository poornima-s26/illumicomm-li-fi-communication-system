# ILLUMICOMM – Li-Fi Communication System

**ESP32 | ESP32-CAM | Li-Fi | Visible Light Communication (VLC) | BPW34 | LM358 | LM393 | Optical Wireless Communication**

---

## Project Status

✅ Completed Academic Project  

---

## Project Overview

ILLUMICOMM is a **Li-Fi based wireless communication system** developed for transmitting **text, image, and audio data** using **Visible Light Communication (VLC)** technology.

Unlike conventional wireless systems that use radio frequency (RF), this project uses **optical light intensity modulation through laser transmission** to communicate data wirelessly.

The system demonstrates secure, interference-free, short-range wireless communication completely through visible light.

---

## Project Objective

To develop a multi-modal wireless communication system capable of transmitting:

- Text Data  
- Image Data  
- Audio Signals  

using **optical communication instead of conventional RF communication**.

---

## System Modules Developed

### 1. Image and Text Communication Module

- Text transmission using optical digital pulses  
- ASCII to binary conversion  
- 8×8 image encoding and binary pixel transmission  
- Laser based ON-OFF Keying (OOK) modulation  
- Receiver side digital decoding using ESP32  

---

### 2. Audio Communication Module

- Microphone based analog audio signal acquisition  
- Signal amplification using LM358 operational amplifier  
- Analog optical modulation using laser intensity variation  
- Photodiode based signal detection  
- Audio reconstruction using LM386 amplifier and speaker  

---

## Work Completed

### Hardware Development

- Transmitter circuit designed and tested  
- Receiver circuit designed and tested  
- BPW34 photodiode light detection tested  
- LM358 amplification circuit implemented  
- LM393 comparator circuit implemented  

### Communication Testing

- Text transmission successfully completed  
- Image transmission successfully completed  
- Audio transmission successfully completed  
- Distance and signal stability testing completed  

---

## Communication Techniques Used

### Digital Communication (Text + Image)

- NRZ Encoding  
- ON-OFF Keying (OOK)  
- Binary Data Transmission  

### Analog Communication (Audio)

- Analog Intensity Modulation  
- PWM based optical modulation  

---

## Hardware Components Used

- ESP32 Development Board  
- ESP32-CAM Module  
- BPW34 Photodiode  
- LM358 Operational Amplifier  
- LM393 Comparator  
- LM386 Audio Amplifier  
- Laser Diode Module  
- Microphone Module  
- Speaker  
- Resistors  
- Capacitors  
- Breadboard  
- Power Supply Unit  

---

## Software Tools Used

- Arduino IDE  
- ESP32 Libraries  
- ESP32-CAM Libraries  
- WebServer Library  
- Serial Communication  
- Embedded C / Arduino Programming  

---

## Repository Structure

```text
illumicomm-li-fi-communication-system/

├── diagrams/
├── methodology/
├── firmware/
├── hardware/
├── software/
├── results/
└── README.md
```

---

## Future Scope

- Increase communication range beyond current testing distance  
- Improve image transmission quality  
- Real-time video transmission using Li-Fi  
- Reduce optical noise and signal distortion  
- Improve receiver sensitivity  
- Industrial optical communication applications  
- High-speed secure wireless communication systems  

---

## Technologies Used

- ESP32  
- ESP32-CAM  
- Li-Fi Communication  
- Visible Light Communication (VLC)  
- Embedded Systems  
- Optical Communication  
- Arduino Programming  

---

## Author

**Poornima S**  
Electronics and Instrumentation Engineering  
Siddaganga Institute of Technology, Tumakuru  

---

## Project Goal

To demonstrate a practical implementation of **Li-Fi based optical wireless communication** capable of transmitting **text, image, and audio signals securely and efficiently using visible light instead of RF communication**.
