#include <iostream>
//#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
: myRoot(0)
{}

bool BST::empty() const
{ return myRoot == 0; }


bool BST::search(const int & item) const
{
   BinNode * locptr = myRoot;
   bool found = false;
   while (!found && locptr != 0)
   {
      if (item < locptr->data)       // descend left
        locptr = locptr->left;
      else if (locptr->data < item)  // descend right
        locptr = locptr->right;
      else                           // item found
        found = true;
   }
   return found;
}


int BST::countelements(){
      int i=countelements(myRoot);
	cout << i-1 << endl;
}


void BST::printInorder(){
      printInorder(myRoot);
}

void BST::printPreorder(){
      printPreorder(myRoot);
}

void BST::printPostorder(){
      printPostorder(myRoot);
}

int BST::countelements(BinNode * p)
{
     int count=1;
     if(p==0)
        {
	return count;
	
	}
	else
        {

	count=countelements(p->left)+countelements(p->right);
        
        
	}

}

void BST::printInorder(BinNode * ptr)
{
   
   if(ptr != 0)
   {
	printInorder(ptr->left);
        cout << ptr->data << " ";
	printInorder(ptr->right);
   }     
        
}

void BST::printPreorder(BinNode * ptr)
{
   
   if(ptr != 0)
   {
	cout << ptr->data << " ";
	printPreorder(ptr->left);
        printPreorder(ptr->right);
   }     
        
}

void BST::printPostorder(BinNode * ptr)
{
   
   if(ptr != 0)
   {
	printPostorder(ptr->left);
	printPostorder(ptr->right);
        cout << ptr->data << " ";
	
   }     
        
}


void BST::insert(const int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   while (!found && locptr != 0)
   {
      parent = locptr;
      if (item < locptr->data)       // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else                           // item found
         found = true;
   }
   if (!found)
   {                                 // construct node containing item
      locptr = new BinNode(item);  
      if (parent == 0)               // empty tree
         myRoot = locptr;
      else if (item < parent->data )  // insert to left of parent
         parent->left = locptr;
      else                           // insert to right of parent
         parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
}

void BST::search1(int item, BinNode **par, BinNode **loc)
{
    BinNode *ptr; BinNode *ptrs;
    if(item == myRoot->data)
    {
       *loc=myRoot;
       *par=0;
        return;
    }
    
    if(item < myRoot->data)
        {ptr=myRoot->left;}
    else
        {ptr=myRoot->right;}
    ptrs=myRoot;

   while(ptr != 0)
   {
	if(item == ptr->data)
        {	
            *loc = ptr;
            *par = ptrs;
            return;      
        }
        ptrs=ptr;
        if(item < ptr->data)
        {
	   ptr=ptr->left;
         }
        else 
        {
           ptr=ptr->right;
        }

   }
   *loc=0;
   *par=ptrs;
}
void BST::deletenode(const int item)
{  

    BinNode * parent;
    BinNode * locptr;
    BinNode * next;
    BinNode * temp;
    BinNode * temp1;
    BinNode * temp2;
    search1(item, &parent, &locptr);
	//printf("parent : %d,child : %d",parent->data,locptr->data);
    //Case1:
   if(locptr->left==0 && locptr->right==0)
   {
	if(parent == 0) {
		myRoot = 0;
	}
        else if(parent->right==locptr)
	{
	     free(locptr);
	     parent->right=0;
	}
        else if(parent->left==locptr)
        {
	     free(locptr);
	     parent->left=0;
        }
        else{
        parent->left=0;
        parent->right=0;
        }
   
   }
   //Case2:
   else if(parent->right==locptr)
   {
   if(locptr->left !=0 && locptr->right == 0)
   {
	next=locptr->left;
	locptr=0;
	parent->right=next;
       
        
   }
   else if(locptr->left ==0 && locptr->right != 0){
	next=locptr->right;
	locptr=0;
	parent->right=next;
      
   }

   else if(parent->left==locptr)
   {
   if(locptr->left !=0 && locptr->right == 0)
   {
	next=locptr->left;
	locptr=0;
	parent->left=next;
       
        
   }
   else {
	next=locptr->right;
	locptr;
	parent->left=next;
      
       
   }
   }

   //Case3:
   else
   {
      
         temp=locptr;
        // next=locptr->right;
         //int asd=0;
	      while(temp->left!=0)
	{
		//asd=1;
		next=temp;
		temp=temp->left;
	}
        locptr->data=temp->data;
	if(next->right==locptr)
	{
	     //free(locptr);
	     next->right=0;
	}
        else
        {
	    // free(locptr);
	     next->left=0;
        }
        free(temp);
   }
}
}