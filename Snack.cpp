#include <iostream>

class Snack{
public:
    double price;
    std::string name;
    int id, quanity;

    Snack();
    Snack(int ID, std::string Name, double Price, int Quanity);
    ~Snack();
};

Snack::Snack(){
    std::cout<<"Snack object created\n";
}

Snack::Snack(int ID, std::string Name, 
double Price, int Quanity){
    this->name = Name; this->price = Price; 
    this->quanity = Quanity;
    this->id = ID;
}

Snack::~Snack(){
    std::cout<<"Snack object destroyed\n";
}