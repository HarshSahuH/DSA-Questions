class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> freq = new HashMap<>();
        StringBuilder ans = new StringBuilder();
        
        for (char c : s.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }

        List<Character> chars = new ArrayList<>(freq.keySet());
        chars.sort((a, b) -> freq.get(b) - freq.get(a));

        for (char c : chars) {
            for (int i = 0; i < freq.get(c); i++) {
                ans.append(c);
            }
        }

        return ans.toString();
    }
}
