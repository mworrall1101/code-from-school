
import java.util.Scanner;
import java.io.File;
import java.util.Arrays;


public class HashTable1{


	/* **************** HASH TABLE METHODS **************** */
	public static final int TableSize = 23;

	TableStorage T = new TableStorage(TableSize);

	/* hash(s)
	   Return the hash code for the provided string.
	   The returned value must be in the range [0,TableSize-1]
	*/
	public int hash(String s){
        //string -> code
		return Integer.parseInt(s)%tableSize;
	}

	/* insert(s)
	   Insert the value s into the hash table and return the index at
	   which it was stored.
	*/
	public int insert(String s){
            int index = hash(s);
			T[index] = s;
			return index;
	}

	/* find(s)
	   Search for the string s in the hash table. If s is found, return
	   the index at which it was found. If s is not found, return -1.
	*/
	public int find(String s){

		//Get the hash value of the string and start the search at that index.
		int i = hash(s);

		//Use linear probing to find the string.
		for(int x = 0; x < TableSize; x++){
			String element = T.getElement(i);
			//If the slot is empty, the provided string was not found.
			if (element == null){
				return -1;
                        }
			//If the slot contains the desired string, return its index.
			//Note that to test whether strings are equal in Java,
			//the '==' operator is not correct.
			if (s.equals(element)){
                            return i;
                        }
			//If the string was not at this index, continue looking.
			i++;
			if (i >= TableSize)
				i = i%TableSize;
		}
                return -1;
	}

	/* **************************************************** */




	/* **************** TableStorage Class **************** */
	/* The hash table methods use this class to store
	   and retrieve table values. Do not modify this class in
	   any way. If this class is modified, it may not be possible
	   to mark your submission.
	*/
	public static class TableStorage{

		public TableStorage(int tableSize){
			table = new String[tableSize];
                        mark = new boolean[tableSize];
                        Arrays.fill(mark, false);
		}
                
		private String[] table;
                private boolean[] mark;
                private int count = 0;
                
                public int count(){
                    return count;
                }
                
		public void setElement(int index, String value){
			table[index] = value;
                        mark[index] = true;
                        count++;
		}
		public String getElement(int index){
                        if(mark[index] == false) return null;
			return table[index];
		}
	}
	
	public static void main(String[] args) throws Exception{
            Scanner in = new Scanner(new File("E:\\Academic\\[Java_projects]\\Codeforces\\src\\in.in"));
            HashTable1 H = new HashTable1();
            
            while(in.hasNextLine()){
                String[] str = in.nextLine().split("#");
                String city_name = str[1];
                
                
                if(str[0].equals("INSERT")){
                    int index = H.insert(city_name);
                    System.out.println("INSERTED at " + index + "\t: " + city_name);
                }
                else if(str[0].equals("FIND")){
                    int index = H.find(city_name);
                    if(index == -1) System.out.println("NOT FOUND\t: " + city_name);
                    else System.out.println("FOUND at " + index + "\t: " + city_name);
                }
                else{
                    System.out.println("Should not have happened");
                }
            }
        }
}
