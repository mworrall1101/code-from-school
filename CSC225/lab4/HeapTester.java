
import java.io.File;
import java.util.Scanner;

public class HeapTester{
	//used for testing the heap class
	public static void main(String args[]) {
		Heap heap = new Heap(20);
		
		Scanner in = new Scanner(new File("in.in"));
		
		int n = in.nextInt();
		
		for(int i = 0; i < n; i++){
			heap.insert(in.nextInt());
		}
		while(!heap.isEmpty()) {
			System.out.printf("%d", heap.top());
			heap.delete();
		}
	
	}

}