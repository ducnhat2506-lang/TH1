#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Khai báo LCD: địa chỉ 0x27, 16 cột, 2 hàng
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    // Khởi tạo I2C cho ESP32
    Wire.begin(21, 22);    // SDA=21, SCL=22

    lcd.init();            // Khởi tạo LCD
    lcd.backlight();       // Bật đèn nền

    lcd.setCursor(0, 0);   // Cột 0, hàng 0
    lcd.print("Xin chao"); // Hiển thị chữ
}

void loop() {
    // Không cần làm gì thêm
}
