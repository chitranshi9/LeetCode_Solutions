class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;

        while(i < nums.size())
        {
            int index = abs(nums[i]);

            if(nums[index] < 0) {
                return index;
            }
            else {
                nums[index] *= -1;
                i++;
            }
        }

        return -1;
    }
};