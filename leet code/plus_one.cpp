#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> digits{1,2,3};
    n=nums.size()-1;
    while(n>=0){
            if(digits[n]==9){
            digits[n]=0;
            }
            else{
                digits[n]++;
                break;
            }
            n--;
        }
        digits.insert(digits.begin(),1);
    return 1;
}