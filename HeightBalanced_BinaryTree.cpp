/*
	Determine if a binary tree is height balanced.
	
	An empty tree is height-balanced. A non-empty binary tree T is balanced if:
		1) Left subtree of T is balanced
		2) Right subtree of T is balanced
		3) The difference between heights of left subtree and right subtree is not more than 1.
		
	These are used a lot in AVL trees; a self-balancing tree
	
	SOLUTION:  to check, get the height of the left subtree and the height of the right subtree.
		Return true if different is 0 <= x <= 1.  
			else return false ==> they are not balanced.  
 */
 
 #include <iostream>
 #include <cstdlib>
 
 using namespace std;
 
 
 //set up a node class to check left and right nodes
 class Node {
 
	public:
		int data;
		Node *right;
		Node *left;
 };
 
 //forward declarations
 int height(Node* node);
 int max(int a, int b);
 Node* newNode(int data);
 bool isBalanced(Node *root);
 void dispay(bool flag);
 
 //compute the height of the binary tree ==> number of nodes along the longest path from root to bottom node
 int height(Node *node){
	 
	 //base if zero 
	 if(node == NULL) {
		 return 0;
	 }
	 
	 return 1 + max(height(node->left), height(node->right));
 }
 
 //return max of two integers
 int max(int a, int b) {
	 
	 return (a >= b) ? a : b;  
	 
 }


 //ctor for new node data
 Node* newNode(int data) {
	 
	 Node *node = new Node();
	 node->data = data;
	 node->left = NULL;
	 node->right = NULL;
	 
	 return (node);
 }
 
 //return true if tree is height-balanced
 bool isBalanced(Node *root){
	 
	int lhand, rhand; //height for left and right subtree

	if(root == NULL) {
		
		return 1;  //1 equals true
	}
	 
	//get heights of lhand and rhand
	lhand = height(root->left);
	rhand = height(root->right);
	 
	//check to make sure heights are not more than 1 apart and 
	//then  recursively check same for left and right subtree
	if(abs(lhand - rhand) <= 1 && isBalanced(root->left) &&
			isBalanced(root->right)) {
			
		return 1;
	}
	
	//if not balanced
	return 0;
	
 }
 
 //display output
 void display (bool flag) {
	 
	 if(flag) {
		cout << "The tree is balanced!\n";
	 } else {
		cout << "The tree is NOT balanced!\n";
	 } 
 }
 
 //driver main
 int main() {
	 
	Node *root = newNode(1);
	
	// test root, should be balanced
	display(isBalanced(root));
	 
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->left->left = newNode(6);
	
	//not balanced
	display(isBalanced(root));
	 
	root->right->right = newNode(7);
	root->right->left = newNode(8);
	root->right->right = newNode(9);
	
	//now balanced again
	display(isBalanced(root));
	
	return 0; 
 }
 
 
 