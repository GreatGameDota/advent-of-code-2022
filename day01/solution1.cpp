#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream fs;
    fs.open("input.txt", ios::in);

    long long res = 0;
    if (fs.is_open()) {
        string s;
        long long sum = 0;
        while (getline(fs, s)) {
            if (s.length() == 0) {
                res = max(res, sum);
                sum = 0;
            } else {
                sum += (long long)stoi(s);
            }
        }
    }
    cout << res << endl;
    fs.close();
}