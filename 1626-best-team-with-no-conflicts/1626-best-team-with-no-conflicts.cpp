class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> v;
        for(int i=0; i<ages.size(); i++){
            v.push_back({ages[i], scores[i]});
        }

        sort(v.begin(), v.end());

        for(int i=0; i<v.size(); i++){
            ages[i] = v[i].first;
            scores[i] = v[i].second;
        }
        int n = scores.size();

        vector<int> dp(n);

        int ans = 0;

        for(int i = 0; i < n; i++){

            dp[i] = scores[i];

            for(int j = 0; j < i; j++){

                if(scores[j] <= scores[i]){
                    dp[i] = max(dp[i], dp[j] + scores[i]);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;

    }
};