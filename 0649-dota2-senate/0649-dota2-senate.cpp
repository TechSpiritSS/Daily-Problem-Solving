class Solution {
public:
    string predictPartyVictory(string senate) { 
        int n = senate.size();
        queue<int> rQueue, dQueue;

        for (int i = 0; i < n; ++i)
            if (senate[i] == 'R') rQueue.push(i);
            else dQueue.push(i);
            
        while (!rQueue.empty() && !dQueue.empty()) 
        {
            int rTurn = rQueue.front();
            rQueue.pop();
            int dTurn = dQueue.front();
            dQueue.pop();
            
            if (dTurn < rTurn) dQueue.push(dTurn + n);
            else rQueue.push(rTurn + n);
        }

        return rQueue.empty() ? "Dire" : "Radiant";
    };
};