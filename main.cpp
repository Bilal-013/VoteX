#include"src/header/Admin.h"
#include"src/header/Candidate.h"
#include"src/header/User.h"
#include"src/header/Voter.h"

void admins_up(string &, string &);


int main() {

    int var;
    cout << "\t\t\t\t\t====Main Menu===="
         << "\t\t\t\t\tHow would you like to login\n"
         << "\t\t\t\t\t1. Admin\n"
         << "\t\t\t\t\t2. Candidate\n"
         << "\t\t\t\t\t3. User\n"
         << "\t\t\t\t\tPlease Enter you choice(1-4): ";
    cin >> var;
    string Cnic, Pass;
    switch(var) {
        case 1:
            admins_up(Cnic, Pass);
            break;
        
        case 2: 
            cout << "candidate Panal\n";
            break;

        case 3:
            cout << "User Panal\n";
            break;
        
        default:
            cerr << "Enter a correct choice(1-3)\n";
            break;
    }

}

void admins_up(string &a, string &b) {
    string role = "admin";
    cout << "Enter your CNIC:  ";
    cin >> a;
    cout << "Enter your Password:  ";
    cin >> b; 
    Admin A1(a, b, role);
    a = A1.get_cnic();
    b = A1.get_password();
    if(A1.get_login()) {
        A1.show_Menu();
    }
    else 
        cerr << "Enter a valid CNIC or password...\n";
    
}
