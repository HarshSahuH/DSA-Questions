class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        int[] candyArr = new int[n];
        Arrays.fill(candyArr,1);

        for(int i=0; i<n-1; i++){
            if(ratings[i+1] > ratings[i]){
                candyArr[i+1] = candyArr[i]+1;
            }
        }

        for(int i= n-1; i>0; i--){
            if(ratings[i-1] > ratings[i]){
                if(candyArr[i-1] <= candyArr[i]){
                    candyArr[i-1] = candyArr[i]+1;
                }
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += candyArr[i];
        }

        return ans;
    }
}