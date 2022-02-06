#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
void Dfs(vector<vector<int>>& A ,int vertex)
{
   if(A[vertex][vertex]==0) //visited
    {
        return;
    }
        
    for(int i=0;i<A.size();i++)
    {
        if(A[vertex][i]==1)
        {
            A[vertex][i]=0; // make 0
            Dfs(A,i);
        }
    }
        
}

int bus(vector<vector<int>>& A) 
    {
       int ans=0;
      for(int i=0;i<A.size();i++)
      {
          if(A[i][i]==1) // not visited
          {
            ans++;
            Dfs(A,i);
          }
      }
      
        return ans;
    }
    
    

void solve()
{
    int n,m;
    cin>>n>>m;
    
     vector<vector<int>> v(n , vector<int> (n, 0));

    for(int i=0;i<n;i++)  // diagonal matrix 
    {
        v[i][i]=1;
    }
   
    for(int j=0;j<m;j++)
    {
        int x,y;
        cin>>x>>y;
        v[x-1][y-1]=1;
        v[y-1][x-1]=1;
    }
   int ans =bus(v);
   cout<<ans<<endl;
}


int32_t main() 
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(nullptr);
    cout.tie(NULL);
	int t=1;
	//cin>>t;
	while(t--)
	{  
	    solve();
	    
	}
	return 0;
}
