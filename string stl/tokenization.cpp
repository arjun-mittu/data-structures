#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char *mystrtok(char *str,char delim){
    static char *input=NULL;
    if(str!=NULL){
        input=str;
    }
    if(input==NULL){
        return NULL;
    }
    char *output=new char[strlen(input)+1];
    int i=0;
    for(;input[i]!='\0';i++){
        if(output[i]==delim){
        output[i]=input[i];}
        else{
            output[i]='\0';
            input=input+i+1;
            return output;
        }
    }
    output[i]='\0';
    input=NULL;
    return output;
}
int main(){
    char s[100]="abcd efgh";
    char *ptr=mystrtok(s," ");
   while(ptr!=NULL){
       cout<<ptr<<endl;
    ptr=mystrtok(NULL," ");// for next
    }

    return 0;
}