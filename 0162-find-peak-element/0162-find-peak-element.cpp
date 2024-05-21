class Solution {
public:
    int binarySearch(vector<int> &arr) {
        int s = 0;
        int e = arr.size()-1;
        int mid = s + (e-s)/2;

        while(s < e) {
            if(arr[mid] < arr[mid+1]) {
                // on line A
                s = mid+1; // right search for peak element
            }
            else {
                // either on peak element or line B
                e = mid; // left search without losing peak element
            }

            mid = s + (e-s)/2;
        }

        return s; // or return e;
    }
    int findPeakElement(vector<int>& nums) {
        return binarySearch(nums);
    }
};