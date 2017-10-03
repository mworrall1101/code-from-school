/*
	Heap.java
	An array implimentation of a heap.
	Mark Worrall - 06/22/16
*/
import java.util.ArrayList;


public class Heap{
	
	
	private ArrayList<Element> heap = new ArrayList<Element>();
	
	private class Element{
		int key;
		Element(int key) {
			this.key = key;
		}
		
		Element(){}
	
	}
	public boolean isEmpty(){
		return heap.isEmpty();
	}
	public void insert(int value){
		Element e = new Element(val);
		heap.add(e);
	}
	public void delete(){
		heap.set(0, heap.get(heap.size()-1));// set root node to last node
		heap.remove(heap.size()-1);
		bubbleDown(0);//bubble down
	}
	public void swap(int ind1, int ind2){
		E temp = new Element(heap.get(ind2));
		heap.set(ind2, heap.get(ind1));
		heap.set(ind1, temp);
	}
	public void bubbleDown(int rootInd){
		int root = heap.get(rootInd);
		int left = heap.get(2*rootInd + 1);
		int right = heap.get(2*rootInd + 2); 
		int smallNode = left;
		if(right < smallNode) smallNode = right;
		if( root > smallNode) {
			swap(rootInd, smallNode);
			bubbleDown(rootInd);
		}
	}
	public int top(){
		return heap.get(0);
	}
	
}