class Solution {
public:
     vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int u=1;u<=8;u++){
            int num = u;
            for(int j=u+1;j<=9;j++){
                num = num*10+j;
                if(num>=low && num <=high) ans.push_back(num);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};