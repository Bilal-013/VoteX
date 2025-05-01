#include "../header/Admin.h"
#include <fstream>
#include <iomanip>
#include <sstream>
Admin::Admin() : User() {}

Admin::Admin(string &a, string &b, string &d) : User(a, b, d)
{
    validate_user();
}

void Admin::show_Menu()
{
    int x;
    cout << "\t\t\t\t\t====Admin Menu==== \n"
            "\t\t\t\t\t1. Register Voter/candidate. \n"
            "\t\t\t\t\t2. Update a Voter/Candidate. \n"
            "\t\t\t\t\t3. Remove a Voter/Candidate.\n"
            "\t\t\t\t\t4. Start Elections\n";
    cin >> x;
    switch (x)
    {
    case 1:
        int y;
        cout << "Add: \n1. Voter. \n2. Candidate. \n";
        cin >> y;
        if (y == 1)
        {
            add_voter();
        }
        else if (y == 2)
        {
            add_cand();
        }
        else
            cerr << "Enter a valid option...\n";
        break;

    case 2:
        int q;
        cout << "Update: \n1. Voter. \n2. Candidate. \n";
        cin >> q;
        if (q == 1)
        {
            update_voter();
        }
        else if (q == 2)
        {
            update_cand();
        }
        else
            cerr << "Enter a valid option...\n";
        break;

    case 3:
        int w;
        cout << "Remove: \n1. Voter. \n2. Candidate. \n";
        cin >> w;
        if (w == 1)
        {
            remove_voter();
        }
        else if (w == 2)
        {
            remove_cand();
        }
        else
            cerr << "Enter a valid option...\n";
        break;

    case 4:
        start_elections();
        break;

    default:
        cerr << "Please enter a valid choice (From 1-4)\n";
        break;
    }
}

void Admin::validate_user()
{
    string id, pas;
    fstream admin_log("admin.txt", ios ::in);
    if (admin_log.is_open())
    {
        while (getline(admin_log, id, '*') && getline(admin_log, pas))
        {
            if (id == CNIC && pas == password)
            {
                admin_log.close();
                isLoggedin = true;
            }
            else
                isLoggedin = false;
        }
        admin_log.close();
    }
}

void Admin::update_voter()
{
    string cnic;
    cout << "\nEnter CNIC of voter to update: ";
    cin >> cnic;

    ifstream inFile("voter.txt");
    ofstream tempFile("temp.txt");

    if (!inFile || !tempFile)
    {
        cerr << "\nError: Unable to open files!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(inFile, line))
    {
        if (line.substr(0, line.find('*')) == cnic)
        {
            found = true;

            string password, name, region, age, dob;

            cout << "Enter new Password: ";
            cin >> password;

            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter new Region: ";
            getline(cin, region);

            cout << "Enter new Age: ";
            cin >> age;

            cout << "Enter new Date of Birth (DD/MM/YYYY): ";
            cin >> dob;

            tempFile << cnic << "*" << password << "*" << name << "*" << region << "*" << age << "*" << dob << endl;
        }
        else
        {
            tempFile << line << endl;
        }
    }

    inFile.close();
    tempFile.close();

    remove("voter.txt");
    rename("temp.txt", "voter.txt");

    if (found)
    {
        cout << "\nVoter with CNIC " << cnic << " updated successfully!" << endl;
    }
    else
    {
        cout << "\nNo voter found with CNIC " << cnic << endl;
    }
}

void Admin::update_cand()
{
    string cnic;
    cout << "\nEnter CNIC of candidate to update: ";
    cin >> cnic;

    ifstream inFile("candidate.txt");
    ofstream tempFile("temp.txt");

    if (!inFile || !tempFile)
    {
        cerr << "\nError: Unable to open files!" << endl;
        return;
    }

    string line;
    bool found = false;
    string votecount;

    while (getline(inFile, line))
    {
        if (line.substr(0, line.find('*')) == cnic)
        {
            found = true;
            string currentLine = line;
            for (int i = 0; i < 6; i++)
            {
                size_t pos = currentLine.find('*');
                if (pos != string::npos)
                {
                    currentLine = currentLine.substr(pos + 1);
                }
            }
            votecount = currentLine;
            string password, name, region, age, dob;

            cout << "Enter new Password: ";
            cin >> password;

            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter new Region: ";
            getline(cin, region);

            cout << "Enter new Age: ";
            cin >> age;

            cout << "Enter new Date of Birth (DD/MM/YYYY): ";
            cin >> dob;

            tempFile << cnic << "*" << password << "*" << name << "*" << region << "*" << age << "*" << dob << "*" << votecount << endl;
        }
        else
        {
            tempFile << line << endl;
        }
    }

    inFile.close();
    tempFile.close();

    remove("candidate.txt");
    rename("temp.txt", "candidate.txt");

    if (found)
    {
        cout << "\nCandidate with CNIC " << cnic << " updated successfully!" << endl;
    }
    else
    {
        cout << "\nNo candidate found with CNIC " << cnic << endl;
    }
}

void Admin::start_elections()
{
    cout << "\nElections have been started!\n";
}

void Admin::add_voter()
{
    int numVoters;
    cout << "\nHow many voters do you want to add? ";
    cin >> numVoters;

    for (int i = 0; i < numVoters; i++)
    {
        cout << "\nAdding voter " << (i + 1) << " of " << numVoters << endl;
        string cnic, password, name, region, age, dob;

        cout << "Enter CNIC (without dashes): ";
        cin >> cnic;

        cout << "Enter Password: ";
        cin >> password;

        cout << "Enter Name: ";
        cin.ignore();
        if (i > 0)
            cin.clear();
        getline(cin, name);

        cout << "Enter Region: ";
        getline(cin, region);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Date of Birth (DD/MM/YYYY): ";
        cin >> dob;

        ifstream checkFile("voter.txt");
        if (!checkFile.good())
        {
            ofstream createFile("voter.txt");
            createFile.close();
            cout << "Voter file created." << endl;
        }
        checkFile.close();

        ifstream checkCnic("voter.txt");
        string line;
        bool cnicExists = false;

        while (getline(checkCnic, line))
        {
            if (cnic == line.substr(0, line.find('*')))
            {
                cnicExists = true;
                break;
            }
        }
        checkCnic.close();

        if (cnicExists)
        {
            cout << "\nError: A voter with this CNIC already exists!" << endl;
            i--;
            continue;
        }

        ofstream voterFile("voter.txt", ios::app);
        if (voterFile.is_open())
        {
            voterFile << cnic << "*" << password << "*" << name << "*" << region << "*" << age << "*" << dob << endl;
            voterFile.close();
            cout << "\nVoter added successfully!" << endl;
        }
        else
        {
            cerr << "\nError: Unable to open voter file!" << endl;
            i--;
        }
    }
}

void Admin::add_cand()
{
    int numCandidates;
    cout << "\nHow many candidates do you want to add? ";
    cin >> numCandidates;

    for (int i = 0; i < numCandidates; i++)
    {
        cout << "\nAdding candidate " << (i + 1) << " of " << numCandidates << endl;
        string cnic, password, name, region, age, dob, votecount;

        cout << "Enter CNIC (without dashes): ";
        cin >> cnic;

        cout << "Enter Password: ";
        cin >> password;

        cout << "Enter Name: ";
        cin.ignore();
        if (i > 0)
            cin.clear();
        getline(cin, name);

        cout << "Enter Region: ";
        getline(cin, region);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Date of Birth (DD/MM/YYYY): ";
        cin >> dob;

        votecount = "0";

        ifstream checkFile("candidate.txt");
        if (!checkFile.good())
        {
            ofstream createFile("candidate.txt");
            createFile.close();
            cout << "Candidate file created." << endl;
        }
        checkFile.close();

        ifstream checkCnic("candidate.txt");
        string line;
        bool cnicExists = false;

        while (getline(checkCnic, line))
        {
            if (cnic == line.substr(0, line.find('*')))
            {
                cnicExists = true;
                break;
            }
        }
        checkCnic.close();

        if (cnicExists)
        {
            cout << "\nError: A candidate with this CNIC already exists!" << endl;
            i--;
            continue;
        }

        ofstream candFile("candidate.txt", ios::app);
        if (candFile.is_open())
        {
            candFile << cnic << "*" << password << "*" << name << "*" << region << "*" << age << "*" << dob << "*" << votecount << endl;
            candFile.close();
            cout << "\nCandidate added successfully!" << endl;
        }
        else
        {
            cerr << "\nError: Unable to open candidate file!" << endl;
            i--;
        }
    }
}

void Admin::remove_voter()
{
    int choice;
    cout << "\nDo you want to remove:\n";
    cout << "1. Single voter\n";
    cout << "2. Multiple voters\n";
    cin >> choice;

    if (choice == 1)
    {
        string cnic;
        cout << "\nEnter CNIC of voter to remove: ";
        cin >> cnic;

        ifstream inFile("voter.txt");
        ofstream tempFile("temp.txt");

        if (!inFile || !tempFile)
        {
            cerr << "\nError: Unable to open files!" << endl;
            return;
        }

        string line;
        bool found = false;

        while (getline(inFile, line))
        {
            if (line.substr(0, line.find('*')) == cnic)
            {
                found = true;
                continue;
            }
            tempFile << line << endl;
        }

        inFile.close();
        tempFile.close();

        remove("voter.txt");
        rename("temp.txt", "voter.txt");

        if (found)
        {
            cout << "\nVoter with CNIC " << cnic << " removed successfully!" << endl;
        }
        else
        {
            cout << "\nNo voter found with CNIC " << cnic << endl;
        }
    }
    else if (choice == 2)
    {
        int count;
        cout << "\nEnter number of voters to remove: ";
        cin >> count;

        string *cnics = new string[count];
        cout << "\nEnter CNICs of voters to remove:" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << "CNIC " << (i + 1) << ": ";
            cin >> cnics[i];
        }

        ifstream inFile("voter.txt");
        ofstream tempFile("temp.txt");

        if (!inFile || !tempFile)
        {
            cerr << "\nError: Unable to open files!" << endl;
            delete[] cnics;
            return;
        }

        string line;
        int removed = 0;

        while (getline(inFile, line))
        {
            string currentCnic = line.substr(0, line.find('*'));
            bool shouldRemove = false;

            for (int i = 0; i < count; i++)
            {
                if (currentCnic == cnics[i])
                {
                    shouldRemove = true;
                    removed++;
                    break;
                }
            }

            if (!shouldRemove)
            {
                tempFile << line << endl;
            }
        }

        inFile.close();
        tempFile.close();

        remove("voter.txt");
        rename("temp.txt", "voter.txt");

        cout << "\nRemoved " << removed << " voters successfully!" << endl;
        if (removed < count)
        {
            cout << "Note: " << (count - removed) << " CNICs were not found." << endl;
        }

        delete[] cnics;
    }
    else
    {
        cout << "\nInvalid choice. Returning to menu." << endl;
    }
}

void Admin::remove_cand()
{
    int choice;
    cout << "\nDo you want to remove:\n";
    cout << "1. Single candidate\n";
    cout << "2. Multiple candidates\n";
    cin >> choice;

    if (choice == 1)
    {
        string cnic;
        cout << "\nEnter CNIC of candidate to remove: ";
        cin >> cnic;

        ifstream inFile("candidate.txt");
        ofstream tempFile("temp.txt");

        if (!inFile || !tempFile)
        {
            cerr << "\nError: Unable to open files!" << endl;
            return;
        }

        string line;
        bool found = false;

        while (getline(inFile, line))
        {
            if (line.substr(0, line.find('*')) == cnic)
            {
                found = true;
                continue;
            }
            tempFile << line << endl;
        }

        inFile.close();
        tempFile.close();

        remove("candidate.txt");
        rename("temp.txt", "candidate.txt");

        if (found)
        {
            cout << "\nCandidate with CNIC " << cnic << " removed successfully!" << endl;
        }
        else
        {
            cout << "\nNo candidate found with CNIC " << cnic << endl;
        }
    }
    else if (choice == 2)
    {
        int count;
        cout << "\nEnter number of candidates to remove: ";
        cin >> count;

        string *cnics = new string[count];
        cout << "\nEnter CNICs of candidates to remove:" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << "CNIC " << (i + 1) << ": ";
            cin >> cnics[i];
        }

        ifstream inFile("candidate.txt");
        ofstream tempFile("temp.txt");

        if (!inFile || !tempFile)
        {
            cerr << "\nError: Unable to open files!" << endl;
            delete[] cnics;
            return;
        }

        string line;
        int removed = 0;

        while (getline(inFile, line))
        {
            string currentCnic = line.substr(0, line.find('*'));
            bool shouldRemove = false;

            for (int i = 0; i < count; i++)
            {
                if (currentCnic == cnics[i])
                {
                    shouldRemove = true;
                    removed++;
                    break;
                }
            }

            if (!shouldRemove)
            {
                tempFile << line << endl;
            }
        }

        inFile.close();
        tempFile.close();

        remove("candidate.txt");
        rename("temp.txt", "candidate.txt");

        cout << "\nRemoved " << removed << " candidates successfully!" << endl;
        if (removed < count)
        {
            cout << "Note: " << (count - removed) << " CNICs were not found." << endl;
        }

        delete[] cnics;
    }
    else
    {
        cout << "\nInvalid choice. Returning to menu." << endl;
    }
}

void Admin::show_all_candidates()
{
    fstream show_cand("candidate.txt", ios::in);

    if (!show_cand.is_open())
    {
        cerr << "\nError: Unable to open candidate file!" << endl;
        return;
    }
    string line;
    bool empty = true;
    if (show_cand.is_open())
    {
        cout << "\n======================= CANDIDATE LIST =======================\n";
        cout << left << setw(15) << "CNIC" << setw(20) << "Name" << setw(15)
            << "Region" << setw(8) << "Age" << setw(12) << "DOB" << setw(10) << "Votes" << endl;
        cout << "==============================================================\n";
        while (getline(show_cand, line))
        {
            empty = false;
            istringstream ss(line);
            string cnic, password, name, region, age, dob, votes;

            getline(ss, cnic, '*');
            getline(ss, password, '*');
            getline(ss, name, '*');
            getline(ss, region, '*');
            getline(ss, age, '*');
            getline(ss, dob, '*');
            getline(ss, votes, '*');

            cout << left << setw(15) << cnic << setw(20) << name << setw(15)
                 << region << setw(8) << age << setw(12) << dob << setw(10) << votes << endl;
        }
    if (empty)
    {
        cout << "\nNo candidates are currently registered in the system.\n";
    }
        cout << "==============================================================\n";
        show_cand.close();
    }
}

void Admin::show_all_voters() {

    fstream show_voters("voter.txt", ios::in);
    if (!show_voters.is_open())
    {
        cerr << "\nError: Unable to open voter file!" << endl;
        return;
    }

    string line;
    bool empty = true;
    
    cout << "\n========================= VOTER LIST =========================\n";
    cout << left << setw(15) << "CNIC" << setw(20) << "Name" << setw(15)
         << "Region" << setw(8) << "Age" << setw(12) << "DOB" << endl;
    cout << "=============================================================\n";
    
    while (getline(show_voters, line))
    {
        empty = false;
        istringstream ss(line);
        string cnic, password, name, region, age, dob;

        getline(ss, cnic, '*');
        getline(ss, password, '*');
        getline(ss, name, '*');
        getline(ss, region, '*');
        getline(ss, age, '*');
        getline(ss, dob, '*');

        cout << left << setw(15) << cnic << setw(20) << name << setw(15)
             << region << setw(8) << age << setw(12) << dob << endl;
    }
    
    if (empty)
    {
        cout << "\nNo voters are currently registered in the system.\n";
    }
    
    cout << "=============================================================\n";
    show_voters.close();
}

void Admin::show_eligible_voters() {
    fstream show_voters("voter.txt", ios::in);
    if (!show_voters.is_open())
    {
        cerr << "\nError: Unable to open voter file!" << endl;
        return;
    }

    string line;
    bool empty = true;
    
    cout << "\n======================= ELIGIBLE VOTER LIST =======================\n";
    cout << left << setw(15) << "CNIC" << setw(20) << "Name" << setw(15)
         << "Region" << setw(8) << "Age" << setw(12) << "DOB" << setw(15) << "Status" << endl;
    cout << "=================================================================\n";
    
    while (getline(show_voters, line))
    {
        empty = false;
        istringstream ss(line);
        string cnic, password, name, region, age, dob;

        getline(ss, cnic, '*');
        getline(ss, password, '*');
        getline(ss, name, '*');
        getline(ss, region, '*');
        getline(ss, age, '*');
        getline(ss, dob, '*');

        int ageValue = stoi(age);
        string status = (ageValue >= 18) ? "Eligible" : "Not Eligible";
        
        cout << left << setw(15) << cnic << setw(20) << name << setw(15)
             << region << setw(8) << age << setw(12) << dob << setw(15) << status << endl;
    }
    
    if (empty)
    {
        cout << "\nNo voters are currently registered in the system.\n";
    }
    
    cout << "=================================================================\n";
    show_voters.close();
}