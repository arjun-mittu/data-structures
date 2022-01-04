class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,k=m-1;
        int j=0;
        while(i<=k && j<n){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                swap(nums1[k],nums2[j]);
                k--;j++;
            }
        }
        sort(nums1.begin(),nums1.begin()+m);
        sort(nums2.begin(),nums2.end());
        for(int itr=0;itr<n;itr++){
            nums1[itr+m]=nums2[itr];
        }
        
    }
};