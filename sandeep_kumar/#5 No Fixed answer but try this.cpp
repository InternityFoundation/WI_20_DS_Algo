#include <iostream>
#include<vector>
using namespace std;
vector <int> arr;
void record(int id) {
    arr.push_back(id);
}
int get_last(int i) {
    return arr[arr.size() - 1 - i];
}
int main()
{
    arr = { 109,104,145,111,534,124,655,632,112 };
    record(100);
    cout << get_last(3) << endl;
}
