// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C
#include<bits/stdc++.h>
using namespace std;
void sort012(int a[],int n)
{
    int lo = 0; 
        int hi = n - 1; 
        int mid = 0; 

        while (mid <= hi) { 
            switch (a[mid]) { 

            // If the element is 0 
            case 0: 
                swap(a[lo++], a[mid++]); 
                break; 

            // If the element is 1 . 
            case 1: 
                mid++; 
                break; 

            // If the element is 2 
            case 2: 
                swap(a[mid], a[hi--]); 
                break; 
            }
        }
         
    
}

// { Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends