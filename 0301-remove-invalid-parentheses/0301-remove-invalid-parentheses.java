class Solution {
    public List<String> removeInvalidParentheses(String s) {
        List<String> result = new ArrayList<>();
        if (s == null) return result;

        Set<String> visited = new HashSet<>();
        Queue<String> queue = new LinkedList<>();

        queue.add(s);
        visited.add(s);
        boolean found = false;

        while (!queue.isEmpty()) {
            int size = queue.size();
            Set<String> levelResult = new HashSet<>();

            for (int i = 0; i < size; i++) {
                String curr = queue.poll();

                if (isValid(curr)) {
                    levelResult.add(curr);
                    found = true;
                }

                // If we found valid strings at this level, don't generate next level (more removals)
                if (found) continue;

                // Generate all possible states by removing one parenthesis at a time
                for (int j = 0; j < curr.length(); j++) {
                    char c = curr.charAt(j);
                    if (c != '(' && c != ')') continue; // Skip non-parentheses characters

                    String next = curr.substring(0, j) + curr.substring(j + 1);
                    if (!visited.contains(next)) {
                        visited.add(next);
                        queue.add(next);
                    }
                }
            }

            if (found) {
                result.addAll(levelResult);
                break;
            }
        }

        return result;
    }

    // Helper method to check if a string has valid parentheses
    private boolean isValid(String s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }
}