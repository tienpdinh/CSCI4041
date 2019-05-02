/**
 * This implementation is based on the implementation from geeksforgeeks
 * https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
 * The key takeaway for avl tree is there is no such thing as double
 * rotation, all 4 cases are merely the combinations of a single
 * leftRotation or rightRotation, by combining the correct rotations
 * we can maintain the balance factor of the tree.
 *
 * To run this from a Unix shell
 * > javac AVLTree.java
 * > java AVLTree
 *
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
    private int height(Node N) {
	return (N == null) ? 0 : N.height;
    }

    // Utility func to return the max num
    private int max(int a, int b) {
	return (a > b) ? a : b;
    }

    // Rotate right, illustrated below
    //       y          x
    //      / \        / \
    //     x   n ==>  z   y
    //    / \            / \ 
    //   z   m          m   n
    private Node rightRotate(Node y) {
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
    private Node leftRotate(Node x) {
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
    private int getBalance(Node N) {
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
	if (bal < -1 && key < node.right.key) {
	    node.right = rightRotate(node.right);
	    return leftRotate(node);
	}

	// Awesome, the tree is balanced, there is nothing
	// else for me to do other than just return the node.
	return node;
    }

    // Utility function to print the preorder traversal
    // of the tree (for testing purposes)
    public void preorder(Node node) {
	if (node != null) {
	    System.out.print(node.key + ", ");
	    preorder(node.left);
	    preorder(node.right);
	}
    }

    // Main function to test stuff
    public static void main(String[] args) {
	AVLTree avl = new AVLTree();
	avl.root = avl.insert(avl.root, 10);
	avl.root = avl.insert(avl.root, 20);
	avl.root = avl.insert(avl.root, 30);
	avl.root = avl.insert(avl.root, 40);
	avl.root = avl.insert(avl.root, 50);
	avl.root = avl.insert(avl.root, 60);
	avl.root = avl.insert(avl.root, 70);
	avl.preorder(avl.root);
	System.out.println("");

	// Normal tree insertion would result in a linear
	// tree which looks just like a linked list.
	// 10
	//  \
	//  20                     40
	//   \                    /  \
	//   30                  /    \
	//    \                 /      \
	//    40               20      60
	//     \              /  \    /  \
	//     50            10  30  50  70
	//      \
	//      60
	//       \
	//       70
	// On the left is the ugly linked list, while
	// on the right is the elegent avl tree.
    }
}
