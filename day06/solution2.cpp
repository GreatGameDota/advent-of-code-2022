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
    int freq[26];
    memset(freq, -1, sizeof(freq));
    if (fs.is_open())
    {
        string s;
        while (getline(fs, s))
        {
            if (s.length() != 0)
            {
                int len = 0;
                for (int i = 0; i < s.length(); i++)
                {
                    if (freq[s[i] - 'a'] < i - len)
                    {
                        freq[s[i] - 'a'] = i;
                        len++;
                        if (len == 14)
                        {
                            res = i + 1;
                            break;
                        }
                    }
                    else
                    {
                        len = i - freq[s[i] - 'a'];
                        freq[s[i] - 'a'] = i;
                    }
                }
            }
        }
    }
    cout << res;
    fs.close();
}