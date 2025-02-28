template <class T> class MaxPQ {
    vector<T> maxPq;

    void heapify(int i) // O(logN)
    {
        int largest = i;
        int left = i * 2 + 1, right = i * 2 + 2;
        int n = maxPq.size();

        if (left < n && maxPq[largest] < maxPq[left]) {
            largest = left;
        }
        if (right < n && maxPq[largest] < maxPq[right]) {
            largest = right;
        }
        if (largest != i) {
            swap(maxPq[largest], maxPq[i]);
            heapify(largest);
        }
    }

public:
    bool empty() { return maxPq.empty(); }

    T top() { return maxPq[0]; }

    void pop() {
        if (maxPq.size() == 1) {
            maxPq.pop_back();
            return;
        }

        maxPq[0] = maxPq[maxPq.size() - 1];
        maxPq.pop_back();
        heapify(0);
        return;
    }

    void push(T x) {
        maxPq.push_back(x);
        if (maxPq.size() == 1)
            return;
        int i = maxPq.size() - 1;
        while (i != 0) {
            int parent = (i - 1) / 2; // i/2 for 1 based indexing
            if (maxPq[parent] < maxPq[i]) {
                swap(maxPq[i], maxPq[parent]);
                i = parent;
            } else
                break;
        }
    }
};

class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;

        MaxPQ<pair<int, char>> pq;
        for (auto x : mp) { // Insertion takes logn
            pq.push({x.second, x.first});
        }

        string res = "";
        while (!pq.empty()) {
            res += string(pq.top().first, pq.top().second);
            pq.pop();
        }
        return res;

        /* unordered_map<char, int> mp;
        for(char c: s) mp[c]++;
        priority_queue<pair<int, char>> pq;

        for(auto x: mp){    // Insertion takes logn
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
        return res; */
    }
};