class Solution {
public:
    
    int n;
    vector<vector<int> > pre; //pre[i] stores the count of each character in word s[i]
    unordered_map<string, int> dp;
    
    int util(string target, vector<int>& t){
        if(target.size()==0)
            return 0;
        if(dp.find(target)!=dp.end())
            return dp[target];
        int flag=0, ans=2e9;
        for(int i=0; i<n; i++){
            vector<int> nt(26, 0);
            for(int j=0; j<26; j++)
                if(t[j]>0 && pre[i][j]>0)
                    nt[j]=max(0, t[j]-pre[i][j]);
                else
                    nt[j]=t[j];
            string nts="";
            for(int j=0; j<26; j++)
                for(int k=1; k<=nt[j]; k++)
                    nts+=(char)(j+'a');
            if(nts!=target){
                flag=1;
                ans=min(ans, 1+util(nts, nt));
            }
        }
        return dp[target]=ans;
    }
    
    int minStickers(vector<string>& s, string target) {
        n=s.size(), pre=vector<vector<int> >(n, vector<int>(26, 0));
        for(int i=0; i<n; i++)
            for(char ch: s[i])
                pre[i][ch-'a']++;
        vector<int> t(26, 0);
        for(char ch: target)
            t[ch-'a']++;
        int ans=util(target, t);
        if(ans>=2e9)
            return -1;
        else
            return ans;
    }
};