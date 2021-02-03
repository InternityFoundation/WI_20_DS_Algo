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

    vector<pair<int,string>> data;
    vector<int> t1;

    string v1, v2, v3, v4, v5, v6, v7, v8, v9;
    int no_of_users = 0;

    ifstream ip("C:/Users/SHIVANI/Desktop/abc.csv");
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
            sscanf(v1.c_str(), "%d %s %d %d:%d:%d", &d, &mon, &yr, &h, &m, &s);//Time to seconds
            int secs = h * 3600 + m * 60 + s;

            t1.push_back(secs);
        }
        ip.close();
        cout << "Number of entries: " << no_of_users << endl;
    }
    else
    {
        cout << "Unable to open file";
    }
    for(int i=0;i<t1.size();i++)
    {
        data.push_back({t1[i],username[i]});
    }

    vector<string> pairs,single;

    for(int i=0;i<data.size()-1;i++)
    {
        for(int j=1;j<data.size();j++)
        {
            if(data[j].first==0 || data[i].first==0)
            {
                continue;
            }
            if(data[i].first - data[j].first>=900)
            {
                pairs.push_back(data[i].second);
                pairs.push_back(data[j].second);
                data[i].first=0;
                data[j].first=0;
                break;
            }
            else if(j==data.size()-1)
            {
                single.push_back(data[i].second);
            }
        }
    }

    for(int i=0;i<pairs.size()-2;i=i+2)
    {
        cout<<"{"<<pairs[i]<<","<<pairs[i+1]<<"}\n";
    }
    cout<<"\n";
    /*
    if(single.size()%2==0)
    {
        for(int i=0;i<single.size()-2;i=i+2)
        {
            cout<<"{"<<single[i]<<","<<single[i+1]<<"}\n";
        }
    }
    else
    {
       int var=(single.size()/2-1)*2;
       for(int i=0;i<single.size()-1;i=i+2)
       {
           if(i<var)
           {
               cout<<"{"<<single[i]<<","<<single[i+1]<<"}\n";
           }
           else
           {
               cout<<"{"<<single[i]<<","<<single[i+1]<<","<<single.back()<<"}\n";
           }
       }
    }*/

    return 0;
}
