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
    vector<vector<int>> arr;
    if (fs.is_open())
    {
        string s;
        while (getline(fs, s))
        {
            if (s.length() != 0)
            {
                vector<int> v;
                for (char &c : s)
                    v.push_back(c - '0');
                arr.push_back(v);
            }
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            int ret = 1;
            int tot = 0;
            int x2 = i + 1, y2 = j;
            while (x2 < arr[0].size())
            {
                tot++;
                if (arr[x2][j] >= arr[i][j])
                    break;
                x2++;
            }
            ret *= (tot == 0 ? 1 : tot);
            tot = 0;
            x2 = i - 1, y2 = j;
            while (x2 >= 0)
            {
                tot++;
                if (arr[x2][j] >= arr[i][j])
                    break;
                x2--;
            }
            ret *= (tot == 0 ? 1 : tot);
            tot = 0;
            x2 = i, y2 = j + 1;
            while (y2 < arr.size())
            {
                tot++;
                if (arr[i][y2] >= arr[i][j])
                    break;
                y2++;
            }
            ret *= (tot == 0 ? 1 : tot);
            tot = 0;
            x2 = i, y2 = j - 1;
            while (y2 >= 0)
            {
                tot++;
                if (arr[i][y2] >= arr[i][j])
                    break;
                y2--;
            }
            ret *= (tot == 0 ? 1 : tot);
            tot = 0;
            res = max(res, (long long)ret);
        }
    }

    cout << res;
    fs.close();
    return 0;
}