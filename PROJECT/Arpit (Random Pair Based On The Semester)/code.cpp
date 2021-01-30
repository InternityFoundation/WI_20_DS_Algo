#include <random>

#include "bits/stdc++.h"
using namespace std;

void write_pair(string user1,string user2){
string s="{"+user1+","+user2+"}\n";
ofstream op;
op.open("output.txt",ios::app);
if(op.is_open()){
    op<<s;
}
else{
    cout<<"Not able to open output.txt";
}
op.close();
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


    string v1,v2,v3,v4,v5,v6,v7,v8,v9;
    int no_of_users = 0;

    ifstream ip("./input2.txt");
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

    // 6

    // Hashing table to keep the track of the already paired students
    bool *hash = new bool [no_of_users];

    // Filling the hash table with a default value:false
    fill(hash, hash + no_of_users, false);

    cout << endl << "***************" <<endl;

    for(int i = 0; i < no_of_users; i++){

        bool flag = false; //keep track if their is any valid pair
        int idx = -1; //will keep the index of the paired student
        int minDiff = 0; //will keep track of the min =imum difference

        if(!hash[i]){ //won't check if the pair is already created

            for(int j = i + 1; j < no_of_users; ++j){
                if(!hash[j]){ //won't check if the pair is already created

                    int diff = abs(stoi(semester[i]) - stoi(semester[j]));
                    if(diff <= 3 && diff >= minDiff){ //trying to find a pair with biggest semester difference and satisfies the condition
                        idx = j;
                        minDiff = diff;
                        flag = true;
                    }

                }
            }
        }


        //To push the pair into the output.txt file
        write_pair(username[0],username[1]);

        if(flag){
            hash[i] = true;
            hash[idx] = true;
            cout << "{ ";
            cout <<  username[i] << "(semester: " << semester[i] << ")";
            cout << ", ";
            cout << username[idx] << "(semester: " << semester[idx] << ")";
            cout << "}";
            cout << endl;
        }
    }


    return 0;
}
