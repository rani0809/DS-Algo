class Solution {
public:
    bool canIWin(int M, int T) 
  {
    int sum = M*(M+1)/2; // sum of entire choosable pool

    // I just pick 1 to win
    if (T < 2) return true;
    
    // Total is too large, nobody can win
    else if (sum < T) return false;
    
    // Total happens to match sum, whoever picks at odd times wins
    else if (sum == T) return M%2;
    
    // Non-trivial case: do DFS
    // Initial total: T
    // Initial game state: k = 0 (all numbers are not picked)
    else return dfs(M, T, 0);
  }

  // DFS to check if I can win
  // k: current game state
  // T: remaining total to reach
  bool dfs(int M, int T, int k) 
  {
    // memorized
    if (mem[k] != 0) return mem[k] > 0;
    
    // total is already reached by opponent, so I lose
    if (T <= 0) return false;

    // try all currently available numbers
    for (int i = 0; i < M; ++i)
      // if (i+1) is available to pick and my opponent can't win after I picked, I win!
      if (!(k&(1<<i)) && !dfs(M, T-i-1, k|(1<<i))) {
        mem[k] = 1;
        return true;
      } 
    
    // Otherwise, I will lose
    mem[k] = -1;
    return false;      
  }

  // m[key]: memorized game result when pool state = key
  // 0: un-computed; 1: I win; -1: I lose
  int mem[1<<20] = {};
};