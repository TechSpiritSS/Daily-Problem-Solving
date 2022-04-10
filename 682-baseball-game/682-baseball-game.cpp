class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> score;
        
        for (int i = 0; i < ops.size(); ++i)
        {
            int n = score.size() - 1;
            if (ops[i] == "C")
                score.pop_back();
            
            else if (ops[i] == "D")
                score.push_back(score[n] * 2);
            
            else if (ops[i] == "+")
                score.push_back(score[n] + score[n - 1]);
            else
                score.push_back(stoi(ops[i]));
        }
        
        int sum =  0;
        sum = accumulate(score.begin(), score.end(), sum);
        return sum;
    }
};