bool isvalid(vector<int> &books, int n, int m, int ans)
{
    int student = 1;
    int pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (books[i] > ans)
            return false;
        if (pages + books[i] > ans)
        {
            student++;
            pages = books[i];
            if (student > m)
                return false;
        }
        else
        {
            pages += books[i];
        }
    }
    return true;
}
int Solution::books(vector<int> &books, int m)
{
    int n = books.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += books[i];
    }
    int s = 0;
    int e = sum;
    if (n < m)
        return -1;
    int ans = INT_MAX;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (isvalid(books, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}
