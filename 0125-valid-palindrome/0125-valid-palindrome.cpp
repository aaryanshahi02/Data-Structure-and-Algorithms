class Solution {
public:
    bool isPalindrome(string s) {
        string t;

        for(char ch:s){
            if(isalnum(ch))
                t+=tolower(ch);
        }

        return t == string(t.rbegin(),t. rend());
    }
};