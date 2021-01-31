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

    vector<pair<int,bool>> registrationSeconds;

    string v1, v2, v3, v4, v5, v6, v7, v8, v9;
    int no_of_users = 0;

    ifstream ip("C:/Users/shivani/Desktop/abc.csv");
    if (ip.is_open())
        {
        string line;
        getline(ip, line);

        while (!ip.eof()) {
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

            int d, yr, h, m, s;
            string mon;
            sscanf(v1.c_str(), "%d %s %d %d:%d:%d", &d, &mon, &yr, &h, &m, &s);
            int secs = h * 3600 + m * 60 + s;

            registrationSeconds.push_back(make_pair(secs,false));
        }
        ip.close();
        cout << "Number of entries: " << no_of_users << endl;
    }
    else
    {
        cout << "Unable to open file";
    }

    for (int i = 0; i < registrationSeconds.size(); i++)
        {
          for(int j = 0; j < registrationSeconds.size(); j++)
          {
            if(!registrationSeconds[j].second and registrationSeconds[i].first + 900 >= registrationSeconds[j].first and i!=j)
            {
                registrationSeconds[j].second = true;
                registrationSeconds[i].second = true;

                cout << "{ " << username[i] << ", " << username[j] << "}" << endl;
                break;
            }
        }
    }

    return 0;

}
