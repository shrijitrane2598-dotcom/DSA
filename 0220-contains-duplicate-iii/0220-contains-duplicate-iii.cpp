class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<long long> window; 

        for(int i=0; i<=nums.size()-1; i++) {

        // Find the first element >= nums[i] - valueDiff
            auto it = window.lower_bound((long long)nums[i] - valueDiff);

        // Check if the found element is within valueDiff
            if(it != window.end() && *it <= (long long)nums[i] + valueDiff) {
                return true;
            }

        // Insert current element into the window
            window.insert(nums[i]);

        //keep tha window size <= indexDiff
            if(window.size() > indexDiff) {
                window.erase(window.find(nums[i - indexDiff]));
            }
        }
        return false;
    }
};