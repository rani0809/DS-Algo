
    class Solution {
public:
    bool isHappy(int n) {
        int sum=0;
        
        while(n!=1){
            while(n){
                sum+=(n%10)*(n%10);
            n/=10;
            }
            n=sum;
            sum=0;
            if(n==4) return false;
            cout<<n<<endl;
        }
        
        return true;
    }
};
