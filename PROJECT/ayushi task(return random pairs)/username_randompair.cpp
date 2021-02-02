#include <random>

#include "bits/stdc++.h"
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

    ifstream ip("C:/Users/ayushisheode/Desktop/a.csv");
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
    full.reserve(res.size());
    full.insert( full.end(), res.begin(), res.end() );
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

