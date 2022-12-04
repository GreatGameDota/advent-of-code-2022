#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    fstream fs;
    fs.open("input.txt", ios::in);

    long long res = 0;
    if (fs.is_open()) {
        string s;
        while (getline(fs, s)) {
            if (s.length() != 0) {
                int i = 0;
                string l = "";
                while (s[i] != '-') {
                    l += s[i++];
                }
                i++;
                string r = "";
                while (s[i] != ',') {
                    r += s[i++];
                }
                i++;
                string l2_ = "";
                while (s[i] != '-') {
                    l2_ += s[i++];
                }
                i++;
                string r2_ = "";
                while (i < s.length()) {
                    r2_ += s[i++];
                }

                int l1 = stoi(l), r1 = stoi(r);
                int l2 = stoi(l2_), r2 = stoi(r2_);

                if ((l1 >= l2 && r1 <= r2) || (l2 >= l1 && r2 <= r1))
                    res++;
            }
        }
    }
    cout << res << endl;
    fs.close();
}