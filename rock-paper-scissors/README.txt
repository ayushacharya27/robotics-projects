This is a Rock Paper Scissor Playing Program where I have used Google's mediaPipe module Feature to Track hands and then serially Communicating with Arduino To move Servo's.

Its an Unbeatable computer (as there are three cases only ,u can add more cases as u like) , programmed to always defy the option u r showing on the camera.

For clarity the Gestures are not trained it's just i used mediapipe's mentioned coordinates to track the fingers. I made a function for each rock , paper and scissor , for example for paper
i took two cases , first the tip of all fingers should be above the mcp(bottom most point) and also the middle most point should also be above the mcp.
More details in the code....


For the testing hand i used a cardboard and cut out a 3 fingered hand , which can show all rock paper and scissor comfortably , and connected them from behind with rubber bands
so that they stay streched out (dont forget to make a resisting cardboard behind ) , then i connected to the servos and used a arduino uno to controll them.
Components used : 
1. Arduino
2. Python Programming (includes modules such as serial , OpenCV, mediapipe)
3. Servo Motors
4. A 3 Fingered Hand Replicating the Original Hand(Cardboard Cutouts).   
