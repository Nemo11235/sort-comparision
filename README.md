# sort-comparision
This is a program that compares 5 different types of sorting algorithms by running them on the same Shakespeare's article.
General Overview:
The purpose of this lab is to help us visualize the run time of each algorithm and comparing them using the high_resolution_clock class. It is also a good exercise for us to practice providing lots of options for the users to make the program more flexible. Additionally, the program is also a good practice for us to learn how to deal with strings because we need to code functions that take out only the information we want from a great amount of string data.


Purpose:
This program is for us to reinforce our memory of the five sorting algorithms we’ve learned so far by using them to solve problems that might occur in real life. More importantly, it can help us visualize and compare the run time of each sorting algorithm and give us a more straightforward way to have a deeper understanding of the efficiency of each algorithm and associate it with the Big O notation. The runtime will also help us verify the Big O notation efficiency by comparing different data sizes.

Planning and Organizations:

Base on the requirements, these are the functionalities that must be coded:
A function that reads the file and separates each word into a string, then turn it into an array. The part that separates each word should be aware of some punctuations should be ignored because they are connecting two words into one, and some should not be ignored because it is one word;
A function that counts the number of words;
A function that distinguishes if a character is one of the 26 letters, upper or lower case;
The code that allows the program to calculate the runtime;
A user interface that allows user to select the algorithm for sorting, the number of words he/she wants to sort, ask if he/she wants to repeat. This interface should be in the main function;
Implement 5 different types of sorting algorithms that sort an array of string in alphabetical order;
A validator that helps makes sure the user inputs the integer within a certain range since we are providing a lot of choices for the user in this program. It should accept two integers as range and return the validated integer.
A function that helps allow the user to choose to print the first or last 50 elements in the array


And I made a flow chart on what the program should do so that I can keep track of where I’m working on:

(Here is my flow chart on how the program should be running)
Step 1: code the basic functions

The easiest part will be coding the 5 sorting algorithms because we’ve already done it many times, all I have to do is to add a timer on them, so I’ll start off with coding and testing the 5 sorting algorithms and make sure they work as intended. So that’s the first thing I did:

(I made a string array with random characters, and test the sorting functions one by one)


(And it can be seen that the function runs well, the meaningless strings are sorted in order.)

And then I decided to work on the validator because I had already done data validation in the previous lab, all I have to do is to modify it and make it a function. Here is the testing:


(The picture shows a validation that requires the user to input an integer from 1 to 3, any number that is out of range and any other characters will not be accepted until the user enters the right thing.)
Step2: user interface
Now we can finish the frame of the program, which is the user interface. In other words, the menu. The logic is pretty simple here but requires several integers to get user choice and run the corresponding module. Additionally, we need to verify the user input just in case they enter the wrong thing by accident, which is the job of the validator I made above. The following picture shows all the options:

(This screenshot shows half of the options available to the user)


(The screenshot shows the other half of the options for the user)
Step 3: Read the file, put all words into an array
In the next step we need to read through the file, take out each word, and put them into an array for us to use the sorting algorithms.

The function which counts the word should follow the following rules:

Accept only letters and dashes
When there’s one dash between two words, consider the two words are one; when there are two dashes, consider the two words separated;

Following the rules above, reading the file line by line, and simply running through two while loops, I finished the function which helps me count the number of words in the file:


(The number at the end is the total amount of words in the file)

Now we have the number of words, which will be the size of the array, the next step will be putting the right amount of words from the file to the array. After lots of debugging and adjusting, I finally completed this module. This module can also be reused on the other options which require different sizes of data.

(The screenshot shows the running result of how I read each line and separated each word then put them into the array. Because this part of code is related to several arrays and the substr function, the index out of bounds error happened many times, it took me a lot of time to make it work as intended.)

Step 4: Sort the array
By now the preparation for the sorting is nearly done, it’s time to sort the words. I decided to start from the second option, which is letting the user choose one sorting algorithm and compare it with different sizes of data.

To avoid repetitive code, I made a function called sort() that accepts the sorting algorithm that the user picked, the array, and the size of the array as input, does the sorting, records the duration, calculates the average, and put the numbers into a vector which will be returned at the end.

Now we have the vector that contains all the runtime, we need a function that prints the table, so that’s what I did afterward.

And I implemented the function that allows users to choose to see the first or last 50 elements in the array.

In the end, the comparison (option 1) looks like this:

(The comparison table is shown at the bottom of the screenshot)


If the user wants to see the first 50 or last 50 elements of the array:

(First 50 elements has been printed on the screen)

(Last 50 elements have been printed on the screen)

And then the part which allows users to compare 2 different algorithms. For this part, all I need to do is :
read through the file and put all words into the array;
sort the array and record the run times as well as the average;
display on the screen.

So here is how it looks like:


(The screenshot shows the run down if the user choose to compare two algorithms)



Q&A:
Q: What input does the program use? Why?

A: The accepts integer inputs from the user because all the options are provided to user as integers, and the integers from user input will tell the program what operation to perform next.

Q: What variables will you need? Why?

A: Here are all the variables needed in the main function:

     @int article - the number that represents the article user choose
     @int sort1 and sort2 - the vector that stores the runtimes and average of an algorithm
     @int count_picked - a counter that counts how many algorithms the user has picked
     @int data_size_choice - the number that represents the data size that the user choose
     @int compare_choice - the number from user input that tells what kind of comparison they want to make
     @int algorithm_choice - the number from user input that tells what algorithm they want to use
     @int numOfWords - the integer from the user choice that stores the number of words in the array, it will also be the amount of words that will be sorted
     @std::string filename - the name of the file to open
     @std::vector<double> times, times2 - the two vectors that stores the 5 runtimes and well as the average
     
We need these variables to store the choices made by the user and perform the corresponding operation. We will also need variables like vector<double> times, times2 to store the runtime result and output to the screen.

Q: What constants, if any, will you need?
A: We don’t really need any constant for this program.

Q: What functions do you use? How did you decide what operations go into each function? 
A: Besides the five sorting algorithms that must be included and modified into the version of sorting strings and case non-sensitive, I will also need the following functions:
int validatedInt(int, int). I need this function to get me an integer within a certain range. This is to prevent the user from giving me the wrong type of input and end the program ungracefully by accident.
void printArray(std::string[], int). I need this function to ask if the user wants to print the first or last 50 elements in the array.
int countWord(std::string). I need this function to count the total amount of words in a file and therefore determine the size of the array that I’m going to sort later.
bool isLetter(char). I need this function to decide if I should skip this character when I’m reading through the file and getting words. 
std::vector<double> sort(int, std::string[], int). I need this function to help me decided which sorting algorithm to use and print out the resulting runtimes.
void printTable(std::vector<double>,int,int). I’ll need to print the time table for the runtimes
std::string stringToUpper(std::string). Since the comparison between strings are not case sensitive, I need this function to change all lower case letters in the string to uppercase before comparing.

Q: How do you decide that your program is complete?
A: When each option performs its functionality, especially from the first and last 50 elements of the sorted list generated from each algorithm, the program will be considered completed. We can also verify it by comparing the runtimes and see whether the runtimes matches the expected runtime by the big O notation.

Product:

The program will start with asking which article the user wants for this run:

(There are 3 articles available)

If the user gave the wrong input, the program will keep asking until the user gives a valid input:

(The input must be an integer within a certain range)


Then it will ask user for which type of comparison he wants the program to perform. If the user choose to compare two algorithms, the program will ask which two algorithms he wants to compare.

(The user chose the compare merge sort and quick sort)



And then the user got to choose to see the first or the last 50 elements in the sorted array.

(First 50 elements in the array. They are all a. Notice they are mixed with lower and upper cases, which shows that the comparison between strings is not case sensitive.)


(Last 50 elements in the array)

After this, the comparison table will be printed as follows:

(The screenshot shows that the runtime for quick sort and merge sort is similar, which matches their similar efficiency in big O notation.)

And then the program will ask if the user wants to choose another two to compare. If yes, the program will ask the user for another two algorithms and perform the same operation as above. If no, it will jump out of the loop and ask if the user wants to start over from the beginning.


The test case of option 1 (compare the performance of one algorithm on different data size)

(The screenshot shows the time for the 3 different data sizes and 5 run times in total. It will ask the user if he wants to the beginning and the end as well. The longest one (20000) will be used.)



Pitfalls:

The first pitfall I encounter is that c++ does not allow the function to return any arrays, which means my sorting functions cannot return the sorted array back into the main function and the same for the array that contains the runtimes. But with that said, the program still needs to allow the users to see the first and last fifty elements in the sorted list. To circumvent this, I made a separate function called sort() which will do all the sorting and asked for user options within the function, and then return the runtimes as a vector at the end.

Another problem that took a lot of time for me to solve is to take out the words and put them into the array. My starting idea was correct, but because I missed some conditions for my loops and operation, the function keeps going out of bound or gives me lots of characters that I didn’t want. I realized that it is really difficult for me to spot the mistake I made from the result of such a large amount of data, so I decided to use the function on a very small amount of data and solve the mistakes one by one by putting cout command everywhere as checkpoints. It makes things much easier to assemble the functions together after I make sure all of the works in a small amount of data.

Another mistake I made that took me quite a while to find is that I forgot the parameters of merge sort and quick sort function is a little bit different from the other three. The bubble, insertion and selection sort accepts the array and length as parameters, while the quick and merge sort accepts the array, the beginning index and the last index of the array as parameters. What I did was I put the length of the array as the last index, which is not correct because the length of an array is always equal to the index of the last element plus one. So I kept getting index out of bound error without knowing what caused this. I discussed this problem with a friend and he told me where the mistake is at because he made the same mistake too.


Possible improvement:

Q: What could you have done differently to improve your specific completion of this assignment? 

A: I could have read through the requirement more carefully and make sure I understand everything before I started to work on it. Because sometimes I realized I did the wrong thing after I spend a lot of time on it.

Additionally, for some reason, the apostrophe doesn’t go into the word even though I should have included it as a part of the string. I didn’t realize this mistake during the development of the program and it was found during the live demo.

Q: What could have been done differently to avoid some of the possible pitfalls in general, especially those pitfalls that seem to be common throughout your completion of different assignments? 

A: When I was trying to get the words in the file, I’ve spent a lot of time debugging the index out of bounds error. Also, since the file is large, it takes a lot of time to compile and test. Instead of waiting, I could have tested my functions with a smaller file. After making sure everything works as intended, then put it back to the main function to run it on the large file. 

Q: What could be improved about this assignment overall, for you to better demonstrate successful and mindful mastery of the programming concepts covered so far?


A: I think this lab is a good practice for us to review the algorithms that we’ve learned. It will also compare and present the performance of different algorithms on a large scale of data thus give us a better view of the efficiency of each algorithm. However, there are the following points that I believe can be improved:

The instruction may not be clear enough. My friends and I were confused on the following:
 Whether the sorting of words be case sensitive or not. It was clarified one day before we need to submit, I believe it should be added to the requirement.
How does the comparison table suppose to look like? We were hoping to have an example of how the table should look like. A picture will be really helpful and save us a lot of time working on the wrong output.

Too many options for the users. I understand this is absolutely doable and it’s always good to make the lab closer to real-world problems, but as a practice lab, it should focus more on the core since the time we have is limited. If we ended up spending most of our time on the user menu, read the files and all kinds of other options for the user instead of the core, which is comparing the efficiency of each algorithm, the lab will seem a little off-topic and inefficient as an exercise.

Therefore, I suggest the following modification to the lab:
clarify the lab regarding the two points I mentioned above, some pictures on how the result will look like. The work of each student may not be the same but the picture should present everything the lab wants us to have;
reduce the number of articles to one;
choose the same article for everyone, so that we can get to know if we are on the right track by checking the results we got from other people, including the number of words and runtimes of each algorithm;
