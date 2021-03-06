#include <iostream>
#include <climits>
#include <cstring>
#include <string>
using namespace std;
string find_window(string s, string pat)
{
    int sl = s.length();
    int pl = pat.length();
    if (pl > sl)
    {
        return "None";
    }
    //2 freq maps
    int fs[256] = {0};
    int fp[256] = {0};
    for (int i = 0; i < pl; i++)
    {
        char ch = pat[i];
        fp[ch]++;
    }
    //3. sliding window (expansion & contraction +update the min length window)
    int cnt = 0;
    int start = 0; //left pointer for shrinking
    int min_len = INT_MAX;
    int start_idx=-1;
    for (int i = 0; i < sl; i++)
    {
        char ch = s[i];
        fs[ch]++;
        //maintain cnt of characters matched
        if (fp[ch] != 0 && fs[ch] <= fp[ch])
        {
            cnt++;
        }
        // if all characters match
        if (cnt == pl)
        {
            char temp = s[start];
            //start  shrinking the window
            //loop to remove all unwanted characters
            while (fp[temp] == 0 || fs[temp] > fp[temp])
            {
                fs[temp]--;
                start++;
                temp = s[start];
            }
            //window size;
            int window_len = i - start + 1;
           // cout<<i<<" "<<start<<" "<<window_len<<endl;
            if (window_len < min_len)
            {
                min_len = window_len;
                start_idx=start;
            }
        }
    }
    if(start_idx==-1){
        return "None";
    }
    string ans=s.substr(start_idx,min_len);
    return ans;
}
int main()
{
    string s = "heelleeoeaeo world";
    string p="eelo";
    cout<<find_window(s,p);
    return 0;
}