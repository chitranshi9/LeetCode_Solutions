class Solution {
public:
    long long int binarySearch(int n) {
        long long int tempAns = 0;
        long long int s = 0;
        long long int e = n;
        long long int mid = s + (e-s)/2;

        while(s <= e) {
            if(mid*mid == n) {
                return mid;
            }
            else if (mid*mid > n) {
                // left search
                e = mid-1;
            }
            else {
                // store ans and search in right for nearest possible ans
                tempAns = mid;
                s = mid+1;
            }

            mid = s + (e-s)/2;
        }

        return tempAns;
    }

    int mySqrt(int x) {
        return binarySearch(x);
    }
};