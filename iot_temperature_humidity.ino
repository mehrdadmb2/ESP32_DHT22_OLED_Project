#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

// تنظیمات DHT22
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// تنظیمات OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_SDA 17
#define OLED_SCL 18
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// تنظیمات WiFi
const char* ssid = "Your_SSID";         // نام شبکه WiFi
const char* password = "Your_Password"; // رمز عبور شبکه

// آدرس سرور
const char* serverURL = "http://your-server.com/api";

void setup() {
  Serial.begin(115200);
  dht.begin();

  // تنظیم پین‌های I2C
  Wire.begin(OLED_SDA, OLED_SCL);

  // راه‌اندازی OLED
  if (!display.begin(SSD1306_I2C_ADDRESS, 0x3C)) {
    Serial.println(F("OLED initialization failed!"));
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Connecting to WiFi...");
  display.display();

  // اتصال به WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
  display.clearDisplay();
  display.println("WiFi connected!");
  display.display();
}

void loop() {
  // خواندن دما و رطوبت
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // نمایش دما و رطوبت روی OLED
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print(temperature);
  display.println(" C");
  display.print("Humidity: ");
  display.print(humidity);
  display.println(" %");
  display.display();

  // ارسال داده به سرور
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String postData = "temperature=" + String(temperature) + "&humidity=" + String(humidity);

    http.begin(serverURL);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    int httpResponseCode = http.POST(postData);

    if (httpResponseCode > 0) {
      Serial.println("Data sent successfully!");
      Serial.println(http.getString());
    } else {
      Serial.print("Error sending data: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("WiFi not connected.");
  }

  delay(10000); // ارسال داده هر 10 ثانیه
}
