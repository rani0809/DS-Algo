class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr)
    {
        int n = arr.size() ;
        sort(arr.begin(),arr.end()) ;
        
        stack<pair<int,int>> st ;
        
        for(int i=0;i<n-1;i++)
        {
			// Case 1 : Stack is empty
            if(st.empty())
            {
                st.push({arr[i],arr[i+1]}) ;
                continue ;
            }
            
            int diff = arr[i+1]-arr[i] ;
            
            int x = st.top().second - st.top().first ;
			
             // Case 2.1
            if(x<diff)
                continue ;
            
			// Case 2.2
            if(x==diff)
            {
                st.push({arr[i],arr[i+1]}) ; continue ;
            }
            
			//Case 2.3
            while(!st.empty())
                st.pop() ;
            st.push({arr[i],arr[i+1]}) ;
            
        }
        
        vector<vector<int>> ans ;
        
        while(!st.empty())
        {
            ans.push_back({st.top().first,st.top().second}) ;
            st.pop() ;
        }
        
        reverse(ans.begin(),ans.end()) ;
        return ans ;
        
    }
};