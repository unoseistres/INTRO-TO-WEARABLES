# INTRO-TO-WEARABLES
Introduction to wearables, sensors, and narrative

## 3/11 BASICS OF CIRCUITS 
OBJECTIVE: Teach the basics of circuitry through wearable electronics. Participants will start by creating their own parallel circuits and transition to programming with neopixels. 
[PRESENTATION SLIDES](https://docs.google.com/presentation/d/1wLszAbNCf_Xq_jpfsa_EkXWA_PH6H4VORgawnll-k4c/edit?usp=sharing)

1. Basic circuitry

<p align="center"> 
 <img src="https://github.com/unoseistres/INTRO-TO-WEARABLES/blob/master/images/IMG_3197.jpg" width="600">
 </p>
  <p align="left"> 
  <img src="https://github.com/unoseistres/INTRO-TO-WEARABLES/blob/master/images/LED.png">
  </p>

  - LED/coin cell orientation

  - Create parallel switch circuit- LED, nylon fabric tape

  <p align="center"> 
  <img src="https://github.com/unoseistres/INTRO-TO-WEARABLES/blob/master/images/LED%20switch%20circuit.jpg" width="600">
  </p>

  - One LED light up switch

  <p align="center"> 
  <img src="https://github.com/unoseistres/INTRO-TO-WEARABLES/blob/master/images/arduino%20switch.gif" width="400">
  </p>

  - Where have you seen a parallel circuit before? (christmas lights, etc)
  - Diagram on [how energy flows](https://proquest.safaribooksonline.com/book/electrical-engineering/9781449336769/firstchapter#X2ludGVybmFsX0h0bWxWaWV3P3htbGlkPTk3ODE0NDkzMzY3NjklMkZfY2lyY3VpdF9iYXNpY3NfaHRtbCZxdWVyeT0=)
  - What is ground?
    - ground is the reference point in an electrical circuit from which voltages are measured, a common return path for             electric current
    - What is VBATT, 3.3V = current flow places
    - Rest are digital pins 

2. Programming Neopixels
  - What are neopixels? 
    - Needs data but how do we send it data? 
  - Circuit diagram
    - Flora- microcontroller- runs a piece of code. Only knows to do that.
      - Reprogram (by uploading new code) it but only does the one thing
      - [Flora diagram](https://learn.adafruit.com/assets/2845)
      - How is data flowing?
  - Input
      - Are pins where you can connect devices that supply information to the microcontroller. - sensors, switches
          - Digital input - refers to a binary state. On or off, high or low. 
          - Analog input- refers to pins that can accommodate a range of values. You can accomplish a more varied effect.
  - Output
      - Are pins where information is delivered from the microcontroller in the form of varying voltage.- LEDs, motors, and         speakers. 
      
3. Sewing your circuit
  
  <p align="center"> 
  <img src="https://github.com/unoseistres/INTRO-TO-WEARABLES/blob/master/neopixels/flora%20neopixel%20diagrams.png" width="400">
  </p>
  
  - How do you sew?
    - Look out for direction
    - Sewing snaps
    - Positive and Negative connections don’t have breaks HOWEVER data connections do. 
    - Upload simple strand test
    - Arduino programming structure  
    
4. HOMEWORK
  - Come in with an animation
    - Blink animation ⇒ snake animation 
      - INTRO, BLINK, CHASER 
    - Feeling animation: 	
      - High
      - Crushed
      - Magnificent 
5. [OTHER REFERENCES](https://playground.arduino.cc/uploads/Main/arduino_comic_v0004.pdf)

## 3/13 SENSING THE BODY 
1. Introduction to Arduino
  - Go over Animation homework- Questions? Hurdles? Discoveries?

## Introduction to Sensors
2. Construct circuit 
 - Accelerometer (2)
   - How does an accelerometer work?
   - What is it detecting?
 - Stretch sensor (2)
   - What is this stretch sensor made out of?
   - What is it detecting?
 - Mic
   - What is it detecting?
   - How are the neopixels being animated?
 - Capacitive touch
   - What is it detecting?
   - What is resistance? 

BREAK

4. HOMEWORK
  - Create a 2 min max. performance
  - No words
  - Has to involve more than one body
  - Prompt- “I have to tell you a secret”

5. Designing your circuit 
  - Where does your sensor live on the body?
  - Examples of how to migrate your circuit  
  - What is your sensor potentially highlighting?
    - What kind of gestures does your sensor invite?
    - What kind of meaning does the data have? 

## References
- Make: Wearable Electronics by Kate Hartman ([Read Online](https://proquest.safaribooksonline.com/book/electrical-engineering/9781449336769/firstchapter) via PULibrary)
