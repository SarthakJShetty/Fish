
# Open Source Robotic Fish
This repository is dedicated to the developement of the predatory robotic fish, developed at the [Theoretical Ecology and Evolution Laboratory](https://teelabiisc.wordpress.com/), [Indian Institute of Science](https://www.iisc.ac.in).

### Introduction:
The robotic fish developed was used to study the aggregation and swarming characteristics of the Serpae tetra species of fish.

### Construction:
- The body of the Fish is made of extruded polystyrene. The [design](https://bitbucket.org/Fish) was made in SolidWorks, and carved using a crafting blade.

- The Fish is maneuvered using a joystick controller through the [pygame](Pygame.org) library for Python. A list of supported controllers is given [here](https://www.pygame.org/docs/ref/joystick.html).

- The Fish is controlled through an Arduino UNO, which communicates with the computer running pygame through a Bluetooth module, mounted on it's head.

- A [SHARP Distance Sensor GP2Y0A21YK0F](https://www.pololu.com/category/79/sharp-distance-sensors) was used to judge the distance between the fish and obstacles up ahead.

- The Fish was encased in a layer of polythene to ensure waterproofing while operating underwater. Specifically, the joints between successive links was encased in a skin-like layer of polythene.

- The necessary propelling movements were provided by a series of 3 [Tower SG90 Servo Motors](https://servodatabase.com/servo/towerpro/sg90).

- A pair of [9V batteries](https://www.amazon.com/AmazonBasics-Everyday-Alkaline-Batteries-8-Pack/dp/B00MH4QM1S) were used in series to provide the necessary electric power for the operation of the fish.

### Fritzing Diagram:

### Working:
1. The electrical connections are made as shown in the Fritzing diagram.

2. Once the connections are made and checked (to prevent short circuiting underwater!), the batteries are connected to the battery headers provided in the circuit.

3. The SHARP sensors are obstructed to check if the necessary commands are executed (in this case the C_MOVE() function would be executed).

4. Once the [Joystick.py](https://bitbucket.org/SarthakJShetty/Fish/Code/Joystick_Code/Joystick_Code.py) has been executed, wait for 5 seconds as the [EEPROM_Code.cpp](https://bitbucket.org/SarthakJShetty/Fish/Code/EEPROM_Flush_Code) script executes and flushes the EEPROM on-board the UNO to prevent interferences from previous stored values.

5. The Fish can be maneuvered as required using the left analog stick of the joystick. Three movements are possible:
	- [Forward](https://bitbucket.org/SarthakJShetty/Fish/Code/Stable_Movement_Code/Stable_Movement_Code.cpp)- The Fish moves in an S-type movement 
	- [Left](https://bitbucket.org/SarthakJShetty/Fish/Code/Stable_Movement_Code/Stable_Movement_Code.cpp)- The Fish moves in a C-type movement, deflecting towards the left.
	- [Right](https://bitbucket.org/SarthakJShetty/Fish/Code/Stable_Movement_Code/Stable_Movement_Code.cpp)- The Fish moves in a C-type movement, deflecting towards the right.
	- [Obstacle Avoidance](https://bitbucket.org/SarthakJShetty/Fish/Code/Stable_Movement_Code/Stable_Movement_Code.cpp)- The Fish moves in a C-type movement, deflecting towards the left. 

6. The Fish operates either through the controls of the user, through the joystick, or it continuously moves in an S-type fashion, until it encounters an obstacle, thereafter which it executes a C-type movement.

### Known Issues:

- Occasionally, the Bluetooth module on-board losses communication link with the Bluetooth on the PC. When this happens, close the pygame dialog and rerun the Joystick_Code.py script to establish control once again (<strong>this issue has now been resolved by connecting the Bluetooth Module</strong>).

- The Arduino will reboot, if sufficient power is not provided. Thus, we suggest the use of LiPo batteries to provide a more reliable and lasting power source.

- Communication link between the UNO and the computer will not be active until the EEPROM_Flush_Code has been executed, thereafter which the LED on the UNO associated with GPIO pin 13 will glow.