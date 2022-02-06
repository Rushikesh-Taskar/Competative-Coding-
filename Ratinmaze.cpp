#include<bits/stdc++.h>
#include<vector>
using namespace std;
 
int ans=0;
void canreach(int i, int j,vector<vector<int>> &m ,vector<vector<int>>& visited)
{
    int n=m.size();
    if(i>=n || j>=n || j<0 || i<0)
    {
        return;
    }
    
    if(i==n-1 && j==n-1)
    {
        ans++;
        return;
    }
        visited[i][j]=1;
        
        //up
        if(i-1>=0 && visited[i-1][j]==0 && m[i-1][j]==0)
        {
         canreach(i-1,j,m,visited);
        }
        
        //down
         if(i+1<n && visited[i+1][j]==0 && m[i+1][j]==0)
         {
          
          canreach(i+1,j,m,visited);
         }
         
        //right
         if(j+1<n && visited[i][j+1]==0 && m[i][j+1]==0)
         {
          
          canreach(i,j+1,m,visited);
         }
         
        //left
         if(j-1>=0 && visited[i][j-1]==0 && m[i][j-1]==0)
         {
          
          canreach(i,j-1,m,visited);
         }
         
        visited[i][j]=0;
}
    
int main() 
{
    int n;
    cin >> n;
    
    vector<vector<int>> vect(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> vect[i][j];
        }
    }
    
    vector<vector<int>> visited(n, vector<int>(n, 0));

    canreach(0,0,vect , visited);

    cout << ans;


}
