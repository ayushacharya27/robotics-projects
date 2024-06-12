import serial # FOR CONTROLLING FROM SERIAL PORT
import keyboard # FOR TAKING KEYS INPUTS FROM KEYBOARD
 
# SELECTING SERIAL PORT
arduino = serial.Serial("COM4", 9600, timeout=1) 

while True:
    if keyboard.is_pressed('w'):
        # GIVING COMMAND 
        arduino.write(b'w')
        # CREATING A LOOP WHICH WILL RUN UNTIL THE KEY W IS PRESSED 
        while keyboard.is_pressed('w'):
            pass
        # IF W IS RELEASED THEN , IT WILL EXIT FROM LOOP AND TRASNMIT M WHICH WILL STOP THE CAR
        arduino.write(b'm')
        
     # SIMILIARLLY A DID THIS FOR A , S &  D    
    if keyboard.is_pressed('a'):
        arduino.write(b'a')
         
        while keyboard.is_pressed('a'):
            pass
        arduino.write(b'm')
        
         
    if keyboard.is_pressed('d'):
        arduino.write(b'd')
         
         
        while keyboard.is_pressed('d'):
            pass
        arduino.write(b'm')
         
         
    if keyboard.is_pressed('s'):
        arduino.write(b's')
         
         
        while keyboard.is_pressed('s'):
            pass
        arduino.write(b'm')
        
         
