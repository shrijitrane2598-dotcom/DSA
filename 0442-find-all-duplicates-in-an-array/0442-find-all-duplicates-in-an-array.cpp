class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;                  //store tha result 

        for (int i=0; i<n; i++) {
            int num = abs(nums[i]);          //abs is used to -ve number conver into +ve number 

            int idx = num-1;                 //idx will -1 chake 

            if(nums[idx] < 0) {              // if tha idx is allradey -ve that tha my ans....
                result.push_back(num);
            } else {
                nums[idx] *= -1;
            }
        } 

        return result;
    }
};