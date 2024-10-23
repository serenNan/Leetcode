class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char> list;
        int front = 0,back = 0;
        int ans = 0;
        while(front < s.size())
        {
            if(list.find(s[front]) == list.end())
            {
                list.insert(s[front++]);
            }
            else
            {
                list.erase(s[back++]);
            }
            ans = max(ans,(front - back));
        }
        return ans;
    }
};
