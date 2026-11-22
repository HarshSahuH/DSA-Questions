class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        //first we will asume that 1 element of array is the majority element
        int candidate = nums[0];
        int count = 1; 

        //now we traverse and see if nums[i] agr candidate ke equal hai toh 
        // increment count other decrease it
        // aur agr decrease krte time hame 0 aa gya mtlab new candidate mil gya
        for(int i=1; i<nums.length; i++){
            if(count == 0){
                candidate = nums[i];
                count = 1;
            }
            else if(nums[i] != candidate){
                count--;
            }
            else if(nums[i] == candidate){
                count++;
            }
        }

        //verification of that candidate that 
        int majority = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == candidate){
                majority++;
            }
        }

        if(majority > n/2){
            return candidate;
        }else{
            return -1;
        }

    }
}