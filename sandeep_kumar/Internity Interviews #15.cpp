#include <iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    vector <string> candidates = { "A","B","C","D","E" };
    vector <int> sem = { 5,4,3,5,3 };
    int no_of_candidates = 5;
    //cin >> no_of_candidates;
    /*for (int i = 0; i < no_of_candidates; i++) {
        string s;
        cin >> s;
        candidates.push_back(s);
    }*/
    /*for (int i = 0; i < no_of_candidates; i++) {
        int n;
        cin >> n;
        sem.push_back(n);
    }*/

    //Assuming that there are only two interviewers only all the time
    string s1 = "interviewer1", s2 = "interviewer2";
    //cin >> s1 >> s2;

    vector <string> I1, I2;
    int sum1 = 0, sum2 = 0;
    if (no_of_candidates % 2 == 0) {
        for (int i = 0; i < no_of_candidates; i++) {
            if (i % 2 == 0) {
                cout << candidates[i] << " ";
            }
        }
        cout << endl;
        for (int i = 0; i < no_of_candidates; i++) {
            if (i % 2 != 0) {
                cout << candidates[i] << " ";
            }
        }
        cout << endl;
    }
    else {
        for (int i = 0; i < no_of_candidates; i++) {
            if (i % 2 == 0) {
                sum1 += sem[i];
            }
        }
        cout << endl;
        for (int i = 0; i < no_of_candidates - 1; i++) {
            if (i % 2 != 0) {
                sum2 += sem[i];
            }
        }
        if (sum1 >= sum2) {
            for (int i = 0; i < no_of_candidates; i++) {
                if (i % 2 == 0) {
                    cout << candidates[i] << " ";
                }
            }
            cout << endl;
            for (int i = 0; i < no_of_candidates; i++) {
                if (i % 2 != 0) {
                    cout << candidates[i] << " ";
                }
            }
            cout << endl;
        }
        else {
            for (int i = 0; i < no_of_candidates; i++) {
                if (i % 2 == 0) {
                    cout << candidates[i] << " ";
                }
            }
            cout << endl;
            for (int i = 0; i < no_of_candidates - 1; i++) {
                if (i % 2 != 0) {
                    cout << candidates[i] << " ";
                }
            }
            cout << candidates[no_of_candidates - 1];
            cout << endl;
        }
    }
}
