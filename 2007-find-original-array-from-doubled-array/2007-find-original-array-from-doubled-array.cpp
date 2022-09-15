class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int, int> frq;
        
        sort(changed.begin(), changed.end());

		for (int i = 0; i < changed.size(); ++i)
			++frq[changed[i]];

		vector<int> ans;

		for (int i = 0; i < changed.size(); ++i)
		{
            if (changed[i] == 0 && frq[changed[i]] % 2)
                return {};
			if (changed[i] % 2)
			{
				if (frq[changed[i] && frq[changed[i] * 2]])
				{
					ans.push_back(changed[i]);
					--frq[changed[i]];
					--frq[changed[i] * 2];
				}
            }
			else
			{
				if (frq[changed[i] / 2] && frq[changed[i]])
				{
					ans.push_back(changed[i] / 2);
					--frq[changed[i]];
					--frq[changed[i] / 2];
				}
				else if (frq[changed[i] * 2] && frq[changed[i]])
				{
					ans.push_back(changed[i]);
					--frq[changed[i]];
					--frq[changed[i] * 2];
				}
            }
		}

		if (ans.size() * 2 == changed.size())
			return ans;
		return {};
    }
};