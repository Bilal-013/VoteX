#include "../header/User.h"

User::User() : CNIC(""), password(""), isLoggedin(false), role("") {}

User::User(string& a, string& b, bool& c, string &d) :
    CNIC(a),
    password(b),
    isLoggedin(c), 
    role(d) {}

string User:: get_cnic() { return CNIC; }

string User:: get_password(){ return password; }

bool User:: get_login() { return isLoggedin; }

string User:: get_role(){ return role; }

void User:: set_role(string &a) {
    role = a;
}

void User:: set_login(bool &a) {
    isLoggedin = a;
}

void User:: Validate_login(string &a, string &b) {
    if(a == CNIC && b == password) isLoggedin = true;
    
    isLoggedin = false;
}