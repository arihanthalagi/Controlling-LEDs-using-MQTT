# Controlling-LEDs-using-MQTT
#  Task 3b – Controlling LEDs Using MQTT

##  Objective

To understand and implement MQTT communication by establishing publishing and subscribing functionalities. This task helps me learn how devices communicate over a network and how MQTT can be used to control hardware components like LEDs remotely.

---

##  Description

In this task, I will explore the basics of the MQTT (Message Queuing Telemetry Transport) protocol and understand how it works using the publish–subscribe model.

MQTT works with three main components:

- **Publisher** – Sends messages  
- **Subscriber** – Receives messages  
- **Broker** – Manages message distribution  

In this project:

- The ESP32 acts as a **subscriber**.
- An MQTT client (like a mobile app or web dashboard) acts as a **publisher**.
- When a message is published, the ESP32 receives it and controls the corresponding LED.

---

#  Working Principle

1. ESP32 connects to WiFi.
2. ESP32 connects to an MQTT broker.
3. It subscribes to a specific topic (example: `home/led`).
4. When a message is published to that topic:
   - The ESP32 reads the message.
   - It checks the command.
   - It turns ON or OFF the specified LED.
  


#                          Example Commands

| Published Message | Action |
|-------------------|--------|
| `LED 1 ON`  | Turns ON LED 1 |
| `LED 1 OFF` | Turns OFF LED 1 |
| `LED 2 ON`  | Turns ON LED 2 |
| `LED 2 OFF` | Turns OFF LED 2 |

---

#  Components Required

- ESP32  
- 2 or more LEDs  
- 220Ω resistors  
- Breadboard  
- WiFi connection  
- MQTT Broker (e.g., Mosquitto or online broker)
