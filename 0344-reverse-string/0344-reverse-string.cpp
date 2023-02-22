class Solution {
public:
    void reverseString(vector<char>& s) {
        
// pushing all character into stack
        stack<int> ans;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            ans.push(ch);
        }
        

// traversing Stack and pushing top element into vector        
        int i=0;
        while(!ans.empty() ){
            s[i]=ans.top();
            ans.pop();
            i++;
        }
    }
};

//T.C. O(n)
// S.C. O(n)