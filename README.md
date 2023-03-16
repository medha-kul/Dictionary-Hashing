
##Dictionary-Hashing Program


This program reads words from a text file named "Dictionary.txt", hashes them based on their first two characters, and inserts them into a hash table. The program then prompts the user to enter a word to search for in the hash table. If the word is found, the program prints "True" and suggests other words in the same bucket (words that have the same first two characters as the searched word). If the word is not found, the program prints "False".

The main function of the program first initializes an instance of the "Hashing" class and declares some variables for file reading and word indexing. It then reads each line of the text file, hashes the word, and inserts it into the hash table using the "increValue" function. After the hash table is populated, the program prompts the user to enter a word to search for and converts it to lowercase using the "transform" function from the "algorithm" library. Finally, the "searchInfo" function is called to search for the word in the hash table and suggest other words if the word is found.

The "Hashing" class contains several functions. The constructor initializes an array of nodes (which will be the hash table) and assigns each node a default value of an empty string and a null top pointer. The "hashing_idx" function hashes a string based on its first two characters using a double hashing collision resolution technique. The "increValue" function adds a new node to the hash table bucket if the bucket already contains a node. The "printOutput" function prints the values of the nodes in a particular bucket. The "searchInfo" function searches for a word in the hash table and suggests other words if the word is found.

Overall, the program is a basic implementation of a hash table with collision resolution and searching functionality. It allows users to efficiently search for words in a large dictionary by using hash functions to index and store the words.
