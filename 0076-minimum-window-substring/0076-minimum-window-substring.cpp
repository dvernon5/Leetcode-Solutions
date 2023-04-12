class Solution {
public:
    string minWindow(string s, string t) {
       int start = 0, minLength = INT_MAX;
       int left = 0, right = 0;
       unordered_map<char, int> needs;
       unordered_map<char, int> windows;

       for (char ch : t)
       {
           needs[ch]++;
       }

       int match = 0;

       while (right != s.size())
       {
           char ch1 = s[right];
           if (needs.count(ch1))
           {
               windows[ch1]++;
               if (windows[ch1] == needs[ch1])
               {
                   match++;
               }
           }
           right++;

           while (match == needs.size())
           {
               if (right - left < minLength)
               {
                   start = left;
                   minLength = right - left;
               }

               char ch2 = s[left];
               if (needs.count(ch2))
               {
                   windows[ch2]--;
                   if (windows[ch2] < needs[ch2])
                   {
                       match--;
                   }
               }

               left++;
           }
       }

       return minLength == INT_MAX ? "" : s.substr(start, minLength);
    }
};