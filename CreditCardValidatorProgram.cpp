#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

int getDigit(const int number);
int sumOddDigits(const std::string cardNumber);
int sumEvenDigits(const std::string cardNumber);

int main(){

    //will utilize the Luhn Algorithm
    /*
    1. Double every second digit from right to left
    If the doubled number is 2 digits split them
    2. Add all single digits from step 1
    3. Add all odd number digits from right to left
    4. Sum of results from 2 & 3
    5. If step 4 is divisible by 10, # is valid
    
    ex. 6011 0009 9013 9424
        6 1  0 0  9 1  9 2 
        12 2  0 0  18  2  18  4
        1 2  2  0 0  1 8 2  1 8 4
        29

        6011 0009 9013 9424
         0 1  0 9  0 3  4 4
        21

        21 + 29 = 50
        50 / 10 = 5 = Valid
    */

    std::string cardNumber;
    int result = 0;
    char cont;

    do{
    std::cout << "Enter a Credit Card Number: " << '\n';
    std::cin >> cardNumber;

    result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);

    if(result % 10 == 0){
        std::cout << cardNumber << " is Valid!!!" << '\n';
        std::cout << "Do you want to continue?(Y/N): " << '\n';
        std::cin >> cont;
        cont = toupper(cont);
    }
    else{
        std::cout << cardNumber << " is not valid" << '\n';
        std::cout << "Do you want to continue?(Y/N): " << '\n';
        std::cin >> cont;
        cont = toupper(cont);
    }}while(cont == 'Y');

    return 0;
}
int getDigit(const int number){
    /*
    ex.
    9 * 2
    18 / 10
    1 % 10
    1
    8 + 1
    9    
    */
    return number % 10 + (number / 10 % 10);
}
int sumOddDigits(const std::string cardNumber){
    int sum = 0;

    for(int i = cardNumber.size() - 1; i >= 0; i -= 2){
        sum += getDigit((cardNumber[i] - '0'));

    }

    return sum;
}
int sumEvenDigits(const std::string cardNumber){
    int sum = 0;

    for(int i = cardNumber.size() - 2; i >= 0; i -= 2){
        sum += getDigit((cardNumber[i] - '0') * 2);

    }

    return sum;
}