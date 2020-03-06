#include <iostream>
using namespace std;  

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
 class BinNode;
 public:
  /***** Function Members *****/
  BST();
  bool empty() const;
  bool search(const int & item) const; 
  void insert(const int & item);
  void printInorder();
  void printPreorder();
  void printPostorder();
  int countelements();
  void deletenode(const int item);
  
  
 private:

  void printInorder(BinNode * ptr);
  void printPreorder(BinNode * ptr);
  void printPostorder(BinNode * ptr);
  int countelements(BinNode * p);
  void search1(int item,BinNode **, BinNode **);

  /***** Node class *****/
  class BinNode 
  {
   public:
    int data;
    BinNode * left;
    BinNode * right;

    // BinNode constructors
    // Default -- data part is default int value; both links are null.
    BinNode()
    : left(0), right(0)
    {}

    // Explicit Value -- data part contains item; both links are null.
    BinNode(int item)
    : data(item), left(0), right(0)
    {}
 
  };// end of class BinNode declaration
  
  /***** Data Members *****/
  BinNode * myRoot; 

}; // end of class declaration

#endif
