class WordFilter {
public:
    unordered_map<string, int> mp;
    
    WordFilter(vector<string>& words) {
        mp.clear();
        
        for(int k = 0; k < words.size(); ++k)
        {
            string x = words[k];
            string s;
			for(int i = 0; i < x.length(); ++i)
            {
                s += x[i];
                s += "#";
                string q;
                for (int j = x.length() - 1;j >= 0; --j)
                {
                    q += x[j];
                    string a = q;
                    reverse(a.begin(), a.end());
                    string ans = s + a;
                    mp[ans] = k;
                }
                s.pop_back();
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string s = prefix + "#" + suffix;
        if (mp.find(s) == mp.end())
            return -1;
        return mp[s];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */