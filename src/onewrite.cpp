#include <Arduino.h>
#include <DHT.h>

// ===== CẤU HÌNH CHÂN KẾT NỐI =====
#define DHTPIN 4        // Chân GPIO4 kết nối DATA của DHT11
#define DHTTYPE DHT11   // Loại cảm biến: DHT11

// Khởi tạo đối tượng DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Khởi tạo Serial Monitor
  Serial.begin(115200);
  delay(2000);   // Chờ Serial ổn định

  Serial.println("\n===== DHT11 Sensor Test =====");

  // Khởi tạo cảm biến DHT11
  dht.begin();

  Serial.println("DHT11 initialized!");
  Serial.println("Reading data...\n");
}

void loop() {
  // Đọc dữ liệu từ cảm biến
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Kiểm tra dữ liệu hợp lệ
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
  } 
  else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" *C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.println("------------------------");
  }

  // Đợi 2 giây trước lần đọc tiếp theo
  delay(2000);
}
