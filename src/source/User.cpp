#include "../header/User.h"

User::User() : username(""), password(""), isLoggedin(false) {}

User::User(string& a, string& b, bool& c) :
    username(a),
    password(b),
    isLoggedin(c) {}