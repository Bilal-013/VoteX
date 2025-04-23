#ifndef VOTER_H
#define VOTER_H
#include"User.h"
#include<iostream>
class Voter: public User {
private:

public:
    Voter();

    Voter(string &, string &, bool &);

    

    void show_Menu() override;
};

#endif