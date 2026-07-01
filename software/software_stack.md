# Software and Programming

This document contains software tools and algorithms used in the **ILLUMICOMM Li-Fi Communication System**.

---

## Programming Environment

- Arduino IDE  

Used for programming ESP32 and ESP32-CAM modules.

---

## Libraries Used

- ESP32-CAM Libraries  
- Wi-Fi Libraries  
- Serial Communication Libraries  

---

## Algorithms Implemented

### Image Processing Algorithm

- Image capture using ESP32-CAM  
- Image compression into 8×8 matrix  
- Binary pixel conversion (0 and 1)  

Purpose:

Prepare image data for optical transmission.

---

### Text Processing Algorithm

- Character input processing  
- ASCII conversion  
- Binary bitstream generation  

Purpose:

Convert text into digital data packets.

---

### Communication Algorithm

**ON-OFF Keying (OOK) Modulation**

Working:

- Laser ON = Binary 1  
- Laser OFF = Binary 0  

Purpose:

Transmit digital information using light pulses.

---

### Audio Processing Algorithm

- Microphone analog signal capture  
- Signal amplification using LM358  
- Analog intensity modulation  

Purpose:

Transmit analog audio using laser intensity variation.

---

## Debugging and Monitoring

- Serial Monitor  
- Wi-Fi Web Server Interface  

Used for:

- Monitoring transmitted text  
- Displaying received image  
- System debugging  

---

## Software Functions

The software controls:

- Signal encoding  
- Laser modulation  
- Optical data transmission  
- Receiver decoding  
- Output display and validation
