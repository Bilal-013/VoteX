#include "../header/Voter.h"

Voter::Voter() : User() {}

Voter::Voter(string &a, string &b, bool &c, string &d) : User(a, b, c, d) {}

void Voter::show_Menu()
{
    int x;
    cout << "\t\t\t\t\t====Voter Menu===\n"
            "\t\t\t\t\t1. Cast votes\n"
            "\t\t\t\t\t2. View Results\n"
            "\t\t\t\t\t3. Logout\n"
            "\t\t\t\t\tEnter correct choice(1-3):  ";
    cin >> x;
    switch (x)
    {
    case 1:
        cout << "cast votes under development";
        break;
    case 2:
        cout << "View Results under development";
        break;
    case 3:
        cout << "Logging out...";
        break;
    default:
        cerr << "Invalid choice. Please try again.";
        break;
    }
}