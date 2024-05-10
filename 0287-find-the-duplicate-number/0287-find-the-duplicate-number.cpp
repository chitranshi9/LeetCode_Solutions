class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Solution 1: Marking Visited
        // int i = 0;
        // while (i < nums.size()) {
        //     int index = abs(nums[i]);
        //     if (nums[index] < 0) {
        //         return index;
        //     } else {
        //         nums[index] *= -1;
        //         i++;
        //     }
        // }
        // return -1;

        // Solution 2: Positioning elements method
        while(nums[0] != nums[nums[0]]){
            swap(nums[0], nums[nums[0]]);
        }

        return nums[0];
    }
};