class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int maxi = items[0][1];
        for(auto &item: items){
            maxi = max(maxi, item[1]);
            item[1] = maxi;
        }
        vector<int> res;
        int size = items.size();
        for(int q: queries){
            int left = 0, right = size - 1, cnt = 0, mid;
            while(left <= right){
                mid = (right + left)/2;
                if(items[mid][0] <= q){
                    cnt = mid + 1;
                    left = mid + 1;
                } else right = mid - 1;
            }
            if(cnt==0) res.push_back(0);
            else res.push_back(items[cnt-1][1]);
        }
        return res;
    }
};