# IoT Temperature and Humidity Monitor 🌡️💧

![Hits](https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2Fmehrdadmb2%2FESP32_DHT22_OLED_Project&count_bg=%2379C83D&title_bg=%23555555&icon=github.svg&icon_color=%23E7E7E7&title=visits&edge_flat=false)
![GitHub license](https://img.shields.io/github/license/mehrdadmb2/ESP32_DHT22_OLED_Project)
![GitHub stars](https://img.shields.io/github/stars/mehrdadmb2/ESP32_DHT22_OLED_Project?style=social)
![GitHub forks](https://img.shields.io/github/forks/mehrdadmb2/ESP32_DHT22_OLED_Project?style=social)
![GitHub issues](https://img.shields.io/github/issues/mehrdadmb2/ESP32_DHT22_OLED_Project)
![GitHub contributors](https://img.shields.io/github/contributors/mehrdadmb2/ESP32_DHT22_OLED_Project)
![GitHub last commit](https://img.shields.io/github/last-commit/mehrdadmb2/ESP32_DHT22_OLED_Project)
![GitHub pull requests](https://img.shields.io/github/issues-pr/mehrdadmb2/ESP32_DHT22_OLED_Project)
![GitHub repo size](https://img.shields.io/github/repo-size/mehrdadmb2/ESP32_DHT22_OLED_Project)

---

## 📜 Introduction

This project is a simple yet powerful **IoT Temperature and Humidity Monitor** designed using:

![Board](https://img.shields.io/badge/Board-ESP32-%2344CC11?style=plastic&logo=esp32&logoColor=white)  
![Sensor](https://img.shields.io/badge/Sensor-DHT22-%23FFCC00?style=plastic&logo=sensor&logoColor=black)  
![Display](https://img.shields.io/badge/Display-OLED-%237D7D7D?style=plastic&logo=display&logoColor=white)

It captures the ambient temperature and humidity, displays them on an OLED screen, and sends the data to a remote server over WiFi. This project is perfect for:
- 🌟 **Beginners** exploring IoT.
- 🚀 **Intermediate developers** building embedded systems.

---

## 📸 Schematic Diagram

![Schematic](PIC/Schematic.png)

---

## ⚙️ Features

- 🌐 **WiFi-enabled**: Send temperature and humidity data to a remote server.
- 📟 **Real-time Display**: View readings instantly on an OLED screen.
- 🔧 **Customizable**: Easily adjust sensor pins, server URL, and WiFi credentials.
- 🔋 **Low Power**: Optimized for IoT deployments.

![Code](https://img.shields.io/badge/Code-Arduino%20C-%234078D7?style=plastic&logo=arduino&logoColor=white)  
![Connectivity](https://img.shields.io/badge/Connectivity-WiFi-%230077B5?style=plastic&logo=wifi&logoColor=white)

---

## 🛠️ Components

| **Component**         | **Description**               | **Quantity** | **Badge**                                |
|-----------------------|------------------------------|--------------|------------------------------------------|
| ESP32                 | WiFi-enabled microcontroller | 1            | ![Board](https://img.shields.io/badge/Board-ESP32-%2344CC11?style=plastic&logo=esp32&logoColor=white) |
| DHT22                 | Temperature & Humidity Sensor| 1            | ![Sensor](https://img.shields.io/badge/Sensor-DHT22-%23FFCC00?style=plastic&logo=sensor&logoColor=black) |
| OLED Display (I2C)    | 128x64 Pixels                 | 1            | ![Display](https://img.shields.io/badge/Display-OLED-%237D7D7D?style=plastic&logo=display&logoColor=white) |
| Jumper Wires          | Male-to-Male/Female-to-Male   | As needed    | ![Cables](https://img.shields.io/badge/Wires-Jumper-%23FF6347?style=plastic&logo=wireguard&logoColor=black) |
| Breadboard            | For prototyping              | 1            | ![Breadboard](https://img.shields.io/badge/Tools-Breadboard-%23F9D342?style=plastic&logo=tools&logoColor=black) |

---

## 🔌 Pin Connections

| **Component** | **Pin** | **ESP32 Pin** |
|---------------|---------|---------------|
| **DHT22**     | VCC     | 3.3V          |
|               | GND     | GND           |
|               | DATA    | GPIO4         |
| **OLED**      | VCC     | 3.3V          |
|               | GND     | GND           |
|               | SDA     | GPIO17        |
|               | SCL     | GPIO18        |

---

## 🚀 Getting Started

Follow these steps to set up the project:

### **1. Clone the Repository**
![Git](https://img.shields.io/badge/Command-Git-%23F1502F?style=plastic&logo=git&logoColor=white)
```bash
git clone https://github.com/mehrdadmb2/ESP32_DHT22_OLED_Project.git
cd ESP32_DHT22_OLED_Project
```

### **2. Install Required Libraries**
- Open Arduino IDE.  
- Install the following libraries via **Library Manager** (`Sketch > Include Library > Manage Libraries`):  
  - **Adafruit GFX**  
  - **Adafruit SSD1306**  
  - **DHT sensor library**  
  - **Adafruit Unified Sensor**  

### **3. Open the Code**
- Open the file `iot_temperature_humidity.ino` in Arduino IDE.

### **4. Update WiFi and Server Details**
Replace the placeholders in the code with your WiFi credentials and server URL:
```cpp
const char* ssid = "Your_SSID";         // Replace with your WiFi name
const char* password = "Your_Password"; // Replace with your WiFi password
const char* serverURL = "http://your-server.com/api"; // Replace with your server URL
```

### **5. Upload Code**
![Upload](https://img.shields.io/badge/Step-Upload%20Code-%234CC417?style=plastic&logo=codefactor&logoColor=white)
- Select the correct **Board** and **Port** (`Tools > Board`).
- Click the **Upload** button.

---

## 📈 How It Works

1. **Initialization**:
   - The ESP32 connects to the WiFi network.
   - The OLED display initializes and shows connection status.

2. **Data Capture**:
   - The DHT22 sensor measures temperature and humidity.

3. **Data Display**:
   - The OLED displays temperature and humidity in real-time.

4. **Data Transmission**:
   - The data is sent to the specified server as an HTTP POST request.

---

## 🖥️ Example Output

### **OLED Display**
![OLED Example](https://img.shields.io/badge/OLED%20Output-Example-%234DD0E1?style=plastic&logo=display&logoColor=black)
```
Temp: 25.3 C
Humidity: 60.5 %
```

### **Serial Monitor**
![Serial Monitor](https://img.shields.io/badge/Monitor-Serial%20Output-%2345A1FF?style=plastic&logo=logseq&logoColor=white)
```
WiFi connected!
Temp: 25.3 C
Humidity: 60.5 %
Data sent successfully!
```

---

## 💡 Troubleshooting

- **Problem**: OLED is not displaying data.  
  **Solution**: Verify SDA and SCL connections and ensure the I2C address matches your OLED.

- **Problem**: Failed to connect to WiFi.  
  **Solution**: Check WiFi credentials and ensure the network is in range.

- **Problem**: DHT sensor reads `nan`.  
  **Solution**: Verify the sensor connections and type (`DHT22`).

---

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 🤝 Contributing

![Contribution](https://img.shields.io/badge/Contribute-Welcome-%23FF6F61?style=plastic&logo=github&logoColor=white)  
Contributions are welcome! Feel free to submit issues, fork the repository, or open a pull request.

---

## 🌟 Acknowledgements

Special thanks to:
- [Adafruit](https://www.adafruit.com/) for their amazing libraries.
- The open-source community for making IoT projects accessible to everyone.

---

## 📊 Badges

![Hits](https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2Fmehrdadmb2%2FESP32_DHT22_OLED_Project&count_bg=%2379C83D&title_bg=%23555555&icon=github.svg&icon_color=%23E7E7E7&title=visits&edge_flat=false)
![GitHub license](https://img.shields.io/github/license/mehrdadmb2/ESP32_DHT22_OLED_Project)
![GitHub stars](https://img.shields.io/github/stars/mehrdadmb2/ESP32_DHT22_OLED_Project?style=social)
![GitHub forks](https://img.shields.io/github/forks/mehrdadmb2/ESP32_DHT22_OLED_Project?style=social)
![GitHub issues](https://img.shields.io/github/issues/mehrdadmb2/ESP32_DHT22_OLED_Project)
![GitHub contributors](https://img.shields.io/github/contributors/mehrdadmb2/ESP32_DHT22_OLED_Project)
![GitHub last commit](https://img.shields.io/github/last-commit/mehrdadmb2/ESP32_DHT22_OLED_Project)
![GitHub pull requests](https://img.shields.io/github/issues-pr/mehrdadmb2/ESP32_DHT22_OLED_Project)
![GitHub repo size](https://img.shields.io/github/repo-size/mehrdadmb2/ESP32_DHT22_OLED_Project)
<!--
```

این نسخه بهبود یافته شامل بدج‌های جذاب‌تر و ساختاری مرتب‌تر است. اگر نیاز به تغییر بیشتری دارید، اطلاع دهید! 😊
-->
