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
#include<cstring>

using namespace std;

int main()
{
    vector<string> timestamp;
    vector<string> username;
    vector<string> faceoffId;
    vector<string> fullname;
    vector<string> college;
    vector<string> semester;
    vector<string> company;
    vector<string> dslevel;
    vector<string> city;

    string v1,v2,v3,v4,v5,v6,v7,v8,v9;
    int no_of_users = 0;

    ifstream ip("C:/Users/agmeg/Desktop/input.csv");
    if (ip.is_open())
    {
        string line;
        getline(ip, line);

        while (!ip.eof())
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

            no_of_users += 1;
        }
        ip.close();

    }
    else
    {
        cout << "Unable to open file";
        return 0;
    }

    vector<string> B;
    vector<string> M;
    vector<string> E;

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

    if(full.size()%2 == 0)
    {
        for (int i = 0; i < full.size(); i=i+2)
        {
            cout << "{" << full[i] << ", " << full[i + 1] << "}" << endl;
        }
    }
    else
        {
        for (int i = 0; i < full.size() - 3; i=i+2)
        {
            cout << "{" << full[i] << ", "  << full[i+1] << "}" << endl;
        }

        string last1 = full.back();
        full.pop_back();
        string last2 = full.back();
        full.pop_back();
        string last3 = full.back();
        full.pop_back();
        cout << "{" << last3 << ", " << last2  <<  ", " << last1 << " }" << endl;
    }

    return 0;
}
