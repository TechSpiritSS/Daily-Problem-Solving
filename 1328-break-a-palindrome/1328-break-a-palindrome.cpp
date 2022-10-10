class Solution {
    bool isPalindrome(string s)
	{
		int i = 0, j = s.size() - 1;
		while (i < j)
		{
			if (s[i] != s[j]) return false;
			++i;
			--j;
		}
		return true;
	}

public:
	string breakPalindrome(string palindrome)
	{
		if (palindrome.size() <= 1) return "";
		string s = palindrome;
		for (int i = 0; i < palindrome.size(); ++i)
			if (palindrome[i] != 'a') 
            {
				palindrome[i] = 'a';
				if (!isPalindrome(palindrome)) return palindrome;
				else palindrome[i] = s[i];
			}
		
		palindrome.back() = 'b';
		return palindrome;
    }
};