#include "../header/Admin.h"
#include <fstream>

Admin::Admin() : User() {}

Admin::Admin(string &a, string &b, string &d) : User(a, b, d)  {}

void Admin::show_Menu()
{
    int x;
    cout << "\t\t\t\t\t====Admin Menu==== \n"
            "\t\t\t\t\t1. Register User/candidate. \n"
            "\t\t\t\t\t2. Update a User/Candidate. \n"
            "\t\t\t\t\t3. Remove a User/Candidate.\n"
            "\t\t\t\t\t4. Start Elections\n";
    cin >> x;
    switch (x)
    {
    case 1:
        int y;
        cout << "Add: \n1. User. \n2. Candidate. \n";
        cin >> y;
        if (y == 1)
        {
            cout << "Adding User\n";
        }
        else if (y == 2)
        {
            cout << "Adding Candidate\n";
        }
        else
            cerr << "Enter a valid option...\n";
        break;

    case 2:
        cout << "Update someone\n";
        break;

    case 3:
        cout << "Removing user\n";
        break;

    case 4:
        cout << "Start elections\n";
        break;

    default:
        cerr << "Please enter a valid choice (From 1-4)\n";
        break;
    }
}

void Admin::validate_user() {
    string id, pas;
    fstream admin_log("admin.txt", ios :: in); 
    // if(!admin_log) {
    //     admin_log.open("admin.txt", ios::out | ios::app);
    // }
    if (admin_log.is_open()) {
        while (getline(admin_log, id, '*') && getline(admin_log, pas)) {
            if (id == CNIC && pas == password) {
                admin_log.close();
                isLoggedin = true;
            }
            else isLoggedin = false;
        }
        admin_log.close();
    }
}