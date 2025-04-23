#ifndef USER_H
#define USER_H
#include<string>

using namespace std;

class User {
protected:
    string CNIC;
    bool isLoggedin;
    string password;
    string role;
public:
    User();

    string get_cnic();

    string get_password();

    bool get_login();

    void set_login(bool &);

    string get_role();

    void set_role(string &);

    User(string&, string&, bool&, string &);

    virtual void show_Menu() = 0;

void Validate_login(string &, string &);


};
#endif