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
    vector<int> ans;
    int i = 0;
    
    void check(NestedInteger x)
    {
        if (x.isInteger())
            ans.push_back(x.getInteger());
        else
            for (auto &z : x.getList())
                check(z);
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto &x : nestedList)
            check(x);
    }
    
    int next() {
        return ans[i++];
    }
    
    bool hasNext() {
        return i < ans.size();
    }
};
