#include<iostream>
using namespace std;
bool issafe(int board[][10],int i,int j,int n){
    // check col
    for(int row=0;row<i;row++){ 
        if(board[row][j]==1){
            return false;
        }
    }
    // left diagonal
    int x=i;
    int y=j;
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
    x=i;
    y=j;
    while(x>=0 && y<n){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y++;
    }
    return true;
}
bool solvenqueen(int board[][10],int i,int n){
    if(i==n){
        //successfully place queens in n rows
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    cout<<"Q ";
                }
                else{
                    cout<<"_ ";
                }
            }
            cout<<endl;
        }
        // for one 
        // return true;
        // for all
        return false;
    }
    for(int j=0;j<n;j++){
        //check if i,j pos is safe to place the queen
        if(issafe(board,i,j,n)){
            //place queen assuming i,j is right position
            board[i][j]=1;
            bool nextqueen=solvenqueen(board,i+1,n);
            if(nextqueen){
                return true;
            }
            // i,j not in right position 
            board[i][j]=0;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int board[10][10]={0};
    solvenqueen(board,0,n);
    return 0;
}