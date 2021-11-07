class Solution {
public:
    int search(vector<int>& arr, int key) {
        
 int start = 0, end = arr.size()-1;
       while (start <= end){
           long long mid = (start+end)/2;
           if(arr[mid] == key){
               return mid;
           }
           else if (arr[mid] > key){
               end = mid -1;
           }
           else{
               start = mid +1;
           }
       }
       return -1;
    }
};

