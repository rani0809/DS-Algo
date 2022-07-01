class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {            
        sort(boxTypes.begin(), boxTypes.end(), [](auto& lhs, auto& rhs){
           return lhs[1] > rhs[1]; 
        });
        
        int ans = 0;
        for(auto& box : boxTypes) {
            if(truckSize >= box[0]) {
                ans += box[0] * box[1];
                truckSize -= box[0];
            } else {
                ans += box[1] * truckSize;
                return ans;
            }
        }
        
        return ans;
        
    }
};