class Solution {
public:
     void static merge(vector<int>& nums1, int m, const vector<int>& nums2, int n)
        {
            // We will write from the back of the first array to its front,
            // starting at what will be the last entry in it:
            unsigned write = n + m - 1;
            
            // Make m and n index the last source entry in each of the two input ranges:
            --m;
            --n;
            
            // Loop right to left over input ranges, at each step choosing the,
            // greatest of the two inputs to write into the current destination position:
            while(n >= 0 && m >= 0){
                const int num1 = nums1[m];
                const int num2 = nums2[n];
                nums1[write] = std::max(num1, num2);
                if(num1 > num2){
                    --m;
                } else {
                    --n;
                }
                --write;
            }
            
            // Drain the tail from the input range with spare entries:
            // If the first input is the one with spare, they are already in place
            // so only actually loop if the spares are in the second input and thus
            // need copying over.
            while(n >= 0){
                nums1[write] = nums2[n];
                --n;
                --write;
            }
        }
};