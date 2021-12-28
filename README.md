# Fire Fighting robot

When Fire burns it emits small amount of IR(Infrared Light) which is detected by the sensor. The sensor sends message to Arduino which works on the programming done by me. The NodeMCU fires the WebHook to CallMeBot API which sends a WhatsApp Message to the fire brigade.

The hardware required are 3 flame sensors, Arduino Uno, jumper wires, relay module, chassis, 2 motors and wheels,12v DC water pump, mini breadboard, L293D module and NodeMCU.
The Software used are Arduino IDE, Blynk and CallMeBot API.

This project uses Arduino, which is an open-source electronics platform. It is based on easy-to-use hardware and software. I have used NodeMCU and Call Me Bot API for sending and receiving WhatsApp Messages. 

There are three flame sensors which detect the fire on the front, left and right side.Whenever the robot detects the fire, on the front or left or right side , it will go near the fire in that direction and spray water to extinguish the fire. At the same time Webhook trigger will be fired and a WhatsApp message will be sent to the Fire Brigade. 

With the advancement of technology especially in Robotics it is very much possible to replace humans with robots for fighting the fire. This would improve the efficiency of firefighters and would also prevent them from risking human lives. This project "FIRE FIGHTING ROBOT" will help to extinguish the fire without threat to human life. This will help us to save property and lives.

We can make an app for the robot, so that along with automatic, it could be controlled by the fire brigade while standing outside the building through remote control.
THE END
