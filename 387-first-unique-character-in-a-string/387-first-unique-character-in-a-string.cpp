class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mymap;
        int ans = INT_MAX;
        for(int i = 0; i < s.size(); i++){
            if(mymap.find(s[i]) == mymap.end()){
                mymap[s[i]] = i;
            }
            else{
                mymap[s[i]] = INT_MAX;
            }
        }
        for(auto it : mymap){
            ans = min(it.second, ans);
        }
        return (ans == INT_MAX)? -1 : ans;
    }
};