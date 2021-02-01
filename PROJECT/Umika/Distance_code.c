#include <random>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long double toRadians(const long double degree)
{
    // cmath library in C++
    // defines the constant
    // M_PI as the value of
    // pi accurate to 1e-30
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}
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
    string v1, v2, v3, v4, v5, v6, v7, v8, v9;
    int no_of_users = 0;

    ifstream ip("C:\Users\u\Desktop\raw.csv");
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
        }
        ip.close();
        cout << "Number of entries: " << no_of_users << endl;
    }
    else
    {
        cout << "Unable to open file";
    }
/*Inputing Cities latitude and longitude from another csv
*/

string c,lat,longit;
unordered_map<string,pair<float,float>> m;
ifstream ip1("C:\Users\u\Desktop\Indian Cities Database.csv");
    if (ip1.is_open())
        {
        string line;
        getline(ip1, line);

        while (!ip1.eof()) {
            getline(ip1, c, ',');
            getline(ip1, lat, ',');
            getline(ip1, longit, ',');

            m[c]=make_pair(std::stof(lat),std::stof(longit));
        }
        ip1.close();

    }
    else
    {
        cout << "Unable to open file";
    }



// we created a map of all cities of india

pair<string,string> answer;
float lat1, lat2,long1,long2,ans;
for(int i=0;i<no_of_users;i++)
{
    for(int j=i+1;j<no_of_users;j++)
    {
        if(m.find(city[i])!=m.end())
        {
            lat1=m[city[i]].first;
            long1=m[city[i]].second;
        }
        if(m.find(city[j])!=m.end())
        {
            lat2=m[city[j]].first;
            long2=m[city[j]].second;
        }
        lat1 = toRadians(lat1);
        long1 = toRadians(long1);
        lat2 = toRadians(lat2);
        long2 = toRadians(long2);

        // Haversine Formula
        float dlong = long2 - long1;
        float dlat = lat2 - lat1;

        ans = pow(sin(dlat / 2), 2) +cos(lat1) * cos(lat2) *pow(sin(dlong / 2), 2);

        ans = 2 * asin(sqrt(ans));

        // Radius of Earth in
        // Kilometers, R = 6371
        // Use R = 3956 for miles
        float R = 6371;

        // Calculate the result
        ans = ans * R;

        if(ans>=500)
        {
            answer.first=city[i];
            answer.second=city[j];
            cout << answer.first << " ";
            cout << answer.second << endl;
        }
    }
}
    return 0;

}
