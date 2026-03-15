// User function Template for Java//User function Template for Java
class Solution {
    public void helper(int idx, int[] arr, List<Integer> currSubset, List<Integer> ans, int currSum){
        if(idx == arr.length){
            ans.add(currSum);
            return;
        }
        
        if(idx < arr.length){
            currSubset.add(arr[idx]);
            helper(idx+1,arr,currSubset,ans, currSum+arr[idx]);
            currSubset.remove(currSubset.size()-1);
        }
        helper(idx+1,arr,currSubset,ans, currSum);
    }
    public ArrayList<Integer> subsetSums(int[] arr) {
        ArrayList<Integer> ans = new ArrayList<>();
        ArrayList<Integer> currSubset = new ArrayList<>();
        
        helper(0,arr,currSubset,ans,0);
        
        Collections.sort(ans);
        return ans;
    }
}