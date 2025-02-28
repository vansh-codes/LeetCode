class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char c: s) mp[c]++;
        priority_queue<pair<int, char>> pq;

        for(auto x: mp){
            pq.push({x.second, x.first});
        }

        string res = "";
        while(!pq.empty()){
            int cnt = pq.top().first;
            while(cnt){
                res += pq.top().second;
                cnt--;
            }
            pq.pop();
        }
        return res;
    }
};