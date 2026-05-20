class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });

        vector<int> dp(n, 1);

        int ans = 1;

        for(int i=0; i<n; i++){

            for(int prev=0; prev<i; prev++){

                if(check(words[prev], words[i]) && dp[prev] + 1 > dp[i]){
                    dp[i] = dp[prev] + 1;
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }

    bool check(string &a, string &b){

        if(a.size() + 1 != b.size()) return false;

        int i = 0, j = 0;

        while(i < a.size() && j < b.size()){

            if(a[i] == b[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        return i == a.size();
    }
};