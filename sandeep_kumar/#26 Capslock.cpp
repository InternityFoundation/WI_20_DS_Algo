#include <iostream>
using namespace std;

string reverseCase(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (isupper(s[i])) {
            s[i]=tolower(s[i]);
        }
        else {
            s[i]=toupper(s[i]);
        }
    }
    return s;
}

int main()
{
    string s;
    cin >> s;
    int cu = 0, cl = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isupper(s[i])) {
            cu++;
        }
        else {
            cl++;
        }
    }
    if (islower(s[0]) && cu == s.size() - 1) {
        s=reverseCase(s);
    }
    if (cu == s.size()) {
        s=reverseCase(s);
    }
    cout << s;
    return 0;
}