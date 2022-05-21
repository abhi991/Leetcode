class Solution
{
    public:
        int firstOcc(vector<int> nums, int x)
        {
            int lo = 0, hi = nums.size()-1;
            int index = -1;
            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;

                if (nums[mid] >= x)
                {
                    hi = mid - 1;
                }
                else lo = mid + 1;
                if (nums[mid] == x) index = mid;
            }
            return index;
        }
    int lastOcc(vector<int> nums, int x)
    {
        int lo = 0, hi = nums.size()-1;
        int index = -1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] <= x)
            {
                lo = mid + 1;
            }
            else hi = mid - 1;
            if (nums[mid] == x) index = mid;
        }
        return index;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        int n = firstOcc(nums, target);
        int m = lastOcc(nums, target);
        ans.push_back(n);
        ans.push_back(m);
        return ans;
    }
};