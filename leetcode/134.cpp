/**

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s = 0, sum = 0, start = 0, mid = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            mid = mid + gas[i] - cost[i];
            if(mid < 0){
                start = i+1;
                mid = 0;
            }
            sum = sum + gas[i] - cost[i];
        }
        if(sum < 0)
            return -1;
        return start;
    }
};
