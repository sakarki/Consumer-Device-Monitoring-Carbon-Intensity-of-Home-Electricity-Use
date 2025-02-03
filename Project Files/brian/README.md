2024-02-05 - First meeting with TA 
We met with TA Zheng for the first time to talk about our project, "Indicating CO2 Intensity." We agreed to get together every Tuesday at 5 PM to talk about our progress.

2024-02-12 - Parts Updates
We chose to acquire some LEDs, a speaker, and PCB boards for our design. We are still in the process of working on our PCB board.

2024-02-26 - Design Review
Today we reviewed the design for our project and it went well. We explained how we plan to set up our "Indicating CO2 Intensity" project for the demonstration. The professor and TA suggested that we use about 3.3 volts to power the LED lights and the speaker.

![Screenshot 2024-05-02 at 9 12 39 PM](https://github.com/biping2/ECE445_Team57/assets/168696447/a0e1e9f8-da17-4413-a5ab-5b68f494babf)


2024-03-18 - Ordered PCB Board
We ordered the PCB boards individually and spent around 20 dollars each to get them.

![Screenshot 2024-05-02 at 9 07 38 PM](https://github.com/biping2/ECE445_Team57/assets/168696447/6d3b6bf0-61ee-48a6-b414-fd321b00038e)

2024-03-25 - Parts update

![Screenshot 2024-05-02 at 9 09 20 PM](https://github.com/biping2/ECE445_Team57/assets/168696447/528f24be-1c5a-434e-8757-25a29e1f6a3c)

We ordered the bread board individually because we missed the deadline, and this is our bread board.
This is our bread board. We just need to wait for our resistors, gate drivers, and LEDs to arrive before we can solder everything onto the PCB board.

2024-03-27 - Initial Soldering (Easier Components)
We finished soldering the resistors and gate drivers.

2024-04-02 - More soldering(Testing Components for functionality)
We had to solder again to double-check that everything was soldered properly.

2024-04-05 - Final Soldering(Testing subsystems with forced inputs)

![Screenshot 2024-05-02 at 9 18 18 PM](https://github.com/biping2/ECE445_Team57/assets/168696447/78474a71-df13-4824-a74a-2f55678bde5a)

We finally finished soldering our PCB board, and now we need to start writing code to run it.

2024-04-10 - Attempted programming board. 
Sakar and Bipin wrote code to run our PCB board. There were some errors when trying to turn on the LED lights, but we are trying to fix them as soon as possible.
2024-04-12 Successfully programmed board using development board instead of USBASP or UART

![Screenshot 2024-05-02 at 9 18 50 PM](https://github.com/biping2/ECE445_Team57/assets/168696447/8cdc1e7e-ff67-44c2-9232-bc6ce7f925c0)


Our code worked properly and allowed our PCB board to function correctly.

2024-04-15 - Code connects device to Wifi, LEDs programmed manually

![Screenshot 2024-05-02 at 9 19 31 PM](https://github.com/biping2/ECE445_Team57/assets/168696447/d0fad088-b3a8-4643-99e0-52be56103c10)

Thankfully, our code worked to turn on the LED lights and also connected to Wi-Fi to measure the carbon intensity.

2024-04-15- Mock Demo
We completed our practice demo with our TA Zheng and successfully did our final demo. In the demo, we had to turn on blue lights for low carbon intensity and green lights for high carbon intensity.

2024-04-19 AC to DC Converter damaged. Instead We used a 5V/1A USB to outlet block.
Our outlet got damaged because we didn't notice that the positive and negative wires were slightly connected. We had to find another outlet to plug it into.

![Screenshot 2024-05-02 at 9 20 09 PM](https://github.com/biping2/ECE445_Team57/assets/168696447/a8878191-1100-4cd6-a4b3-3ff3436fbaa5)

2024-04-20- Completed full code functionality with API and integrated with LEDs
Before, we were able to turn on the LED lights but couldn't choose between blue or green. Luckily, we fixed a mistake in our code. Now, we can accurately measure how much carbon there is and display the right color, blue or green, on the LED lights.

![Screenshot 2024-05-02 at 9 20 37 PM](https://github.com/biping2/ECE445_Team57/assets/168696447/51574933-91ac-461e-83dc-2e9972703e2a)

2024-04-22- Finished final Demo

We completed our final demo with Professor Grue, presenting our project "Indicating CO2 Intensity." Everything worked great, with the LED lights showing green for low intensity and blue for high intensity. We also showed off the code we wrote for our project. These pictures show low intensity and high intensity.

![Screenshot 2024-05-02 at 9 21 04 PM](https://github.com/biping2/ECE445_Team57/assets/168696447/f8eb3792-01c9-495f-a6a7-61e59e31cd1a)

![Screenshot 2024-05-02 at 9 21 56 PM](https://github.com/biping2/ECE445_Team57/assets/168696447/cd23219d-909a-4847-94f5-f7dafa732fbd)


