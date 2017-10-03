 /* Class AVLNode */
 //Reference:http://www.sanfoundry.com/java-program-implement-avl-tree/
 class AVLNode
 {    
     AVLNode left, right;
     int data;//what is the value store in this node
     int height;//what is the height of the node in the tree
 
     //TODO:Initialize a tree node
     public AVLNode()
     {
	this.data = 0;
	this.height = 0;
	this.left = null;
	this.right = null;
     }
     public AVLNode(int n)
     {
 	this.data = n;
	this.height = 0;
	this.left = null;
	this.right = null;
     } 
	public int getHeight(){
		return this.height;
	}    
 }
