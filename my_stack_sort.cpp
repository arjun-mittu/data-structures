#include <bits/stdc++.h> 
using namespace std; 
stack <int> s1;
stack <int> s2;
vector <int> ans;

int solve(int unit,int tens,int extra){
    int a,b,c,e,f,i,j;
    int flag=0;    
    if(tens==INT_MIN){
        s2.pop();
        s2.push(unit);
        flag=1;    }
    if((unit)/10==0 && (tens)/10==0){                
            if(abs(unit-tens)==1){
                if(extra==1){
                  s1.pop();                    
                }
                  s2.pop();
                   if(unit>tens){
                       c=unit*10+tens;                       
                   }
                   else{
                       c=tens*10+unit;
                   }
                   s2.push(c);
                   flag=1;
                }           }
            else if((unit)/10==0  && (tens)/100==0){
                e=tens%10;
                tens=tens/10;
                f=tens%10;
                a=e>f?(e>unit?e:unit):(f>unit?f:unit);
                b=e<f?(e<unit?e:unit):(f<unit?f:unit);                
                if(abs(unit-e)==1||abs(unit-f)==1){
                if(extra == 1 ){
                  s1.pop();   }               
                s2.pop();
                c=a*10+b;
                s2.push(c);
                flag=1;
                }
               else if(unit>f){
                    if(extra == 1){
                  s1.pop();
                                }
                s2.push(unit);
                flag=1;
                }           }
            else if((unit)/100==0 && (tens)/10==0){
                e=unit%10;
                unit=unit/10;
                f=unit%10;
                a=e>f?(e>tens?e:tens):(f>tens?f:tens);
                b=e<f?(e<tens?e:tens):(f<tens?f:tens);
                if(abs(tens-e)==1||abs(tens-f)==1){
                if(extra == 1 ){
                  s1.pop();
                                    }
                s2.pop();                
                c=a*10+b;
                s2.push(c);
                flag=1;
                }               
            }
            else if((unit)/100==0 && (tens)/100==0){
                e=unit%10;
                unit=unit/10;
                f=unit%10;
                i=tens%10;
                tens=tens/10;
                j=tens%10;
                if(abs(f-i)==1||abs(e-j)==1){
                    if(extra == 1){
                      s1.pop();
                }
                s2.pop();
                a = e>f?(e>i?e:f):(f>i?f:i);
                a=a>j?a:j;
                b=e<f?(e<i?e:i):(f<i?f:i);
                b=b<j?b:j;
                c=a*10+b;
                s2.push(c);
                flag=1;
                }            }
        return flag;
    
}
int main(){
	int n,val,unit,tens,tempplace,f,temp;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>val;
		s1.push(val);
	}
	if(s2.empty()){
		tempplace=s1.top();
		s1.pop();
		s2.push(tempplace);
	}
	while(!s1.empty()){
		unit=s1.top();
		tens=s2.top();
		if(unit>tens){
			f=solve(unit,tens,1);
			if(f==0){
				s1.pop();
				s2.push(unit);
			}
			else{
				f=0;
			}}
		else{
			temp=s1.top();
			f=solve(temp,tens,1);
			if(f==0){
				s1.pop();
			do{
				s2.pop();
				if(s2.empty()){
					s2.push(INT_MIN);
				}
				s1.push(tens);
				tens=s2.top();
				f=solve(temp,tens,0);
			}while(f==0);
		}
	}
	}
	int first,p,m,g,h;
    while (!s2.empty())  
    {    m=s2.top();
        cout <<m<<" "; 
        if(m/100==0 && (m/10)>0){
            p=m%10;
            m=m/10;
            first=m%10;
            while(abs(p-first)>1){
                ans.push_back(first);
                first--;
            }
            ans.push_back(first);
            ans.push_back(p);
        }
        else{
            ans.push_back(m);
        }
        s2.pop();       
    } 
    cout << '\n'; 
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }   
    cout << '\n'; 
}

