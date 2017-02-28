/**
Total Accepted: 42212
Total Submissions: 125084
Difficulty: Medium
Contributors: Admin
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int num = 0;
        int n = citations.size();
        for(int i = 1; i <= n; i++)
        {
            if(citations[n-i] < i)
                break;
            num ++;
        }
        return num;
    }
};
