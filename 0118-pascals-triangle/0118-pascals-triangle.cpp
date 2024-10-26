class Solution {
private:
    void fillTriangle(vector<vector<int>>&pascal, int n, int index){
        if(index>n) return;
        vector<int> temp(index, 1);
        if(index==1 || index==2){
            pascal.push_back(temp);
        }
        else{
            for(int i = 1;i<index-1;i++){
                temp[i] = pascal[pascal.size()-1][i-1] + pascal[pascal.size()-1][i];
            }
            pascal.push_back(temp);
        }
        fillTriangle(pascal, n, index+1);
    }

public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        fillTriangle(pascal, numRows, 1);
        return pascal;
    }
};