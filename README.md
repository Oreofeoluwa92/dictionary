This C++ program analyzes a text file and generates various statistics about the words and letters within it.
It calculates the frequency of each letter (both lowercase and uppercase), identifies unique words, and provides a histogram for visualizing letter frequencies.

Word and Letter Count: Counts the total number of words, letters, and lines in the input file.
Letter Frequency: Calculates the frequency of each letter (both lowercase and uppercase) and displays the frequencies with histograms.
Word Frequency: Lists unique words and their corresponding frequencies.
Longest Words: Tracks and displays the longest words in the file.

Program Details
The program uses various STL containers such as:
std::set for storing unique words.
std::map for tracking letter and word frequencies.
std::priority_queue for identifying the longest words.
It ensures that only alphabetic characters are considered as valid letters or words.
Symbols, numbers, and non-alphabetic characters are ignored in word and letter frequency calculations.

The program reads data from an input file named input.txt.
Program can be complied on any IDE Environment.
