class Solution {
    class Interval {
        int start, end, weight, id;

        Interval(int start, int end, int weight, int id) {
            this.start = start;
            this.end = end;
            this.weight = weight;
            this.id = id;
        }
    }

    class Result {
        long weight;
        List<Integer> indices;

        Result(long weight, List<Integer> indices) {
            this.weight = weight;
            this.indices = indices;
        }
    }

    public Result[][] memo;

    private Result solve(int i, int count, Interval[] arr) {
        //base case
        if (count == 0 || i == arr.length) {
            return new Result(0, new ArrayList<>());
        }

        if (memo[i][count] != null) {
            return memo[i][count];
        }

        //option 1 skip
        Result skip = solve(i + 1, count, arr);

        //option 2 take 
        int next = nextIndex(arr, i);
        Result takeNext = solve(next, count - 1, arr);

        List<Integer> takeList = new ArrayList<>();
        takeList.add(arr[i].id);
        takeList.addAll(takeNext.indices);
        Collections.sort(takeList);

        Result take = new Result(arr[i].weight + takeNext.weight, takeList);

        Result best = compare(skip, take);

        return memo[i][count] = best;
    }

    public Result compare(Result r1, Result r2) {
        if (r1.weight > r2.weight)
            return r1;
        if (r2.weight > r1.weight)
            return r2;

        // Weight equal hone par Lexicographically smaller list chunna hai
        int size = Math.min(r1.indices.size(), r2.indices.size());
        for (int k = 0; k < size; k++) {
            int cmp = Integer.compare(r1.indices.get(k), r2.indices.get(k));
            if (cmp < 0)
                return r1;
            if (cmp > 0)
                return r2;
        }

        return r1.indices.size() <= r2.indices.size() ? r1 : r2;

    }

    public int nextIndex(Interval[] arr, int currIndex) {
        int n = arr.length;
        int target = arr[currIndex].end;
        int low = currIndex + 1;
        int high = n - 1;
        int ans = arr.length;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid].start > target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    public int[] maximumWeight(List<List<Integer>> intervals) {
        int n = intervals.size();
        Interval[] arr = new Interval[n];

        for (int i = 0; i < n; i++) {
            List<Integer> curr = intervals.get(i);
            arr[i] = new Interval(curr.get(0), curr.get(1), curr.get(2), i);
        }

        //Step 1
        // Sort by start time, agar start time same hai toh original id ke basis pe
        Arrays.sort(arr, (a, b) -> {
            if (a.start != b.start) {
                return Integer.compare(a.start, b.start);
            } else {
                return Integer.compare(a.id, b.id);
            }
        });

        //Step 3
        memo = new Result[n][5];
        Result bestResult = solve(0,4,arr);

        int []ans = new int[bestResult.indices.size()];
        for(int i=0; i<ans.length; i++){
            ans[i] = bestResult.indices.get(i);
        }

        return ans;
    }
}