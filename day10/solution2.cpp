#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void drawCRT(int X, int cycle)
{
    if (cycle < 240)
    {
        if (X - 1 <= cycle % 40 && X + 1 >= cycle % 40)
            cout << "#";
        else
            cout << ".";
        if ((cycle + 1) % 40 == 0)
            cout << endl;
    }
}

int main()
{
    fstream fs;
    fs.open("input.txt", ios::in);

    long long res = 0;
    int cycle = 1, X = 1;
    cout << "#";
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
                    drawCRT(X, cycle - 1);
                    cycle++;
                    X += stoi(s.substr(4, s.length()));
                    drawCRT(X, cycle - 1);
                }
                else
                {
                    cycle++;
                    drawCRT(X, cycle - 1);
                }
            }
        }
    }

    // cout << res;
    fs.close();
    return 0;
}