/*
 *  Java Program to Implement AVL Tree
 */
 
 import java.util.Scanner;
 
 /* Class AVLTree */
 class AVLTree
 {
     private AVLNode root;     
 
     //TODO: initialize the tree
     public AVLTree()
     {
	root = new AVLNode();
     }

     /* Function to check if tree is empty */
     public boolean isEmpty()
     {
         return root == null;
     }

     //TODO: Make the tree logically empty */
     public void makeEmpty()
     {
         root = null;
     }

     public void insert(int data)
     {
         root = insert(data, root);
     }

     //TODO:Get the height of a node
     private int height(AVLNode t)
     {
        return t.height;
     }

     //TODO: return bigger children
     private int max(int lhs, int rhs)
     {
	if(lhs.getHeight() > rhs.getHeight()) return lhs.getHeight();
        return rhs.getHeight();
     }

     //TODO: insert value into the tree recursively
     private AVLNode insert(int x, AVLNode t)
     {
	if((x > t.data) && t.right == null){
		t.right = new AVLNode(x);
		t = t.right;	
	} else if((x < t.data) && t.left == null){
		t.left = new AVLNode(x);
		t = t.left;	
	} else if(x > t.data){
		t = insert(x, t.right);
		return t;
	} else if(x < t.data){
		t = insert(x, t.left);
		return t;
	}
         return t;
     }

     /* Rotate binary tree node with left child */     
     private AVLNode rotateWithLeftChild(AVLNode k2)
     {
         AVLNode k1 = k2.left;
         k2.left = k1.right;
         k1.right = k2;
         k2.height = max( height( k2.left ), height( k2.right ) ) + 1;
         k1.height = max( height( k1.left ), k2.height ) + 1;
         return k1;
     }
 

     /* Rotate binary tree node with right child */
     private AVLNode rotateWithRightChild(AVLNode k1)
     {
         AVLNode k2 = k1.right;
         k1.right = k2.left;
         k2.left = k1;
         k1.height = max( height( k1.left ), height( k1.right ) ) + 1;
         k2.height = max( height( k2.right ), k1.height ) + 1;
         return k2;
     }
     /**
      * Double rotate binary tree node: first left child
      * with its right child; then node k3 with new left child */
     private AVLNode doubleWithLeftChild(AVLNode k3)
     {
         k3.left = rotateWithRightChild( k3.left );
         return rotateWithLeftChild( k3 );
     }
     /**
      * Double rotate binary tree node: first right child
      * with its left child; then node k1 with new right child */      
     private AVLNode doubleWithRightChild(AVLNode k1)
     {
         k1.right = rotateWithLeftChild( k1.right );
         return rotateWithRightChild( k1 );
     }    
     /* Functions to count number of nodes */
     public int countNodes()
     {
         return countNodes(root);
     }
     //TODO: count how many nodes in the tree 
     private int countNodes(AVLNode r)
     {
        return 0;
     }



     /* Functions to search for an element */
     public boolean search(int val)
     {
         return search(root, val);
     }
     //TODO: Found whether the given value is in the tree.
     private boolean search(AVLNode r, int val)
     {
         boolean found=false;
         return found;
     }


     /* Function for inorder traversal */
     public void inorder()
     {
         inorder(root);
     }
     private void inorder(AVLNode r)
     {
         if (r != null)
         {
             inorder(r.left);
             System.out.print(r.data +" ");
             inorder(r.right);
         }
     }
     /* Function for preorder traversal */
     public void preorder()
     {
         preorder(root);
     }
     private void preorder(AVLNode r)
     {
         if (r != null)
         {
             System.out.print(r.data +" ");
             preorder(r.left);             
             preorder(r.right);
         }
     }
     /* Function for postorder traversal */
     public void postorder()
     {
         postorder(root);
     }
     private void postorder(AVLNode r)
     {
         if (r != null)
         {
             postorder(r.left);             
             postorder(r.right);
             System.out.print(r.data +" ");
         }
     }     
 }
