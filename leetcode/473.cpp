/**
Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.

Example 1:
Input: [1,1,2,2,2]
Output: true

Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:
Input: [3,3,3,3,4]
Output: false

Explanation: You cannot find a way to form a square with all the matchsticks.
Note:
The length sum of the given matchsticks is in the range of 0 to 10^9.
The length of the given matchstick array will not exceed 15.
*/
bool cmp(const int & a, const int & b){ return a > b;}
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4) return false;
        int num = 0;
        int sq[4] = {0};
        for(int i = 0; i < nums.size(); i++)
            num += nums[i];
        int len = num / 4;
        sort(nums.begin(), nums.end(), cmp);
        return makesquarehelp(nums, sq, 0, len);
    }
    bool makesquarehelp(vector<int>& nums, int sq[], int ix, int target)
    {
        if(ix == nums.size())
        {
            if(sq[0] == target&& sq[1] == target && sq[2] == target && sq[3] == target)
                return true;
            return false;
        }
        for(int i = 0; i < 4; i++)
        {
            if(sq[i] + nums[ix] > target)
                continue;
            sq[i] += nums[ix];
            if(makesquarehelp(nums, sq, ix+1, target))
                return true;
            sq[i] -= nums[ix];
        }
        return false;
    }
};
