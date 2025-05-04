#include<iostream>
#include<string>
#include<fstream>

using namespace std;
class Candidates {
private:
    static int id;
	int candidateid;
    string candidatename;
    string partyname;
    int votes;
public:
    Candidates(string cn="", string pn="");
	Candidates(string cn, string pn, int v, int cid);
    int countvotes();
    void incrementvotes();
    string getcandidatename();
    string getpartyname();
	int getcandidateid();
    
};

class elections {
protected:
    string electiontype;
    string electionstartdate;
    string electionenddate;
    bool active;
    int candidateno;
    int  maxcandidates;
    Candidates *candidates;
public:
    elections();
    elections(string et, string esd, string eed, int maxcan);
    virtual void electionsstart() = 0;
    virtual void electionsend() = 0;
	void addcandidate(string cn, string pn);
	void castevote(int id);
    void loadfromfile(string filename);
    void savetofile(string filename);
	virtual void showresults() = 0;
    void loadcandidatesfromfile(string filename);
    void savecandidatestofile(string filename);
    void showcandidates(string filename);
    ~elections();
};
class nationalelections :public elections {
public:
    nationalelections(string et, string esd, string eed, int noc);
    void electionsstart();
    void electionsend();
    void loadfromfile();
    void savetofile();
    void addcandidate();
    void castevote();
    void showresults();
};
class localelections :public elections {
    string reigon;
public:
    localelections(string et, string esd, string eed, int noc, string r);
    void electionsstart();
    void electionsend();
    void loadfromfile();
    void savetofile();
    void addcandidate();
    void castevote();
    void showresults();
}; 
void menu();