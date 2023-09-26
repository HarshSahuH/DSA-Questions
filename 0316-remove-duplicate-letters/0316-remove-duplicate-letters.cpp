class Solution {
public:
    string removeDuplicateLetters(string s) {
       // Initialize two vectors to track character frequencies and whether characters are seen
        vector<int> freq(26, 0);     // freq: to count the frequency of each lowercase letter
        vector<bool> seen(26, 0); // seen: to track if a letter is already in the result
        stack<int> st;               // Create a stack to store the indices of characters
        
        // Count the frequency of each character in the input string 's'
        for (char c : s)
            freq[c - 'a']++;

        // Initialize a deque to store the resulting characters
        deque<char> ans;
        int n = s.size(); // Get the length of the input string 's'

        for (int i = 0; i < n; i++) {
            char c = s[i]; // Current character

            freq[c - 'a']--; // Decrease the frequency of this character since we are considering it

            if (seen[c - 'a']) continue; // If we've already seen this character, skip it

            // Check for characters in the stack that are greater than the current character
            while (!st.empty() && c < s[st.top()] && freq[s[st.top()] - 'a'] > 0) {
                // Pop characters from the stack and mark them as unseen
                seen[s[st.top()] - 'a'] = 0;
                st.pop();
            }

            // Push the current character onto the stack and mark it as seen
            st.push(i);
            seen[c - 'a'] = 1;
        }

        // Pop characters from the stack and add them to the front of the result deque
        while (!st.empty()) {
            ans.push_front(s[st.top()]);
            st.pop();
        }
        
        // Convert the deque to a string and return the result
        return string(ans.begin(), ans.end());
    }
};