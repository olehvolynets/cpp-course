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
    double decimalPounds = 0.0L;
    std::cout << "Enter decimal punds: ";
    std::cin >> decimalPounds;

    int pounds = static_cast<int>(decimalPounds);
    double rest = decimalPounds - pounds;

    int shillings = rest / 0.05f;
    rest -= convertShillings(shillings);

    int pence = rest / (1.0L / 240);

    std::cout << "Equivalent in old notation: £"
        << pounds << '.' << shillings << '.' << pence << std::endl;

    return 0;
}


