#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
#include<map>
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

void delete_content(){
    ofstream ofs;
    ofs.open("output.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

map<string,string> getinfo(vector<std::string> &input, std::string searched) {
    
    map <string,string> M;
    int i;
    for (i = 0; i < input.size(); i++) {
        if (input[i] == searched) {
            M["Timestamp"]=timestamp[i];
            M["Username"]=username[i];
            M["FaceoffId"]=faceoffId[i];
            M["Fullname"]=fullname[i];
            M["College"]=college[i];
            M["Semester"]=semester[i];
            M["Company"]=company[i];
            M["Dslevel"]=dslevel[i];
            M["City"]=city[i];
            return M;
        }
    }
    if(i==input.size()){
        cout<<"Username does not exist";
    }
    return M;
}

int main() {

	string v1,v2,v3,v4,v5,v6,v7,v8,v9; //variables from file are here
	int no_of_users = 0;

	ifstream ip("input.csv"); //opening the file.
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
		}
		ip.close(); //closing the file
		no_of_users--;
		cout << "Number of entries: " << no_of_users << endl;
	}
	else cout << "Unable to open file"; //if the file is not open output
    
    //To remove the text of the file output.txt
    delete_content();
    

    //Start editing the code form here onwards if needed.....

    //To push the pair into the output.txt file
    write_pair(username[0],username[1]);

    // To get the key value pairs of the passed username in the function getinfo()
    map <string,string> M=getinfo(username,"codeogeek");
    for( auto it = M.begin(); it != M.end(); ++it )
    {
      cout<<it->first <<" : "<<it->second<<endl;
    } 
    
	return 0;
}