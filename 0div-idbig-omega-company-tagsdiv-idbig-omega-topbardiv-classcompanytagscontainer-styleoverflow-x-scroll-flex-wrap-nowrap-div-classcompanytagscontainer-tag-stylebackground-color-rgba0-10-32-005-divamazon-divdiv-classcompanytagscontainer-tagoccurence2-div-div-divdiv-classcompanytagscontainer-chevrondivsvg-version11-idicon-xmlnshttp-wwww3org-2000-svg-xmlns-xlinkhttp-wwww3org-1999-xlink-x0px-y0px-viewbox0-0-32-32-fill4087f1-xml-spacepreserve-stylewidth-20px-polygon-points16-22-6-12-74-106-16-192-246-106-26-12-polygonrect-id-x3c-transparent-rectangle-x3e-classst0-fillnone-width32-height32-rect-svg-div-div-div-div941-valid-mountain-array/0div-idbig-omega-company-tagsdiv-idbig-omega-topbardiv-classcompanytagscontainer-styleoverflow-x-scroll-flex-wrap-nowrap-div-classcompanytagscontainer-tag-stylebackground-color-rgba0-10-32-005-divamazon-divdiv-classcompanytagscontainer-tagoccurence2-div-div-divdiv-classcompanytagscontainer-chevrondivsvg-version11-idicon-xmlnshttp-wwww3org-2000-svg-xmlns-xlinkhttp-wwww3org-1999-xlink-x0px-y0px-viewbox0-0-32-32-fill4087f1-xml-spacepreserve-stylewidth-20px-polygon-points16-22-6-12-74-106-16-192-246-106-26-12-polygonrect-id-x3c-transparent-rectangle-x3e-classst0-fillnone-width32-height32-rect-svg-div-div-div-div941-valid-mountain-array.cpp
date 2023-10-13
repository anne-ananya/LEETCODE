class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int c = 0, ind = 0, ele = INT_MIN;
        while (ind < arr.size() - 1 && arr[ind] < arr[ind + 1]) {
            ele = arr[ind];
            ind++;
            c++;
        }

        if (c == 0 || ind == arr.size() - 1) {
            return false;
        }

        while (ind < arr.size() - 1 && arr[ind] > arr[ind + 1]) {
            ind++;
        }
        return ind == arr.size() - 1;
    }
};
