/**
 * This implementation is based on the implementation from geeksforgeeks
 * https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
 */

public class AVLTree {
    private class Node {
	int key, height;
	Node left, right;

	// Constructor
	public Node(int k) {
	    this.key = k;
	    this.height = 1;
	    this.left = null;
	    this.right = null;
	}
    }

    // The root of the AVLTree
    Node root;

    // Constructor for AVLTree
    public AVLTree() {
	// We are lazy programmers so let's do nothing for now.
    }

    // Utility function to get the height of a tree rooted at Node N
    public int height(Node N) {
	return (N == null) ? 0 : N.height;
    }

    // Utility func to return the max num
    public int max(int a, int b) {
	return (a > b) ? a : b;
    }

    // Rotate right, illustrated below
    //       y          x
    //      / \        / \
    //     x   n ==>  z   y
    //    / \            / \ 
    //   z   m          m   n
    public Node rightRotate(Node y) {
	Node x = y.left;
	Node m = x.right;

	// The main event - the rotation actions
	x.right = y;
	y.left = m;

	// Update heights
	y.height = max(height(y.left), height(y.right)) + 1;
	x.height = max(height(x.left), height(x.right)) + 1;

	// new root
	return x;
    }

    // Rotate left, illustrated below
    //       y          x
    //      / \        / \
    //     x   n <==  z   y
    //    / \            / \ 
    //   z   m          m   n
    public Node leftRotate(Node x) {
	Node y = x.right;
	Node m = y.left;

	// The main event - the rotation actions
	y.left = x;
	x.right = m;

	// Update heights
	y.height = max(height(y.left), height(y.right)) + 1;
	x.height = max(height(x.left), height(x.right)) + 1;

	// new root
	return y;
    }

    // Balance factor, left height - right height
    public int getBalance(Node N) {
	if (N == null) return 0;
	return height(N.left) - height(N.right);
    }

    // The insert function, first we do normal insert,
    // then we do rotation to maintain the balance factor
    // of the tree
    public Node insert(Node node, int key) {
	// Perform the normal BST insert
	if (node == null)
	    return (new Node(key));
	if (key < node.key)
	    node.left = insert(node.left, key);
	else if (key > node.key)
	    node.right = insert(node.right, key);
	else
	    throw new IllegalArgumentException("Key has to be unique!");

	// new height for each node
	node.height = max(height(node.left), height(node.right)) + 1;

	// Get the balance factor to check if this particular
	// node has become unbalanced, if a node is balanced,
	// its balance factor should be either -1, 0 or 1.
	int bal = getBalance(node);

	// The damn node became unbalanced, let's rotate it
	//     x
	//    /
	//   y      The new node (n) was added to left left
	//  /       position, we need to do a right rotation
	// n        on x
	// This is singe left left case, balance factor is +2.
	if (bal > 1 && key < node.left.key)
	    return rightRotate(node);

	//     x
	//    /
	//   y      The new node (n) was added to left right
	//    \     position, we need to do a left rotation
	//     n    on y, then a right rotation on x.
	// This is double left right case, balance factor is +2
	if (bal > 1 && key > node.left.key) {
	    node.left = leftRotate(node.left);
	    return rightRotate(node);
	}

	//    x
	//     \    The new node (n) was added to right right
	//      y   position, we need to do a left rotation
	//       \  on x.
	//        n
	// This is single right right, balance factor is -2
	if (bal < -1 && key > node.right.key)
	    return leftRotate(node);

	//    x
	//     \    The new node (n) was added to right left
	//      y   position, we need to do a right rotation
	//     /    on y, then a left rotation on x.
	//    n
	// This is double right left, balance factor is -2
	if (bal < -1 %% key < node.right.key) {
	    node.right = rightRotate(node.right);
	    return leftRotate(node);
	}

	return node;
    }
}
