# Open Source Robotic Fish
This repository is dedicated to the developement of the predatory robotic fish, developed at the [Theoretical Ecology and Evolution Laboratory](https://teelabiisc.wordpress.com/), [Indian Institute of Science](https://www.iisc.ac.in).

### :warning: Code is buggy :warning:

### Introduction:
The robotic fish developed was used to study the aggregation and swarming characteristics of the Serpae tetra species of fish.

### Construction:
- The body of the Fish is made of extruded polystyrene. The [design](https://bitbucket.org/SarthakJShetty/fish/src/master/Design%20Files/Mechanical_Design/Fish_Design/) was made in SolidWorks, and carved using a crafting blade.

- The Fish is maneuvered using a joystick controller through the [pygame](Pygame.org) library for Python. A list of supported controllers is given [here](https://www.pygame.org/docs/ref/joystick.html). We have tried out a number of joysticks, such as the [Xbox 360 controller](https://www.amazon.com/Xbox-360-Wireless-Controller-Packaging-Black/dp/B073WJCQGT/ref=sr_1_4?ie=UTF8&qid=1530160595&sr=8-4&keywords=xbox+360+controller), and the [Logitech Extreme 3D Pro Gamepad](https://www.amazon.com/Extreme-3D-Pro-Joystick-Windows/dp/B00009OY9U/ref=sr_1_1?s=videogames&ie=UTF8&qid=1530160648&sr=1-1&keywords=logitech+extreme+pro).

- The Fish is controlled through an Arduino UNO, which communicates with the computer running pygame through a Bluetooth module, mounted on it's head.

- A [SHARP Distance Sensor GP2Y0A21YK0F](https://www.pololu.com/category/79/sharp-distance-sensors) was used to judge the distance between the fish and obstacles up ahead.

- The Fish was encased in a layer of polythene to ensure waterproofing while operating underwater. Specifically, the joints between successive links was encased in a skin-like layer of polythene.

- The necessary propelling movements were provided by a series of 3 [Tower SG90 Servo Motors](https://servodatabase.com/servo/towerpro/sg90).

- A pair of [9V batteries](https://www.amazon.com/AmazonBasics-Everyday-Alkaline-Batteries-8-Pack/dp/B00MH4QM1S) were used in series to provide the necessary electric power for the operation of the fish.

### Fritzing Diagram:

![Fritzing Diagram](https://raw.githubusercontent.com/SarthakJShetty/Fish/master/Design%20Files/Electrical_Design/Circuit_Design/Fish_Circuitry.png "Fritzing Diagram")

### SolidWorks Model:

![SolidWorks Model Diagram](https://raw.githubusercontent.com/SarthakJShetty/Fish/master/Design%20Files/Mechanical_Design/Fish_Design/Fish_Assembly.png "Solidworks Diagram")

### Working:
1. The electrical connections are made as shown in the Fritzing diagram.

2. Once the connections are made and checked (to prevent short circuiting underwater!), the batteries are connected to the battery headers provided in the circuit.

3. The SHARP sensors are obstructed to check if the necessary commands are executed (in this case the ```C_MOVE()``` function would be executed).

4. Once the [Joystick.py](https://bitbucket.org/SarthakJShetty/fish/src/master/Code/Joystick_Code/Joystick_Code.py) has been executed, wait for 5 seconds as the [EEPROM_Code.cpp](https://bitbucket.org/SarthakJShetty/Fish/src/master/Code/EEPROM_Flush_Code) script executes and flushes the EEPROM on-board the UNO to prevent interferences from previous stored values.

5. The Fish can be maneuvered as required using the left analog stick of the joystick. Three movements are possible:
	- [Forward](https://bitbucket.org/SarthakJShetty/Fish/src/master/Code/Stable_Movement_Code/Stable_Movement_Code.cpp)- The Fish moves in an S-type movement 
	- [Left](https://bitbucket.org/SarthakJShetty/Fish/src/master/Code/Stable_Movement_Code/Stable_Movement_Code.cpp)- The Fish moves in a C-type movement, deflecting towards the left.
	- [Right](https://bitbucket.org/SarthakJShetty/Fish/src/master/Code/Stable_Movement_Code/Stable_Movement_Code.cpp)- The Fish moves in a C-type movement, deflecting towards the right.
	- [Obstacle Avoidance](https://bitbucket.org/SarthakJShetty/Fish/src/master/Code/Stable_Movement_Code/Stable_Movement_Code.cpp)- The Fish moves in a C-type movement, deflecting towards the left. 

6. The Fish operates either through the controls of the user, through the joystick, or it continuously moves in an S-type fashion, until it encounters an obstacle, thereafter which it executes a C-type movement.

### Known Issues:

1. Occasionally, the Bluetooth module on-board losses communication link with the Bluetooth on the PC. When this happens, close the pygame dialog and rerun the Joystick_Code.py script to establish control once again (**this issue has now been resolved by connecting the Bluetooth module to a 3.3V voltage supply**).

2. The Arduino will reboot, if sufficient power is not provided. Thus, we suggest the use of LiPo batteries to provide a more reliable and lasting power source. We are currently using 12V, 2000mAh LiPo batteries.

3. Communication link between the UNO and the computer will not be active until the `EEPROM_Flush_Code.cpp` has been executed (approx 5 seconds), thereafter which the LED on the UNO associated with GPIO pin 13 will glow a bright orange (depending on the make of the Arduino board).