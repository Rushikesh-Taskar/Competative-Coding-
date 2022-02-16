     
// for adjecentry matrix 
vector<int>adj[V];
     
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(edges[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    edges[i][j]=0;
                    edges[j][i]=0;
                }
                
            }
             
        }


// for vector of vector with 2 value in middle vector
vector<int>adj[V];
        for(int i=0;i<edges.size();i++)
        {
             adj[edges[i][1]-1].push_back(edges[i][0]-1);
             adj[edges[i][0]-1].push_back(edges[i][1]-1);
             
        }

