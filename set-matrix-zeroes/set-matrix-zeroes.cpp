class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        
        int H = matrix.size();
        int W = matrix[0].size();
        
        // find the last 0 row
        int last_0_row = -1;
        for (int y = H - 1; y >= 0 && last_0_row == -1; y--)
            for (int x = 0; x < W; x++)
                if (matrix[y][x] == 0)
                {
                    last_0_row = y;
                    break;
                }
        if (last_0_row == -1)
            return;
        
        // go row by row
        for (int y = 0; y < last_0_row; y++)
        {
            bool this_is_a_0_row = false;
            
            for (int x = 0; x < W; x++)
            {
                if (matrix[y][x] == 0)
                {
                    this_is_a_0_row = true;
                    matrix[last_0_row][x] = 0;
                }
            }
            
            if (this_is_a_0_row)
            for (int x = 0; x < W; x++)
            {
                matrix[y][x] = 0;
            }
        }
        
        // set collums to 0
        for (int y = 0; y < H; y++)
        for (int x = 0; x < W; x++)
        {
            if (matrix[last_0_row][x] == 0)
                matrix[y][x] = 0;
        }
        
        // set the last 0 row 
        for (int x = 0; x < W; x++)
        {
            matrix[last_0_row][x] = 0;
        }
    }
};