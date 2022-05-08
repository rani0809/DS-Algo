/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int>v;
    int pos=0;
    void flatter(vector<NestedInteger> &nestedlist){
        for(auto it: nestedlist){
            if(it.isInteger()){
                v.push_back(it.getInteger());
            }else{
                flatter(it.getList());
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatter(nestedList);
    }
    
    int next() {
        return v[pos++];
    }
    
    bool hasNext() {
        return pos<v.size();
    }
};
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */