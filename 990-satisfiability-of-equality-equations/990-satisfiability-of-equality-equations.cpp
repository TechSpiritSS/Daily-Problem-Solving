class Solution {
    int val[26];

	int pos(int i) {
		return val[i] == i ? i : val[i] = pos(val[i]);
	}

public:
	bool equationsPossible(vector<string> &equations) {
		for (int i = 0; i < 26; ++i) val[i] = i;

		for (auto &i : equations)
			if (i[1] == '=') val[pos(i[0] - 'a')] = pos(i[3] - 'a');

		for (auto &i : equations)
			if (i[1] == '!' && pos(i[0] - 'a') == pos(i[3] - 'a')) return false;

		return true;
	}
};