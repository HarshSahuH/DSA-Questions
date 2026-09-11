class Solution {
    public int totalNumbers(int[] digits) {
        int n = digits.length;
        Set<Integer> numList = new HashSet<>();

        for(int hundredPlace=0; hundredPlace<n; hundredPlace++){
            for(int tensPlace=0; tensPlace<n; tensPlace++){
                for(int unitPlace=0; unitPlace<n; unitPlace++){

                    if(hundredPlace != tensPlace &&  tensPlace != unitPlace && unitPlace != hundredPlace){
                        if(digits[unitPlace] %2 == 0){
                            if(digits[hundredPlace] != 0){
                                int number = 100*digits[hundredPlace] + 10*digits[tensPlace] + digits[unitPlace];
                                numList.add(number);
                            }
                        }
                    }
                    
                }
            }
        }
        return numList.size();
    }
}