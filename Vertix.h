#include <iostream>
#include <string>		
using namespace std;
#ifndef VERTIX_H
#define VERTIX_H
class Vertix {
      private: 
        int weight; 
        string label;
    public:
        Vertix();
        Vertix(int weitght, string label);
        ~Vertix();
        void setWeight(int weight);
        void setLabel(string label);
        void setVertix(Vertix vertix);
        int getWeight();
        string getLabel();
        void showVertix();
};

#endif