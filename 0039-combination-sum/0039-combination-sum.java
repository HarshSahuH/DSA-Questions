class Solution {
    public void helper(int idx, int target, int[]candidates,List<List<Integer>> ans, List<Integer>curr_ds){
        if(idx == candidates.length){
            if(target == 0){
                ans.add(new ArrayList<>(curr_ds));
            }
              return ;
        }

        if(candidates[idx] <= target){
            curr_ds.add(candidates[idx]);
            helper(idx, target-candidates[idx], candidates, ans, curr_ds);
            curr_ds.remove(curr_ds.size()-1);
        }

        helper(idx+1, target, candidates, ans, curr_ds);
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> curr_ds = new ArrayList<>();

        helper(0,target,candidates,ans,curr_ds);

        return ans;
    }
}