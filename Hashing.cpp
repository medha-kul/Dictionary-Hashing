#include <cstdlib>
#include <iostream> //std::cout
#include <string>
#include <fstream> //std::ifstream
#include <algorithm> // for std::transform to convert to lowercase
#include "Hashing.h"
#include "TimeInterval.h"

int main() {

    Hashing hashingObj;
    std::string word_line;
    int idx; //index variable
    std::ifstream file("Dictionary.txt"); //reading from Dictionary.txt
    int read_line = 0;  //read every line of Dictionary.txt and assign the line to variable
    while(file>>word_line){   //each string gets hash function and inserts value in index
      if ( (int) word_line[0] < 97 ) {
        // convert to lowercase
        std::transform(word_line.begin(), word_line.end(), word_line.begin(), ::tolower);
        hashingObj.increValue(idx, word_line);
        } // end if
        idx = hashingObj.hashing_idx(word_line);
        hashingObj.increValue(idx, word_line); //add new string or word to the bucket
        std::cout << std::endl;
        std::cout << " variable line: " << read_line << std::endl;
        read_line++;
    }
    file.close();
    for(int i =0; i < 41; i++){
        hashingObj.printOutput(i);
    }
    std::string input;   //ask user for an input to search through Dictionary.txt
    std::cout <<  std::endl;
    std::cout << "Enter the word for searching: ";
    std::cin >> input;
    std::cout << std::endl;
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    hashingObj.searchInfo(input);
    return 0;
}

//function to print the table.
void Hashing::printOutput(int idx)
{
    Node* Term = Hashing_Table[idx];
    std::cout << std::endl;
    std::cout << "value of index: " << idx << std::endl;

    while(Term != NULL){
        std::cout << "";
        std::cout << Term->info << std::endl;
        std::cout << "----------" << std::endl;
        Term = Term->top;
    }
}

Hashing::Hashing()
{
    for(int i = 0; i < t_Size; i++){
        Hashing_Table[i] = new Node;
        Hashing_Table[i]->info = "";
        Hashing_Table[i]->top = NULL;
    }
}

/*Hashing function: use the first two letters, for example if you have who, what, and were as words. Who and What have same first two letters,
it will hashed in one bucket and who, what & were will be hashed in different bucket. */
int Hashing::hashing_idx(std::string element){
    int h2 = 0;
    int h = 0;
    int h1 = 0;
    int idx;
    h1 = (int)element[0]; //converting the character values to ascii int values, use of casting
    //Here the uppercase A is 65 and lowercase a is 97.
    h2 = (int)element[1];

    //calculate the second hash
    if(h2 < 97){
        h = h + 32;
    }
    //calculate the first hash
    if(h1 < 97){
        h1 = h1 + 32;
    }


    /* double hashing is collision resolving tecnhique, taking random coefficents which are prime less than table size*/
    h = 5*(h1) + 11*(h2);
    //we repeat the collision by increasing i when collision occurs.
    //Table size is prime number, taking prime number for the double hashing minimizes collisions
    idx = h % t_Size;
    return idx;  //collision occurs, return the calculated index from double hashing
}

/* function to increment the pointer till NULL, for comparing the first two letters,
use strings as character arrays, output the first two same letters. Print the number of seconds taken*/
void Hashing::searchInfo(std::string input)
{
    int element = hashing_idx(input);
    bool keepGoing = false;
    std::string word;
    Node* Term = Hashing_Table[element];
    while(Term != NULL)
    {
      if(Term->info == input){
            keepGoing = true;
        }
            Term = Term->top;
    }
    if(keepGoing == true)
    {
        TimeInterval changeTime;
        changeTime.start();
        std::cout << "\nTrue" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "------------------------------" <<std::endl;
        std::cout << "Suggested Words: " << std::endl;
        Node* Term2 = Hashing_Table[element];
        while(Term2 != NULL){
            if(input[0] == Term2->info[0] && input[1] == Term2->info[1])
            {
                if(input != Term2->info){
                    std::cout << Term2->info << std::endl;
                }
            }
            Term2 = Term2->top;
        }
        changeTime.stop();
        std::cout<< std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << std::endl;
        std::cout << changeTime.GetInterval() << " micro seconds is the execution time\n" << std::endl;
    }
    else
    {
        TimeInterval changeTime;
        changeTime.start();
        std::cout << "------------------------" <<std::endl;
        std::cout << "\nFalse" << std::endl;
        std::cout << "However, similar words are " << std::endl;
        Node* Term2 = Hashing_Table[element];
        while(Term2 != NULL){
            if(input[0] == Term2->info[0] && input[1] == Term2->info[1])
            {
                if(input != Term2->info){
                    std::cout << Term2->info << std::endl;
                }
            }
            Term2 = Term2->top;
        }
        changeTime.stop();
        std::cout<< std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << std::endl;
        std::cout << changeTime.GetInterval() << " micro seconds is the execution time\n" << std::endl;
    }
}

//function to add the word to the bucket

void Hashing::increValue(int idx, std::string info)
{
    if(Hashing_Table[idx]->info == "")
    {
        Hashing_Table[idx]->info = info;
    }
    else
    {
        Node* Term = Hashing_Table[idx]; //term is pointer to an array containing all the buckets
        //hashing by chaining, node gets added to linked list in the Hashing_table bucket if it is full of data
        Node* M = new Node;
        M->info = info;
        M->top = NULL;
        while(Term->top != NULL)
        {
            Term = Term->top;
        }
        Term->top = M;
    }
}
