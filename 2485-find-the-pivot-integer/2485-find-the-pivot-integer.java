class Solution {
    public int leftSum(int x, int n){
        int sum = 0; 
        
        for(int i=1; i<=x; i++){
            sum += i;
        }

        return sum;
    }
    public int rightSum(int x,int n){
        int sum = 0; 
        
        for(int i=x; i<=n; i++){
            sum += i;
        }
        
        return sum;
    }
    public int pivotInteger(int n) {
        int pivot = -1;

        for(int i = 1; i<=n; i++){
            if(leftSum(i,n) == rightSum(i,n)){
                pivot = i;
            }
        }

        return pivot;
    }
}