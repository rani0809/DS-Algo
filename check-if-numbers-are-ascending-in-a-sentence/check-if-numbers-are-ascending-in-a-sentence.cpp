class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.size();
        vector<int> nums; //to store all the numbers
        int i;
        for(i = 0;i<n;i++){
            if(isdigit(s[i])){
                string temp; //to store the numbers having more than 1 digit, like 12, 334....
				
                while(i<n && isdigit(s[i]))temp+=s[i++];
				
                nums.push_back(stoi(temp)); //convert string to integer and store in the vector
            }            
        }
        for(i=0;i<nums.size()-1;i++){
            if(nums[i]>=nums[i+1])return false; //check whether the array is sorted or not
        }
        return true;
    }
};