#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "model.h" // Includes the Eloquent Random Forest code

Adafruit_MPU6050 mpu;
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Instantiate the Random Forest Classifier object from the model.h file
Eloquent::ML::Port::RandomForest classifier;

const int buzzerPin = 13;
const int windowSize = 50; 

void setup() {
  pinMode(buzzerPin, OUTPUT);
  lcd.init();
  lcd.backlight();
  
  if (!mpu.begin()) {
    lcd.print("Sensor Error!");
    while (1) yield();
  }
  
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  lcd.clear();
  lcd.print("AI System Ready");
  delay(1000);
}

void loop() {
  float ax[windowSize], ay[windowSize], az[windowSize];
  float sumX = 0, sumY = 0, sumZ = 0;

  // 1. Collect a "Window" of data
  for (int i = 0; i < windowSize; i++) {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    
    ax[i] = a.acceleration.x;
    ay[i] = a.acceleration.y;
    az[i] = a.acceleration.z;
    
    sumX += ax[i];
    sumY += ay[i];
    sumZ += az[i];
    delay(10); 
  }

  // 2. Calculate Mean
  float mX = sumX / windowSize;
  float mY = sumY / windowSize;
  float mZ = sumZ / windowSize;

  // 3. Calculate Std Dev
  float sX = 0, sY = 0, sZ = 0;
  for (int i = 0; i < windowSize; i++) {
    sX += pow(ax[i] - mX, 2);
    sY += pow(ay[i] - mY, 2);
    sZ += pow(az[i] - mZ, 2);
  }
  sX = sqrt(sX / windowSize);
  sY = sqrt(sY / windowSize);
  sZ = sqrt(sZ / windowSize);

  // 4. Inference
  // The model expects features in this specific order:
  // [mean_x, std_x, mean_y, std_y, mean_z, std_z]
  float features[6] = {mX, sX, mY, sY, mZ, sZ};
  
  int prediction = classifier.predict(features); 

  // 5. Alert Logic
  if (prediction == 1) { // 1 = Earthquake
    digitalWrite(buzzerPin, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("!! EARTHQUAKE !!");
    lcd.setCursor(0, 1);
    lcd.print("AI Confidence:HI");
  } else {
    digitalWrite(buzzerPin, LOW);
    lcd.setCursor(0, 0);
    lcd.print("System Stable   ");
    lcd.setCursor(0, 1);
    lcd.print("Mode: AI Scan   ");
  }
}