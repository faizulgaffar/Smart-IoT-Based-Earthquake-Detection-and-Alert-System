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
- Algorithm Used: Random Forest Classifier, CNN  
- Input: Sensor vibration features  
- Output: Normal / Abnormal classification  

Training and evaluation are performed using historical vibration data.
