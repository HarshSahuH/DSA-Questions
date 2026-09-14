class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {

        //overlap 
        //X range mein overlap 
        boolean xRangeOverlap = rec1[0] < rec2[2] && rec2[0] < rec1[2];
        //Y range mein overlap
        boolean yRangeOverlap = rec1[1] < rec2[3] && rec2[1] < rec1[3];
        
        //both x and y range mein overlap then true
        if(xRangeOverlap && yRangeOverlap){
            return true;
        }

        return false;

    }
}