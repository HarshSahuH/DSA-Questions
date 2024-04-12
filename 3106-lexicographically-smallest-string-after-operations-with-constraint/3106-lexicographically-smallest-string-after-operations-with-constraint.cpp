class Solution {
    int minDistanceFromA(char ch){
        return min( ch-'a', (26-(ch-'a')) );
    }
public:
    string getSmallestString(string s, int k) {
        for(int i=0; i<s.size(); i++){
            int distance = minDistanceFromA(s[i]);
            if(distance <= k){
                s[i] = 'a';
                k -= distance; 
            }
            else{
                s[i] -= k;
                k = 0;
                break;
            }
        }
        return s;
    }
};