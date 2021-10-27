class Solution 
{
public:
    void reverse(vector<char>& s,int left,int right)
    {
        if(left > right)
            return ;
        
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
 
        reverse(s,left+1,right-1);
    }
    void reverseString(vector<char>& s) 
    {
        reverse(s,0,s.size()-1);
    }
};