class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int, int> mp;
        for (int x : arr)
            mp[x]++;
        
        if(mp[0]>=2) return true;

        for (int i = 0; i < arr.size(); i++) {
            if(arr[i]==0) continue;
            if (mp.find(arr[i] * 2) != mp.end())
                return true;
            if (arr[i] % 2 == 0)
                if (mp.find(arr[i] / 2) != mp.end())
                    return true;
        }
        return false;
    }
};