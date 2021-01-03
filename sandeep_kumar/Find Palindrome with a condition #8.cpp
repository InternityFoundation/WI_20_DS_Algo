#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome(int n)
{
    int temp = n,rev=0;
    while (n) {
        rev = rev*10 + n % 10;
        n = n / 10;
    }
    if (temp == rev) {
        return true;
    }
    return false;
}
int main()
{
    int n=678;
    if (isPalindrome(n) == true) {
        cout << "Yes the number is palindrome" << endl;
    }
    else {
        cout << "No the number is not palindrome"<< endl;
    }
}
