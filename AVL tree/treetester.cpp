/*----- treetester.cpp -----------------------------------------------------
                Program for testing BST.
 ------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
   // Testing Constructor and empty()
   BST intBST;            // test the class constructor
   cout << "Constructing empty BST\n";
   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";

   // Testing insert
   cout << "\nNow insert a bunch of integers into the BST."
           "\nTry items not in the BST and some that are in it:\n";
   int number;
   for (;;)
   {
      cout << "Item to insert (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      intBST.insert(number);
   }
   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";

   // Testing search()
   cout << "\n\nNow testing the search() operation."
           "\nTry both items in the BST and some not in it:\n";
   for (;;)
   {
      cout << "Item to find (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      cout << (intBST.search(number) ? "Found" : "Not found") << endl;
   }

    int num,j;
    cout << "1.Inorder 2. Preorder 3. Postorder 4.Count of Nodes 5.Delete a node" << endl; 
    cin >> num;
    switch(num)
    {

      case 1: intBST.printInorder();
              break;
      case 2: intBST.printPreorder();
              break;
      case 3: intBST.printPostorder();
              break;
      case 4: intBST.countelements();
              break;
      case 5: for(;;) 
              {
              cout << "Enter a element to delete (-999 to stop):" <<endl;
              cin >> j;
              if (j == -999) break;
              intBST.deletenode(j);
              cout << "Deleted";
              intBST.printInorder();
              printf("\n");
              intBST.printPostorder();
              }
              break;
      default: cout << "No Match ";

   }

}
