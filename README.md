# arduino-ir-remote

# Project Red Nose

Goal: Add LCD screen, IR sensor controlled by remote, use millis to be able to interrupt modes of different Christmas songs

Video: https://www.youtube.com/shorts/fgP550ZJg7w
---

## Timeline
01/02/26:
- objectives
	- intro to LCD screen
	- get it to display something that changes when a button is pressed or something

- Goal: learn how to implement LCD screen
- Achieved: was able to get it to display song and which note it was in
- Next time: fix the order of the code so the display doesn't delay note playing something about resource allocation its not the code but the pins move the lcd displays to analog, add 2 more leds and plan out some patterns, 
	- last is change the rhytmns for each song to make it sound better. for sunday 1/04


---

01/01/26:
- objectives:
	- Troubleshoot ir sensor. if not then just stick to buttons then do LCD.


- Goal: get the ir sensor to work
- Achieved: I did it finally. it was just the order of the define timer statement
- Next time: intro to LCD


---

12/31/25:
- Objectives:
	- learn each part of IR sensor and remote code
	- learn how to implement as three buttons for three channels
- Goal: to use ir sensor as buttons

/*
Button 1:
EF10BF00

2: EF11BF00

3: EF12BF00
*/

- achieved:
	- got it working for the whole code in tinkercad
	- apparently the buzzer and ir sensor both use the same timer 2 so I had to change ir sensor to use timer 1 or something like that
	- failed in breadboard. inconsistent readings


- next time:
	- simple circuit to read ir sensor
	- change wires
	- dim 
	- battery

---

12/29/25:
- Objectives
	- Introduction to IR sensor
	- watch that short video 
	- make a simple led blink with IR sensor

- Goal: just get introduced to the code and hardware a bit

- achieved:
	- learned that there is an indicator used by IR library on the LED that is also connected to pin 13 which is why the led wasn't lighting to the correct input.
	- got a simple led to blink

- next time:
	- make own code. understand how it works do it yourself

---

12/25/25:
- Objectives:
	- sprint 5: make it clean and one function for each of the 3 songs and likely future songs
	- will one function be able to do different timings for different songs? or will separate functions be better?
	- add two green leds and two red leds and rgb leds and make light functions or patterns.

Goal: To essentially get to the last project but have one function for song playing.

achieved:
did sprint 5

next time:
ir sensor. how to use it instead of buttons


[(869) ir sensor arduino - YouTube](https://www.youtube.com/results?search_query=ir+sensor+arduino)

change timings for notes (need to create rythmn arrays to match each code) --> look at the jingle bells code online that had something similar.
to make led patterns better maybe not just flashing while notes are on

---

12/24/25:
- Objectives:
	- you have to create an all stop function when another button is pressed
	- turn into functions? try one function if too complicated stick to 3
	- make sure each button can interrupt each other
	- add other leds to vary light

- Goal: create something similar to the original project at least when it comes to the sounds

achieved:
solved the problem of each notone interrupting each other
each button can interrupt each other
if you press same button twice it cancels
code is cleaner got rid redundancy

next time:
sprint 5: make it clean and one function for each of the 3 songs and likely future songs
will one function be able to do different timings for different songs? or will separate functions be better?
add two green leds and two red leds and rgb leds and make light functions or patterns.

---
 
12/22/25:
- Objectives:
	- maybe review step 2+3 like the logic and mistakes and misconceptions i made. look at logs
	- step 4 add more songs ( make a function for 3 song player)
		- first, rearrange to have 3 buttons. make it look clean
		- write set up for buttons, then melodies
		- then try copy pasting code
		- you have to create an all stop function when another button is pressed
		- turn into functions? try one function if too complicated stick to 3
	- make sure each button can interrupt each other
	- add another led to vary light



changed my mind two songs
achieved:
added other buttons
added other song array for we wish you a merry christmas
made two functions for the two buttons and two song

next time:
problem: we need to isolate each song because right now it is making the buzzer set to notone
 you have to create an all stop function when another button is pressed
		- turn into functions? try one function if too complicated stick to 3
	- make sure each button can interrupt each other
	- add another led to vary light

---

12/21/25:
- Objectives:
	- recreate toggle button for led
	- make sure button works
	- no breakpoints
	- then try no toggle
	- then add toggle

goal:
buzzer+led should be fairly simple?

achieved:
i was able to do it with some help but i understand the logic more
i added song array for one song by myself
Thats step 2 and 3 done:

next steps:
maybe redo step 2+3
step 4 add more songs
make a function for 3 song player (you will make it one in the future)
make sure each button can interrupt each other

ideas later on
add more leds and maybe make a light patterns




---

12/20/25:
- Objectives
	- practice millis
	- understand the logic
	- create a simplified version of buzzer with three buttons for 5 notes
	- then add lights into the mix
	- make sure it is interuptable 
pareto principle
what is the 20 percent effort that will give me 80 percent result?

Goal:
To learn how logic for millis work and implement it



achieved:
learned about fucking breakpoints
did get button and led to work but only while it was being pressed down


next time:
recreate toggle button for led
- make sure button works
- no breakpoints
- then try no toggle
- then add toggle


---

12/16/25:
- Objectives: 
	- Implement millis
	- Troubleshoot for one button
	- Change for the other two buttons

next time
dont focus on the project for now just learn the concepts

---

12/15/25:
- Objectives: 
	- Learn millis function
	- make LEDs blink when a note is playing
	- Extras: fix timing of notes add rests, implement millis
- Outline:
	- Play around with the code to figure out how to make LEDs blink on tinkercad
	- Research for functions
	- Learn millis with another similar setup


check if button was pressed?
Yes? then start for loop to run the notes
if statement about duration to modify it
then we compare the millis to the duration
play note while lighting upo

Was able to all things except for implementing millis

next time:
troubleshoot millis into code 
maybe look at LCD screens
