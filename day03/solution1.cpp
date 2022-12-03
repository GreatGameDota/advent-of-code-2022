#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

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
                unordered_set<int> se;
                for (int i = 0; i < s.length() / 2; i++)
                    se.insert(s[i]);
                    
                for (int i = s.length() / 2; i < s.length(); i++) {
                    if (se.count(s[i])) {
                        res += (s[i] - 'a' > 0 ? s[i] - 'a' + 1 : s[i] - 'A' + 27);
                        se.erase(s[i]);
                    }
                }
            }
        }
    }
    cout << res << endl;
    fs.close();
}