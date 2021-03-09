#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <set>
#include <climits>
using namespace std;
int *hash_array(int A[], int n)
{
    int MAX=10000;
    int *hash = new int[MAX]; //MAX is the maximum possible value of A[i]
    for (int i = 0; i <= MAX; i++)
        hash[i] = -1; //initialize hash to -1.
    int count = 0;
    for (int i = 0; i < n; i++) // Loop through elements of array
    {
        if (hash[A[i]] == -1) // A[i] was not assigned any hash before
        {
            hash[A[i]] = count; // Assigning hash to A[i]
            count++;
            continue;
        }
        for (int j = 0; j < i; j++)
        {
            if (hash[A[j]] > hash[A[i]]) // All the hashes greater than previous hash of A[i] are decremented.
                hash[A[j]]--;
        }
        hash[A[i]] = count - 1; // Assigning a new hash to A[i]
    }
    return hash;
}
bool compare(pair<int,int> p1,pair<int,int> p2){
    return p1.second<p2.second;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    unordered_map<int, int> m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        m[arr[i]]=i;
    }
    vector<pair<int,int>> v;
    for (auto p : m)
    {
        v.push_back(make_pair(p.first,p.second));
    }
    sort(v.begin(),v.end(),compare);
    for(auto i:v){
        cout<<i.first<<endl;
    }
    return 0;
}