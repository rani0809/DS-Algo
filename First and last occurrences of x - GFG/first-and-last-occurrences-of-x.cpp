// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends


int bsearch2(int arr[],int s,int e,int x ){
   int l=s;
   int r=e-1;
   int ans=-1;
   while(r>=l){
       int mid=l+(r-l)/2;
       if(arr[mid]==x){
           ans=mid;
           l=mid+1;
       }
       else if(arr[mid]>x){
           r=mid-1;
       }
       else{
           l=mid+1;
       }
   }
   return ans;
}
int bsearch1(int arr[],int s,int e,int x ){
   int l=s;
   int r=e-1;
   int ans=-1;
   while(r>=l){
       int mid=l+(r-l)/2;
       if(arr[mid]==x){
           ans=mid;
           r=mid-1;
       }
       else if(arr[mid]>x){
           r=mid-1;
       }
       else{
           l=mid+1;
       }
   }
   return ans;
}
vector<int> find(int arr[], int n , int x ){ 
   // code here
    vector<int> o(2);
   o[0] = bsearch1(arr,0,n,x);
   o[1] = bsearch2(arr,0,n,x);
   
   return o;
}