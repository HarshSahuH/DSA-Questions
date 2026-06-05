class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
         // If total cards can't be divided evenly, return false
        if (hand.length % groupSize != 0) return false;

        // Store the frequency of each card
        TreeMap<Integer, Integer> freq = new TreeMap<>();
        for (int card : hand) {
            freq.put(card, freq.getOrDefault(card, 0) + 1);
        }

        // Loop through all keys in the map
        while (!freq.isEmpty()) {

            // Start of the current group
            int start = freq.firstKey();

            // Number of groups to form starting from this card
            int count = freq.get(start);

            // Try to build a group of size groupSize
            for (int i = 0; i < groupSize; i++) {
                int card = start + i;

                // If the card is not present or has fewer frequency
                if (!freq.containsKey(card) || freq.get(card) < count) return false;

                // Decrease the frequency
                if (freq.get(card) == count) freq.remove(card);
                else freq.put(card, freq.get(card) - count);
            }
        }

        // All groups formed successfully
        return true;
    }
}