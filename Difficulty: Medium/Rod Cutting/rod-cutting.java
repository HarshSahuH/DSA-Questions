class Solution {
	public int solve(int[]price, int index, int rodLength, int[][]t) {
		if (rodLength == 0 || index == 0) {
			return 0;
		}
		
		if(t[index][rodLength] != -1){
		    return t[index][rodLength];
		} 
		// choice diagram
		int currentRodLength = index;
		int currentRodPrice = price[index - 1]; // 0-based indexing ke liye
		
		// Agar current piece rodLength se chota ya barabar hai, tabhi kaat sakte hain
		if (currentRodLength <= rodLength) {
			// Choice 1: Include (Kaato)
			// Profit mila + Rod ki length kam hui, LEKIN index same raha (Unbounded!)
			int include = currentRodPrice + solve(price, index, rodLength - currentRodLength,t);
			
			// Choice 2: Exclude (Mat Kaato)
			// Profit 0 + Rod length same rahi, lekin next choti length try karenge (index - 1)
			int exclude = solve(price, index - 1, rodLength,t);
			
			t[index][rodLength] = Math.max(include, exclude);
		}
		
		else {
			// MAJBOORI: Piece size rod length se bada hai -> Sirf Exclude kar sakte hain
			t[index][rodLength] = solve(price, index - 1, rodLength,t);
		}
		
		return t[index][rodLength];
	}
	public int cutRod(int[] price) {
		// code here
		int totalRodLength = price.length;
		int totalOption = price.length;
		
		int [][] t = new int[totalRodLength+1][totalRodLength+1];
		for(int[] row : t){
		    Arrays.fill(row,-1);
		}
		
		
		return solve(price, totalOption, totalRodLength,t);
	}
}
