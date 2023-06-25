class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //moorse voting algorithm 
        int element ;
        int cnt = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(cnt == 0){
                element = nums[i];
                cnt++;
            }
            else if(element == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        
        int cnt1=0;
        for(int i=0; i<nums.size(); i++){
            if(element == nums[i]){
                cnt1++;
            }
        }
        if(cnt1 > (nums.size() / 2))
        {
            return element;
        }
        else{
            return -1;
        }
    }
};

//T.C. O(N) + O(N)  = O(N)
//S.C. O(1)