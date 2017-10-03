/*
* NumPairs.java
* Takes in a list of numbers from a text file in the format

* (#Num test cases)
* (# of ints in test) # # #
* Ex:
* 2
* 3 3 5 6
* 5 78 89 8 67 55 
* 
* Compares the output with a out.out file with the num of pairs for each test
* on a single line
* Mark Worrall - 06/01/16
*/
import java.util.Scanner;
import java.io.*;

class NumPairs{
	
	public static long pairCheck(int[] nums){
		int i, j; 
		long count = 0;
		for(i = 0; i < nums.length; i++) {
			for(j = i; j < nums.length; j++) {
				if(nums[i] > nums[j]) count++;
			}
		}
		return count;
	}
	
	public static void main(String args[]) throws FileNotFoundException {
		Scanner input = new Scanner(new File("in.in"));
		Scanner test = new Scanner(new File("out.out"));
		int numCases = input.nextInt();
		int i, j, count;
		long pairCount, testOutput;
		
		for(i = 0; i < numCases; i++) {
			count = input.nextInt();
			int[] nums = new int[count];
			for(j = 0; j < count; j++) {
				nums[j] = input.nextInt();
				
			}
			pairCount = pairCheck(nums);
			testOutput = test.nextLong();
			if(pairCount == testOutput) {
				System.out.printf("Test %d passed, test = %d, expected = %d\n", (i+1), pairCount, testOutput);
			} else {
				System.out.printf("Test %d failed, test = %d, expected = %d\n", (i+1), pairCount, testOutput);
			}
		}
	
	}
}