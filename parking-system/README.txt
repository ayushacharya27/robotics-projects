This is a Prototype for a parking system , which consists of a Mall entry where u will enter Ur password.
Once entered , u then will be allowed to enter the mall.
After that there is another gate for parking slot entry , it consists of a Ultrasonic Sensor and Two Servos to control the gate movement,
it first takes into account the number of slots available per sides and then allow the car to go that side where slots are less occupied.

Then in this Prototype there is only 2 slots (one left and one right) because Tinker cad Doesn't Support Too many Components in one design.
I tried to link the password management system to parking lot such that if you entered the correct password then through serial communication the first Arduino will send a Confirmation signal to start the functioning of The second Arduino.

Once You get in You will find  P1 slot , you just enter and the Ultrasonic sensor will detect Your presence and accordingly change the values of slot available.
Once You leave the Slot (it is must) then only u will be detected at the exit (otherwise not) and again The slots will be changed accordingly.

List Of Components Used : 
2 Arduino Uno
1 Keypad
4 Ultrasonic Sensors
1 Light Bulb
1 Photo Resistor
6 Servos
2 Lcd Screens(I2c)
2 LED's