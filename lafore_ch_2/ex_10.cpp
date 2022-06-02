#include <iostream>
#include <iomanip>

// 1 pund       = 20 shillings  = 240 pence
// 1 shilling   = 12 pence
//
// 1 shilling   = 0.05 pound
// 1 pence      = 1 / 240

double convertShillings(int shillings) {
    return (1.0L / 20) * shillings;
}

double convertPence(int pence) {
    return (1.0L / (20 * 12)) * pence;
}

int main() {
    int pounds = 0,
        shillings = 0,
        pence = 0;

    std::cout << "Enter punds: ";
    std::cin >> pounds;
    std::cout << "Enter shillings: ";
    std::cin >> shillings;
    std::cout << "Enter pence: ";
    std::cin >> pence;

    double decimalPounds = pounds + convertShillings(shillings) + convertPence(pence);

    std::cout << "£" << pounds << '.' << shillings << '.' << pence
        << " = " << std::setprecision(2) << std::fixed << decimalPounds << std::endl;
        

    return 0;
}


