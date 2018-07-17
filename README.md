# Open Source Robotic Fish

This repository is dedicated to the development of the predatory robotic fish, developed at the [Theoretical Ecology and Evolution Laboratory](https://teelabiisc.wordpress.com/ "TEE-Lab, IISc"), [Indian Institute of Science](https://www.iisc.ac.in "Indian Institute of Science, Bengaluru").

### :warning: Code is buggy :warning:

### Introduction:
The robotic fish developed was used to study the aggregation and swarming characteristics of the <em><a title="Serpae tetra" href="https://en.wikipedia.org/wiki/Serpae_tetra" target="_blank">Serpae tetra</a></em> species of fish.

### Construction:
 - The body of the Fish is made of extruded polystyrene. The [design](https://github.com/SarthakJShetty/fish/tree/master/Design_Files/Mechanical_Design/Fish_Design/ "Mechanical Designs") was made in SolidWorks, and carved using a crafting blade.

 - The Fish is maneuvered using a joystick controller through the [pygame](Pygame.org "pygame") library for Python. A list of supported controllers is given [here](https://www.pygame.org/docs/ref/joystick.html "pygame"). We have tried out a number of joysticks, such as the [XBox 360 controller](https://www.amazon.com/Xbox-360-Wireless-Controller-Packaging-Black/dp/B073WJCQGT/ref=sr_1_4?ie=UTF8&qid=1530160595&sr=8-4&keywords=xbox+360+controller "XBox 360 controller"), and the [Logitech Extreme 3D Pro Gamepad](https://www.amazon.com/Extreme-3D-Pro-Joystick-Windows/dp/B00009OY9U/ref=sr_1_1?s=videogames&ie=UTF8&qid=1530160648&sr=1-1&keywords=logitech+extreme+pro "Logitech Extreme 3D Pro").

 - The Fish is controlled through an Arduino UNO, which communicates with the computer running pygame through a [Bluetooth module](https://www.amazon.com/HiLetgo%C2%AE-Wireless-Bluetooth-Transceiver-Arduino/dp/B071YJG8DR/ref=sr_1_1_sspa?ie=UTF8&qid=1530698951&sr=8-1-spons&keywords=hc05&psc=1 "HC-05 Bluetooth Module"), mounted on it's head.

 - A [SHARP Distance Sensor GP2Y0A21YK0F](https://www.pololu.com/category/79/sharp-distance-sensors "Sharp Distance Sensor") was used to judge the distance between the fish and obstacles up ahead.

 - The Fish was encased in a layer of polythene to ensure waterproofing while operating underwater. Specifically, the joints between successive links was encased in a skin-like layer of polythene.

 - The necessary propelling movements were provided by a series of 3 [Tower SG90 Servo Motors](https://servodatabase.com/servo/towerpro/sg90 "Tower S690 Servo Motors").

 - A pair of [9V batteries](https://www.amazon.com/AmazonBasics-Everyday-Alkaline-Batteries-8-Pack/dp/B00MH4QM1S "9V Batteries") were used in series to provide the necessary electric power for the operation of the fish.

### Fritzing Diagram:
<img style="border: 2px solid black" src="https://raw.githubusercontent.com/SarthakJShetty/Fish/master/Design_Files/Electrical_Design/Circuit_Design/Fish_Circuitry.png" alt="Fritzing Diagram">
<figcaption><strong>Fig 1.</strong><em> Fritzing diagram of electrical wiring.</em>
<em><strong>Note:</strong> 3.7V LiPo is for representation purposes only.</em></figcaption>

### SolidWorks Model:
<img style="border:2px solid black;" src="https://raw.githubusercontent.com/SarthakJShetty/Fish/master/Design_Files/Mechanical_Design/Fish_Design/Fish_Assembly_Snapshot.png" alt="SolidWorks Model">
<figcaption><strong>Fig 2.</strong><em> SolidWorks assembly of mechanical structure.</em></figcaption>


### Working:
 1. The electrical connections are made as shown in the <a title="Fritzing Diagram" href="https://github.com/SarthakJShetty/Fish/master/Design_Files/Electrical_Design/Circuit_Design/Fish_Circuitry.png" alt="Fritzing Diagram">Fritzing diagram</a>.

 2. Once the connections are made and checked (to prevent short circuiting underwater!), the batteries are connected to the battery headers provided in the circuit.

 3. The SHARP sensors are obstructed to check if the necessary commands are executed (in this case the ```C_MOVE()``` function would be executed).

 4. Once the [Joystick.py](https://github.com/SarthakJShetty/fish/tree/master/Code/Joystick_Code/Joystick_Code.py) has been executed, wait for 5 seconds as the [EEPROM_Code.cpp](https://github.com/SarthakJShetty/Fish/tree/master/Code/CPP_Code/EEPROM_Flush_Code.cpp) script executes and flushes the EEPROM on-board the UNO to prevent interferences from previous stored values.

 5. The Fish can be maneuvered as required using the left analog stick of the joystick. Three movements are possible:
	- [Forward](https://github.com/SarthakJShetty/Fish/tree/master/Code/CPP_Code/Stable_Movement_Code.cpp)- The Fish moves in an S-type movement.
	- [Left](https://github.com/SarthakJShetty/Fish/tree/master/Code/CPP_Code/Stable_Movement_Code.cpp)- The Fish moves in a C-type movement, deflecting towards the left.
	- [Right](https://github.com/SarthakJShetty/Fish/tree/master/Code/CPP_Code/Stable_Movement_Code.cpp)- The Fish moves in a C-type movement, deflecting towards the right.
	- [Obstacle Avoidance](https://github.com/SarthakJShetty/Fish/tree/master/Code/CPP_Code/Stable_Movement_Code.cpp)- The Fish moves in a C-type movement, deflecting towards the left. 

 6. The Fish operates either through the controls of the user, through the joystick, or it continuously moves in an S-type fashion, until it encounters an obstacle, thereafter which it executes a C-type movement.

### Build-log:
You can check out the <a title="Build-log" href="https://github.com/SarthakJShetty/Fish/tree/master/build-log.md">build-log</a> for a detailed progress report.

### Known Issues:

 1. Occasionally, the Bluetooth module on-board losses communication link with the Bluetooth on the PC. When this happens, close the pygame dialog and rerun the Joystick_Code.py script to establish control once again (<strong>this issue has now been resolved by connecting the Bluetooth module to a 3.3V voltage supply.</strong>)

 2. The Arduino will reboot, if sufficient power is not provided. Thus, we suggest the use of LiPo batteries to provide a more reliable and lasting power source. We are currently using <a title="12V LiPo battery" href="" target="_blank">12V, 2000mAh LiPo batteries</a> (testing this right now).

 3. Communication link between the UNO and the computer will not be active until the `EEPROM_Flush_Code.cpp` has been executed (approx 5 seconds), thereafter which the LED on the UNO associated with GPIO pin 13 will glow a bright orange (depending on the make of the Arduino board).