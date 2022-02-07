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

// if duplicate element present then result should be unique for that use set 
class Solution {
public:
    set<vector<int>> ans;  //diffrent
    void allsubset(vector<int> partialresult ,vector<int> nums)
    {
        if(nums.size()==0)
        {
            ans.insert(partialresult);  //diffrent
            return;
        }
        
        int a=nums[0];
        nums.erase(nums.begin());
        
        allsubset(partialresult,nums);
        
        partialresult.push_back(a);
        
        allsubset(partialresult,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int>partialresult;
        sort(nums.begin(),nums.end());  // diffrent
        allsubset(partialresult,nums);
        vector<vector<int>> ans1(ans.begin(),ans.end());  //diffrent
        return ans1;
    }
};
