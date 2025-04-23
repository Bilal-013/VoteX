#ifndef CANDIDATE_H
#define CANDIDATE_H

#include"User.h"
#include<iostream>

class Candidate: public User {
private:

public:
    Candidate();

    Candidate(string &, string &, bool &);

    void show_Menu() override;
};


#endif