#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a1[] = {1, 3, 5, 7};
    int a2[] = {0, 2, 6, 8, 9};
    int n =4,m=5;
    int i=0;int j=0;
    for(j=0;j<m;j++){
        while(i<n){
            if(a1[i]<=a2[j]){
                i++;
            }
            if(a2[j]<a1[i]){
                int temp=a2[j];
                a2[j]=a1[i];
                a1[i]=temp;
                i++;
            }

        }
    }
    return 0;
}