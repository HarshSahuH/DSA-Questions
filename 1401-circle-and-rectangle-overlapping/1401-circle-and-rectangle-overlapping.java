class Solution {
    public boolean checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        
        long xCloset ;
        if(x1 > xCenter){
            xCloset = x1;
        }
        else if(xCenter > x2) {
            xCloset = x2;
        }
        else{
            xCloset = xCenter;
        }

        long yCloset ;
        if(y1 > yCenter){
            yCloset = y1;
        }
        else if(yCenter > y2) {
            yCloset = y2;
        }
        else{
            yCloset = yCenter;
        }

        long xDistance = Math.abs(xCenter - xCloset); 
        long yDistance = Math.abs(yCenter - yCloset);
        long distanceSqaured = xDistance*xDistance + yDistance*yDistance;

        if(distanceSqaured <= (long)radius*radius){
            return true;
        }
        return false;
    }
}


/*
{Distance} = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}
*/