// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    string colName (long long int N)
    {
        string res;
        
        while(N)
        {
            int index = N % 26;
            
            if(index == 0)
            {
                res.push_back('Z');
                
                N -= 26;
            }
            else
            {
                res.push_back('A' + (index - 1));
                
                N -= index;
            }
            
            N /= 26;
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends