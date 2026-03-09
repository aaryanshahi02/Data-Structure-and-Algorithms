class Solution {

class Dsu{
    vector<int> parent;

public:
    Dsu(int n){
        parent.resize(n);
        for(int i=0; i<n; i++)
            parent[i] = i;
    }

    int find(int i){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = find(parent[i]);
        }

    void unite(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if(pa != pb) parent[pb] = pa;
    }

    int countSets(int n){
        int count = 0;
        for(int i=0; i<n; i++){
            if(parent[i] == i){
            count++;
        }
        }
        return count;
    }
};

    public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        Dsu dsu(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){
                    dsu.unite(i, j);
                }
            }
        }
        return dsu.countSets(n);
    
    }
};