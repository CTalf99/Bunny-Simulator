A program to simulate the population of a wild rabbit colony. Bunnies breed and die depending on their age, sex and infected status. The attributes of the bunnies are determined randomely when the bunny is born. The program ends when there are no bunnies remaining.

Objectives met:
The program meets the minumum requirements specified in the project outline.
There are two second intervals between the list of bunnies being refreshed and a one second pause between annoucements.
Ability for user to half the population of the colony using 'k' input, in the two second window after list has been displayed.

Current objectives:
Need to put code used for input thread in a different file to reduce code in main, and so that BunnyManager object + userInput doesn't have to be global.

Due to the length of time it takes to run the program, I have not run the program to completion as many times as I would have liked. 
I am working on changing the parameters to speed this up for the purpose of fault finding. 
Although it doesn't break the program, the program currently accepts user input at all times despite only carrying out the 'kill half' command at the desired timing. I would like to resolve this so that it does not always take user input.
The function for removing half of the bunnies isn't completely random as I believe it has a slight bias towards removing rabbits towards the fron the the list, so this could be improved upon. This could Potentially be achieved by copying the list over to a new vector and using the shuffle function, before deleting half of these and resorting them into the list.
Currently not cross-platform due to the functions I have used to format console output.



