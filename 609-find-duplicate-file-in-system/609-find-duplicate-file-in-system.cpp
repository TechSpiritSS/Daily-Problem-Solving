class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> files;

		for (auto &s : paths)
		{
			int j = s.size();
			int i = 0;

			string path = "";

			while (i < j && s[i] != ' ')
			{
				path += s[i];
				++i;
			}

			path += "/";
			++i;

			while (i < j)
			{
				string fileName = "";
				string fileExt = "";

				while (i < j && s[i] != '(')
				{
					fileName += s[i];
					++i;
				}

				while (i < j && s[i] != ' ')
				{
					fileExt += s[i];
					++i;
				}

				files[fileExt].push_back(path + fileName);
				++i;
			}
		}

		vector<vector<string>> ans;

		for (auto &i : files)
			if (i.second.size() > 1)
				ans.push_back(i.second);

		return ans;
    }
};