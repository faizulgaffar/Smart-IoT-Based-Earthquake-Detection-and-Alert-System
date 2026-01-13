# Smart-IoT-Based-Earthquake-Detection-and-Alert-System
This project is an IoT-based earthquake detection system that uses vibration data from sensors and a machine learning model to identify abnormal seismic activity and send real-time alerts. The system combines IoT hardware, machine learning, and embedded systems to provide a low-cost and scalable early-warning solution for smart city applications.

---

## Components Used

### Hardware
- ESP32 Microcontroller
- MPU6050 (Accelerometer & Gyroscope)
- TP4056 Li-ion Battery
- Buzzer
- LCD Display
- Power Supply

### Software & Tools
- Python
- Jupyter Notebook
- Scikit-learn
- Arduino IDE
- ESP32 Libraries

---

## System Workflow
1. MPU6050 sensor captures ground vibration data  
2. Noise filtering and preprocessing  
3. ML model classifies vibration as normal or abnormal  
4. ESP32 processes real-time sensor data  
5. Buzzer & LED alert triggered on detection  

---

## Machine Learning Model
- Algorithm Used: Random Forest Classifier  
- Input: Sensor vibration features  
- Output: Normal / Abnormal classification

Training and evaluation are performed using historical vibration data.

---

## Hardware Pin Configuration
| Component | ESP32 Pin | Description |
| :--- | :--- | :--- |
| **MPU6050 SDA** | GPIO 21 | I2C Data |
| **MPU6050 SCL** | GPIO 22 | I2C Clock |
| **LCD SDA** | GPIO 21 | I2C Data |
| **LCD SCL** | GPIO 22 | I2C Clock |
| **Buzzer** | GPIO 13 | Digital Output |
| **VCC** | 3.3V / 5V | Power Supply |
| **GND** | GND | Ground |

---

## Installation & Usage
### Step 1: Model Training (Python)
Open EdgeAI_Earthquake_Detection_Pipeline.ipynb in Jupyter Notebook or Google Colab.

Run the cells to:

- Load and preprocess the seismic_data.csv.
- Train the Random Forest Classifier (Accuracy ~87%).
- Export the model to C++ using micromlgen.

The notebook will generate a model.h file.

### Step 2: Hardware Deployment (Arduino IDE)
Install the Arduino IDE and setup the ESP32 Board Manager.

Install the required libraries:

- Adafruit MPU6050
- LiquidCrystal_I2C

Open earthquake_detector.ino and ensure the generated model.h file is in the same folder as your .ino file.

Connect your ESP32 to the PC and click Upload.
