class Solution {
public:
    int findPivotIndex(vector<int> &arr) {
        int s = 0;
        int e = arr.size()-1;
        int mid = s + (e-s)/2;

        while(s < e) {
            // handling 2 conditions where sorted array breaks
            if((mid+1) < arr.size() && arr[mid] > arr[mid+1]){
                return mid;
            }
            if((mid-1) >= 0 && arr[mid] < arr[mid-1]) {
                return mid-1;
            }

            // handling other b.s. conditions for left search & right search
            if(arr[s] >= arr[mid]) { // left search for pivot index
                e = mid-1; 
            } else {
                // right search for pivot index
                s = mid+1;
            }

            mid = s + (e-s)/2;
        }
        return s;
    }

    int binarySearch(vector<int> &arr, int target, int s, int e) {
        int mid = s+(e-s)/2;

        while(s<=e) {
            if(arr[mid] == target) {
                return mid;
            }
            else if(target < arr[mid]) {
                e = mid-1;
            } else {
                s = mid+1;
            }

            mid = s + (e-s)/2;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivotIndex = findPivotIndex(nums);

        if(target >= nums[0] && target <= nums[pivotIndex]) {
            // search in array A
            int ans = binarySearch(nums, target, 0, pivotIndex);
            return ans;
        }

        if(pivotIndex+1 < nums.size() && target >= nums[pivotIndex+1] && target <= nums[nums.size()-1]) {
            // search in array B
            int ans = binarySearch(nums, target, pivotIndex+1, nums.size()-1);
            return ans;
        }

        return -1;
    }
};