#include <bits/stdc++.h> 
using namespace std; 
stack <int> stack1; 
stack <int> stack2; 
vector <int> answer_vector;
void answer() 
{   int first,p,m,g,h;
    while (!stack2.empty())  
    {    m=stack2.top();
        cout <<m<<" "; 
        if(m/100==0 && (m/10)>0){
            p=m%10;
            m=m/10;
            first=m%10;
            while(abs(p-first)>1){
                answer_vector.push_back(first);
                first--;
            }
            answer_vector.push_back(first);
            answer_vector.push_back(p);
        }
        else{
            answer_vector.push_back(m);
        }
        stack2.pop();       
    } 
    cout << '\n'; 
    for(int i=0;i<answer_vector.size();i++){
        cout<<answer_vector[i]<<" ";
    }   
    cout << '\n'; 
} 


int solve(int unitplace,int tensplace,int extra){
    int a,b,c,e,f,i,j;
    int flag=0;    
    if(tensplace==INT_MIN){
        stack2.pop();
        stack2.push(unitplace);
        flag=1;    }
    if((unitplace)/10==0 && (tensplace)/10==0){                
            if(abs(unitplace-tensplace)==1){
                if(extra==1){
                  stack1.pop();                    
                }
                  stack2.pop();
                   if(unitplace>tensplace){
                       c=unitplace*10+tensplace;                       
                   }
                   else{
                       c=tensplace*10+unitplace;
                   }
                   stack2.push(c);
                   flag=1;
                }           }
            else if((unitplace)/10==0  && (tensplace)/100==0){
                e=tensplace%10;
                tensplace=tensplace/10;
                f=tensplace%10;
                a=e>f?(e>unitplace?e:unitplace):(f>unitplace?f:unitplace);
                b=e<f?(e<unitplace?e:unitplace):(f<unitplace?f:unitplace);                
                if(abs(unitplace-e)==1||abs(unitplace-f)==1){
                if(extra == 1 ){
                  stack1.pop();   }               
                stack2.pop();
                c=a*10+b;
                stack2.push(c);
                flag=1;
                }
               else if(unitplace>f){
                    if(extra == 1){
                  stack1.pop();
                                }
                stack2.push(unitplace);
                flag=1;
                }           }
            else if((unitplace)/100==0 && (tensplace)/10==0){
                e=unitplace%10;
                unitplace=unitplace/10;
                f=unitplace%10;
                a=e>f?(e>tensplace?e:tensplace):(f>tensplace?f:tensplace);
                b=e<f?(e<tensplace?e:tensplace):(f<tensplace?f:tensplace);
                if(abs(tensplace-e)==1||abs(tensplace-f)==1){
                if(extra == 1 ){
                  stack1.pop();
                                    }
                stack2.pop();                
                c=a*10+b;
                stack2.push(c);
                flag=1;
                }               
            }
            else if((unitplace)/100==0 && (tensplace)/100==0){
                e=unitplace%10;
                unitplace=unitplace/10;
                f=unitplace%10;
                i=tensplace%10;
                tensplace=tensplace/10;
                j=tensplace%10;
                if(abs(f-i)==1||abs(e-j)==1){
                    if(extra == 1){
                      stack1.pop();
                }
                stack2.pop();
                a = e>f?(e>i?e:f):(f>i?f:i);
                a=a>j?a:j;
                b=e<f?(e<i?e:i):(f<i?f:i);
                b=b<j?b:j;
                c=a*10+b;
                stack2.push(c);
                flag=1;
                }            }
        return flag;
    
}
int main(){    
    int n,data,unitplace,tensplace,tempplace,flag,temp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>data;
        stack1.push(data);
    }
  if(stack2.empty()){
       tempplace=stack1.top(); 
       stack1.pop();
       stack2.push(tempplace);
     }
       while(!stack1.empty()){
           unitplace=stack1.top();
           tensplace=stack2.top();          
           if(unitplace>tensplace){               
              flag= solve(unitplace,tensplace,1);
               if(flag==0){
                   stack1.pop();
                   stack2.push(unitplace);
               }
               else{
                   flag=0;
               }           }
           else{
               temp=stack1.top();               
               flag=solve(temp,tensplace,1);               
               if(flag==0){
                   stack1.pop();                   
                do{
                    stack2.pop();                    
                    if(stack2.empty()){
                       stack2.push(INT_MIN);
                   }           
                   stack1.push(tensplace);                   
                   tensplace=stack2.top();                   
                   flag=solve(temp,tensplace,0);                  
               }while(flag==0);
                }}}
       answer();
       return 0;
}
