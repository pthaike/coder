class Solution {
public:
    string convertToBase7(int num) {
        int mod = num >= 0 ? num : -num;
        string ret = "";
        do
        {
            int less = mod % 7;
            ret = to_string(less) + ret;
            mod = mod / 7;
        }while (mod);
        return num >= 0 ? ret : "-" + ret;
    }
};
