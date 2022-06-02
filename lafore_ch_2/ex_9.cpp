#include <iostream>
#include <iomanip>

int main() {
    using namespace std;

    int a = 0, b = 0, c = 0, d = 0;
    char dummy;

    cout << "Enter first fraction: ";
    cin >> a >> dummy >> b;
    cout << "Enter second fraction: ";
    cin >> c >> dummy >> d;

    int sumDivisible = a * d + b * c;
    int sumDivisor = b * d;

    cout << "Sum: " << sumDivisible << '/' << sumDivisor << endl;
 
    return 0;
}
