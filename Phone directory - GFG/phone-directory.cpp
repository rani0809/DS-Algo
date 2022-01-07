// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<vector<string>> displayContacts(int n, string A[], string s) {
        vector<string> contact = removeDuplicates(A, n);
        vector<vector<string>> res;
        res.push_back(contact);
        
        // O(S)
        for(int i = 0; i < (int)s.size(); i++) {
            vector<string> curr;
            // O(N)
            for(int j = 0; j < (int)res.back().size(); j++) {
                // O(K)
                if(res.back()[j][i] == s[i]) curr.push_back(res.back()[j]);
            }
            if(curr.empty()) curr.push_back("0");
            
            // To remove the dummy vector
            if(i == 0) res.pop_back();
            res.push_back(curr);
        }
        
        return res;
    }
    
    // TC -> O(K * NlogN), SC -> O(K * N)
    vector<string> removeDuplicates(string contact[], int n) {
        set<string> unqStrings(contact, contact + n);
        return vector<string>(unqStrings.begin(), unqStrings.end());
    }
};
// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends