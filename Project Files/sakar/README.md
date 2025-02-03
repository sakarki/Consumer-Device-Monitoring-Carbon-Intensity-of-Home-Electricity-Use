# February 5, 2024 - Commencement of the Venture 
On this day, we convened with TA Zheng to discuss our proposed project, “Consumer Device that Monitors CO2 Intensity Levels.” We collectively decided that subsequent meetings would occur weekly, every Tuesday at 5 PM, to discuss our progress. We would also notify our pitcher after our TA meeting, Peter from ImpactECI, about any progress we made or if we had any questions or recommendations to ask of him.

_Signed: Sakar Karki_

# February 12, 2024 - Component Procurement 
The team resolved to acquire essential components for our design: LEDs, a speaker, and PCB boards, as well as any resistors, capacitors, gates, drivers, etc for all of our subsystems. The design of the PCB board is underway.
![image](https://github.com/biping2/ECE445_Team57/assets/59777443/fd2112f8-dd2d-480d-84da-4a4a9d3e6e10)

_Signed: Sakar Karki_

# February 26, 2024 - Initial Design Evaluation 
A design review was held, where we presented our approach for the “Indicating CO2 Intensity” project. The professor, other students, and TA Zheng recommended methods of powering our design using USB as dealing with high voltage is difficult and recommended converting the high voltage from the outlet (120V AC) into approximately 3.3V for the operation of the esp32 and 5V for other subsystems such as the LED driving subsystem.

![image](https://github.com/biping2/ECE445_Team57/assets/59777443/713101b5-5851-4e92-8b56-9e2d88d61074)

_Signed: Sakar Karki_

# March 15, 2024 - Gate Driver Addition in LED Subsystem
We discussed our circuit and possible problems with it with a TA specializing in power systems. Our approach used mosfet to drive RGB LEDs using IO signals from an ESP32 microcontroller. The conversation revolved around the idea of modifying the traditional method of using a single MOSFET for each color channel by including a gate driver that amplifies the voltage from the ESP32’s IO signals. This would ensure sufficient voltage headroom between the Gate and Drain of the MOSFET, which is critical for the MOSFET to accurately respond to the signals fed into its Gate. The proposed design involves using the ESP32 IO signals as input control signals, a gate driver to amplify the voltage to a level suitable for the MOSFET’s Gate, the 5V and 3.3V power supplied from the power subsystem and MOSFETs to switch the RGB LEDs. The gate driver must provide a Gate-to-Source voltage that exceeds the MOSFET’s threshold voltage while keeping the Drain-to-Source voltage within safe operating limits. This will be implemented into our design to ensure proper functionality.
![image](https://github.com/biping2/ECE445_Team57/assets/59777443/00edf570-d675-47ed-819d-fe58a628cb78)

_Signed: Sakar Karki_

# March 18, 2024 - PCB Board Order 
The order for the PCB board was placed, marking a significant step in our project’s materialization. We fixed our ground planes, as well as tracks, sizing of the board, and fixed any errors produced from the production of the gerber files sent to PCBway. We placed our order out of our own pocket, as the parameter of our board exceeded the limit, and was unable to be placed in the weekly order wave.
![image](https://github.com/biping2/ECE445_Team57/assets/59777443/1bff825e-7244-4bcb-808e-b50c1cdccea8)
![image](https://github.com/biping2/ECE445_Team57/assets/59777443/fdc17038-8959-4b08-9159-e012a9d2c3d7)

_Signed: Sakar Karki_

# March 19, 2024 - Finalizing Design
We finalized the design, upon more research and additional help from TAs to fix any possible bugs with our LED driver subsystem. All other subsystems are confident in functionioning correctly. We also calculated our resistance values and ensured our parts were valid and would function within the circuit by creating a falstad simulation circuit, as well as analyzing the voltage threstholds, minimum currents supplied to individual parts, etc.

![image](https://github.com/biping2/ECE445_Team57/assets/59777443/c713652b-43ca-4b0b-9a65-04d4099104f7)

_Signed: Sakar Karki_

# March 25, 2024 - Update on Components 
We received our PCB board, a tangible representation of our project’s impending assembly. We intend to start soldering when are last couple of parts come in.

![image](https://github.com/biping2/ECE445_Team57/assets/59777443/7c01789b-005c-469e-af50-ce9cc08c6458)

_Signed: Sakar Karki_

# March 27, 2024 - Initial Soldering
The initial soldering phase began, focusing on the simpler components of our design. We mainly soldered in resistors and capacitors.

_Signed: Sakar Karki_

# April 2, 2024 - Functional Testing Through Soldering 
Further soldering was conducted to test the functionality of individual components. We tested the voltages from our soldered in power subsystem. We accurately got readings of 5V and 3.3V DC outputted from the subsystem, from a 120V AC input reading from our oscilloscope.

_Signed: Sakar Karki_

# April 5, 2024 - Final Soldering 
Final soldering efforts were made, testing the subsystems with forced inputs to ensure operational integrity.

![image](https://github.com/biping2/ECE445_Team57/assets/59777443/aca76e54-306c-474a-aafc-371c9ecf9b55)

_Signed: Sakar Karki_

# April 10, 2024 - ESP32 Programming Challenges 
An attempt was made to program the board, a challenging yet crucial task in our development process. We were having difficulties as we did not have the correct USBASP or UART adapter. We only had a serial adapter, which did not match the connections onto our PCB, to properly communicate with our computer for programming, booting, and flashing. This is as the lab had run out of UART adapters, combined with our lack of micro-USB cable with proper data transfer functionality.

_Signed: Sakar Karki_

# April 12, 2024 - Successful Programming
The board was successfully programmed using a development board, bypassing the need for USBASP or UART. We used the RX, TX, receiving and transmission signals as well as the ground to connect it to our development board, which we used the MicroUSB connection from the development board to connect to the RX and TX signals, and setting our communication to our ESP32 soldered into our pcb to prevent transmission/programming to the dev board ESP32 connection. This was an intuitive and simple hack we discovered while reading through the datasheets of the various ESP32 IO connections and iterations of the ESP32. This research greatly improved our knowledge on the chip and we were able to flash our program onto our ESP32 chip on the pcb and boot it and get it running.  
![image](https://github.com/biping2/ECE445_Team57/assets/59777443/c7190d4d-eec4-46e5-84be-1e279f0ca412)

_Signed: Sakar Karki_

# April 15, 2024 - Connectivity and Manual Programming
We achieved a milestone where the code connected the device to Wifi, using a username and password provided, and connected to the local hotspot we setup. We verified this by viewing our hotspot connections and obtaining 1 connection of a device named: "ESP-32". The LEDs were still programmed manually.
![image](https://github.com/biping2/ECE445_Team57/assets/59777443/155b2b56-9db6-4186-ae52-bfa03776e1f8)

_Signed: Sakar Karki_

# April 15, 2024 - Preliminary Demonstration
A mock demonstration was conducted with TA Zheng, where we successfully activated the blue and green lights from the esp-32 programming.

_Signed: Sakar Karki_

# April 19, 2024 - Power Conversion Setback
An unforeseen event led to the damage of the AC to DC Converter. Instead, we utilized a 5V/1A USB outlet block. We connected the voltage positive and ground by stripping the USB cable and soldering them into our 5V output in our power subsystem. Everything functioned correctly and we still obtained 5V and 3.3V DC from our voltmeter readings.

![image](https://github.com/biping2/ECE445_Team57/assets/59777443/33f78806-5791-4bdc-b888-fcd8c23c3b98)

_Signed: Sakar Karki_

# April 20, 2024 - Completion of Code Functionality
I finished the full functionality of the code, integrating the API with the LEDs and speaker. The code files and progression of our code are included in the repository as well. We used a simple greater than 50 or less than 50 range for the high and low carbon intensity values. We then indexed our carbon intensity values from 200-2000Hz using an algorithm we calculated based on tests, that would best accurately produce a tone that indicated a change in tone when the intensity value changes and the button is pressed as well to hear the audio tone.

[Here is the final source code](Final.ino)

![image](https://github.com/biping2/ECE445_Team57/assets/59777443/9e44e82a-3f4e-4a7e-8e45-4910a1caa18b)
![image](https://github.com/biping2/ECE445_Team57/assets/59777443/632038f9-4ec8-4b96-a237-9dcfe1675c7a)

_Signed: Sakar Karki_

# April 21, 2024 - Creating Enclosure
In designing the 3D-printed enclosure for our device, careful consideration was given to the parameters of the printed circuit board (PCB) to ensure a seamless fit. The design incorporated our power outlet connection, which was integrated with precision to maintain functionality and accessibility. Adequate clearance was a priority to prevent any electrical or thermal issues, allowing for safe operation and maintenance. Additionally, strategic openings were included in the enclosure to allow for interaction with peripherals and to keep them visible. This not only enhances the user experience by making it easier to access and monitor the device’s status but also ensures that the design is practical, user-friendly, and aligns with the technical requirements of the PCB and the overall system. The result is a tailored enclosure that supports the device’s functionality while providing robust and aesthetically pleasing housing.

![image](https://github.com/biping2/ECE445_Team57/assets/59777443/7292b0f0-221a-42ad-b4e7-4e4a08013b2b)
![image](https://github.com/biping2/ECE445_Team57/assets/59777443/4ee4435a-4964-4fee-9bcc-196fd27f70dd)

_Signed: Sakar Karki_


# April 22, 2024 - Culmination with the Final Demonstration
The final demonstration was presented to Professor Grue, effectively showcasing our “Indicating CO2 Intensity” project. The demonstration went well, with the LED lights correctly displaying green for low intensity and blue for high intensity, alongside the operational code, and indicatory audio from the speakers upon the press of a button as another form of indicating carbon intensity levels.

![image](https://github.com/biping2/ECE445_Team57/assets/59777443/03f03b2e-8e4f-4f3a-bc49-80f1983f1ac4)

_Signed: Sakar Karki_
