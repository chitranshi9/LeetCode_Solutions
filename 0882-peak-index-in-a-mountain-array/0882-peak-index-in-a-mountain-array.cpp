class Solution {
public:
    int findPeak(vector<int> &arr) {
        int s = 0;
        int e = arr.size()-1;
        int mid = s + (e-s)/2;

        while(s < e) {
            // check for line A
            if(arr[mid] < arr[mid+1]) {
                // search in right
                s = mid+1;
            }
            else {
                // either it is a peak element or on line B
                e = mid;
            }

            // update mid
            mid = s + (e-s)/2;
        }

        return s; // or return e;
    }

    int peakIndexInMountainArray(vector<int>& arr) {
        return findPeak(arr);
    }
};