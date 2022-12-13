#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

void moveTail(int x1, int y1, int &x2, int &y2)
{
    if (abs(x1 - x2) > 1 || abs(y1 - y2) > 1)
    {
        if (abs(x1 - x2) == abs(y1 - y2))
        {
            x2 = (x1 > x2 ? x1 - 1 : x1 + 1);
            y2 = (y1 > y2 ? y1 - 1 : y1 + 1);
        }
        else if (x1 == x2)
        {
            y2 = (y1 > y2 ? y1 - 1 : y1 + 1);
        }
        else if (y1 == y2)
        {
            x2 = (x1 > x2 ? x1 - 1 : x1 + 1);
        }
        else
        {
            if (abs(x1 - x2) > abs(y1 - y2))
            {
                y2 = y1;
                x2 = (x1 > x2 ? x1 - 1 : x1 + 1);
            }
            else
            {
                x2 = x1;
                y2 = (y1 > y2 ? y1 - 1 : y1 + 1);
            }
        }
    }
}

int main()
{
    fstream fs;
    fs.open("input.txt", ios::in);

    vector<vector<int>> v(10, vector<int>(2, 0));
    set<vector<int>> se;
    if (fs.is_open())
    {
        string s;
        while (getline(fs, s))
        {
            if (s.length() != 0)
            {
                char dir = s[0];
                int num = stoi(s.substr(2, s.length()));
                switch (dir)
                {
                case 'U':
                    for (int i = 0; i < num; i++)
                    {
                        v[0][1]++;
                        for (int j = 0; j < 9; j++)
                            moveTail(v[j][0], v[j][1], v[j + 1][0], v[j + 1][1]);
                        se.insert({v.back()[0], v.back()[1]});
                    }
                    break;
                case 'D':
                    for (int i = 0; i < num; i++)
                    {
                        v[0][1]--;
                        for (int j = 0; j < 9; j++)
                            moveTail(v[j][0], v[j][1], v[j + 1][0], v[j + 1][1]);
                        se.insert({v.back()[0], v.back()[1]});
                    }
                    break;
                case 'L':
                    for (int i = 0; i < num; i++)
                    {
                        v[0][0]--;
                        for (int j = 0; j < 9; j++)
                            moveTail(v[j][0], v[j][1], v[j + 1][0], v[j + 1][1]);
                        se.insert({v.back()[0], v.back()[1]});
                    }
                    break;
                case 'R':
                    for (int i = 0; i < num; i++)
                    {
                        v[0][0]++;
                        for (int j = 0; j < 9; j++)
                            moveTail(v[j][0], v[j][1], v[j + 1][0], v[j + 1][1]);
                        se.insert({v.back()[0], v.back()[1]});
                    }
                    break;
                default:
                    break;
                }
            }
        }
    }

    cout << se.size();
    fs.close();
    return 0;
}