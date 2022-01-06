// { Driver Code Starts
// Initial Template for C

#include <stdio.h>

struct pair {
    long long int min;
    long long int max;
};

struct pair getMinMax(long long int arr[], long long int n) ;

int main() {
    long long int t, n, a[100002], i;
    struct pair minmax;

    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);

        for (i = 0; i < n; i++) scanf("%lld", &a[i]);
        minmax = getMinMax(a, n);
        printf("%lld %lld\n", minmax.min, minmax.max);
    }
    return 0;
}// } Driver Code Ends


// User function Template for C

struct pair getMinMax(long long int arr[], long long int n) {
     long long int maxi=0;
     long long int mini=arr[0];
     struct pair s;
     for(long long int i=0; i<=n-1; i++){
         if (maxi<arr[i]){
             maxi = arr[i];
         }
     
         if(mini>arr[i]){
             mini=arr[i];
         }
     }
         s.min=mini;
         s.max=maxi;
     
     return s;
    
}