class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        auto comp = [](const vector<int> &u, const vector<int> &v) {
            return u[0] < v[0];
        };
        sort(intervals.begin(), intervals.end(), comp);
        /*for(int i=0;i<intervals.size()-1;i++){
            vector<int> temp;
            if(intervals[i][1]>=intervals[i+1][0]){
                if(intervals[i][0]>=intervals[i+1][1]){
                    temp.push_back(intervals[i][0]);
                    temp.push_back(intervals[i][1]);
                    i++;
                }
                else{
                    temp.push_back(intervals[i][0]);
                    temp.push_back(intervals[i+1][1]);i++;
                }
            }
            else{
                temp.push_back(intervals[i][0]);temp.push_back(intervals[i][1]);
            }
            ans.push_back(temp);
        }*/
        vector<int> temp_ans;
        temp_ans.push_back(intervals[0][0]);
        temp_ans.push_back(intervals[0][1]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (temp_ans[1] >= intervals[i][0])
            {
                if (temp_ans[1] < intervals[i][1])
                {
                    temp_ans[1] = intervals[i][1];
                }
            }
            else
            {
                ans.push_back(temp_ans);
                temp_ans[0] = intervals[i][0];
                temp_ans[1] = intervals[i][1];
            }
        }
        ans.push_back(temp_ans);
        return ans;
    }
};