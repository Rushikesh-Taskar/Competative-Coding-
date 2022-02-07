class Solution {
public:
    vector<vector<int>> ans;
    void allsubset(vector<int> partialresult ,vector<int> nums)
    {
        if(nums.size()==0)
        {
            ans.push_back(partialresult);
            return;
        }
        int a=nums[0];
        nums.erase(nums.begin());
        allsubset(partialresult,nums);
        partialresult.push_back(a);
        allsubset(partialresult,nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int>partialresult;
        allsubset(partialresult,nums);
        return ans;
    }
};
