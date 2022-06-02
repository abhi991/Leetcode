class Solution
{
    public:
        int myAtoi(string s)
        {
           	//remove whitespace
            int i = 0;
            while (i < s.length() && s[i] == ' ') i++;
            if (i >= s.length()) return 0;
           	//whitespaces taken care of

           	//signs + or -
            int sign = 1;
            if (s[i] == '-') i++, sign = -1;
            else if(s[i] == '+') i++;
            if (i >= s.length()) return 0;
            //sign done
            
            long long ans = 0;
            for (i; i < s.length() && s[i] >= '0' && s[i] <= '9'; i++)
            {
                ans = ans *10 + s[i] - '0';
                if(ans*sign >= INT_MAX) return INT_MAX;
                if(ans*sign <= INT_MIN) return INT_MIN;     
            }
            return ans * sign;
        }
};