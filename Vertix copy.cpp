#include <iostream>
#include <string>		
using namespace std;

class Vertix {
    private: 
        int weight; 
        string label; 
    public:
        Vertix(int weight, string label){
            this -> weight = weight;
            this -> label = label;
        }

        void setWeight(int weight){
            this -> weight = weight;
        }
        void setLabel(string label){
            this -> label = label;
        }

        void setVertix(Vertix vertix){
            this -> weight = vertix.getWeight();
            this -> label = vertix.getLabel();
        };

        int getWeight(){
            return this -> weight;
        }

        string getLabel(){
            return this -> label;
        }

        void setVertix(Vertix vertix){
            this -> weight = vertix.getWeight();
            this -> label = vertix.getLabel();
        };
        
        void showVertix(){
            cout << "weight :" << weight << "label: " << label << endl;
        }
        

};

int main(){
    Vertix vertix(2,"3");
    vertix.showVertix();
    return 0;
}