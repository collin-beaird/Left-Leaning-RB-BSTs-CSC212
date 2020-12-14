CSC 212 Final Project
Members: Collin Beaird, Andrew DiBiase, Enoch Osamaye

Left-Leaning Red-Black BSTs

Left Leaning Red-Black BSTs are a type of balance search tree that utilizes left-leaning red links/edges to indicate grouping within a node. Very similar to Red-Black trees and 2-3-4 trees with a difference in formatting and balancing.

We have attached our source code in this repository as leanleft.cpp. For test cases, we included the Shrek movie script, the Gettysburg Address, and the Declaration of Independence.

In order to compile, simply use CS50 IDE and use g++ leanleft.cpp -o "filename", where the "filename" can be whatever you please.

Once it compiles, use ./"filename", followed by textfile.txt, where the "textfile" is whatever you insert. 

We attached test cases small and large for this, however we wish to point out that the source code only compiles and does not run properly, much to our disappointment. We did put a lot of effort into this project, however due to other academic and life challenges we could not get it running before the deadline. 

We hope that you do find our effort through our presentation, report, and what we do have for implementation.

Contributions:

Collin: 
Got the basic skeleton of the current source code implemented

Helped alter the insertion method to compile the left/right rotations and color swap

Helped alter the classes into one cpp file as the template used in lab utilized separate files

Implemented the for loop at end of main() function that calls the insertion function

Helped with research regarding Left Leaning Red Black Trees and their history and design

Attempted debugging current source code with Andrew

Implemented class utilization in our first and second attempt

Created the repo and the ‘READ.me’ explaining how to compile/run the code


Andrew:
Helped alter the insertion method to compile the left/right rotations and color swap

Implemented the first part of the main() function of our current code that pushes the text file through a vector and uses a for loop with .begin() and .end() iterations to output a single line text with no unnecessary spaces or indentations

Successfully pushed back the contents of the text file we used into a vector and format the output of the text file through CS50 as a single line without unnecessary spaces or indentations

Pioneered our first attempt at the project, with the main() function in our current code being similar to the first attempt

Implemented a sorting, color swap and compare string algorithm in first attempt

Helped with research regarding Left Leaning Red Black trees and their history and design

Attempted debugging current source code with Collin

Helped Collin fix any syntax errors when need arose


Enoch:
Helped with research regarding Left Leaning Red Black trees and their history and design

Contributed to the description of methods and concepts of 2-3-4 and red black trees that are described in the report and presentation

