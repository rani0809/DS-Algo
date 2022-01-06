class Solution {
public:
    int myAtoi(string s) {
        int num = 0, i = 0, sign = 1;
        
        // Remove whitespaces
        while(iswspace(s[i])) i++;
        
        // Update the sign
        if(s[i] == '-' || s[i] == '+')
        {
            if(s[i] == '-')  
                sign = -1;
            i++;
        }
        
        // Get the number
        while(s[i] >='0' && s[i] <= '9')
        {
            // INT_MAX : 2147483647  (2nd condition check if all the digits are same to INT_MAX excluding the last digit. Then if it's greater then 7 clamp it).
            if(num > INT_MAX / 10 || ((num == INT_MAX / 10) && (s[i] -'0') > 7))
            {
                // Return according to sign
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            num = 10 * num + (s[i] - '0');
            i++;
        }
        //We got the number
        return sign * num;
    }
};