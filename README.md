**Autonomous Rover Project - Readme**

**Introduction:**
Welcome to the Autonomous Rover Project! This project aims to develop an autonomous rover capable of navigating its environment, avoiding obstacles, and adapting to changing wind and environmental conditions. The rover is designed to perform various tasks, including data collection and environmental monitoring.

**Hardware Requirements:**
To build and run the rover, you will need the following hardware components:

1. Arduino Mega microcontroller
2. Motors and Motor Driver Shield
3. Ultrasonic Sensors
4. Anemometer and Wind Speed Measurement Sensor
5. Environmental Sensors (Humidity, Temperature, Pressure)
6. Other necessary components (wiring, chassis, power supply, etc.)

**Software Requirements:**
The software for the rover is written in Arduino's C++ programming language. Ensure you have the Arduino IDE installed to upload the code to the Arduino Mega microcontroller.

**Installation and Configuration:**
1. Connect all the hardware components to the Arduino Mega microcontroller as per the wiring diagrams provided.
2. Open the Arduino IDE and load the required .ino files for the different functionalities of the rover (e.g., moteur.ino, obstacles_contournement.ino, trajectoire.ino, etc.).
3. Configure the communication setup (uno_emetteur.ino and uno_recepteur.ino) for wireless data transmission between rover components if necessary.

**Usage:**
1. Upload the relevant .ino files to the Arduino Mega microcontroller.
2. Power on the rover and make sure all connections are secure.
3. Observe the rover's behavior and autonomous navigation based on the uploaded code.

**Libraries:**
The project utilizes various libraries to manage different functionalities of the rover. Some notable libraries include:

1. "moteur" Library: Provides functions for motor control, such as avancer(), arreter(), tourner(), and demiTour().
2. "obstacles_contournement" Library: Manages obstacle avoidance and path planning algorithms with functions like is_visible() and solve_obstacle_avoidance().
3. "uno_emetteur" and "uno_recepteur" Libraries: Control wireless data transmission between rover components with envoyerNombre() and recevoirNombre() functions.
4. "mesure" Library: Offers functions to retrieve measurements from various sensors, including getDistanceAvant(), getDistanceDroite(), getVitesseVent(), getHumidite(), getTemperature(), and getPression().

**Acknowledgments:**
This project was originally developed by Théo Gachet and Matéi Voillemier in 2019.

**Disclaimer:**
Please use this project responsibly and ensure that the rover operates safely within its environment. The creators and contributors of this project are not responsible for any damages or issues resulting from the use or misuse of the rover.
