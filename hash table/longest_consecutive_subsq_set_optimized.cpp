#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
int findlargestseq(int arr[], int n)
{
    unordered_set<int > s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    int max_streak=1;
    //iterate over all elements
    //target those from which a streak can start
    for(int i=0;i<n;i++){
        // check arr[i]-1 is not present
        if(s.find(arr[i]-1)==s.end()){
            //a[i] is a starting point of streak
            //traverse the entire range 
            int next_no=arr[i]+1;
            int streak_len=1;
            while (s.find(next_no)!=s.end())
            {
                next_no+=1;
                streak_len+=1;   
            }
            max_streak=max(streak_len,max_streak);
        }
    }
    return max_streak;
}
int main()
{
    int arr[] = {14, 5, 1, 2, 6, 3, 7, 8, 9, 13, 15, 11, 12, 13, 17, 10};
    int n = sizeof(arr) / sizeof(int);
    cout << findlargestseq(arr, n);
}