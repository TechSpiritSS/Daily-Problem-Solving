class Solution {
    unordered_map<int, string> hashes;
    int cnt = 0;
    string base = "http://tinyurl.com/";
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        hashes[cnt] = longUrl;
        return base + to_string(cnt++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string x = string(shortUrl.begin() + 19, shortUrl.end());
        return hashes[stoi(x)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));