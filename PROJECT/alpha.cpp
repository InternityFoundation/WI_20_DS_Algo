#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>
#include <random>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

vector<string> timestamp;
vector<string> username;
vector<string> faceoffId;
vector<string> fullname;
vector<string> college;
vector<string> semester;
vector<string> company;
vector<string> dslevel;
vector<string> city;
vector<pair<int,string>> dataa;
vector<int> t1;

int no_of_users = 0;

void write_pair(string user1, string user2)
{
    string s = "{" + user1 + "," + user2 + "}\n";
    ofstream op;
    op.open("output.txt", ios::app);
    if (op.is_open())
    {
        op << s;
    }
    else
    {
        cout << "Not able to open output.txt";
    }
    op.close();
}
void write_three(string user1,string user2,string user3){
    string s = "{" + user1 + "," + user2 + "," + user3 + "}\n";
    ofstream op;
    op.open("output.txt", ios::app);
    if (op.is_open())
    {
        op << s;
    }
    else
    {
        cout << "Not able to open output.txt";
    }
    op.close();
}

void delete_content()
{
    ofstream ofs;
    ofs.open("output.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

map<string, string> getinfo(vector<std::string> &input, std::string searched)
{

    map<string, string> M;
    int i;
    for (i = 0; i < input.size(); i++)
    {
        if (input[i] == searched)
        {
            M["Timestamp"] = timestamp[i];
            M["Username"] = username[i];
            M["FaceoffId"] = faceoffId[i];
            M["Fullname"] = fullname[i];
            M["College"] = college[i];
            M["Semester"] = semester[i];
            M["Company"] = company[i];
            M["Dslevel"] = dslevel[i];
            M["City"] = city[i];
            return M;
        }
    }
    if (i == input.size())
    {
        cout << "Username does not exist";
    }
    return M;
}

vector<string> split_string(string S)
{

    char *s;
    s = &S[0];
    vector<string> str;
    char *token = strtok(s, " ");

    while (token != NULL)
    {
        string token_string(token);

        str.push_back(token_string);

        token = strtok(NULL, " ");
    }
    return str;
}

void ayushiTask()
{
    // 1. Read sheet, pick username, create random pairs, return the names of the random pairs. -- Ayushi
    vector<string> U;

    for(int i = 0; i < no_of_users; i++)
        {

           U.push_back(username[i]);
       }

    shuffle(U.begin(),U.end(), mt19937(random_device()()));


    vector<string> res;

    srand(time(0));
    for (int i = U.size() - 1; i > 0; i--)
   {
	  int n = rand() % (i + 1);
	  swap( U[i], U[n] );

   }
     for(int i = 0; i < no_of_users; i++)
        {

           res.push_back(U[i]);
        }

    vector<string> full;
    full.reserve(U.size());
    full.insert(full.end(), U.begin(), U.end());
    if (full.size() % 2 == 0)
    {
        for (int i = 0; i < full.size(); i = i + 2)
        {
            write_pair(full[i], full[i + 1]);
            cout << "{" << full[i] << ", " << full[i + 1] << "}" << endl;
        }
    }
    else
    {
        for (int i = 0; i < full.size() - 3; i = i + 2)
        {
            write_pair(full[i], full[i + 1]);
            cout << "{" << full[i] << ", "  << full[i+1] << "}" << endl;
        }
        string last1 = full.back();
        full.pop_back();
        string last2 = full.back();
        full.pop_back();
        string last3 = full.back();
        full.pop_back();
        write_three(last3, last2, last1);
        cout << "{" << last3 << ", " << last2  <<  ", " << last1 << " }" << endl;
    }
}

void ShivaniTask()
{
    // 2. Read sheet, pick usernames, create random pairs based on the time of registration with a difference of more than 15 minutes -- Shivani
        for(int i=0;i<t1.size();i++)
    {
        dataa.push_back({t1[i],username[i]});
    } 
    vector<string> pairs,single;

    for(int i=0;i<dataa.size()-1;i++)
    {
        for(int j=1;j<dataa.size();j++)
        {
            if(dataa[j].first==0 || dataa[i].first==0)
            {
                continue;
            }
            if(dataa[i].first - dataa[j].first>=900)
            {
                pairs.push_back(dataa[i].second);
                pairs.push_back(dataa[j].second);
                dataa[i].first=0;
                dataa[j].first=0;
                break;
            }
            else if(j==dataa.size()-1)
            {
                single.push_back(dataa[i].second);
            }
        }
    }

    for(int i=0;i<pairs.size()-2;i=i+2)
    {
        write_pair(pairs[i],pairs[i+1]);
        cout<<"{"<<pairs[i]<<","<<pairs[i+1]<<"}\n";
    }
    cout<<"\n";
}

void ShwetaTask()
{
    // 3. Read sheet, pick usernames, create random pairs based on the college such that no same college student should fight with each other.
    //  Note: This needs an additional task of cleansing the dataa for the college name (Case-sensistive) Shweta

    for (auto &i : college)
    {
        if (i == "Shri Ram Murti Smarak College of Engg. and Tech" || i == "SRMS CET")
            i = "SRMS";
        else if (i == "IIT Delhi" || i == "Indian insstitute of technology Delhi")
            i = "IIT D";
        else if (i == "IIIT Delhi" || i == "Indian insstitute of information technology Delhi")
            i = "IIIT D";
        else if (i == "NIT Agartala")
            i = "NITAgt";
        else if (i == "NIT Allahabad")
            i = "NITA";
    }

    vector<string> s;

    for (auto &i : college)
    {

        transform(i.begin(), i.end(), i.begin(), ::toupper);
    }

    int n = college.size();

    bool vis[500];
    for (int i = 0; i < n; i++)
    {
        vis[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (college[i] != college[j])
            {
                write_pair(username[i], username[j]);
                cout << username[i] << " " << username[j] << endl;
                vis[j] = true;
                vis[i] = true;
                break;
            }
        }
    }
}

void MeghaTask()
{
    // 4. Read sheet, pick usernames, create random pairs based on the level of DS, they know.
    // Note: No different DS level student should match with another level -- Megha
    vector<string> B;
    vector<string> M;
    vector<string> E;
    cout<<no_of_users;
    for(int i = 0; i < no_of_users; i++)
        {
       if(dslevel[i] == "B")
       {
           B.push_back(username[i]);
       }
       else if(dslevel[i] == "M")
       {
           M.push_back(username[i]);
       }
       else
       {
           E.push_back(username[i]);
       }
    }
    shuffle(B.begin(),B.end(), mt19937(random_device()()));
    shuffle(M.begin(),M.end(), mt19937(random_device()()));
    shuffle(E.begin(),E.end(), mt19937(random_device()()));
    vector<string> full;
    full.reserve(B.size() + M.size() + E.size());
    full.insert( full.end(), B.begin(), B.end() );
    full.insert( full.end(), M.begin(), M.end() );
    full.insert( full.end(), E.begin(), E.end() );
    
    if (full.size() % 2 == 0)
    {
        for (int i = 0; i < full.size(); i = i + 2)
        {
            write_pair(full[i], full[i + 1]);
            cout << "{" << full[i] << ", " << full[i + 1] << "}" << endl;
        }
    }
    else
    {
        for (int i = 0; i < full.size() - 3; i = i + 2)
        {
            write_pair(full[i], full[i + 1]);
            cout << "{" << full[i] << ", "  << full[i+1] << "}" << endl;
        }

        string last1 = full.back();
        full.pop_back();
        string last2 = full.back();
        full.pop_back();
        string last3 = full.back();
        full.pop_back();
        write_three(last3, last2, last1);
        cout << "{" << last3 << ", " << last2  <<  ", " << last1 << " }" << endl;
    }
}

void ArpitTask()
{
    // 6. Create random pair based on the semester of a student. The difference of the semester should not be greater than 4.
    // For eg. student A of 1st semester cannot pair with student B of 5th Semester but can pair with student C of 3rd Semester -- Arpit

    // Hashing table to keep the track of the already paired students
    bool *hash = new bool[no_of_users];

    // Filling the hash table with a default value:false
    fill(hash, hash + no_of_users, false);

    cout << endl
         << "***************" << endl;

    for (int i = 0; i < no_of_users; i++)
    {

        bool flag = false; //keep track if their is any valid pair
        int idx = -1;      //will keep the index of the paired student
        int minDiff = 0;   //will keep track of the min =imum difference

        if (!hash[i])
        { //won't check if the pair is already created

            for (int j = i + 1; j < no_of_users; ++j)
            {
                if (!hash[j])
                { //won't check if the pair is already created

                    int diff = abs(stoi(semester[i]) - stoi(semester[j]));
                    if (diff <= 3 && diff >= minDiff)
                    { //trying to find a pair with biggest semester difference and satisfies the condition
                        idx = j;
                        minDiff = diff;
                        flag = true;
                    }
                }
            }
        }

        if (flag)
        {
            hash[i] = true;
            hash[idx] = true;
            write_pair(fullname[i], fullname[idx]);
            cout << "{ ";
            cout << fullname[i]<< ":" << username[i] << "(semester: " << semester[i] << ")";
            cout << ", ";
            cout << fullname[idx]<< ":"<< username[idx] << "(semester: " << semester[idx] << ")";
            cout << "}";
            cout << endl;
        }
    }
}

int main()
{

    string v1, v2, v3, v4, v5, v6, v7, v8, v9; //variables from file are here

    ifstream ip("input.csv"); //opening the file.
    if (ip.is_open())         //if the file is open
    {
        //ignores the first line
        string line;
        getline(ip, line);

        while (!ip.eof()) //while the end of file is NOT reached
        {
            getline(ip, v1, ',');
            timestamp.push_back(v1);

            getline(ip, v2, ',');
            username.push_back(v2);

            getline(ip, v3, ',');
            faceoffId.push_back(v3);

            getline(ip, v4, ',');
            fullname.push_back(v4);

            getline(ip, v5, ',');
            college.push_back(v5);

            getline(ip, v6, ',');
            semester.push_back(v6);

            getline(ip, v7, ',');
            company.push_back(v7);

            getline(ip, v8, ',');
            dslevel.push_back(v8);

            getline(ip, v9, '\n');
            city.push_back(v9);

            no_of_users += 1; //increment number of lines
            int d, yr, h, m, s;
            string mon;
            sscanf(v1.c_str(), "%d %s %d %d:%d:%d", &d, &mon, &yr, &h, &m, &s);
            int secs = h * 3600 + m * 60 + s;
            t1.push_back(secs);
        }
        ip.close(); //closing the file
        no_of_users--;
        cout << "Number of entries: " << no_of_users << endl;
    }
    else
        cout << "Unable to open file"; //if the file is not open output

    // To get the key value pairs of the passed username in the function getinfo()
    map<string, string> M = getinfo(username, "codeogeek");

    while (1)
    {

        int x;
        cout << "Input 1 for Aayushi's task:\n";
        cout << "Input 2 for Shivani's task:\n";
        cout << "Input 3 for Shweta's task:\n";
        cout << "Input 4 for Megha's task:\n";
        cout << "Input 5 for Arpit's task:\n";
        cout << "Input -1 to exit from the program\n";
        cin >> x;
        switch (x)
        {
        case 1:
            // 1. Read sheet, pick username, create random pairs, return the names of the random pairs. -- Ayushi
            delete_content();
            cout<<endl;
            ayushiTask();
            cout<<endl;
            cout << "See output.txt for the output..\n"
                 << endl;
            cout << "------------------\n";
            break;
        case 2:
            // 2. Read sheet, pick usernames, create random pairs based on the time of registration with a difference of more than 15 minutes -- Shivani
            delete_content();
            cout<<endl;
            ShivaniTask();
            cout<<endl;
            cout << "See output.txt for the output..\n"
                 << endl;
            cout << "------------------\n";
            break;
        case 3:
            // 3. Read sheet, pick usernames, create random pairs based on the college such that no same college student should fight with each other.
            //  Note: This needs an additional task of cleansing the dataa for the college name (Case-sensistive) Shweta
            delete_content();
            cout<<endl;
            ShwetaTask();
            cout<<endl;
            cout << "See output.txt for the output..\n"
                 << endl;
            cout << "------------------\n";
            break;
        case 4:
            // 4. Read sheet, pick usernames, create random pairs based on the level of DS, they know.
            // Note: No different DS level student should match with another level -- Megha
            delete_content();
            cout<<endl;
            MeghaTask();
            cout<<endl;
            cout << "See output.txt for the output..\n"
                 << endl;
            cout << "------------------\n";
            break;
        case 5:
            // 6. Create random pair based on the semester of a student. The difference of the semester should not be greater than 4.
            // For eg. student A of 1st semester cannot pair with student B of 5th Semester but can pair with student C of 3rd Semester -- Arpit
            delete_content();
            cout<<endl;
            ArpitTask();
            cout<<endl;
            cout << "See output.txt for the output..\n"
                 << endl;
            cout << "------------------\n";
            break;
        case -1:
            exit(-1);
            break;
        default:
            cout << "OOPS wrong input..\n"
                 << endl;
            cout << "------------------\n";
        }
    }

    return 0;
}