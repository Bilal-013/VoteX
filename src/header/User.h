#ifndef USER_H
#define USER_H
#include<string>
#include<fstream>
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

    User(string&, string&, string &);

    virtual void show_Menu() = 0;

    virtual void validate_user() = 0;
};
#endif