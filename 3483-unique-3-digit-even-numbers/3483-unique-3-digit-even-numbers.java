class Solution {
    public boolean check(int unitPlace, int tensPlace, int hundredPlace, int[] count) {
       count[unitPlace]--;
       count[tensPlace]--;
       count[hundredPlace]--;

       boolean isValid = count[unitPlace] >=0 && count[tensPlace]>=0 && count[hundredPlace] >=0;

       count[unitPlace]++;
       count[tensPlace]++;
       count[hundredPlace]++; 

       return isValid;
    }

    public int totalNumbers(int[] digits) {
        int totalDistinctNumber = 0;
        
        // Digits 0-9 ki frequency store karne ke liye simple array
        int[] count = new int[10];
        for (int digit : digits) {
            count[digit]++;
        }

        for (int i = 100; i <= 998; i+=2) {
            int number = i;

            int unitPlace = number % 10;
            number = number / 10;

            int tensPlace = number % 10;
            number = number / 10;

            int hundredPlace = number % 10;

            if (check(unitPlace, tensPlace, hundredPlace, count)) {
                totalDistinctNumber++;
            }
        }
        return totalDistinctNumber;
    }
}