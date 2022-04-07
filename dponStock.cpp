// memoization 
class Solution {
public:
    int findmax(vector<int>& price ,int i,int buy ,vector<vector<int>>& dp)
    {
        
        if(i==price.size())  // base case
        {
            return 0;
        }
        
        if(dp[i][buy]!=-1)
        {
            return dp[i][buy];
        }
        if(buy) // buy condition 
        {
             return dp[i][buy]= max(-price[i]+findmax(price,i+1 ,0 ,dp), findmax(price,i+1,1,dp)); 
            //                     buy                         not buy
        }
        else
        {
          return dp[i][buy] = max(price[i]+findmax(price,i+1 ,1 ,dp) , findmax(price,i+1,0 ,dp));
                             //   sell                     not sell 
        }
        
        
    }
    int maxProfit(vector<int>& prices) 
    {
        vector<vector<int>> dp(prices.size() , vector<int>(2,-1));  // dp for memoization 
        return findmax(prices ,0,1 ,dp);   // start buy or not 
    }
};



// tabulation 
vector<vector<int>> dp(price.size()+1 , vector<int>(2,0));  
        int n= price.size();
      
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<2;buy++)
            {
                
               if(buy) // buy condition 
               {
                    dp[i][buy]= max(-price[i]+dp[i+1][0], dp[i+1][1]); 
                    //                     buy                     not buy
               } 
              else
              {
                   dp[i][buy] = max(price[i]+dp[i+1][1] , dp[i+1][0]);
                             //   sell                     not sell 
              }
                
            }
        }
        
        return dp[0][1];
