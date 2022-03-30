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
