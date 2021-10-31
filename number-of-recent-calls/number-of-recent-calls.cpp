//USING DEQUE
class RecentCounter {
public:
    deque<int> dq;
    RecentCounter() {
        return ;
    }
    
    int ping(int t) {
        dq.push_back(t);
        while(!dq.empty() && dq.front()<t-3000)
            dq.pop_front();
        return dq.size();
    }
};