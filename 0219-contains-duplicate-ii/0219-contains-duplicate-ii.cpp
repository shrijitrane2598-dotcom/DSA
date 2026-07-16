class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int , int> mp;

        for(int i=0; i<nums.size(); i++) {
            if(mp.find(nums[i]) != mp.end() && abs(mp[nums[i]] -i) <= k)  //cheack  abs(i-j) <= k 
            return true;
            else
                mp[nums[i]] = i;   //number , index
        }
        return false;
    }
};