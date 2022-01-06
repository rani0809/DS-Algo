class Solution {
public:
    
    static bool comp(vector<int> lhs, vector<int> rhs)
    {
        if(lhs[1]<rhs[1] || (lhs[1]==rhs[1] && lhs[2]<rhs[2]))
            return true ;
        return false ;
    }
        
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        int n = trips.size() ;
		
        sort(trips.begin(),trips.end(),comp) ;
        
        int curr = 0 ;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // destinaton , numpassengers
        
        for(int i=0;i<n;i++)
        {
			// step - 1 : 
            while(!pq.empty() && pq.top().first<=trips[i][1])
            {
                curr-=pq.top().second ;
                pq.pop() ;
            }
            
			//step - 2
            pq.push({trips[i][2],trips[i][0]}) ;
            curr+=trips[i][0] ;
			
			//step - 3
            if(curr>capacity)
                return false ;
        }
		
        return true ;  
    }
};