#include <bits/stdc++.h> 
using namespace std; 
stack <int> s1; 
stack <int> s2; 
vector <int> s3;
void display() 
{   int q,p,m,g,h;
    while (!s2.empty())  
    {    m=s2.top();
        cout <<m<<" "; 
        if(m/100==0 && (m/10)>0){
            p=m%10;
            m=m/10;
            q=m%10;
            while(abs(p-q)>1){
                
                s3.push_back(q);
                q--;
            }
            
                s3.push_back(q);
                
                s3.push_back(p);
        }
        else{
            s3.push_back(m);
        }
        s2.pop(); 
        
    } 
    cout << '\n'; 
    for(int i=0;i<s3.size();i++){
        cout<<s3[i]<<" ";
    }
   
    cout << '\n'; 
} 


int algorithm(int x,int y,int v){
    int a,b,c,e,f,i,j;
    int flag=0;
    
    if(y==-800){
        s2.pop();
        s2.push(x);
        flag=1;
    }
    if((x)/10==0 && (y)/10==0){
                
            if(abs(x-y)==1){
                if(v==1){
                  s1.pop();
                    
                }
                  s2.pop();
                   if(x>y){
                       c=x*10+y;
                       
                   }
                   else{
                       c=y*10+x;
                   }
                   s2.push(c);
                   flag=1;
                }
               
            }
            else if((x)/10==0  && (y)/100==0){
                e=y%10;
                y=y/10;
                f=y%10;
                a = e > f ? (e > x ? e: x) : (f > x ? f : x);
                b= e < f ? (e < x ? e: x) : (f < x ? f : x);
                
                if(abs(x-e)==1||abs(x-f)==1){
                if(v==1){
                  s1.pop();
                  
                    
                }
                
                s2.pop();
                c=a*10+b;
               
                s2.push(c);
                flag=1;
                }
               else if(x>f){
                    if(v==1){
                  s1.pop();
                    
                }
                s2.push(x);
                flag=1;
                }
              
            }
            else if((x)/100==0 && (y)/10==0){
                e=x%10;
                x=x/10;
                f=x%10;
                a = e > f ? (e > y ? e: y) : (f > y ? f : y);
                b= e < f ? (e < y ? e: y) : (f < y ? f : y);
                if(abs(y-e)==1||abs(y-f)==1){
                if(v==1){
                  s1.pop();
                    
                }
                s2.pop();
                
                c=a*10+b;
                s2.push(c);
                flag=1;
                }
               
            }
            else if((x)/100==0 && (y)/100==0){
                e=x%10;
                x=x/10;
                f=x%10;
                i=y%10;
                y=y/10;
                j=y%10;
                if(abs(f-i)==1||abs(e-j)==1){
                    if(v==1){
                  s1.pop();
                    
                }
                s2.pop();
                    a = e > f ? (e > i ? e: f) : (f > i ? f : i);
                    a = a > j ? a : j;
                b= e < f ? (e < i ? e: i) : (f < i ? f : i);
                b= b < j  ? b:j;
                c=a*10+b;
                s2.push(c);
                flag=1;
                }
            }
        return flag;
    
}

int main(){
    
    int N,d,x,y,z,f,t;
    cin>>N;
    for(int i=0;i<N;i++){
     cin>>d;
    s1.push(d);
    }
  if(s2.empty()){
       z=s1.top(); 
       s1.pop();
       s2.push(z);
     }
       while(!s1.empty()){
           x=s1.top();
           y=s2.top();
          
           if(x>y){
               
              f= algorithm(x,y,1);
               if(f==0){
                   s1.pop();
                   s2.push(x);
               }
               else{
                   f=0;
               }
           }
           else{
               t=s1.top();
               
               f=algorithm(t,y,1);
               
               if(f==0){
                   s1.pop();
                   
                do{
                    s2.pop();
                    
                    if(s2.empty()){
                       s2.push(-800);
                   }
                   
                   
                   s1.push(y);
                   
                   y=s2.top();
                   
                   f=algorithm(t,y,0);
                   
                  
               }while(f==0);
                   
               }
           }
           
       }
       display();
      
       return 0;
}
