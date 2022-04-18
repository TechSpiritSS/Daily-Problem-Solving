class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        short l = arr.size();
        for (int i = 0; i < l; ++i)
            for (int j = i + 1; j < l; ++j)
                if (arr[i] == arr[j] * 2 || (arr[i] * 2 == arr[j]))
                    return true;
        return false;
    }
};