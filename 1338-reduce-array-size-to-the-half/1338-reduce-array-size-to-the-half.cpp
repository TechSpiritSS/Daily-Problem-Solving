class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        unordered_map<int, int> count;

        for (auto &i : arr)
            ++count[i];

        vector<std::pair<int, int>> arr2;
        for (const auto &item : count)
            arr2.emplace_back(item);

        std::sort(arr2.begin(), arr2.end(),
                  [](const auto &x, const auto &y)
                  { return x.second > y.second; });

        int ans = 0;
        int size = arr.size();
        int half = size / 2;

        for (auto &i : arr2)
        {
            size -= i.second;
            ++ans;
            if (size <= half)
                break;
        }
        return ans;
    }
};