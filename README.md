## RobotArm

RobotArm is a hardy little firmware for the Arduino Uno, created to control a [Fischertechnik Trainingsrobot](http://www.cpcwiki.eu/index.php/Fischertechnik_Trainingsrobot) which was originally intended for the Commodore 64 home computer. The robot comes with an interface card which plugs into a DB-25 Parallel port and an extensive manual which details the control protocol used for this interface card. The card translates these control commands into analog signals which drive different motors on the arm.

This firmware bypasses the interface card completely, and instead uses an [Adafruit v1 Motor Shield](https://www.adafruit.com/product/81) (or any chinesium-grade clone) to drive the motors. Furthermore, it accepts its own communication protocol over standard Arduino serial communication to control the arm. 

### Communication

### Safety
Since the motors used in the arm are direct-drive DC motors, there is no way for the Arduino to know where the arm is positioned. Instead, it relies on endstops to prevent any overreaching and subsequent physical damage.

The Arduino has final say in any emergency stops, and will not allow any further movement in the offending direction if the endstop is reached. As soon as the endstop is released (by movement in the opposing direction), normal movement is allowed again.

### Improvement Ideas