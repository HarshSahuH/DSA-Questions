class Solution {
    int length(string word, unordered_set<string>& s, unordered_map<string, int>& mp) {
        if (word.length() == 0) // checking if the word is "" i.e., empty string
            return 0;
        if (mp.find(word) != mp.end()) //Memoization using Map
            return mp[word];
        int answer = 0;

        //Removing all characters of the word one by one
        for (int i = 0; i < word.length(); i++) {
            string aux = word.substr(0, i) + word.substr(i + 1);
            //Removing character
            //ex - abcd --> aux =  abcd.substr(0, 0)+abcd.substr(1) -- "" + "bcd" = "bcd"
            if (s.find(aux) != s.end())
                answer = max(answer, 1 + length(aux, s, mp)); // Calling the function with the word with Removed character
        }
        mp[word] = answer;
        return answer;
    }
public:
    int longestStrChain(vector<string>& words) {
        unordered_set<string> s;
        for (string x : words)
            s.insert(x);
        int ans = 0;

        unordered_map<string, int> mp;
        // Checking for each word, taking it as last word.
        for (int i = 0; i < words.size(); i++) {
            string w = words[i];
            ans = max(ans, length(w, s, mp));
        }
        return ans + 1;
    }
};