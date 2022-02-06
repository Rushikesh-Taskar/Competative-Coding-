class Solution {
public:
    
    int largestRectangleArea(vector<int>& h) 
    {
        // lets use concept of monotonic stack 
        // stack which store eleement in incresing order is called monotonic stack 
        h.push_back(0); // to pop all eleemnt at last 
        int n=h.size();
          int area =0;
        stack<int>st;  // store indices 
      
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && h[st.top()]>h[i])
            {
                int height= h[st.top()];
                st.pop();
                int l = st.empty() ? -1 : st.top(); // if empty thrn -1 to result -ve ans because we want                                                                max ans 
                area = max(area , height*(i-l-1));
            }
            st.push(i);
        }
        return area;
       
    }
};
