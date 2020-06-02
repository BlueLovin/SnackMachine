#include <vector>
#include "User.cpp"

class Machine{
private:
    bool isPoweredOn;
public:
    Machine();
    //~Machine();
    //void CreateSnacks();
    void MainMenu();
    void BuyItem(int id);
    void DepositMoney(int id);
    bool WantsToContinue();
};
struct SnackStruct{
public:
    Snack *chips = new Snack(1,"Lay's Chips", 2.0, 6);           //1
    Snack *skittles = new Snack(2,"Skittles", 1.0, 12);          //2
    Snack *hersheysBar = new Snack(3,"Hershey's Bar", 2.5, 19);  //3
    Snack *honeyBuns = new Snack(4,"Honey Buns", 1.75, 4);       //4
    std::vector<Snack> SnackList = {*chips, *skittles, *hersheysBar,
    *honeyBuns};
};
SnackStruct s; // GLOBAL SNACKSTRUCT INSTANCE

Machine::Machine(){
    std::cout<<"Machine Created\n";
}
// Machine::~Machine(){
//     std::cout<<"Machine Destroyed\n";
// }
// void Machine::CreateSnacks(){       //CREATE SNACK OBJECTS
//     std::cout<<"CreateSnacks called\n";
// }
void Machine::MainMenu(){           //DISPLAY ALL SNACKS AND THEIR PRICES AND QUANITIES
    system("clear");
    std::cout<<"Welcome to the Snack Machine.\n";
    std::cout<<"YOUR CURRENT BALANCE IS: $" << u.GetBalance() 
    << std::endl << std::endl;
    for(int i = 0; i < 4; i++){
        std::cout<<"["<< s.SnackList[i].id << "]"<<
        s.SnackList[i].name << " -- $" << 
        s.SnackList[i].price << " Quanity: "<<
        s.SnackList[i].quanity <<std::endl;
    }
    std::string inputID;
    std::cout<<"\nPlease select an item ID: ";
    std::cin >> inputID;
    int inputInt = stoi(inputID);

    if(inputInt < 0 || inputInt > 4){ //INVALID INPUT
        system("clear");
        std::cout<<"Invalid! Try again! [PRESS ENTER]\n";
        std::cin.clear();
        std::cin.ignore(); std::cin.get();
    }
    else if (s.SnackList[inputInt - 1].quanity > 0 //IF IN STOCK AND USER HAS SUFFICIENT FUNDS
    && u.GetBalance() >= s.SnackList[inputInt - 1].price){
        BuyItem(inputInt - 1);
    }
    else if(s.SnackList[inputInt - 1].quanity > 0
    && u.GetBalance() < s.SnackList[inputInt - 1].price){
        system("clear");
        std::cout<<"INSUFFICIENT FUNDS!\n";
        DepositMoney(inputInt);
    }
    else{ //WHEN QUANITY IS 0
        std::cout<<"OUT OF STOCK\n\n";
    }
}
void Machine::BuyItem(int id){      //CALLED WHEN USER BUYS A SNACK
    system("clear");
    std::cout<< "\nThank you, enjoy your "<<s.SnackList[id].name << std::endl;
    s.SnackList[id].quanity--;
    *u.ptrBalance -= s.SnackList[id].price;
    std::cout<<"Your balance is now: $" << u.GetBalance() << std::endl;
    Inventory.push_back(s.SnackList[id]);
}

void Machine::DepositMoney(int id){ //CALLED IF A USER IS SHORT ON MONEY
    double owed = (s.SnackList[id - 1].price) - u.GetBalance();     //CALCULATES AMOUNT OWED
    std::cout<< "You owe: $" << owed << "\nHow much would you like to deposit?\n$";
    double deposit;
    std::cin.clear(); std::cin.ignore();

    std::cin >> deposit;
    
    if(deposit > 0 && deposit < 500){
        *u.ptrBalance += deposit;
    }
    else{
        std::cout<<"Invalid input!\n";
        std::cin.clear(); std::cin.ignore();
        std::cin.get();
    }
    

}
bool Machine::WantsToContinue(){
    std::cout<<"\n\nEnter 'inv' if you want to view your inventory.\n";
    std::cout<<"Would you like to return to the main menu? y/n\n\n";
    std::string input; std::cin >> input;
    if(input == "y")
        return true;
    else if(input == "inv"){
        u.ViewInventory();
        return true;
    }
    else
        return false;
}