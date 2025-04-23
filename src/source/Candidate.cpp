#include "../header/Candidate.h"

Candidate::Candidate(): User() {}

Candidate:: Candidate(string& a, string &b, bool &c): User(a, b, c) {}

void Candidate::show_Menu()
{
    int x;
    cout << "\t\t\t\t\t====Candidate Menu==== \n"
            "\t\t\t\t\t1. View announced elections. \n"
            "\t\t\t\t\t2. View my votes. \n"
            "\t\t\t\t\t3. View my profile. \n"
            "\t\t\t\t\t4. Select/Update my party. \n";
    cin >> x;
    switch (x)
    {
    case 1:
        cout << "Viewing elections...\n";
        break;

    case 2:
        cout << "Viewing votes...\n";
        break;

    case 3:
        cout << "Viewing your profile...\n";
        break;

    case 4:
        cout << "Available parties...\n";
        break;

    default:
        cerr << "Please enter a valid choice (From 1-4)....\n";
        break;
    }
}
