# Team
    * Team Name: Co1n1oT
    * Course: ESE5160 2023
    * Team Members: Qiming Zhang/ Mark Xia
# Video

General vedio:

https://drive.google.com/file/d/1hO6zPIGfDyBZ-z6QKKJkaqXucsmvbcgw/view?usp=drive_link

OTAFU: 

https://drive.google.com/file/d/1PaVpMbMSJU6eB2cHe8P0BNUaxAxGv5d5/view?usp=sharing

# Pictures

<img src="https://github.com/ese5160/a14-final-submission-group-co1n1ot/assets/148792076/eb6e03e5-2b22-4f4e-8679-af0d7744f1f3" width="15%"></img><img src="https://github.com/ese5160/a14-final-submission-group-co1n1ot/assets/148792076/2ffad481-f484-4002-b52a-0939c2490383" width="15%"></img><img src="https://github.com/ese5160/a14-final-submission-group-co1n1ot/assets/148792076/f76fdb50-4fd9-4289-92e8-b139db0ff52e" width="15%"></img><img src="https://github.com/ese5160/a14-final-submission-group-co1n1ot/assets/148792076/7de7fe3a-6262-4500-b5ce-6d60428901c5" width="15%"></img><img src="https://github.com/ese5160/a14-final-submission-group-co1n1ot/assets/148792076/8778c7e2-2209-467d-be77-8e2ac7e7f716" width="15%"></img><img src="https://github.com/ese5160/a14-final-submission-group-co1n1ot/assets/148792076/bd863cc3-8b23-4b9a-985a-679d88abab75" width="15%"></img><img src="https://github.com/ese5160/a14-final-submission-group-co1n1ot/assets/148792076/b943f3f1-89b8-458b-86ac-d0046f851f42" width="15%"></img><img src="https://github.com/ese5160/a14-final-submission-group-co1n1ot/assets/148792076/11b4ba92-4ed2-45c3-8dda-36809309e67f" width="15%"></img><img src="https://github.com/ese5160/a14-final-submission-group-co1n1ot/assets/148792076/77d39a5b-fa9e-48c7-b05b-79104054d36c" width="15%"></img><img src="https://github.com/ese5160/a14-final-submission-group-co1n1ot/assets/148792076/14e9c2c4-85f8-4909-81ac-f1a58af914db" width="15%"></img><img src="https://github.com/ese5160/a14-final-submission-group-co1n1ot/assets/148792076/ccfc17e3-aacc-4f0f-8c86-795a6a102272" width="15%"></img>

# Project Summary
## 1. Inspiration

This project aims to create a personal coin bank at home. Nowadays, physical currency transactions have been gradually replaced by electronic transfers. However, coin usage still exists in small transactions in our daily lives. With our intelligent personal bank powered by IoT technology, we can help you to manage coins. Get notified of the remaining coins of two kinds (dimes and quarters) in our mobile app so you can prepare more coins in advance! Plus, mobile app unlocking as a safety feature lets your piggy bank know who is its owner.

## 2. What it does

In this project, we're creating a sophisticated personal bank with two main features. Firstly, a coin counter utilizing two sets of light sensors differentiates coin types; larger coins like quarters block both sensors, and the light sensor detects more light input, whereas smaller ones block only one with more light input, allowing the system to accurately calculate the total amount of money deposited. Secondly, the bank incorporates an online UI with an unlocking feature for enhanced security. This is achieved using a servo motor-controlled electronic lock, integrated with cloud technology and a mobile app. Additionally, an LCD display on the piggy bank, along with the mobile app, informs users of the total coin count. Users can enjoy these features by logging in on any mobile device.

## 3. How we built it

Firstly, we determined the functionalities of this piggy bank and selected suitable chips to realize the functionality.
Then we designed a compact PCB that holds all the sensors to make all sensors and devices that have proper power feed and can be assembled into our piggy bank.
After this PCB was manufactured, we wrote the drivers for the light sensors, motors, and screens.
Algorithms for the two light sensors for detecting the exact coin were also designed and the functionality of the proper motor was also tested.
We designed the UI on Nodered and tested the connectivity between our piggy bank and the MQTT online control.
Finally, we conducted the complete test and all functionalities worked well.

## 4. Challenges we ran into

Hardware:
The power regulator of the 5V boost is not functioning properly on our customized PCD. Therefore we used the public SAMW25 Xplain Pro to hold and implement the OLED and motor which require the 5V power supply.

Software:
The SPI communication utilized in the ST7735 screen driver is relatively slow, and it is not functioning in our Clithread, thus we used another OLED screen SSD1306 which used I2C communication.

## 5. Accomplishments that we're proud of

We build our slope dedicatedly, with the help of two light sensors, so it can recognize two different types of coins precisely with more than 95% accuracy.
The online UI is able to show the balance accordingly with real-time updates.
The motor works to automatically unlock the piggy bank, unlike the traditional one which needs to open it manually.

## 6. What we learned

Creating a PCBA in line with specific guidelines to guarantee its effective operation.
Acquiring knowledge about various communication protocols like SPI, UART, and I2C.
Grasping the fundamentals of FreeRTOS and applying it in our project.
Exchanging data through MQTT and showcasing it on a dashboard with Node-RED.
Recognizing the significance of integrating mechanical and electrical components.

## 7. What's next for ESE516 IoT Piggy Bank

Advanced Coin Recognition Technology: Expanding the coin recognition capability to include a wider range of coins, potentially even recognizing and sorting coins from different currencies. This enhancement will involve refining the sensor technology and algorithms for greater accuracy and versatility.

Enhanced User Interface and Experience: Developing a more intuitive and user-friendly mobile app interface. This could include features like setting savings goals, tracking spending habits, or receiving personalized insights based on coin deposit patterns.

Integration with Financial Management Tools: Linking the piggy bank with personal finance management software or apps. This integration would allow users to view their savings in the piggy bank as part of their broader financial portfolio, aiding in comprehensive financial planning.

# Note:

There are two separate projects included in this repo; one is for the dev board which is in charge of handling the servo; and the other one is in charge of handling all the components connected to the PCBA: light sensors, LEDs, etc.


## 8. Link to our Node-RED demo URL

http://172.190.188.203:1880/ui
