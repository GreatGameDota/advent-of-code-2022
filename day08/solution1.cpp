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

    vector<vector<bool>> visited = vector<vector<bool>>(arr.size(), vector<bool>(arr[0].size(), false));
    res += 4;
    for (int i = 1; i < arr.size() - 1; i++)
    {
        res += 2;
        int maxNum = arr[i][0];
        for (int j = 1; j < arr[0].size() - 1; j++)
        {
            if (arr[i][j] > maxNum && !visited[i][j])
            {
                res++;
                visited[i][j] = true;
            }
            maxNum = max(maxNum, arr[i][j]);
        }
        maxNum = arr[i][arr[0].size() - 1];
        for (int j = arr[0].size() - 2; j > 0; j--)
        {
            if (arr[i][j] > maxNum && !visited[i][j])
            {
                res++;
                visited[i][j] = true;
            }
            maxNum = max(maxNum, arr[i][j]);
        }
    }

    for (int j = 1; j < arr[0].size() - 1; j++)
    {
        res += 2;
        int maxNum = arr[0][j];
        for (int i = 1; i < arr.size() - 1; i++)
        {
            if (arr[i][j] > maxNum && !visited[i][j])
            {
                res++;
                visited[i][j] = true;
            }
            maxNum = max(maxNum, arr[i][j]);
        }
        maxNum = arr[arr.size() - 1][j];
        for (int i = arr.size() - 2; i > 0; i--)
        {
            if (arr[i][j] > maxNum && !visited[i][j])
            {
                res++;
                visited[i][j] = true;
            }
            maxNum = max(maxNum, arr[i][j]);
        }
    }

    cout << res;
    fs.close();
    return 0;
}