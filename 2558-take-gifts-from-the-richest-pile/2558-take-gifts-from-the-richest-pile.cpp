class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long res = 0;
        for(int x: gifts){
            pq.push(x);
        }
        while(k--){
            pq.push(sqrt(pq.top())); pq.pop();
        }
        while(pq.size()>0){
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};