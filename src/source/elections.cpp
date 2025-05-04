#include"elections.h"
int Candidates::id = 0;
Candidates::Candidates(string cn , string pn):candidatename(cn), partyname(pn), candidateid(++id) {
	votes = 0; 
}
Candidates::Candidates(string cn, string pn, int v, int cid) :candidatename(cn), partyname(pn), votes(v),candidateid(cid) {}
int Candidates::countvotes() {
	return votes;
}
void Candidates::incrementvotes() {
	votes++;
}
string Candidates::getcandidatename() {
	return candidatename;
}
string Candidates::getpartyname() {
	return partyname;
}
int Candidates::getcandidateid() {
	return candidateid;
}

elections::elections() {
	electiontype = "none";
	electionstartdate = "none";
	electionenddate = "none";
	active = false;
	candidateno = 0;
	maxcandidates = 10;
	candidates = new Candidates[maxcandidates];
	;
}
elections::elections(string et, string esd , string eed ,int maxcan):
    electiontype(et), electionstartdate(esd), electionenddate(eed),maxcandidates(maxcan), active(false),candidateno(0) {
	candidates = new Candidates[maxcandidates];
	;
}
void elections::addcandidate(string cn, string pn) {
	if (candidateno < maxcandidates) {
		candidates[candidateno] = Candidates(cn, pn);
		candidateno++;
		cout << "Candidate added: " << cn << endl;
	}
	else {
		cout << "Max Candidate limit reached\n";
	}
}
void elections::castevote(int cid) {
	if (active == false) {
		cout << "Elections ended or not started yet \n";
		return;
	}
	for (int i = 0; i <candidateno; i++) {
		if (candidates[i].getcandidateid() == cid) {
			candidates[i].incrementvotes();
			cout << "Vote casted for " << candidates[i].getcandidatename() <<endl;
			return;
		}
	}
	cout << "Candidate not found\n";
}
void elections::loadfromfile(string filename) {
		ifstream outfile(filename) ;
	if (!outfile.is_open()) {
		cout << "cannot open file\n";
		return;
	}
	getline(outfile,electiontype,'\n');
    getline(outfile, electionstartdate, '\n');
	getline(outfile, electionenddate, '\n');
	outfile >> candidateno;
	for (int i = 0; i < candidateno; i++) {
		string cn, pn;
		int v,cid;
		outfile >> cn;
		outfile >> pn ;
		outfile >> v;
		outfile >> cid;
		candidates[i] = Candidates(cn, pn,v,cid);
	}
	outfile.close();
}
void elections::savetofile(string filename) {

	ofstream infile (filename);
	if (!infile.is_open()) {
		cout << "cannot open file\n";
		return;
	}
		infile << electiontype << endl;
		infile << electionstartdate << endl;
		infile << electionenddate << endl;
		infile << candidateno<<endl;
		for (int i = 0; i < candidateno; i++) {
			infile << candidates[i].getcandidatename() << "\n" << candidates[i].getpartyname()<<"\n" << candidates[i].countvotes() <<"\n"<<candidates[i].getcandidateid()<< endl;
		}
		infile.close();
	}
void elections::loadcandidatesfromfile(string filename) {
	ifstream infile(filename);
	if (!infile.is_open()) {
		cout << "cannot open file\n";
		return;
	}
	string cn, pn;
	int cid;
	for(int i=0;i<candidateno;i++)
	{
		infile >> cid;
		infile.ignore();
		getline(infile, cn, '\n');
		getline(infile, pn, '\n');
		candidates[i] = Candidates(cn, pn, 0,cid);
	}
	infile.close();
}
void elections::savecandidatestofile(string filename) {
	ofstream outfile(filename);
	if (!outfile.is_open()) {
		cout << "cannot open file\n";
		return;
	}
	for (int i = 0; i < candidateno; i++)
	{
		outfile << candidates[i].getcandidateid() << endl;
		outfile << candidates[i].getcandidatename() << endl;
		outfile << candidates[i].getpartyname() << endl;
	}
	outfile.close();
}
void elections::showcandidates(string filename) {
	loadcandidatesfromfile(filename);
	cout << "Candidates:\n";
	cout << "-------------------------------------------------------\n";
	for (int i = 0; i < candidateno; i++) {
		cout << candidates[i].getcandidateid()<<endl;
		cout << candidates[i].getcandidatename()<<endl;
		cout << candidates[i].getpartyname()<<endl;
	}
}
elections::~elections() {
	delete[] candidates;
}

nationalelections::nationalelections(string et, string esd, string eed, int noc):elections(et,esd,eed,noc) {}
void nationalelections::electionsstart() {
	active = true;
	cout << "National elections started\n";
}
void nationalelections::electionsend() {
	active = false;
	cout << "National elections ended\n";
}
void nationalelections::loadfromfile() {
	elections::loadfromfile("nationalelections.txt");	
}
void nationalelections::savetofile() {
	elections::savetofile("nationalelections.txt");
}
void nationalelections::addcandidate() {
	string cn, pn;
	cout << "Enter candidate name: ";
	cin >> cn;
	cout << "Enter party name: ";
	cin >> pn;
	elections::addcandidate(cn, pn);
	savecandidatestofile("nationalcandidates.txt");
	nationalelections::savetofile();
}
void nationalelections::castevote() {
	showcandidates("nationalcandidates.txt");
	int id;
	cout << "Enter candidate id: ";
	cin >> id;
	elections::castevote(id);
	nationalelections::savetofile();
}
void nationalelections::showresults() {
	nationalelections::loadfromfile();
	cout << "Election Results:\n";
	for (int i = 0; i < candidateno; i++) {
		cout << "-------------------------------------------------------\n";
		cout << "Candidate: " << candidates[i].getcandidatename() << "\n Party: " << candidates[i].getpartyname() << "\n Votes: " << candidates[i].countvotes() << endl;
	}
}
localelections::localelections(string et, string esd, string eed, int noc,string r) :elections(et, esd, eed, noc),reigon(r) {}
void localelections::electionsstart() {
	active = true;
	cout << "Local elections started\n";
}
void localelections::electionsend() {
	active = false;
	cout << "Local elections ended\n";
}
void localelections::loadfromfile() {
	elections::loadfromfile("localelections.txt");
}
void localelections::savetofile() {
	elections::savetofile("localelections.txt");
}
void localelections::addcandidate() {
	string cn, pn;
	cout << "Enter candidate name: ";
	cin >> cn;
	cout << "Enter party name: ";
	cin >> pn;
	elections::addcandidate(cn, pn);
	savecandidatestofile("localcandidates.txt");
	localelections::savetofile();
}
void localelections::castevote() {
	showcandidates("localcandidates.txt");
	showcandidates("localelections.txt");
	int id;
	cout << "Enter candidate id: ";
	cin >> id;
	elections::castevote(id);
	localelections::savetofile();
}
void localelections::showresults() {
	localelections::loadfromfile();
	cout << "Election Results:\n";
	for (int i = 0; i < candidateno; i++) {
		cout << "-------------------------------------------------------------------------\n";
		cout << "\nCandidate: " << candidates[i].getcandidatename() << "\n Party: " << candidates[i].getpartyname() << "\n Votes: " << candidates[i].countvotes() << endl;
	}
}
void menu(){
        cout << "\n===== Online Voting System =====\n";
        cout << "1. Start National Election\n";
        cout << "2. Add National Candidate\n";
		cout << "3. See Candidates for National Election\n";
        cout << "4. Cast National Vote\n";
        cout << "5. End National Election & Show Results\n";
        cout << "6. Start Local Election\n";
        cout << "7. Add Local Candidate\n";
        cout << "8. See Candidates for Local Elections\n";
        cout << "9. Cast Local Vote\n";
        cout << "10. End Local Election & Show Results\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
}