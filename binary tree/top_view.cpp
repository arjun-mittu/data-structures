class Solution
{
public:
    // function should return the topView of the binary tree
    void top_view(Node *root, map<int, pair<int, int>> &m, int hd, int height)
    {
        if (root == NULL)
            return;
        if (m.find(hd) == m.end())
        {
            m[hd] = make_pair(root->data, height);
        }
        else
        {
            if (m[hd].second > height)
            {
                m.erase(hd);
                m[hd] = make_pair(root->data, height);
            }
            /* pair<int,int> p=(m.find(hd))->second;
            if(p.second>height){
                m.erase(hd);
                m[hd]=make_pair(root->data,height);
            }*/
        }
        top_view(root->left, m, hd - 1, height + 1);
        top_view(root->right, m, hd + 1, height + 1);
    }
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        map<int, pair<int, int>> m;
        top_view(root, m, 0, 0);
        for (auto x : m)
        {
            ans.push_back(x.second.first);
        }
        return ans;
    }
};