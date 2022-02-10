#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    //recursion and memoization 
    int maxcount(int wt[] ,int val[] ,int W ,int i,vector<vector<int>>& dpm)
    {
        if(i==0)
        {
            if(W>=wt[0])
            {
                return val[0];
            }
            return 0;
        }
        if(dpm[i][W]!=-1)
        {
            return dpm[i][W];
        }
        int nottake = 0+maxcount(wt,val ,W,i-1,dpm);
        int take =INT_MIN;
        if(W>=wt[i])
        {
            take =val[i]+maxcount(wt,val,W-wt[i],i-1,dpm);
        }
        dpm[i][W]=max(take,nottake);
        return dpm[i][W];
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        
       
        
        vector<vector<int>> dpm(n,vector<int>(W+1,-1)); // dp for memoization 
          
      //tabulation 
       vector<vector<int>> dp(n,vector<int>(W+1,0));

       for(int i=wt[0];i<=W;i++)
       {
           dp[0][i]=val[0];
       }
       
       for(int i=1;i<n;i++)
       {
           for(int weight =0;weight<=W;weight++)
           {
                  int nottake = 0+dp[i-1][weight];
                  int take =INT_MIN;
                  if(weight>=wt[i])
                  {
                    take =val[i]+dp[i-1][weight-wt[i]];
                  }
                dp[i][weight]=max(take,nottake);
           }
       }
       
       return dp[n-1][W];
      
      //return maxcount(wt,val,W,n-1,dpm);  memoization function 
      
      
      //space optimization 
      vector<int>cur(W+1,0),prev(W+1 ,0);
       
       for(int i=wt[0];i<=W;i++)
       {
           prev[i]=val[0];
       }
       
       for(int i=1;i<n;i++)
       {
           for(int weight =0;weight<=W;weight++)
           {
                  int nottake = 0+prev[weight];
                  int take =INT_MIN;
                  if(weight>=wt[i])
                  {
                    take =val[i]+prev[weight-wt[i]];
                  }
                cur[weight]=max(take,nottake);
           }
           prev=cur;
       }
      
      return cur[W];
    }
};



int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
} 
