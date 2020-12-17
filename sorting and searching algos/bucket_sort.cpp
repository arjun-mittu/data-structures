//question used counting sort for sorting according to students marks
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
class stduent{
public:
    int marks;
    string name;
};

void bucket_sort(stduent s[],int n){
    //marks in range 0-100
    vector<stduent> v[101];
    for(int i=0;i<n;i++){
        int m=s[i].marks;
        v[m].push_back(s[i]);
    }
    for(int i=100;i>=0;i--){
        for( vector<stduent>::iterator it=v[i].begin();it!=v[i].end();it++){
            cout<<(*it).marks<<" "<<(*it).name<<endl;
        }
    }
}
int main(){
    stduent s[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i].marks>>s[i].name;
    }
    bucket_sort(s,n);
    return 0;
}