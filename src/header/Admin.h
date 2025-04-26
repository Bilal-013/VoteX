#ifndef ADMIN_H
#define ADMIN_H

#include"User.h"
#include<iostream>

using namespace std;

class Admin: public User {
private:
    fstream admin_log;
    fstream candidate_log;
    fstream voter_log;
    void validate_user() override;
public:
    Admin();
    
    Admin(string &, string &, string &);
    
    void show_Menu() override; 

    void start_elections();

    void add_voter();

    void add_cand();

    void remove_voter();

    void remove_cand();

    void update_voter();

    void update_cand();
};

#endif