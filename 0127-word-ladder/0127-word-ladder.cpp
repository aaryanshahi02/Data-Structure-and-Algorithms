class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        queue<pair<string, int>> q;
        vector<int> vis(n);
        unordered_set<string> st(wordList.begin(), wordList.end());

        q.push({beginWord, 1});
        st.erase(beginWord);

        if(!st.count(endWord)) return 0;

        while(!q.empty()){
            auto[currWord, currDist] = q.front();
            q.pop();
            if (currWord == endWord)
                return currDist;

            for(int i=0; i<currWord.length(); i++){
                char og = currWord[i];

                for(char j='a'; j<='z'; j++){
                    currWord[i] = j;
                    if(st.count(currWord)){
                        q.push({currWord, currDist+1});
                        st.erase(currWord);
                    }
                }
                currWord[i] = og;
            }
        }

        return 0;
    }
};