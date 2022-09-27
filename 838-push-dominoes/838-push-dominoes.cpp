class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
		vector<int> push(n);

		int currPush = 0;
		for (int i = 0; i < n; ++i)
		{
			if (dominoes[i] == 'R') currPush = n;
			else if (dominoes[i] == 'L') currPush = 0;
			else currPush = max(currPush - 1, 0);
			push[i] += currPush;
		}

		currPush = 0;
		for (int i = n - 1; i >= 0; --i)
		{
			if (dominoes[i] == 'R') currPush = 0;
			else if (dominoes[i] == 'L') currPush = n;
			else currPush = max(currPush - 1, 0);
			push[i] -= currPush;
		}

		string ans = "";
		for (auto &i : push)
		{
			if (i > 0) ans += 'R';
			else if (i < 0) ans += 'L';
			else ans += '.';
		}
		return ans;
    }
};