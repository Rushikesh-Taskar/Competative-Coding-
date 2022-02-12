// print all ways 
class Solution {
public:
    int sum;
    vector<vector<int>>ans;
     void count(vector<int>& nums ,int target , vector<int> dp ,int start)
    {
         if(target==0)
         {
            ans.push_back(dp);
             return;
         }
         
         if(target<0)
         {
             return;
         }
         
        for(int i=start;i<nums.size();i++)
        {
            dp.push_back(nums[i]);
            count(nums ,target-nums[i] ,dp, i); //i=0 if duplicate are also allowed 
            dp.pop_back(); // backtracking
        }
         
     }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        sum=target;
        sort(nums.begin(),nums.end());
        vector<int> dp;
        count(nums,target,dp ,0);
        return ans;
    }
};
// each index only onces 
class Solution {
public:
    
    vector<vector<int>>ans;
    void count(vector<int>& nums ,int target , vector<int> dp ,int start)
    {
         if(target==0)
         {
            ans.push_back(dp);
             return;
         }
         
         if(target<0)
         {
             return;
         }
         
        for(int i=start;i<nums.size();i++)
        {  
            if(i>start && nums[i]==nums[i-1])
            {    
                continue;
            }
            dp.push_back(nums[i]);
            count(nums ,target-nums[i] ,dp, i+1);  
              dp.pop_back(); // backtracking
        }
         
     }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target)
    {
         vector<int> dp;
        sort(nums.begin(),nums.end());
        count(nums,target,dp ,0);
        return ans;
    }
};

// count all ways
class Solution {
public:
    
    int count(vector<int>& nums ,int target , vector<int>& dp)
    {
         if(target==0)
         {
               return 1;
         }
         if(target<0)
         {
             return 0;
         }
        if(dp[target]!=-1)
        {
            return dp[target];
        }
        
        int ans =0;
        for(auto it :nums)
        {
            ans=ans+count(nums ,target-it ,dp);
        }
        
        dp[target]=ans;
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) 
    {
        int n= nums.size();
        
       vector<int> dp(target+1,-1);
        
        return count(nums,target,dp);
    }
};

