public class Vector {

	private int[] vectorArray;
	private int size;
	public static final int INIT_SIZE = 3;

	public Vector(int[] incoming) {
		vectorArray = incoming;
		size = incoming.length;
	}
	
	public Vector() {
		vectorArray = new int[INIT_SIZE];
	}
	
	public void add(int newInt) {
		vectorArray[size++] = newInt;
	}

	// no checking done here.
	public void update(int index, int newNum) {
		vectorArray[index] = newNum;
	}

	public Vector copy() {
		int[] b = new int[vectorArray.length];
		for (int i = 0; i<b.length; i++){
			b[i] = vectorArray[i];
		}
		return new Vector(b);

	}

	public String toString() {
		StringBuffer s = new StringBuffer(size*5+2);
		s.append("{");
		for (int i=0; i<size-1; i++) {
			s.append(vectorArray[i]+",");
		}
		if (size > 0) {
			s.append(vectorArray[size-1]+"}");
		}
		return s.toString();
	}
	
	public static void main(String[] args) {
		Vector v1 = new Vector();
		v1.add(4);
		v1.add(16);
		v1.add(12);
		System.out.println("v1 = "+v1);
		Vector v2 = v1.copy();
		System.out.println("v2 = "+v2);
		v2.update(0,25);
		System.out.println("After changing v2:");
		System.out.println("v1 = "+v1);
		System.out.println("v2 = "+v2);
	}
}
