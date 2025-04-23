#ifndef ADMIN_H
#define ADMIN_H

#include"User.h"
#include<iostream>

using namespace std;

class Admin: public User {
private:

public:
    Admin();
    Admin(string &, string &, bool &);

    void show_Menu() override;

};

#endif