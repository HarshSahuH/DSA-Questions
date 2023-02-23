class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> umap;
        vector<int> v ;
        stack<int> s;
        
         for(int i=nums2.size()-1; i>=0; i--){
             int element = nums2[i];
             
             if(s.size()==0)
             {
              umap.insert({element,-1});  
             }
             
             else if(s.size()>0 && s.top() > nums2[i]){
                  umap.insert( {element,s.top()} ); 
             }
             
             else if(s.size()>0 && s.top() < nums2[i]){
                 
                 while(s.size()>0 && nums2[i] >= s.top() ){
                     s.pop();
                 }
                 
                 if(s.size()==0){
                      umap.insert( {element,-1} ); 
                 }
                 else{
                      umap.insert( {element,s.top()} ); 
                 }
             }
    
             s.push(nums2[i]);
         }
        
        
        for(auto x: nums1){
            v.push_back(umap[x]);
        }
     return v;
    }
};