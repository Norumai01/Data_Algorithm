#include <iostream>
#include <algorithm>


struct TreeNode {
	int ele;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
	TreeNode() : ele{0}, left{nullptr}, right{nullptr}, parent{nullptr} {}
	TreeNode(int x) : ele{x}, left{nullptr}, right{nullptr}, parent{nullptr} {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : ele{x}, left{left}, right{right}, parent{nullptr} {}
};

// Maximum Depth or Height of Binary Tree
int treeHeight(TreeNode *p) {
	// Your code here
	if (p == nullptr) {
		return 0;
	}
	else {
		int leftHei = treeHeight(p->left);
		int rightHei = treeHeight(p->right);
		return std::max(leftHei,rightHei) + 1;
	}
}

// Printing binary tree through InOrder Traversal. 
void printInOrder(TreeNode *p) {
    if (p == nullptr) {
        return;
    }
    printInOrder(p->left);
    std::cout << p->ele << " ";
    printInOrder(p->right);
}


// Test
int main() {
	// Test 1
	TreeNode t1(15); // leaf
	TreeNode t2(7); // leaf
	TreeNode t3(9); // leaf
	TreeNode t5(20, &t1, &t2); // internal node
	TreeNode t6(3, &t3, nullptr); // internal node
	TreeNode t7(1, &t5, &t6); // root

	std::cout << "Tree Height is: " << treeHeight(&t7) << std::endl; // 3
	std::cout << "InOrder traversal: ";
	printInOrder(&t7);
	std::cout << std::endl;

	// Test 2

	TreeNode n4(4, nullptr, nullptr); // leaf
	TreeNode n3(3, nullptr, &n4); // internal node
	TreeNode n2(2, &n3, nullptr); // internal node
	TreeNode n1(1, nullptr, &n2); // root

	std::cout << "Tree Height is: " << treeHeight(&n1) << std::endl; // 4
    std::cout << "InOrder traversal: ";
    printInOrder(&n1);
    std::cout << std::endl;
}
