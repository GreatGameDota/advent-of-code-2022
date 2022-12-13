#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    fstream fs;
    fs.open("input.txt", ios::in);

    long long res = 0;
    int cycle = 1, X = 1, target = 20;
    if (fs.is_open())
    {
        string s;
        while (getline(fs, s))
        {
            if (s.length() != 0)
            {
                if (s[0] == 'a')
                {
                    cycle++;
                    if (cycle == target)
                    {
                        res += cycle * X;
                        target += 40;
                    }
                    cycle++;
                    X += stoi(s.substr(4, s.length()));
                    if (cycle == target)
                    {
                        res += cycle * X;
                        target += 40;
                    }
                }
                else
                {
                    cycle++;
                    if (cycle == target)
                    {
                        res += cycle * X;
                        target += 40;
                    }
                }
            }
        }
    }

    cout << res;
    fs.close();
    return 0;
}