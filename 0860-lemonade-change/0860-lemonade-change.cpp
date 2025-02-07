class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int bill: bills){
            if(bill==5) five++;
            else if(bill==10){
                ten++;
                if(five<1) return false;
                five--;
            }
            else{
                if(ten<1 || five<1) return false;
                ten--;
                five--;
            }
        }
        return true;
    }
};