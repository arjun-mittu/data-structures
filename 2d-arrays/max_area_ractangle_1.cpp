vector<int> getnextsmaller(vector<int> &heights)
{
    stack<int> st;
    int n = heights.size();
    vector<int> res(n, n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            res[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return res;
}
vector<int> getprevsmaller(vector<int> &heights)
{
    stack<int> st;
    int n = heights.size();
    vector<int> res(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            res[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return res;
}
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    if (n == 0)
        return 0;
    int ans = 0;
    auto next = getnextsmaller(heights);
    auto prev = getprevsmaller(heights);
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, heights[i] * (next[i] - prev[i] - 1));
    }
    return ans;
}
int maxArea(int M[MAX][MAX], int n, int m)
{
    // Your code here
    vector<int> heights(m, 0);
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 1)
            {
                heights[j] += M[i][j];
            }
            else
            {
                heights[j] = 0;
            }
        }
        int temp = largestRectangleArea(heights);
        // cout<<temp<<endl;
        ans = max(temp, ans);
    }
    return ans;
}