class Solution {
public:
    int titleToNumber(string columnTitle) {
        int columnNum = 0;
        for (int i = 0; i < columnTitle.size(); i++) {
            columnNum = columnNum * 26 + (columnTitle[i] - 'A' + 1);
        }
        return columnNum;
    }
};

/* 
A->1
AA->27
AAA->703
 */