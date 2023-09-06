class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        
        bitset<sizeof(uint32_t) * 8> binaryRepresentation(n);
        string temp = binaryRepresentation.to_string();
        return count(temp.begin(), temp.end(), '1');
    }
};