# 2024-02-05 - First meeting with TA 
We had our first meeting with TA Zheng to discuss our project called "Indicating CO2 Intensity." We decided to meet every Tuesday at 5 PM to discuss updates.

# 2024-02-12 - Parts Updates

We decided to get some LEDs, a speaker, and breadboards for our design. We are currently still working on our PCB board. We also got some of the materials that we would need to work on our project including personal tools and the lab kit.


# 2024-02-26 - Design Review

- We had our design review today
- Received very good feedback on our design
   - 3.3V LEDS
   - Removed Battery Backup to reduce complexity
   - Considered using USB rather than a wall outlet

<img src="https://github.com/biping2/ECE445_Team57/assets/123705149/02d79a6a-d44b-4ad4-8b2b-f579994ab10d" width="500">

# 2024-03-18 - Ordered PCB Board

- After speaking to a TA and making various changes we were able to order our PCB
   - Notable Changes
      - NMOS vs PMOS
      - Gate Drivers
      - Restructuring of LED Subsystem 

<img src="https://github.com/biping2/ECE445_Team57/assets/123705149/73d66439-d089-4f88-8f1b-107e644a826c" width="500">



# 2024-03-25 - Parts update
<img src="https://github.com/biping2/ECE445_Team57/assets/123705149/68746433-b81d-4a4d-a7a0-f6bdccac5ca9" height="500">
<img src="https://github.com/biping2/ECE445_Team57/assets/123705149/61500821-d0dc-44e2-a9fe-f2608a12ecc7" height="500">

Parts came in. We will start soldering and testing individual components.

# 2024-03-27 - Initial Soldering (Easier Components)

Began soldering with easier components. I want to have as much experience as possible before soldering the microcontroller, amplifier, and other important chips


    - Soldered MOSFETs
    - Soldered SD Card Holder
<img src="https://github.com/biping2/ECE445_Team57/assets/123705149/a2b2893c-7055-488e-845a-be53c3ddb3bc" height="1000">    

# 2024-04-02 - More soldering(Testing Components for functionality)

Spent a lot of time soldering today. Power system seems to be working as expected.

    - Soldered Power Subsystem
    - Tested Power Subsystem
        - We are getting 5V at all places where we need it
        - Linear Regulator is working as expected
            - 3.3V is getting to the places where it is expected
    - Soldered Gate Drivers (Untested)
<img src="https://github.com/biping2/ECE445_Team57/assets/123705149/c5316817-e243-42cc-96b8-2f4d5cfd6236" height="1000">

# 2024-04-05 - Final Soldering(Testing subsystems with forced inputs)

All systems have been successfully soldered on. Forced input using DC voltage as well as signal generator to make sure systems work as expected. 

# 2024-04-10 - Attempted programming board. 

We were unable to program the board using the USBASP. More testing to be done. We need a functional USB-UART Bridge however there are none available for checkout. We will look into other options now

# 2024-04-12 - Successfully programmed board using development board instead of USBASP or UART

We were able to use the development board as a USB to UART bridge and we were able to load in some basic programs to test the functionality of the ESP32.

# 2024-04-15 - Code connects device to Wifi, LEDs programmed manually

We achieved a milestone by connecting the device to WiFi. It showed up as connected on my laptop hotspot. Additionally, we managed manual programming of LEDs to demonstrate control capabilities.
<img src="https://github.com/biping2/ECE445_Team57/assets/123705149/108b3e1a-5032-4fda-b61d-7d5518174138" height="500">

# 2024-04-15- Mock Demo

We showed our TA the functionality of different subsystems. They haven't been fully integrated yet.

# 2024-04-19 - Major Issues

We blew up our board. We weren't being careful enough with the board and the lack of clearance between our power connector headers comprimised our tracks. The next time we plugged in our board it completely blew up and sparked. This left multiple burn marks on the board and we ended up removing parts of the power subsystem and replacing it with an iphone 5V charger for power.

We removed the ACDC converter and powered it with the lab power supply and it still worked. We then replaced that with a iphone 5V power brick.

<img src="https://github.com/biping2/ECE445_Team57/assets/123705149/6bbcb419-0809-4c92-b413-f37ce6851bc2" height="500">


# 2024-04-20- Completed full code functionality with API and integrated with LEDs
<img src="https://github.com/biping2/ECE445_Team57/assets/123705149/2e615e9a-6e70-4462-aa76-b67b40ae0201" height="500">


The complete code integrating the API with the LEDs was finalized, some of the LEDs dont fully work because of issues with the Gate Driver however we were able to get two of them to function as expected so that we would be able to show high and low level carbon intensities..

# 2024-04-22- Finished final Demo

The project culminated in a successful final demonstration, showcasing the almost fully functional device. The system performed well during the demo, there were a couple of glitches caused by the inconsistency of my computers hotspot however we were able to show that all of our requirements were completed. 
Afterwards we reprinted the enclosure so that it would look more presentable in our videos as well as our final presentation.

![Screenshot 2024-05-02 at 9 21 04 PM](https://github.com/biping2/ECE445_Team57/assets/168696447/f8eb3792-01c9-495f-a6a7-61e59e31cd1a)

![Screenshot 2024-05-02 at 9 21 56 PM](https://github.com/biping2/ECE445_Team57/assets/168696447/cd23219d-909a-4847-94f5-f7dafa732fbd)
