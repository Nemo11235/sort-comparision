#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <algorithm>

using std::ifstream;
using std::ofstream;
using namespace std::chrono;

// forward declaration of all functions
void bubbleSort(std::string[], int);
void selectionSort(std::string[], int);
void insertionSort(std::string[], int);
void mergeSort(std::string[],int,int);
void merge(std::string[],int,int,int);
void quickSort(std::string[],int,int);
int partition(std::string[],int,int);
int validatedInt(int, int);
void printArray(std::string[], int);
int countWord(std::string);
bool isLetter(char);
std::vector<double> sort(int, std::string[], int);
void printTable(std::vector<double>,int,int);
std::vector<double> sortOne(int, std::string[], int, int);
std::string stringToUpper(std::string);


int main()
{
    /* declare variables needed
     @int article - the number that represents the article user choose
     @int sort1 and sort2 - the vector that stores the runtimes and average of an algorithm
     @int count_picked - a counter that counts how many algorithms the user has picked
     @int data_size_choice - the number that represents the data size that the user choose
     @int compare_choice - the number from user input that tells what kind of comparison they want to make
     @int algorithm_choice - the number from user input that tells what algorithm they want to use
     @int numOfWords - the integer from the user choice that storest the number of words in the array, it will also be the amount of words that will be sorted
     @std::string filename - the name of the file to open
     @std::vector<double> times, times2 - the two vectors that stores the 5 runtimes and well as the average
     
     */
    
    int article, sort1 = 0, sort2 = 0, count_picked, option = 0, compare_choice, algorithm_choice, numOfWords;
    std::vector<double> times, times2;
    std::string filename;

    
    // The starting of the menu, loop until the user wants to quit
    while(option != 2)
    {
        // choose an article and set the file path
        std::cout << "Please select an article: " << std::endl;
        std::cout << "1. Antony and Cleopatra" << std::endl << "2. As You Like It" << std::endl << "3. Coriolanus" << std::endl;
        article = validatedInt(1 , 3);
        if(article == 1){ filename = "Antony and Cleopatra.txt";
        }else if(article == 2){ filename = "As You Like It.txt";
        }else{ filename = "Coriolanus.txt";}   
        
        // choose what to compare
        std::cout << "Do you want to compare two algorithms or just one algorithms with different sizes of data? " << std::endl <<
        "1. Compare two algorithms" << std::endl <<
        "2. Using one algorithm to sort different sizes of data " << std::endl;
        compare_choice = validatedInt(1, 2);
        option = 0;
        // operation if the user choose the first option
        if(compare_choice == 2)
        {
            // while loop that allows user to repeat
            while(option != 2)
            {
                // choose an algorithm
                std::cout << "Please slection the algoritm you want to use to sort different sizes of data: " << std::endl;
                std::cout << "1. Bubble Sort" << std::endl <<
                "2. Selection Sort" << std::endl <<
                "3. Insertion Sort" << std::endl <<
                "4. Merge Sort" << std::endl <<
                "5. Quick Sort" << std::endl;
                algorithm_choice = validatedInt(1,5);
                
                std::cout << std::setw(14) << std::left << "Data Size" << std::setw(10) << std::left << "Time  1" << std::setw(10) << std::left << "Time  2" << std::setw(10) << std::left << "Time  3" << std::setw(10) << std::left <<  "Time  4" << std::setw(10) << std::left << "Time  5" << std::setw(10) << std::left << "Average" << std::endl;
                
                for(int i = 0; i < 3; i++)
                {
                    if(i == 0){numOfWords = 5000;}
                    else if(i == 1){numOfWords = 10000;}
                    else{numOfWords = 20000;}
                    // open the file and read the file, put words into the array
                    std::string words[numOfWords];
                    int index = 0;
                    ifstream infile;
                    infile.open(filename);
                    // check if the file is openned
                    if(!infile.is_open()) { std::cout << "file not found" << std::endl; }
                    else
                    {
                        // read the file and put them into the array
                        std::string line;
                        bool have_word;
                        while(!infile.eof())
                        {
                            getline(infile, line);
                            for(int i = 0; i < line.length(); i++)
                            {
                                have_word = false;
                                // skip charactors until a letter has been found
                                while(!isLetter(line[i]) && i < line.length()) { i++; }
                                // get the starting and ending index of the word
                                int start = i;
                                while(i < line.length() && (isLetter(line[i]) || line[i] == '\'' || (line[i] == '-' && line[i+1] != '-')))
                                {
                                   have_word = true;
                                    i++;
                                }
                                int stop = i;
                                if(have_word)
                                {
                                    if(index < numOfWords)
                                        words[index++] = line.substr(start, stop-start);
                                }
                            }
                        }
                        infile.close();
                    }
                    // print the time table
                    
                    times = sortOne(algorithm_choice, words, numOfWords, i);
                }
                // ask if the user wants to repeat
                std::cout << "Do you want choose another algorithm?" << std::endl <<
                "1. Yes" << std::endl <<
                "2. No" << std::endl;
                option = validatedInt(1, 2);
            }
        }
        else
        {
            option = 0;
            // choose two algorithms
            while(option != 2)
            {
                // counter that keeps track of how many algorithm has been picked
                count_picked = 0;
                // repeat until user picked two algorithm
                while(count_picked < 2)
                {
                    if(count_picked == 0)
                        std::cout << "Please slection the first algorithm:" << std::endl;
                    else
                        std::cout << "Please slection the second algorithm:" << std::endl;
                    std::cout << "1. Bubble Sort" << std::endl <<
                    "2. Selection Sort" << std::endl <<
                    "3. Insertion Sort" << std::endl <<
                    "4. Merge Sort" << std::endl <<
                    "5. Quick Sort" << std::endl;
                    
                    if(count_picked == 0) { sort1 = validatedInt(1,6); }
                    else { sort2 = validatedInt(1,6); }
                    count_picked++;
                }
                
                // read the file and put words into the array
                numOfWords = countWord(filename);
                std::string words[numOfWords];
                // open the file and read the file, put words into the array
                int index = 0;
                ifstream infile;
                infile.open(filename);
                // check if the file is openned
                if(!infile.is_open()) { std::cout << "file not found" << std::endl; }
                else
                {
                    std::cout << "file openned" << std::endl;
                    
                    // read the file and put them into the array
                    std::string line;
                    bool have_word;
                    while(!infile.eof())
                    {
                        getline(infile, line);
                        for(int i = 0; i < line.length(); i++)
                        {
                            have_word = false;
                            // skip charactors until a letter has been found
                            while(!isLetter(line[i]) && i < line.length()) { i++; }
                            // get the starting and ending index of the word
                            int start = i;
                            while(i < line.length() && (isLetter(line[i]) || line[i] == '\'' || (line[i] == '-' && line[i+1] != '-')))
                            {
                               have_word = true;
                                i++;
                            }
                            int stop = i;
                            if(have_word)
                            {
                                words[index++] = line.substr(start, stop-start);
                            }
                        }
                    }
                    infile.close();
                }
                times = sort(sort1, words, numOfWords);
                times2 = sort(sort2, words, numOfWords);
                std::cout << std::setw(14) << std::left << "Algorithm" << std::setw(10) << std::left << "Time  1" << std::setw(10) << std::left << "Time  2" << std::setw(10) << std::left << "Time  3" << std::setw(10) << std::left <<  "Time  4" << std::setw(10) << std::left << "Time  5" << std::setw(10) << std::left << "Average" << std::endl;
                printTable(times, sort1, 0);
                printTable(times2, sort2, 0);
                
                
                std::cout << std::endl << "Do you want choose choose another two algorithms?" << std::endl <<
                "1. Yes" << std::endl <<
                "2. No" << std::endl;
                option = validatedInt(1, 2);
            }
        }
        
        
        std::cout << "Do you want to start over?" << std::endl <<
        "1. Yes" << std::endl <<
        "2. No" << std::endl;
        option = validatedInt(1, 2);
    }
    return 0;
}


// This is a function that sorts a string array using bubble sort
void bubbleSort(std::string arr[], int size)
{
    bool notSorted = true;
    while(notSorted)
    {
        notSorted = false;
        for(int i = 0; i < size - 1; i++)
        {
            if(stringToUpper(arr[i]) > stringToUpper(arr[i + 1]))
            {
                notSorted = true;
                std::string temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        size--;
    }
}

// This is a function that sorts a string array using selection sort
void selectionSort(std::string arr[], int size)
{
    int min_pos, i, j;
    for(i = 0; i < size-1; i++)
    {
        min_pos = i;
        for(j = i + 1; j < size; j++)
        {
            if(stringToUpper(arr[min_pos]) > stringToUpper(arr[j])) { min_pos = j;}
        }
        if(min_pos != i)
        {
            std::string temp = arr[i];
            arr[i] = arr[min_pos];
            arr[min_pos] = temp;
        }
    }
    
}

// This is a function that sorts a string array using insertion sort
void insertionSort(std::string arr[], int size)
{
    for(int i = 1; i < size; i++)
    {
        std::string next = arr[i];
        int j = i;
        while(j > 0 && stringToUpper(arr[j - 1]) > stringToUpper(next))
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = next;
    }
}

/* This is a function that accepts a range as input and return a validated interger within the range. It will make sure only an input within range will be returned, and only integers are allowed */
int validatedInt(int a, int b)
{
    int input;
    std::cin >> input;
    while(input < a || input > b || std::cin.fail())
    {
        std::cout << "Invalid option, please enter a number from " << a << " to " << b << ": " << std::endl;
        std::cin.clear();
        std::cin.ignore(999999, '\n');
        std::cin >> input;
    }
    return input;
}

// This is a function that helps merge sort perform its function
void merge(std::string arr[], int from, int mid, int to)
{
   int n = to - from + 1;
   std::string *b = new std::string[n];

   int i1 = from;
   int i2 = mid + 1;
   int j = 0;
  
   while (i1 <= mid && i2 <= to)
   {
      if (stringToUpper(arr[i1]) < stringToUpper(arr[i2]))
      {
         b[j] = arr[i1];
         i1++;
      }
      else
      {
         b[j] = arr[i2];
         i2++;
      }
      j++;
   }

   while (i1 <= mid)
   {
      b[j] = arr[i1];
      i1++;
      j++;
   }
    
   while (i2 <= to)
   {
      b[j] = arr[i2];
      i2++;
      j++;
   }

   for (j = 0; j < n; j++) { arr[from + j] = b[j]; }

   delete[] b;
}

// This is a function that sorts a string array using merge sort
void mergeSort(std::string arr[], int from, int to)
{
   if (from == to) { return; }
   int mid = (from + to) / 2;
  
   mergeSort(arr, from, mid);
   mergeSort(arr, mid + 1, to);
   merge(arr, from, mid, to);
}

// This is a function that helps quick sort perform its function
int partition(std::string a[], int from, int to)
{
   int pivot = from;
   int i = from - 1;
   int j = to + 1;
   while (i < j)
   {
      i++; while (stringToUpper(a[i]) < stringToUpper(a[pivot])) { i++; }
      j--; while (stringToUpper(a[j]) > stringToUpper(a[pivot])) { j--; }
      if (i < j)
      {swap(a[i], a[j]);}
   }
   return j;
}

// This is a function that sorts a string array using quick sort
void quickSort(std::string a[], int from, int to)
{
   if (from >= to) { return; }
   int p = partition(a, from, to);
   quickSort(a, from, p);
   quickSort(a, p + 1, to);
}


// This is a function that checks if the letter is one of the 26 letters, upper or lower case
bool isLetter(char c) { return((c >= 65 && c <= 90) || (c >= 97 && c <= 122));}

// // This is a function that counts the numebr of english words within a document
int countWord(std::string filename)
{
    int numOfWords = 0;
    ifstream infile;
    bool have_word;
    
    infile.open(filename);
    if(!infile.is_open()) { std::cout << "file not found" << std::endl; }
    else
    {
        std::cout << "file openned" << std::endl;
        std::string line;
        
        while(!infile.eof())
        {
            getline(infile, line);
            for(int i = 0; i < line.length(); i++)
            {
                have_word = false;
                while(!isLetter(line[i])){ i++; }
                while(i < line.length() && (isLetter(line[i]) || line[i] == '\'' || (line[i] == '-' && line[i+1] != '-'))) { i++; have_word = true;}
                if(have_word){ numOfWords++; }
            }
        }
        infile.close();
        std::cout << "Number of words: " << numOfWords << std::endl;
        return numOfWords;
    }
    return 0;
}

/* This function will accept an integer which represents the sort we used, an array we want to sort, and the size of the array as input. The function will make a copy of the array input, and sort it 5 times, get the run time and average, then put all the duration in double data type and return them all as a vector<double> */
std::vector<double> sort(int sort, std::string arr[], int size)
{
    std::vector<double> times;
    std::string algoName;
    std::string copy[size];
    double totalTime = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int i = 0; i < size; i++) { copy[i] = arr[i]; }
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        if(sort == 1){ bubbleSort(copy, size);
        }else if(sort == 2){ selectionSort(copy, size);
        }else if(sort == 3){ insertionSort(copy, size);
        }else if(sort == 4){ mergeSort(copy, 0, size - 1);
        }else{ quickSort(copy, 0, size - 1); }
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
        totalTime += time_span.count();
        times.push_back(time_span.count());
    }
    times.push_back(totalTime/5);
    std::cout << "Sorted succesfully!" << std::endl;
    printArray(copy, size);
    return times;
}

// This is a funtion that allows user to see the first 50 or last 50 elements in the array.
void printArray(std::string arr[], int size)
{
    std::cout << "Would you like to see the beginning or the end of the sorted array?" << std::endl;
    std::cout << "1. Show me first 50" << std::endl;
    std::cout << "2. Show me last 50" << std::endl;
    std::cout << "3. No thanks" << std::endl;
    
    int option = validatedInt(1, 3);
    while(option != 3)
    {
        if(option == 1){
            for(int i = 0; i < 50; i++) { std::cout << arr[i] << std::endl; }
        }else if (option == 2){
            for(int j = size - 50; j < size; j++) { std::cout << arr[j] << std::endl; }
        }
        std::cout << "Do you want to see something else?" << std::endl;
        std::cout << "1. Show me first 50" << std::endl;
        std::cout << "2. Show me last 50" << std::endl;
        std::cout << "3. No thanks" << std::endl;
        option = validatedInt(1, 3);
    }
}

/* Brief description: This function will receive a vector<double> which contains 6 times and print out the comparison table
 
 @std::String algoName - string that tells what algorithm the user picked
 @vector<double> vec - vector that contains the 5 runtimes in doubles as well as the average
 @int sort - the number that tells what sorting algorithm the user picekd
 */
void printTable(std::vector<double> vec, int sort, int size)
{
    std::string algoName;
    if(sort == 1){ algoName = "Bubble sort:";
    }else if(sort == 2){ algoName = "Selection sort:";
    }else if(sort == 3){ algoName = "Insertion sort:";
    }else if(sort == 4){ algoName = "Merge sort:";
    }else{ algoName = "Quick sort:"; }
    if(size != 0) {algoName = std::to_string(size); }
    std::cout << std::setw(14) << std::left << algoName;
    std::cout << std::setprecision(5) << std::fixed;
    for(int i = 0; i < vec.size() - 1; i++) { std::cout << std::setw(10) << std::left << vec[i]; }
    std::cout << vec[vec.size() - 1] << std::endl;
}

// the sort funtion to sort different sizes of array
std::vector<double> sortOne(int sort, std::string arr[], int size, int print)
{
    std::vector<double> times;
    std::string algoName;
    std::string copy[size];
    double totalTime = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int i = 0; i < size; i++) { copy[i] = arr[i]; }
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        if(sort == 1){ bubbleSort(copy, size);
        }else if(sort == 2){ selectionSort(copy, size);
        }else if(sort == 3){ insertionSort(copy, size);
        }else if(sort == 4){ mergeSort(copy, 0, size - 1);
        }else{ quickSort(copy, 0, size - 1); }
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
        totalTime += time_span.count();
        times.push_back(time_span.count());
    }
    times.push_back(totalTime/5);
    printTable(times, sort, size);
    if (print == 2) {printArray(copy, size);}
    return times;
}

/* this funtion will return a stirng that changed all the lower case letter in the input
array to upper case */
std::string stringToUpper(std::string s){
   for(int i = 0; i < s.length(); i++)
   {
       s[i] = toupper(s[i]);
    }
    return s;
}

