class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(128);
        int required = s1.size();

        for (const char c : s1)
        {
            ++count[c];
        }

        for (int windowStart = 0, windowEnd = 0; windowEnd < s2.size(); ++windowEnd)
        {
            if (--count[s2[windowEnd]] >= 0)
            {
                --required;
            }
            while (required == 0)
            {
                if (windowEnd - windowStart + 1 == s1.size())
                {
                    return true;
                }

                if (++count[s2[windowStart++]] > 0)
                {
                    ++required;
                }
            }
        }

        return false;
    }
};