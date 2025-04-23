#ifndef USER_H
#define USER_H
#include<string>

using namespace std;

class User {
protected:
    string username;
    bool isLoggedin;
    string password;
public:
    User();

    User(string&, string&, bool&);

    virtual void show_Menu() = 0;

};
#endif