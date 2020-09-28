#include<iostream>
#include "vector.h"
using namespace std;
int main(){
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}