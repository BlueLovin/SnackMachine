#include "Snack.cpp"
class User{
private:
    double Balance = 0;
    //inventory list
public:
    double *ptrBalance = &Balance;
    User();
    User(double Bal);
    // ~User();
    
    double GetBalance();
    void ViewInventory();
    
    void AddToInventory(Snack snack);
};
static std::vector<Snack> Inventory = {};
User u;
User::User(){

}
User::User(double Bal){
    this->Balance = Bal;
}
// User::~User(){
//     std::cout<<"User object destroyed\n"; 
// }
double User::GetBalance(){
    return Balance;
}
void User::ViewInventory(){
    system("clear");
    std::cout<<"Your inventory: ";

    for(int i = 0; i < Inventory.size(); i++){//loops through user inventory and displays
        if(i == Inventory.size() - 1)
            std::cout<< Inventory[i].name << std::endl;
        else
            std::cout<< Inventory[i].name << ", ";
    }

    std::cout<<"Press [ENTER] to continue.\n";
    std::cin.clear();
    std::cin.ignore();
    std::cin.get();
}
void AddToInventory(Snack snack){
    
}