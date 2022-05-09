A program to simulate the population of a wild rabbit colony. Bunnies breed and die depending on their age, sex and infected status. The attributes of the bunnies are determined randomly when the bunny is born. The program ends when there are no bunnies remaining.

Objectives met:
The program meets the minumum requirements specified in the project outline.
There are two second intervals between the list of bunnies being refreshed and a one second pause between annoucements.

Current objectives:

The function for randomly removing bunnies after population increases over 1000 is biased towards removing bunnies near the start of the list. This function could be improved upon. A way to do this could be to create a new vector where the list is copied into before being shuffled, halved, and then returned to the original list.
I was in the process of allowing user input for manually removing half of the bunnies from the list. I did get this working to an extent but my implementation of it was buggy and it overcomplicated the main.cpp file so I decided to remove the feature. 
I could try to put this feature back in when I have a greater undertanding of threads, as I was trying to receive user input as the program was still running. I think one of the reasons why this might have caused bugs is because I was writing to the list in parallel.



