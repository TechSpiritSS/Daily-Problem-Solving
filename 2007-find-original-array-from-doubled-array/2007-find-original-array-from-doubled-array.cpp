class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2) return {};
		sort(changed.begin(), changed.end());
		vector<int> ans;
		map<int, int> frq;

		for (auto &i : changed)
			++frq[i];

		for (auto &i : changed)
		{
			if (frq[i] == 0) continue;
			--frq[i]; 
            
            if (frq[i * 2] == 0) return {};
			--frq[i * 2];
            
			ans.push_back(i);
		}
		return ans;
    }
};