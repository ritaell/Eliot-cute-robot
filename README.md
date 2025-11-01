# 🌟 Elliot – Interactive Robot (Touch + OLED Only)

---

## 📝 **Code Overview**

This Arduino sketch makes the robot interactive using a **metal touch sensor** and an **OLED display** with RoboEyes:  

- The robot displays eyes that can **move, blink, and change mood**.  
- **Single touch** triggers a random emotion animation (happy, angry, confused, or curious scan).  
- **Idle behavior** moves the eyes left and right when no interaction occurs.  
- If no interaction happens for **40 minutes**, the robot goes into **sleep mode**.  
- The code uses non-blocking updates to keep animations smooth and responsive.

---

## 📸 **Media / Photos / Videos**

![20251021_075052](https://github.com/user-attachments/assets/e5b491e7-450c-41ce-867f-8cac3bbf2de0)

![1000044470](https://github.com/user-attachments/assets/e72b842e-e944-4977-a40f-f4415ec8369c)



https://github.com/user-attachments/assets/6339da41-89e8-4aab-8676-338427ba0558



> 📝 **Note:** The robot’s body is made with **foam clay**, and you can decorate it however you like! Be creative and make it unique.  

---

## 🧩 **Components Needed**

- **Arduino Uno**  
- **KY-036 Metal Touch Sensor**  
- **OLED Display 128x64**  
- **Wires / Dupont Cables**  
- **5V USB or regulated 5V power source**  

> ⚠️ Optional: Cover the touch sensor with a small metal plate or foil to improve sensitivity.

---

## 🔌 **Wiring / Schematic**

| Component               | Arduino Pin |
|-------------------------|------------|
| OLED VCC                | 5V         |
| OLED GND                | GND        |
| OLED SDA                | A4         |
| OLED SCL                | A5         |
| KY-036 VCC              | 5V         |
| KY-036 GND              | GND        |
| KY-036 Signal           | D2         |

> ⚠️ Make sure all **GNDs are connected together**. Keep sensor wires short for reliable touch detection.

---

## 💻 **Software Setup**

1. **Install Arduino IDE**: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)  
2. **Install Required Libraries**:  
   - `Adafruit SSD1306`  
   - `Adafruit GFX`  
   - `FluxGarage RoboEyes`  
3. Open `cutie_patoutie.ino` in Arduino IDE  
4. Select **Arduino Uno** as the board and the correct **COM port**  
5. Upload the sketch to your Arduino  

---

## 🎮 **Usage**

- Power the Arduino via USB or a regulated 5V source  
- **Single touch** → robot reacts with a random emotion  
- **Double touch** → robot reacts differently  
- **Idle behavior** → eyes move left/right automatically  
- **Sleep mode** → if no interaction for 40 minutes, robot goes into rest mode  

---

## ⚡ **Touch Sensitivity Tips**

- If the robot does not detect your hand reliably:  
  - Cover the sensor with a **small metal plate** or foil  
  - Ensure the Arduino has a **stable 5V power supply**  
  - Minimize wire length between sensor and Arduino  

---

## 📚 **References**

- [FluxGarage RoboEyes](https://github.com/FluxGarage/RoboEyes)  
- [Adafruit SSD1306 library](https://github.com/adafruit/Adafruit_SSD1306)  
