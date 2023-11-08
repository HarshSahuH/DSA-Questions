class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        long long int x=abs(sx-fx);
        long long int y=abs(sy-fy);
        long long int g=max(x,y);
        if(g>t || (g==0 &&(t<2 and t>0)))
        {
            return false;
        }
        else{
            
            return true;
        }
    }
};