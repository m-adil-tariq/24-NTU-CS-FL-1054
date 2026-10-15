#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_SDA 21
#define OLED_SCL 22
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    -1
);

// 16x16 pixel Smiling Face Bitmap data
const unsigned char smile_bitmap [] PROGMEM = {
    0x07, 0xe0, 0x18, 0x18, 0x20, 0x04, 0x42, 0x42, 0x40, 0x02, 0x89, 0x91, 0x80, 0x01, 0x80, 0x01, 
    0x80, 0x01, 0x84, 0x21, 0x44, 0x22, 0x43, 0xc2, 0x20, 0x04, 0x18, 0x18, 0x07, 0xe0, 0x00, 0x00
};

void setup() {
    Serial.begin(115200);

    Wire.begin(OLED_SDA, OLED_SCL);

    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        Serial.println("OLED initialization failed!");
        while (true) {
            delay(100);
        }
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    // Print the names
    display.setCursor(0, 0);
    display.println("Muhammad Irtaza");
    display.println("Muhammad Hassan Chtha");
    display.println("Muhammad Adil");

    // Draw the smiling emoji at X=0, Y=32 (16 pixels wide, 16 pixels high)
    display.drawBitmap(0, 32, smile_bitmap, 16, 16, SSD1306_WHITE);

    display.display();

    Serial.println("OLED initialized successfully.");
}

void loop() {
    // Add your application code here.
}
