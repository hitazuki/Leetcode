class Solution {
public:
    int dfs(int step, int m, int n, int j, vector<bool> &v) {
        int i, res=0;
        if(step >= m && step <= n){
            res++;
        }
        if(step >= n) return 1;
        for(i=0; i<9; i++){
            if(i == j || v[i]) continue;
            if((j%3==0 && i-j==2 || j%3==2 && j-i==2 || abs(i-j)==6 || i+j==8)
            && v[(i+j)/2]==0) continue;
            v[i] = 1;
            res += dfs(step+1, m, n, i, v);
            v[i] = 0;
        }
        return res;
    }
    int numberOfPatterns(int m, int n) {
        vector<bool> v(9, 0);
        int i, res=0;
        for(i=0; i<9; i++){
            v[i] = 1;
            res += dfs(1, m, n, i, v);
            v[i] = 0;
        }
        return res;
    }
};
