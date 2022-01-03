class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> set_x,set_y;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    set_x.insert(i);
                    set_y.insert(j);
                }
            }
        }
        for(auto x:set_x){
            for(int j=0;j<matrix[x].size();j++){
                matrix[x][j]=0;
            }
        }
        for(auto y:set_y){
            for(int i=0;i<matrix.size();i++){
                matrix[i][y]=0;
            }
        }
    }
};