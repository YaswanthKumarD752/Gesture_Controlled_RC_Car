→→Hand Gesture Controlled RC Car using ESP32 and OpenCV←←

→Overview (What it does)
 A smart car that detects hand gestures using a laptop webcam and Python, then sends movement commands to an ESP32-based robotic car over Wi-Fi. Each finger count controls a specific direction, and the ESP32 activates the motors via an L298N motor driver accordingly.

→Tech Stack
   	Area	              Tools / Platforms
1. Microcontroller	     ESP32 Dev Module
2. Computer Vision	     OpenCV + MediaPipe (Python)
3. Motor Control	     L298N Dual H-Bridge
4. Communication	     HTTP (Wi-Fi based)
5. Language	             Python, C++ (Arduino IDE)

→Features
1. Real-time gesture recognition using webcam
2. 1 to 5 fingers → Forward, Backward, Left, Right, Stop
3. Wi-Fi communication between PC and ESP32
4. DC motor control via L298N
5. Modular and extensible (can add obstacle detection, camera, etc.)

→How It Works (Architecture)
1. Gesture Detection: Python + MediaPipe counts fingers via laptop webcam.
2. Command Mapping: Each finger count maps to a movement command.
3. HTTP Communication: Python sends the command (/1, /2, etc.) to ESP32.
4. Motor Control: ESP32 receives command and drives motors via L298N.



→Skills Highlighted:
1. Embedded Systems (ESP32, L298N)
2. Python & OpenCV
3. Real-time gesture recognition
4. Wi-Fi communication
5. System integration & debugging