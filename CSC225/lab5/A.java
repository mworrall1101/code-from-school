import java.util.Stack;

public class A {
    
    static private class Element{
        int value;
        boolean is_print_ok;
        Element(int value, boolean is_print_ok){
            this.value = value;
            this.is_print_ok = is_print_ok;
        }
    }
	
	
    public static void main(String[] args) throws Exception {
        // the output should be: 80 40 90 20 100 50 10 60 30 70
        int[] a = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
        
        Stack<Element> st = new Stack<Element>();
        
        st.push(new Element(0, false));
        System.out.printf("Inorder: ");
        //You need to process the nodes on stack until the stack becomes empty
        while(!st.isEmpty()) {
			Element temp = st.pop();
			if(temp.is_print_ok){ 
				System.out.printf("%d, ", a[temp.value]);
			} else {
				temp.is_print_ok = true;
				if((2*temp.value + 2) < (a.length)) st.push(new Element((2*temp.value + 2), false));
				st.push(temp);
				if((2*temp.value + 1) < (a.length)) st.push(new Element((2*temp.value + 1), false));
			}
			
		}
    }

}
