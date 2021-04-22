#include <bits/stdc++.h>
using namespace std;

struct trie
{
    trie *nxt[26];
    bool ended;
    trie()
    {
        for (int i = 0; i < 26; i++)
            nxt[i] = NULL;
    }
};
trie *root;
void insert(string s)
{
    trie *curr = root;
    for (int i = 0; i < s.size(); i++)
    {
        if (curr->nxt[s[i] - 'a'] == NULL)
        {
            curr->nxt[s[i] - 'a'] = new trie();
        }
        curr = curr->nxt[s[i] - 'a'];
    }
    //curr at last node
}
bool in_trie(string s)
{
    trie *curr = root;
    for (int i = 0; i < s.size(); i++)
    {
        if (curr->nxt[s[i] - 'a'] == NULL)
            return false;
        curr = curr->nxt[s[i] - 'a'];
    }

    //curr at last node
    return true;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    root = new trie();
    string text = "abaacadbacad";
    string pat = "aaca";
    int n = text.size(), m = pat.size();
    for (int i = 0; i < n; i++)
    {
        insert(text.substr(i));
    }
    if (in_trie(pat))
    {
        cout << "yup\n";
    }
    else
    {
        cout << "nope\n";
    }
}
