class Solution
{
    public:
        bool isValid(vector<int> wt, int mid, int days)
        {
            int student = 0, pages = 0;

            for (int i = 0; i < wt.size(); i++)
            {

                if (pages + wt[i] > mid)
                {
                    student++;
                    pages = wt[i];
                    if (pages > mid) return false;
                }
                else
                {
                    pages += wt[i];
                }
            }
            if (student < days) return true;
            return false;
        }
    int shipWithinDays(vector<int> &wt, int days)
    {
        int lo = 0, hi = 0, ans = -1;
        for(int i=0;i<wt.size();i++){
            hi+=wt[i];
            lo=max(wt[i],lo);
        }
        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if (isValid(wt, mid, days))
            {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};