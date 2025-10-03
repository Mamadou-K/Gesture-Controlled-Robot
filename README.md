# 🤖 Gesture-Controlled-Robot

An innovative Arduino-powered differential drive robot that responds to your gestures, offering intuitive control through three potentiometers.

![Version](https://img.shields.io/badge/version-1.0.0-blue)
![License](https://img.shields.io/badge/license-MIT)
![Stars](https://img.shields.io/github/stars/Mamadou-K/Gesture-Controlled-Robot?style=social)
![Forks](https://img.shields.io/github/forks/Mamadou-K/Gesture-Controlled-Robot?style=social)

![preview-image](/schema.png)


---

## ⚠️ Disclaimer

- This project has **only been tested in simulation**.  
- Using potentiometers in real-life setups to control high-power motors may be **unsafe**. Always use proper motor controllers and safety circuits for real hardware.  
- Some parts of this code's comments were **assisted using AI** to improve clarity.  

---


## ✨ Features

*   **Intuitive Gesture Control:** 🖐️ Control robot movement (forward, backward, turn) using simple potentiometer adjustments, simulating hand gestures.
*   **Differential Drive System:** ⚙️ Achieves precise and agile maneuverability, ideal for navigating various environments with two independent drive wheels.
*   **Arduino Powered:** ⚡ Built on the versatile Arduino platform, making it accessible for hobbyists and easy to extend with additional sensors or modules.
*   **Modular Design:** 🧩 The codebase and hardware setup are designed for easy understanding and modification, encouraging customization and further development.


## 🚀 Installation Guide

To get your Gesture-Controlled-Robot up and running, follow these steps. This project requires the Arduino IDE and basic familiarity with uploading sketches.

### Prerequisites

*   **Arduino IDE:** Download and install the latest version from the [official Arduino website](https://www.arduino.cc/en/software).
*   **Arduino Board:** An Arduino Uno, Nano, or compatible board.
*   **Motor Driver:** An L298D or similar motor driver module.
*   **DC Motors:** Two DC motors with wheels.
*   **Potentiometers:** Three potentiometers for gesture input.
*   **Power Supply:** A suitable power supply for the motors and Arduino.

### Step-by-Step Installation

1.  **Clone the Repository:**
    Open your terminal or command prompt and clone the project to your local machine:

    ```bash
    git clone https://github.com/Mamadou-K/Gesture-Controlled-Robot.git
    cd Gesture-Controlled-Robot
    ```

2.  **Open in Arduino IDE:**
    Navigate into the cloned directory and open the `robot_control.ino` file using the Arduino IDE.

    ```bash
    # Assuming you are in the Gesture-Controlled-Robot directory
    open robot_control.ino # On macOS
    # or manually open the file from the IDE
    ```

3.  **Install Libraries (if any):**
    This project typically uses standard Arduino libraries. If any specific libraries are required (e.g., for advanced motor control or specific sensors), they would be listed here. For basic motor control, standard `analogRead` and `digitalWrite` functions are usually sufficient.

4.  **Hardware Assembly:**
    Assemble your robot hardware according to your specific design, ensuring the following connections:
    *   Connect the three potentiometers to analog input pins (e.g., A0, A1, A2) on your Arduino.
    *   Connect the motor driver to digital output pins for motor control (e.g., pins 5, 6, 9, 10 for an L298D).
    *   Connect the DC motors to the motor driver output.
    *   Ensure proper power connections for both Arduino and motors.

5.  **Select Board and Port:**
    In the Arduino IDE, go to `Tools > Board` and select your Arduino board (e.g., `Arduino Uno`). Then, go to `Tools > Port` and select the serial port connected to your Arduino.

6.  **Upload the Sketch:**
    Click the `Upload` button (right arrow icon) in the Arduino IDE to compile and upload the `robot_control.ino` sketch to your Arduino board.

    Upon successful upload, your robot is ready for operation!


## 💡 Usage Examples

Once the `robot_control.ino` sketch is uploaded and the hardware is assembled, you can control the robot using the three potentiometers.

### Basic Operation

Each potentiometer is typically mapped to a specific control function:

*   **Potentiometer 1 (Forward/Backward):** Adjust this potentiometer to move the robot forward or backward. A neutral position (e.g., middle) might stop the robot, while moving it to one extreme moves forward and the other extreme moves backward.
*   **Potentiometer 2 (Left/Right Turn):** This potentiometer controls the robot's turning. Moving it to one side will make the robot turn left, and to the other side will make it turn right.
*   **Potentiometer 3 (Speed/Fine-tune):** This potentiometer can be used to adjust the overall speed of the robot, or for fine-tuning specific movements.

**Example Scenario:**
To make the robot move forward and slightly to the right:
1.  Adjust **Potentiometer 1** to the 'forward' position.
2.  Slightly adjust **Potentiometer 2** towards the 'right/left turn' position.
3.  Use **Potentiometer 3** to set the desired speed.

Experiment with different combinations of potentiometer positions to understand the robot's movement characteristics.

### Configuration Options

The current configuration is hardcoded within the `robot_control.ino` file. For advanced users, you can modify the `robot_control.ino` file to change:

*   **Pin Assignments:** Update `analogRead()` and `digitalWrite()` pin numbers to match your specific hardware connections.
*   **Motor Speed Mapping:** Adjust the mapping logic from potentiometer values (0-1023) to motor speed (0-255) to customize responsiveness.
*   **Dead Zones:** Implement or modify dead zones for potentiometers to prevent accidental movements when they are near their center positions.


## 🗺️ Project Roadmap

The Gesture-Controlled-Robot is a foundation for exciting future developments. Here's what's planned:

*   **V1.1 - Wireless Control Integration:**
    *   Implement Bluetooth (HC-05/06) or Wi-Fi (ESP8266) module for remote control via a smartphone app or PC.
    *   Develop a basic mobile interface for gesture input.
*   **V1.2 - Obstacle Avoidance:**
    *   Integrate ultrasonic (HC-SR04) or infrared sensors for basic obstacle detection.
    *   Develop logic for autonomous navigation around obstacles.
*   **V1.3 - Enhanced Gesture Recognition:**
    *   Explore using IMU sensors (accelerometer/gyroscope) for more sophisticated, hand-based gesture input.
    *   Implement machine learning (TinyML) on microcontrollers for more robust gesture classification.
*   **Code Refactoring & Optimization:** Continuously improve code readability, efficiency, and modularity.
*   **Documentation Expansion:** Provide detailed wiring diagrams and assembly instructions.


## 🤝 Contribution Guidelines

We welcome contributions to enhance the Gesture-Controlled-Robot! Please follow these guidelines:

*   **Fork the Repository:** Start by forking the `Gesture-Controlled-Robot` repository to your GitHub account.
*   **Create a New Branch:**
    *   For new features: `git checkout -b feature/your-feature-name`
    *   For bug fixes: `git checkout -b bugfix/issue-description`
*   **Code Style:**
    *   Adhere to standard C++ and Arduino coding conventions.
    *   Use clear, descriptive variable and function names.
    *   Comment your code thoroughly, especially for complex logic.
    *   Maintain consistent indentation (2 spaces is preferred).
*   **Commit Messages:** Write clear and concise commit messages that explain the purpose of your changes.
    *   Example: `feat: Add Bluetooth module integration` or `fix: Correct motor direction bug`
*   **Pull Request Process:**
    1.  Ensure your branch is up-to-date with the `main` branch of the original repository.
    2.  Create a Pull Request (PR) to the `main` branch.
    3.  Provide a detailed description of your changes in the PR.
    4.  Include any relevant screenshots or GIFs if your changes affect the robot's behavior or setup.
*   **Testing:** Before submitting a PR, thoroughly test your changes on your physical robot setup to ensure they work as expected and do not introduce new issues.


## 📄 License Information

This project is distributed under the **MIT License**.

You are free to use, modify, and distribute this software, provided that the original copyright and license notice are included in all copies or substantial portions of the software.

```
MIT License

Copyright (c) 2025 Mamadou-K

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

For the full license text, please refer to the [LICENSE](LICENSE) file in the repository.
