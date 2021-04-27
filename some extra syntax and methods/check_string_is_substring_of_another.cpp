class Solution
{
public:
    bool rotateString(string A, string B)
    {
        if (A.size() != B.size())
            return false;
        string t = A + A;
        return (t.find(B) != string::npos);
    }
};