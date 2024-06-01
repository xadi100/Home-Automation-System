# Home Automation System using ESP8266


## Overview

This project implements a Home Automation System using ESP8266 microcontrollers.
The system allows users to control various devices in their home remotely through a Telegram bot. 
The devices can include lights, fans, and other appliances.

## Features

* Control devices remotely via Telegram bot commands.
* Check the status of devices.
* Password-protected access for security.
* Real-time alerts for unauthorized access attempts.

## Components

* ESP8266 microcontrollers
* Wi-Fi connection
* Telegram Bot API

## Setup

 1. **Clone the Repository:** Clone this repository to your local machine.
 
 ```
 git clone https://github.com/your_username/home-automation.git
 ```

 Hardware Setup: Connect the ESP8266 microcontrollers to the devices you want to control.

2. **Software Setup:**

* Install the required libraries: ESP8266WiFi, WiFiClientSecure, UniversalTelegramBot.
* Update the Wi-Fi SSID and password in the code.
* Replace BOT_TOKEN with your Telegram bot token.
* Upload the code to the ESP8266 devices.
* Telegram Bot Setup: Create a Telegram bot and obtain the bot token.

3. **Run the System:** Power on the ESP8266 devices and start controlling your home devices through the Telegram bot.

## **Usage**
Start a conversation with the Telegram bot.
Use commands like **/start** to begin interaction.
Control devices using commands like ON and OFF.
Check device status using the Status command.

## Contributors
Kumar Nikhil (@anglo-nikhil)
Aditya Pratap Singh (@Adi-Medi9)


