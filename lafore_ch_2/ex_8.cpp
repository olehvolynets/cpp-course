#include <iomanip>
#include <iostream>

int main() {
  using namespace std;

  long pop1 = 2425785, pop2 = 47, pop3 = 9671;

  cout << setw(8) << "LOCATION" << setw(12) << "POPulation" << endl
       << setw(8) << "Portcity" << setw(12) << setfill('.') << pop1 << setfill(' ') << endl
       << setw(8) << "Hightwn"  << setw(12) << setfill('.') << pop2 << setfill(' ') << endl
       << setw(8) << "Lowvile"  << setw(12) << setfill('.') << pop3 << setfill(' ') << endl;

  return 0;
}
