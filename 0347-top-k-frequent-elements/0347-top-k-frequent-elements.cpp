class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        for(int i: nums){
            mp[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minHeap;

        for(auto x: mp){
            minHeap.push({x.second, x.first});   // frequency, element
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        vector<int> res;
        while(!minHeap.empty()){
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;

        /* unordered_map<int, int> mp;
        for(int i: nums){
            mp[i]++;
        }

        priority_queue<pair<int, int> > pq;

        for(auto x: mp){
            pq.push({x.second, x.first});   // frequency, element
        }

        vector<int> res;
        while(k){
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res; */
    }
};