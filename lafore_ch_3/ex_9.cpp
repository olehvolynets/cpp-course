#include <iostream>

int main(int argc, char** argv)
{
    using namespace std;
    int seats, guests;
    seats = guests = 0;

    cout << "Number of seats: "; cin >> seats;
    cout << "Number of guests: "; cin >> guests;

    int combinations = 1;
    for (; seats > 0; --seats)
    {
        combinations *= guests--;
    }

    cout << "Result: " << combinations << endl;

    return 0;
}
