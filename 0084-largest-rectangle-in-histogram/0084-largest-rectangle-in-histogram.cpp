class Solution {
    
    void NSL(vector<int>& NSL_index , vector<int>& heights){
        
        stack< pair<int,int> > s;
        int pseudoindex = -1;
        
        for(int i=0; i<heights.size(); i++){
            
            while(s.size()>0 && s.top().first >= heights[i]){
                s.pop();
            }
            if(s.size()==0){
                NSL_index.push_back(pseudoindex);
            }
            
            // agr stack ke top mein arr se chota mil gya tho uska index push kr do
            else if(s.size()>0 && s.top().first < heights[i]){
                 NSL_index.push_back(s.top().second);
            }
          s.push({heights[i],i});  
        }
     return;   
    }
    
    void NSR(vector<int>& NSR_index , vector<int>& heights){
        
        stack<pair<int,int> > s;
        int pseudoindex = heights.size();
        
        for(int i=heights.size()-1; i>=0; i--){
            while(s.size()>0 && s.top().first >= heights[i] ){
                s.pop();
            }
            if(s.size()==0){
                NSR_index.push_back(pseudoindex);
            }
             // agr stack ke top mein arr se chota mil gya tho uska index push kr do
            else if(s.size()>0 && s.top().first < heights[i] ){
                NSR_index.push_back(s.top().second);
            }
         s.push({heights[i],i});     
        }
        
        reverse(NSR_index.begin(),NSR_index.end());
        return;
    }
        
    
public:
    int largestRectangleArea(vector<int>& heights) {
        
        
         
        
        vector<int> NSL_index; 
        vector<int> NSR_index;
        
        vector<int> width(heights.size(),0);
        vector<int> area(heights.size(),0);
        int mx = INT_MIN;
        
        NSL(NSL_index,heights);
        NSR(NSR_index,heights);
        
         for(int i=0; i<heights.size(); i++){
            int left = NSL_index[i];
            int right = NSR_index[i];
  
            width[i]=(right - left - 1);    // width (right - left - 1 );
            area[i] = width[i]*heights[i];
            mx = max(mx,area[i]);
        }
      return mx;  
    }
};
