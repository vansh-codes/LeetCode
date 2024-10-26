class Solution {
private:
    void plusOne9(vector<int>& num, int idx) {
        if(idx==0 && num[idx]==9){
            num[idx]=0;
            num.insert(num.begin(), 1);
            return;
        } 
        else if(num[idx]==9){
            num[idx]=0;
            if(num[idx-1]==9){
                plusOne9(num, idx-1);
            }
            else
                num[idx-1] += 1;
        }
    }

public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> number(digits);
        if (number[number.size() - 1] < 9) {
            number[number.size() - 1] += 1;
            return number;
        } else
            plusOne9(number, number.size()-1);
        return number;
    }
};