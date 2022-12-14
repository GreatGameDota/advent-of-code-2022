#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Monkey
{
public:
    queue<long long> items;
    int op = -1;
    long long opAmount = -1;
    long long modulo = -1;
    int monkey1 = -1;
    int monkey2 = -1;
    long long (*ptr)(long long) = nullptr;
};

int main()
{
    fstream fs;
    fs.open("input.txt", ios::in);

    long long res = 0;
    int cnt = 0;
    vector<Monkey> v;
    Monkey newMonkey;
    if (fs.is_open())
    {
        string s;
        while (getline(fs, s))
        {
            if (s.length() != 0)
            {
                if (cnt % 6 == 0)
                {
                    newMonkey = Monkey();
                }
                if (cnt % 6 == 1)
                {
                    int i = 0;
                    while (s[i] != ':')
                        i++;
                    i++;
                    while (i < s.length())
                    {
                        int j = i;
                        while (j < s.length() && s[j] != ',')
                            j++;
                        newMonkey.items.push(stoi(s.substr(i, j - 1)));
                        i = j + 2;
                    }
                }
                if (cnt % 6 == 2)
                {
                    int i = 0;
                    while (s[i] != 'd')
                        i++;
                    i += 2;
                    switch (s[i])
                    {
                    case '+':
                        newMonkey.op = 0;
                        break;
                    case '-':
                        newMonkey.op = 1;
                        break;
                    case '*':
                        newMonkey.op = 2;
                        break;
                    case '/':
                        newMonkey.op = 3;
                        break;
                    default:
                        break;
                    }
                    i += 2;
                    if (s[i] != 'o')
                    {
                        newMonkey.opAmount = stoi(s.substr(i, s.length()));
                    }
                    else
                    {
                        newMonkey.ptr = [](long long a)
                        { return a * a; };
                    }
                }
                if (cnt % 6 == 3)
                {
                    newMonkey.modulo = stoi(s.substr(21, s.length()));
                }
                if (cnt % 6 == 4)
                {
                    newMonkey.monkey1 = stoi(s.substr(29, s.length()));
                }
                if (cnt % 6 == 5)
                {
                    newMonkey.monkey2 = stoi(s.substr(29, s.length()));
                    v.push_back(newMonkey);
                }
                cnt++;
            }
        }
    }

    // Calculate Greatest Common Denominator of all Modulos
    vector<int> mods;
    for (Monkey &m : v)
        mods.push_back(m.modulo);

    int mn = *min_element(begin(mods), end(mods));
    while (mn > 0)
    {
        bool flag = true;
        for (Monkey &m : v)
            if (m.modulo % mn != 0)
                flag = false;
        if (flag)
            break;
        mn--;
    }

    // Calculate Lowest Common Multiple
    // (a x b x c ...) / GCD
    int lcm = 1;
    for (Monkey &m : v)
        lcm *= m.modulo;
    lcm /= mn;

    vector<long long> count(v.size(), 0);
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Monkey &m = v[j];
            while (m.items.size() > 0)
            {
                long long curr = m.items.front() % lcm; // Modulo all numbers
                m.items.pop();
                if (m.opAmount != -1)
                {
                    switch (m.op)
                    {
                    case 0:
                        curr += m.opAmount;
                        break;
                    case 1:
                        curr -= m.opAmount;
                        break;
                    case 2:
                        curr *= m.opAmount;
                        break;
                    case 3:
                        curr /= m.opAmount;
                        break;
                    default:
                        break;
                    }
                }
                else
                {
                    curr *= curr;
                }

                if (curr % m.modulo == 0)
                    v[m.monkey1].items.push(curr);
                else
                    v[m.monkey2].items.push(curr);
                count[j]++;
            }
        }
    }

    long long mx = *max_element(begin(count), end(count));
    long long scnd = 0;
    for (long long &i : count)
        if (i != mx)
            scnd = max(scnd, i);
    cout << (mx * scnd) << endl;

    // cout << res;
    fs.close();
    return 0;
}