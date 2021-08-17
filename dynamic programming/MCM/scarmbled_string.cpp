class Solution
{
public:
    unordered_map<string, bool> m;
    bool isScramble(string s1, string s2)
    {
        string key = s1 + '_' + s2;

        if (s1 == s2)
            return true;

        int n = s1.length();
        int count[26] = {0};
        for (int i = 0; i < n; i++)
        {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }

        if (m.find(key) != m.end())
        {
            return m[key];
        }
        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
                return m[key] = false;
        }
        int len = n;
        for (int i = 1; i <= n - 1; i++)
        {
            if (m[key] = (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))))
                return true;
            if (m[key] = (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i))))
                return true;
        }
        return m[key] = false;
    }
};