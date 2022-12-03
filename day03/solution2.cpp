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
    int cnt = 0;
    unordered_map<int, int> m;
    if (fs.is_open())
    {
        string s;
        while (getline(fs, s))
        {
            if (s.length() != 0)
            {
                if (cnt % 3 == 0)
                {
                    if (cnt != 0)
                    {
                        for (auto &p : m)
                        {
                            if (p.second == 3)
                            {
                                res += (p.first - 'a' > 0 ? p.first - 'a' + 1 : p.first - 'A' + 27);
                                break;
                            }
                        }
                    }
                    m = unordered_map<int, int>();
                }
                for (char &c : s)
                {
                    if (!m.count(c) && cnt % 3 == 0)
                        m[c] = 1;
                    if (m.count(c) && cnt % 3 == m[c])
                        m[c]++;
                }
                cnt++;
            }
        }
    }
    if (cnt % 3 == 0)
    {
        if (cnt != 0)
        {
            for (auto &p : m)
            {
                if (p.second == 3)
                {
                    res += (p.first - 'a' > 0 ? p.first - 'a' + 1 : p.first - 'A' + 27);
                    break;
                }
            }
        }
    }
    cout << res << endl;
    fs.close();
}