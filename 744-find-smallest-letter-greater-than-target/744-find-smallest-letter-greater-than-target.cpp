class Solution
{
    public:
        char nextGreatestLetter(vector<char> &a, char target)
        {
            int lo = 0, hi = a.size();
            while (lo < hi)
            {
                int mid = lo + (hi - lo) / 2;
                if (target >= a[mid]) lo = mid + 1;
                else hi = mid;
            }
            if(lo == a.size()) lo=0;
            return a[lo];
        }
};