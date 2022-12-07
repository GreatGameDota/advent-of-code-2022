#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Node
{
public:
    ~Node() { for (int i = 0; i < children.size(); i++) { delete children[i]; }}
    Node *parent;
    vector<Node *> children;
    long long tot = 0;
    string name;
};

long long res = 0;
int dfs(Node *n) {
    if (!n)
        return 0;
    
    long long tot = n->tot;
    for (int i = 0; i < n->children.size(); i++)
        tot += dfs(n->children[i]);
    n->tot = tot;
    if (tot <= 100000)
        res += tot;
    return tot;
}

int main()
{
    fstream fs;
    fs.open("input.txt", ios::in);

    Node *h = nullptr;
    Node *curr = nullptr;
    if (fs.is_open())
    {
        string s;
        while (getline(fs, s))
        {
            if (s.length() != 0)
            {
                if (s.length() == 4 && s[2] == 'l')
                    continue;

                if (s[0] == '$' && s[5] != '.') {
                    string n = s.substr(5, s.length());
                    if (!curr) {
                        curr = new Node();
                        h = curr;
                        curr->name = n;
                        curr->parent = nullptr;
                    } else {
                        curr->children.push_back(new Node());
                        Node *tmp = curr;
                        curr = curr->children.back();
                        curr->name = n;
                        curr->parent = tmp;
                    }
                } else if (s[0] == '$' && s[5] == '.') {
                    curr = curr->parent;
                } else if (s[0] != 'd') {
                    string am = "";
                    int i = 0;
                    while (s[i] != ' ')
                        am += s[i++];
                    curr->tot += stoi(am);
                }
            }
        }
    }

    dfs(h);

    cout << res;
    fs.close();
    delete h;
}