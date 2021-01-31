#include<bits/stdc++.h>
using namespace std;

vector<string> timestamp;
vector<string> usernames;
vector<string> faceoffId;
vector<string> fullname;
vector<string> colleges;
vector<string> semester;
vector<string> company;
vector<string> dslevel;
vector<string> city;




vector<string> split_string(string S){


    char *s;
     s = &S[0];
    vector<string>str;
    char *token = strtok(s, " ");

    while (token != NULL)
    {
        string token_string(token);

        str.push_back(token_string);

        token = strtok(NULL, " ");
    }
    return str;
}


int main (){


    string v1,v2,v3,v4,v5,v6,v7,v8,v9; //variables from file are here
    int no_of_users = 0;

    ifstream ip("C:/Users/Administrator/Desktop/Book1.csv"); //opening the file.
    if (ip.is_open()) //if the file is open
    {
        //ignores the first line
        string line;
        getline(ip, line);

        while (!ip.eof()) //while the end of file is NOT reached
        {
            getline(ip, v1, ',');
            timestamp.push_back(v1);

            getline(ip, v2, ',');
            usernames.push_back(v2);

            getline(ip, v3, ',');
            faceoffId.push_back(v3);

            getline(ip, v4, ',');
            fullname.push_back(v4);

            getline(ip, v5, ',');
            colleges.push_back(v5);

            getline(ip, v6, ',');
            semester.push_back(v6);

            getline(ip, v7, ',');
            company.push_back(v7);

            getline(ip, v8, ',');
            dslevel.push_back(v8);

            getline(ip, v9, '\n');
            city.push_back(v9);

            no_of_users += 1; //increment number of lines
        }
        ip.close(); //closing the file

    }



for(auto &i:colleges){
    if(i=="Shri Ram Murti Smarak College of Engg. and Tech" || i=="SRMS CET")i="SRMS";
    else if(i=="IIT Delhi" || i=="Indian insstitute of technology Delhi")i="IIT D";
   else  if(i=="IIIT Delhi" || i=="Indian insstitute of information technology Delhi")i="IIIT D";
   else if(i=="NIT Agartala")i="NITAgt";
   else if(i=="NIT Allahabad")i="NITA";
}

vector<string>s;

for(auto &i:colleges){

transform(i.begin(), i.end(), i.begin(), ::toupper);
}




int n=colleges.size();


bool vis[n];
for(int i=0;i<n;i++){
    vis[i]=false;
}
for(int i=0;i<n;i++){
    if(vis[i])continue;
    for(int j=i+1;j<n;j++){
        if(colleges[i]!=colleges[j])
        {
            cout<<usernames[i]<<" "<<usernames[j]<<endl;
            vis[j]=true;
            vis[i]=true;
            break;
        }
    }

}



}
