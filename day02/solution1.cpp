#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int wins(char a, char b) {
    if (a == b)
        return 3;
    if ((a == 'R' && b == 'S') || (a == 'S' && b == 'P') || (a == 'P' && b == 'R'))
        return 6;
    return 0;
}

int main()
{
    fstream fs;
    fs.open("input.txt", ios::in);

    long long res = 0;
    unordered_map<char, char> m1 = {{'X', 'R'}, {'Y', 'P'}, {'Z', 'S'}};
    unordered_map<char, char> m2 = {{'A', 'R'}, {'B', 'P'}, {'C', 'S'}};
    unordered_map<char, int> m3 = {{'R', 1}, {'P', 2}, {'S', 3}};
    if (fs.is_open()) {
        string s;
        while (getline(fs, s)) {
            if (s.length() != 0) {
                res += wins(m1[s[2]], m2[s[0]]) + m3[m1[s[2]]];
            }
        }
    }
    cout << res << endl;
    fs.close();
}