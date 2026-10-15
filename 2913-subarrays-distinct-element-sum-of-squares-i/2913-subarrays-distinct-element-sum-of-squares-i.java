class Solution {
    public int checkHomManyDistinct(List<Integer> curr){
        Set<Integer> s = new HashSet<>();
        for(int i=0; i<curr.size(); i++){
            s.add(curr.get(i));
        }

        return s.size();
    }
    public int sumCounts(List<Integer> nums) {
        int ans = 0;
        int n = nums.size();
        List<List<Integer>> subArrays = new ArrayList<>();

        for(int i=0; i<n; i++){
            List<Integer> temp =  new ArrayList<>();
            for(int j=i; j<n; j++){
                temp.add(nums.get(j));
                subArrays.add(new ArrayList<>(temp));
            }
           
        }
        
        for(int i=0; i<subArrays.size(); i++){
            List<Integer> curr = subArrays.get(i);
            int distinct = checkHomManyDistinct(curr);
            ans += distinct*distinct;
        }

        return ans;
    }
}