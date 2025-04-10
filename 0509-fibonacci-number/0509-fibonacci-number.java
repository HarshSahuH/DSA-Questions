class Solution {

    public int Solve(int n){
        if(n>=0 && n<=1){
            return n;
        }
        int ans = Solve(n-1) + Solve(n-2);
        return ans;
    }


    public int fib(int n) {
        return Solve(n);
    }
}