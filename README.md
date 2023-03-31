#VIDEO FLASH TRIGGER WARNING:



#Coding 2 Final Project

This project consists of combining and expanding on two assignments set in class. One of the assignments I chose was the recreation of a Coding1 homework – animation, and the other assignment was using OpenFrameworks with Arduino.

The OpenFrameworks file contains 7 individual animations in the draw loop. The animation is created through the use of sine, cosine, tan and time to modulate circles into different patterns. The trigger to change one animation to the next, using a switch case, is the clicking of the computer mouse. 

When the computer mouse is clicked OpenFrameworks sends the data char ‘1’ to the Arduino. When the data is retrieved by the Arduino it triggers the RGB LED to change colour using a switch case statement. Each time the mouse is clicked it the arduino executes the next case statement and changes the colour of the LED. The LED colours are matched to the colour of the animations 

My main inspiration behind this project is the work of Computational artists Theo Watson and Dan Buzzo. I found both their animations really mesmerising and wanted to create my own interactive vision. I used Dan Buzzo’s tutorial  ‘Draw generative sine-wave animations – tutorial’ as a starting point for my project and to understand how sine animation works. 

Another inspiration behind my project is the work Japanese artist Jonki Jo. He used a motion sensor to control the direction of a boids animation and a line of LED lights. The boids and lights followed his hand as it moved. I really liked the interactive element of his work and wanted to make mine interactive. How ever I did not have time to make it as interactive as I’d liked. I would have liked to have used motion sensors in my project but ran out of time. 


The main issue I came across with the project was getting the arduino to switch case when the mouse was clicked. I started out with if statements and a counter for the incoming data. I planned that every mouse was clicked it would store the data and count up the incidences so I could associate clicks with 1, 2, 3 etc and use ‘if(counter ==2)’. However I could not get it to counter to work with the statements. Instead I tried Switch cases but the counter would still not work. 

My resolve for the problem was to nest if statements into the cases statements so once the mouse was clicked it will be trapped in each case and can only move onto the next if  ‘if (inByte == 1)’ was satisfied. Instead of counting the computer clicks the code only checks if the mouse has been clicked while in the case code block. 

A minor issue I came across was trying to upgrade my old Red and Green LED and animation code into what I needed for this project. However the logic used for the LED being Red or Green was determined by the background colour of the OpenFrameworks animation,ie ‘If backgroundGreen = True’ send data to arduino. 
And when the Arduino receives the data it turns the green LED on. A statement within the Arduino code then turns the Red LED on/off so it was the opposite of the Green LED. The logic was confusing and after trying to understand and rectify it I gave up and rewrote the code which leads onto the if statement/stitch case issues above. 

I would have liked to have more Arduino inputs in the project as the only current input to the code is the computer mouse. My original design did not have an RGB LED as I intended for the user to control the RGB values of the animations using button components on the arduino to increase and decrease the individual colour values. But by the time I was happy with the animations and started trying to incorporate buttons I ran out of time and switched to a colour changing RGB to compliment the animation. 


Links to Inspirations for the project: 
(1) Draw generative sine-wave animations - tutorial: openFrameworks superBasics e10 – YouTube

(1) Control 16 LEDs with openFrameworks and Arduino – YouTube

(1) Particle sine wave. openFrameworks – YouTube

(1) openFrameworks Developer Series :: Theo Watson – YouTube
