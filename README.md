Hello all :) This is the Arduino C code I created that if configured properly on a circuit can detect and respond 
to light. However, I used it to create a robot chassis that uses light sensitivities to follow tracks. The thing about 
Arduinos is that codes can have so many different functionalities depending on how the circuit is configured. What I used it for
could be used entirely different if I had configures the circuit differently and I think that is very cool.

If you wanna know how I configured the circuit keep reading. 
It was important to note that what connected a lot of the components in the circuit I made wasn't necessarily wiring,
but the code. However, the wiring was still significant to the implementation. The left and right motors had duplicate
setups with different digital and analog port pins. Transistors were placed in series with a motor, 1k Ohm resistor, and 
ground. This was a significant aspect of the circuit because the transistors acted as a switch. The 1k Ohm resistor that
was in series with each transistor was connected to a digital port pin that provided the transistor with necessary information.
When the voltage applied to the base was below a certain threshold, the transistor was non-conducting, and the circuit was open.
When the voltage applied to the base was above the threshold, the transistor was fully conducting, and the circuit was closed. 
This determined whether the motors were on and was why each transistor was in series with a motor. On the other side of the circuit, 
the photocells were in series with an analog port pin and a 10k Ohm resistor connected to ground, forming a voltage divider circuit.
The resistance was being measured across the 10k Ohm resistor; however, the photocells' resistance directly affected the voltage 
being measured and provided the analog port pin with information that the transistor used to know when to stop conducting. While 
the top and bottom of the circuit shared a 3.3-volt input, they were not directly connected to each other.
