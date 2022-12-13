/*
 * Implement the find() method for the BST which returns the value if the key is present, empty string otherwise. 
 * Your implemntation can be either iterative or recursive.
*/

#include <iostream>
#include <string>

class Node
{
private:
   int key;
   std::string val;
   Node* left;
   Node* right;
   friend class BinarySearchTree;   
};   


class BinarySearchTree
{
public:   
       BinarySearchTree(): root{nullptr} {}
       void insert(int key, std::string val); // Recursive
       void printInOrder() const; // Prints keys in-order. Recursive
	    std::string find(int key) const; //Returns value if node is present, else return empty string. Iterative
       std::string FindMinValue() const;
       int FindMin() const;
private:
        Node* root;
        void insertHelper(Node* parent, Node* new_node);
        void printInOrderHelper(Node *n) const; //Helper for recursive implemenation of printInroder()
        std::string findHelper(Node *n, int key) const; // Helper for recursive find(). 
};

   
void BinarySearchTree::insert(int key, std::string val) 
{  
   Node* new_node = new Node;
   new_node->key = key;
   new_node->val = val;
   new_node->left = nullptr;
   new_node->right = nullptr;
   if (root == nullptr) { 
      root = new_node; 
   } else { 
      insertHelper(root, new_node); 
   }
}

void BinarySearchTree::insertHelper(Node* parent, Node* new_node) 
{  
   if (new_node->key < parent->key) {  
      if (parent->left == nullptr) { 
         parent->left = new_node; 
      }
      else { 
         insertHelper(parent->left, new_node); }
   }
   else if (new_node->key > parent->key) {  
      if (parent->right == nullptr) {
         parent->right = new_node; 
      }
      else { 
         insertHelper(parent->right, new_node);
      }
   }
}

std::string BinarySearchTree::find(int key) const {
   // Your code here
   Node* temp = root;
   if (temp == nullptr) {  // If no elements is presented.
      return "";
   }
   return findHelper(temp, key);  // Recursive function helper. 
}

std::string BinarySearchTree::findHelper(Node* n, int key) const {
   if (n == nullptr) {  // Return "", if tree ends at null.
      return "";
   }
   if (n->key == key) {  // If node's key matches, return value of the node.
      return n->val;
   }
   else if (n->key > key) {  // If node's key is greater, move tree left.
      return findHelper(n->left, key);
   }
   else {  // If node's key is lesser, move tree right.
      return findHelper(n->right, key);
   }
}

int BinarySearchTree::FindMin() const {
   Node* curr = root;
   int min = curr->key;
   while (curr != nullptr) {
      if (curr->key < min) {
         min = curr->key;
      }
         curr = curr->left;
   }
   return min;
}

std::string BinarySearchTree::FindMinValue() const {
   Node* curr = root;
   Node* min = nullptr; 
   
   while (curr != nullptr) {
      if (min == nullptr) {
         min = curr;
      }
      if (curr->key < min->key) {
         min = curr;
      }
      curr = curr->left;
   }
   return min->val; 
}

void BinarySearchTree::printInOrder() const {
	if (root == nullptr) {
		std::cout << std::endl;
	}
	printInOrderHelper(root);
	std::cout << std::endl;

}
   
void BinarySearchTree::printInOrderHelper(Node* n) const {
	if (n == nullptr) {
		return;
	}
	printInOrderHelper(n->left);
	std::cout << n->key << " ";
	printInOrderHelper(n->right);
}

int main()
{  
   BinarySearchTree t;
   t.insert(5, "Boron");
   t.insert(3, "Lithium");
   t.insert(7, "Nitrogen");
   t.insert(2, "Helium");
   t.insert(4, "Berylium");
   t.insert(6, "Carbon");
   t.insert(8, "Oxygen");
   t.printInOrder(); // Prints the keys in order (will appear sorted)
   int ele = 8;
   std::string val = t.find(ele);
   if (val == "" ) {
	   std::cout << ele << " does not exist in tree" << std::endl;
   } else {
	   std::cout << ele << " : " << val << std::endl;
   }
   ele = 0;
   val = t.find(ele);
   if (val == "" ) {
	   std::cout << ele << " does not exist in tree" << std::endl;
   } else {
	   std::cout << ele << " : " << val << std::endl;
   }
   //val = t.find(t.FindMin());
   //std::cout << "The minimum key is "<< t.FindMin() << " with a key value of " << val << "." << std::endl;
   std::cout << "The minimum key is " << t.FindMin() << " with a key value of " << t.FindMinValue() << "." << std::endl;
   return 0;
}