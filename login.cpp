#include <iostream>
#include <string.h>
#include <fstream>

int begin();
int reg();
void log();

int main() {

    int option;
    do
    {
        option = begin();
        if(option == 1)
            option = reg();
        if(option == 2)
            log();
    } while (option != 0);

    exit(1);    

}

int begin(){
    system("clear");
    std::cout << "\n######## REGISTER & LOGIN SYSTEM ########\n" << std::endl;
    std::cout << "Please choose one of the following options:" << std::endl << "0. Exit\n" << "1. Register\n" << "2. Log in\n" << std::endl;
    int option = 0;

    do
    {
        std::cout << "Enter your option: ";
        std::cin >> option;
    } while (option > 2);

    return option;   
}

int reg(){
    system("clear");
    std::string pass;
    std::cout << "\n\n";

    do
    {
        std::cout << "Enter your password (or 0 to go back): ";
        std::cin >> pass;
        if(pass == "0")
            return 3;
    } while (pass.length() < 8);

    std::fstream myFile;
    myFile.open("passwords.txt", std::ios::app);

    if(myFile.is_open()){
        myFile << pass << std::endl;
        myFile.close();
    }
    return 3;
}

void log(){
    system("clear");

    std::string pass;
    std::string comp;


    std::fstream myFile;
    myFile.open("passwords.txt", std::ios::in);

    int control = 1;

    do
    {
        std::cout << "\nPlease enter your password to log in: ";
        std::cin >> pass;
        
        if(myFile.is_open()) {
            while (std::getline(myFile, comp))
            {
                if(pass == comp){
                    std::cout << "Welcome!\n";
                    control = 0;
                    myFile.close();
                    exit(1);
                }
            }   
            if (control == 1)
            {
                std::cout << "Password not found!\n";
            }
            
            
        }
    } while (control == 1);

}