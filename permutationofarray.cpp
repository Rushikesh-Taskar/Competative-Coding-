
// all permutation
class Solution {
public:
    vector<vector<int>> ans;
    void permute(vector<int>& nums ,int start ,int end)
    {
        if(start==end)
        {
            ans.push_back(nums);
        }
        else
        {
            for(int i=start;i<=end;i++)
            {
                swap(nums[start],nums[i]);
                permute(nums,start+1,end);
                swap(nums[start],nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        permute(nums,0,nums.size()-1);
        return ans;
    }
};

// next nermutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n= nums.size();
       int i=n-2;
        while(i>=0 && nums[i+1]<=nums[i])
        {
           i--;
        }
        
        if(i>=0)
        {
            for(int j=n-1;j>=0;j--)
            {
              if(nums[i]<nums[j])
              {
                swap(nums[j],nums[i]);
                break;
              }
            }
        
        }
      // for 3 2 1 ans is 1 2 3 
        reverse(nums.begin()+i+1 ,nums.end());
        
    }
};
