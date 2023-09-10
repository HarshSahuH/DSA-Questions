class Solution {
const int md = 1e9 + 7;
public:
    int countOrders(int n) {
        long long count = 1;
        for (int starting = 2; starting <= n; ++starting) {
            count = (count * (2 * starting - 1) * starting) % md;
        }
        return (int)count;
    }
};