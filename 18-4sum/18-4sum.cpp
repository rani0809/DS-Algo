class Solution{ 

public:

    vector<vector<int> > fourSum(vector<int> &num, int target){
        vector<vector<int> > vvi;
        int n = num.size();
        if(n < 4) return  vvi;
        
        sort(num.begin(), num.end());        
        unordered_map<int, vector<pair<int, int>> > mp;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                mp[num[i]+num[j]].push_back(make_pair(i,j));
            }
        }
        
        for(int i = 0; i < n; i++){
            if(i>0 && num[i] == num[i-1]) continue;
            for(int j = i + 1; j < n; j++){
                if(j > i + 1 && num[j] == num[j-1]) continue;
                int res = target - num[i] - num[j];
                if(mp.count(res)){
                    for(auto it = mp[res].begin(); it != mp[res].end(); it++){
                        int k = (*it).first, l = (*it).second;
                        if(k > j){ // k>j make sure that the second pair has bigger values than the first pair.
                            if(!vvi.empty() && num[i]==vvi.back()[0] && num[j]==vvi.back()[1]
                            && num[k]==vvi.back()[2] && num[l] == vvi.back()[3]){
                                continue; //if the obtained 4 elements are the same as previous one continue to next
                            }
                            vector<int> vi={num[i], num[j], num[k], num[l]};
                            vvi.push_back(vi);
                        } // if k>j
                        
                    }//for it
                }//if
            }// forj
        }//for i
        return vvi;
    }
  };