[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/hxXvQudU)
# a12-board-bringup
    * Team Number: 
    * Team Name: 
    * Team Members: 
    * Description of hardware: (embedded hardware, laptop, etc) 

*_Fill out your assignment answers below._* 

### 1. 
1. Visual Board Inspection & Photograph
Does your PCBA look like the 3D model?
Yes, our PCBA looks like the 3D model
Are any components soldered to the board that shouldn’t be?
Everything soldered on the board is correct. There should be a battery connector, but it is not soldered on board, and we have ordered it now.
Do you see any manufacturing errors, like solder bridging, rotated components, or poor workmanship?
From the scop. We did not see any manufacturing errors. 
3 photos:




![image](https://github.com/ese5160/a12-board-bringup-group-co1n1ot/assets/148792076/f7cbb73e-0c3f-4c5b-b183-a810743f62f5)


![image](https://github.com/ese5160/a12-board-bringup-group-co1n1ot/assets/148792076/2695a2c5-4103-49c7-b7db-416f9787091d)


![image](https://github.com/ese5160/a12-board-bringup-group-co1n1ot/assets/148792076/915ce371-c9e4-4125-9c5e-cb92835927cb)




2. Power System Evaluation
   
2.1 Distinct Power Modes
 Our device has two power sources: single-cell LiPo and USB power. It has two regulators: a 3.3V buck, and a 5V boost. Our distinct power modes would be:

The unregulated battery only is connected and ranges from 3.30V to 4.20V

Regulated USB only is connected and ranges from 4.85V to 5.25V

Both battery and USB are connected, so the USB voltage will be preferred (4.85-5.25V)

Buck Converter: 3.7V typical input and 3.3V output with max current 0.62A

Boost Converter: 3.7V typical input and 5V output with max current 0.4A

There are two jumpers JP1 and JP12 that prevent the Vout (Vsystem) that going directly from BQ24075RGTR to the input of BUCK and BOOST. Once the 3V3BUCK and 5VBOOST is working, we have to connect JP22 and JP23 to let the power go to devices on board.

![image](https://github.com/ese5160/a12-board-bringup-group-co1n1ot/assets/148792076/23a2275a-0b1e-46c9-addf-9ae95dc86b06)



2.2 Power Regulation Evaluation



![image](https://github.com/ese5160/a12-board-bringup-group-co1n1ot/assets/148792076/647754ca-60a2-45e6-88d3-ae3d54819fb5)

![image](https://github.com/ese5160/a12-board-bringup-group-co1n1ot/assets/148792076/8afd48ec-e45e-4d0d-940c-7a24fb9d3a10)




Since my example device has a 3.3V buck, 5V boost, I would provide a total of 4 oscilloscope captures with the following information:
3.3V startup transient:

![image](https://github.com/ese5160/a12-board-bringup-group-co1n1ot/assets/148792076/b0f05e46-d3ce-4e08-b10d-8f7c212e0344)


It first has a rapid rise, and then it increases slower but finally reaches 3.31V.

3.3V steady state:


![image](https://github.com/ese5160/a12-board-bringup-group-co1n1ot/assets/148792076/dee4a56e-3745-41a0-87d9-317f3320ef78)

Average voltage 3.28V
Error between expected and actual voltage: 0.02V
Min voltage	3.25V
Max voltage	3.41V
Voltage ripple as a percentage of the output voltage:  5%



5V startup transient:

![image](https://github.com/ese5160/a12-board-bringup-group-co1n1ot/assets/148792076/7e87a440-94d3-4df0-acd3-673057a6206e)


It rapidly reaches 5.09V within several milliseconds, which is great.

5V steady state:


![image](https://github.com/ese5160/a12-board-bringup-group-co1n1ot/assets/148792076/38ee6276-af8c-4f68-9f72-503e1ba7d78a)

Average voltage 5.0616V
Error between expected and actual voltage 0.06 V
Min voltage	5.07V
Max voltage 	5.25V
Voltage ripple as a percentage of the output voltage 3.4%


![image](https://github.com/ese5160/a12-board-bringup-group-co1n1ot/assets/148792076/b3b171fc-0337-48ca-9caf-cffb8d43bcfe)



2.3 Load Testing

My 5V boost regulator is the riskiest regulator in my circuit. It needs to supply 250mA to drive a servo motor, but the regulator IC can supply up to 400mA. I will attach the DC power supply to the output of the BQ24075 at 4.2V (not quite a full LiPo). I will attach the E-Load to the motor connector. Then, I will evaluate 10%, 50%, 100%, and 120% loads using the E-Load and write down the corresponding voltages in a table.
Expected Load
Voltage
10% (40mA)

5.02V

50% (200mA)

5.00V

100% (400mA)

4.97V

120% (480mA)

4.96V


 Thermal test:

 
![thermal](https://github.com/ese5160/a12-board-bringup-group-co1n1ot/assets/148792076/d1cb2390-c1c1-4177-8c62-0ad3c5115854)




Results analysis: upon observation and testing, there isn’t anything abnormal and the testing results all fell within our expectations. The boost and buck circuit both have ripple less than 5% which is good. However, the voltage ramp-up and ramp-down time is a little longer, indicating that we might have used some large capacitors.
![J-LINK](https://github.com/ese5160/a12-board-bringup-group-co1n1ot/assets/148792076/39930bde-32d7-4c73-9d56-9eada6b63854)


4. Peripheral Evaluation
   
4.1 Debug LED

https://drive.google.com/file/d/1v5Y9r9VooCLzewBHcAb6WWh5J7bcWdJY/view?usp=drive_link

4.2 Debug Button

https://drive.google.com/file/d/1fP1L5djHMNH83eiUXwgDiIUfuMVWwVvA/view?usp=drive_link

4.3 UART Communication

https://docs.google.com/document/d/1PB-jfH4jkTiy0MRG54VenuvgzTJuidcxYp6yVUtV16w/edit?usp=drive_link
(same as I2C video but we typed in the command window which means that UART is working )

4.4 Non-volatile Memory (SD Card)

https://drive.google.com/file/d/1Ul4GrQvROIQj0KdMYIBmql5JWnFWu1YQ/view?usp=drive_link

4.5 I2C Device

https://docs.google.com/document/d/1PB-jfH4jkTiy0MRG54VenuvgzTJuidcxYp6yVUtV16w/edit?usp=drive_link
