# Experimental Test and Results

This folder contains the testing procedure and experimental results of the **ILLUMICOMM Li-Fi Communication System**.

---

## 1. Text Transmission Test

### Objective

To verify successful transmission of text data using Li-Fi communication.

### Result

- Text encoded by ESP32-CAM was transmitted through the laser beam.  
- Receiver photodiode and LM393 correctly detected digital pulses.  
- The transmitted text was successfully displayed on the laptop serial monitor.  

### Experimental Output

![Text Transmission Result](text_result.png)

---

## 2. Image Transmission Test

### Objective

To verify image data transmission through optical communication.

### Result

- A predefined **8×8 pixel image** was converted into digital bits and transmitted using light.  
- Receiver successfully reconstructed the transmitted image.  
- Image was displayed correctly on the laptop system.  

### Experimental Output

![Image Transmission Result](image_audio_result.png)

---

## 3. Audio Transmission Test

### Objective

To test audio communication through analog optical modulation.

### Result

- Microphone input was amplified using LM358 and transmitted through laser modulation.  
- Receiver photodiode detected signal variations successfully.  
- LM386 amplifier reproduced audio through speaker with minimal distortion.  

### Experimental Output

(Shown in image below)

![Audio Transmission Result](image_audio_result.png)

---

## 4. Distance and Stability Test

### Observation

- System worked reliably at **30 cm line-of-sight distance**.  
- Light-based transmission remained stable with low noise.  
- Signal decoding remained consistent throughout testing.  

---

## 5. Overall Performance

The project successfully demonstrated:

- Multi-modal Li-Fi communication  
- Text transmission through optical communication  
- Image transmission through optical communication  
- Audio transmission using analog laser modulation  
- Secure and interference-free short range communication  

---

## Conclusion

The ILLUMICOMM system successfully demonstrated wireless communication completely through **Visible Light Communication (VLC)** technology, proving its effectiveness for future optical communication applications.
