#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    fstream fs;
    fs.open("input.txt", ios::in);

    priority_queue<long long, vector<long long>, greater<>> h;
    long long res = 0;
    if (fs.is_open()) {
        string s;
        long long sum = 0;
        while (getline(fs, s)) {
            if (s.length() == 0) {
                h.push(sum);
                if (h.size() > 3)
                    h.pop();
                sum = 0;
            } else {
                sum += (long long)stoi(s);
            }
        }
    }
    while (!h.empty()) {
        cout << h.top() << endl;
        res += h.top();
        h.pop();
    }
    cout << res << endl;
    fs.close();
}