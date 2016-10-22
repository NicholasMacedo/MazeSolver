/*************************README.txt****************************************
Student Name: Nicholas Macedo                Student Number: 
Date: January 16th 2015                      Course Name: CIS 2520
****************************************************************************/


************
Compilation
************

Both programs are compiled using gcc and the flags -ansi -Wall -pedantic

Maze Solving Program:
	The maze solving program can be compiled by typing "make program" into the command-line.
	When this is done, it will compile the necessary files producing an executable.  

Stack/List Testing Program:
	The stack/list testing program can be compiled by typing "make testing" into the command-line.
	When this is done, it will compile the necessary files producing an executable. 


***********************
Running the program(s)
***********************

Both program's executable can be found in the bin folder in the main assignment directory.
Maze Solving Program:
	The maze solving program can be run by typing "./bin/mazeSolver <maze file location>" into the command-line.
	In order to run properly, the program must be passed a maze file. When this is done, it will run the program.  

Stack/List Testing Program:
	The stack/list testing program can be run by typing "./bin/runTests" into the command-line.
	When this is done, it will compile the necessary files producing an executable. 


*****************
Known Limitations
*****************

-> Passing No File into the program will cause it to exit w/ a warning.
-> Passing in a file that is not a maze will cause it to segfault.
-> Maze muse be a square or a rectangle. No "L" shapes.
-> (NOT PROGRAM RELATED) Style Checker gives errors for header guards.
-> Mazes must have a vertical hallway width of ONE space wide. See sample mazes in assets folder.
-> Mazes with more than one correct path will be shown both at the same time.
-> No maze bigger than 100x100 and smaller than 10x10.
-> If the maze does not have an exit, the program will just print the maze to the screen with no *'s.
-> In order to draw a path the maze must have a start (Blank wall or S). With out a start maze just draws with no solution.
-> In order to draw a path the maze must have a finish (Blank wall or F). With out a finish maze just draws with no solution.


*******************************
Academic Integrity Pledge
*******************************

I have exclusive control over this submission via my password.
By including this file with my submitted files, I certify that:

1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.

I assert that this work is my own.

I have appropriately acknowledged any and all material (data, images, ideas or
words) that I have used, whether directly quoted or paraphrased.  Furthermore,
I certify that this assignment was prepared by me specifically for this course.

