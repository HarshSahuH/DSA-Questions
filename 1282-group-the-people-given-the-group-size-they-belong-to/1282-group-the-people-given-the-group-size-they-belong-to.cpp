class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> result;
        
        // A map from group size to the list of indices that are there in the group.
        vector<int> size_To_Group[groupSizes.size() + 1];
        
        for (int i = 0; i < groupSizes.size(); i++) {
            size_To_Group[groupSizes[i]].push_back(i);
            
            // When the list size equals the group size, empty it and store it in the answer.
            if (size_To_Group[groupSizes[i]].size() == groupSizes[i]) {
                result.push_back(size_To_Group[groupSizes[i]]);
                size_To_Group[groupSizes[i]].clear();
            }
        }
        
        return result;
    }
};