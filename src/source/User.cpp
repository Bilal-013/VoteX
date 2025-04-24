#include "../header/User.h"

User::User() : CNIC(""), password(""), isLoggedin(false), role("") {}

User::User(string& a, string& b, string &d) :
    CNIC(a),
    password(b), 
    role(d) {}

string User:: get_cnic() { return CNIC; }

string User:: get_password(){ return password; }

bool User:: get_login() { return isLoggedin; }

string User:: get_role(){ return role; }

void User:: set_role(string &a) {
    role = a;
}