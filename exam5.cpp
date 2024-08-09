//Zach Brown
//CS2
//Exam 5 Programming portion

#include <iostream>
#include <string>
#include "Die.h"

void emailValidator(std::string& email);
void promptEmail();

template <class T>
void consoleLog(T input);

int recursiveRolls(Die& die, int num);


int main() {
    
    srand(time(0));
    
    //.1
    promptEmail();

    //2.
    int num1 = 13;
    double num2 = 459.65;
    std::string myWord = "Apple";
    Die die(132);

    consoleLog(num1);
    consoleLog(num2);
    consoleLog(myWord);
    consoleLog(die);

    //3.
    Die die2(365);

    std::cout << recursiveRolls(die2, 24) << std::endl;
    std::cout << recursiveRolls(die2, 13) << std::endl;
    std::cout << recursiveRolls(die2, 87) << std::endl;

}



void emailValidator(std::string& email) {
    int count = 0;
    int positionOfAtSymbol = 0;
    bool atSymbolFound = false;
    bool dotInEmail = false;

    for (int i = 0; i < email.length(); ++i) {

        char ch = email[i];

        if (ch == '@') {
            count++;
            if (count == 1) {
                positionOfAtSymbol = i;
                atSymbolFound = true;
            }
            else {
                throw std::string("Email address must only have one @ sign.");
            }
        }
        if (atSymbolFound && ch == '.' && i > positionOfAtSymbol) {
            dotInEmail = true;
        }
    }
    if (!atSymbolFound) {
        throw std::string("Email address must have one @ sign.");
    }
    if (positionOfAtSymbol == 0) {
        throw std::string("Email address cannot start with an @ sign.");
    }
    if (!dotInEmail) {
        throw std::string("Email address must have a '.' after the @ sign.");
    }
}


void promptEmail() {
    std::string email;
    bool Valid = false;

    while (!Valid) {
        std::cout << "Enter your email address: ";
        std::getline(std::cin, email);

        try {
            emailValidator(email);
            Valid = true;
            std::cout << "Email address accepted." << std::endl;
        }
        catch (std::string& e) {
            std::cout << "Error: " << e << std::endl;
            std::cout << "Try again." << std::endl;
        }
    }
}

template <class T>
void consoleLog(T input) {
    std::cout << input << std::endl;
}

int recursiveRolls(Die& die, int num) {

    int rollCount = 1;
    int roll = die.roll();

    if (roll == num) {
        return rollCount;
    }
    else {
        return rollCount + recursiveRolls(die, num);    

    }

}