class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        if (n == 1)
            return ans;

        for (int i = 2; i <= n; i++) {
            string laststring = ans;
            int j = 0;
            int l = ans.size();
            ans = "";

            while (j < l) {
                int count = 0;
                int k = j;

                while (k < l && laststring[j] == laststring[k]) {
                    count++;
                    k++;
                }
                ans += to_string(k - j) + laststring[j];
                j = k;
            }
        }

        return ans;
    }
};
