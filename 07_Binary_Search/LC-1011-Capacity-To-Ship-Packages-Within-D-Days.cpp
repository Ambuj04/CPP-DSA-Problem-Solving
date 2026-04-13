class Solution {
public:
    bool solve(vector<int>& weights, int guess, int days) {
        int k = 1; //start with 1st day
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] <= guess) {
                sum += weights[i];
            } else {
                k++;
                sum = weights[i];
            }
        }
       if(k>days){
        return false;
       }else{
        return true;
       }
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start = INT_MIN; 
        int end = 0;
        for (auto num : weights) {
            end += num;
            start = max(start,num); //because a single package can't be split into parts
        }
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (solve(weights, mid, days)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};