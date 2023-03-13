#ifndef HASHING_H
#define HASHING_H

#include <iostream>
#include <string>

class Hashing{
    protected:
        struct Node{
            Node* top;
            std::string info;

        };
        static const int t_Size = 41; //take prime number for table size, better for double hashing
        Node* Hashing_Table[t_Size];
      public:
        Hashing();
        int hashing_idx(std::string element);
        void searchInfo(std::string input);
        void printOutput(int idx);
        void increValue(int idx, std::string info);
};
#endif /*HASHING_H*/
