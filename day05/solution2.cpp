#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <deque>

using namespace std;

int main()
{
    fstream fs;
    fs.open("input.txt", ios::in);

    long long res = 0;
    vector<deque<int>> a;
    if (fs.is_open())
    {
        string s;
        while (getline(fs, s))
        {
            if (s.length() != 0)
            {
                if (s[1] == '1')
                {
                    continue;
                }
                if (s[0] != 'm')
                {
                    int i = 1, cnt = 0;
                    while (i < s.length())
                    {
                        if (a.size() <= cnt)
                            a.push_back({});
                        if (s[i] != ' ')
                            a[cnt].push_back(s[i]);
                        i += 4;
                        cnt++;
                    }
                }
                else
                {
                    int i = 0;
                    while (s[i] != ' ')
                        i++;
                    i++;
                    string l = "";
                    while (s[i] != ' ')
                        l += s[i++];
                    i++;
                    while (s[i] != ' ')
                        i++;
                    i++;
                    string f = "";
                    while (s[i] != ' ')
                        f += s[i++];
                    i++;
                    while (s[i] != ' ')
                        i++;
                    i++;
                    string t = "";
                    while (s[i] != ' ')
                        t += s[i++];
                    int loop = stoi(l);
                    int from = stoi(f) - 1;
                    int to = stoi(t) - 1;
                    for (int i = 0; i < loop; i++)
                    {
                        a[to].push_front(a[from][0]);
                        a[from].pop_front();
                    }
                    reverse(a[to].begin(),a[to].begin()+loop);
                }
            }
        }
    }
    for (deque<int> &l : a)
        if (l.size() != 0)
            cout << (char)l[0];
        else
            cout << " ";
    // cout << res << endl;
    fs.close();
}