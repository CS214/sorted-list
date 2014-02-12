/*
*sorted-list.c
*
*Big-O analysis:
*
*
*
*/

#include "sorted-list.h"

SortedListPtr SLCreate(CompareFuncT cf){
	SortedListPtr list = (SortedListPtr) malloc(sizeof(struct SortedList)); //if doesnt compile remove struct datatype
	list->root = NULL;
	list->compare = cf;

	return list;
}

void SLDestroy(SortedListPtr list){ //NOT COMPLETED
	if(list != NULL) //when list is done make loop to traverse through entire tree
		free(list);
}

int SLInsert(SortedListPtr list, void *newObj){
	TreePtr tempRoot = (TreePtr) malloc(sizeof(struct BinaryTree)); //create a temporary tree object
	tempRoot->data = newObj; //make the newObj the root
	tempRoot->leftChild = NULL; //and its children null
	tempRoot->rightChild = NULL;


	if(list->root == NULL){ //if the list is empty
		list->root = tempRoot; //simply make that tempRoot the first item
	}
	else{
		TreePtr traverse = list->root; //else use a pointer to look for where to add that new object
		while(!(traverse->leftChild == NULL && traverse->rightChild == NULL)){ //TEMPORARY CONDITION FIX IT LATER (ONLY THE PLACE TO BE ADDED MUST BE NULL NOT BOTH)
			//can also make condition infinite since code is returned after the addition of object
			if(list->compare(traverse, newObj) == -1){ //if the new object is larger than the node being looked at
				if(traverse->leftChild == NULL){ //if the left spot isnt taken
					traverse->leftChild = tempRoot; //add it to the left (since list is from largest to smallest)
					return 1;
				}
				else{
					traverse = traverse->leftChild; //or else keep looking for an empty spot
				}
			}
			else if(list->compare(traverse, newObj) == 1){ //if the new object is smaller than the node being looked at
				if(traverse->rightChild == NULL){ //same as previous case but in opposite direction
					traverse->rightChild = tempRoot;
					return 1;
				}
				else{
					traverse = traverse->rightChild;
				}		
			}
			else{ //if the object is a duplicate
				return 0; //return 0 which indicates error
			}
		}	
	}
	return 1; //added return here to make compiler happy
}

int SLRemove(SortedListPtr list, void *newObj){ //NOT COMPLETED
	return 0;
}

SortedListIteratorPtr SLCreateIterator(SortedListPtr list){
	if(list == NULL)
		return NULL;
	else{
		SortedListIteratorPtr iterator = (SortedListIteratorPtr) malloc(sizeof(struct SortedListIterator)); //create a new iterator object
		iterator->currentItem = list->root; //make the first item root
		iterator->parentStack = NULL; //and make the stack of parents null

		ParentPtr parents = (ParentPtr) malloc(sizeof(struct ParentStack)); //create a new parent stack
		parents->parent = NULL;
		parents->parentList = NULL;

		iterator->parentStack = parents; //link the list of parents to the parent stack

		while(iterator->currentItem->leftChild != NULL){ //while there are still children on the left (essentially looking for largest data)
			ParentPtr tempParent = (ParentPtr) malloc(sizeof(struct ParentStack)); //create a new temp node and add it to the front of the list
			tempParent->parent = iterator->currentItem;
			tempParent->parentList = parents;
			parents = tempParent;
			iterator->currentItem = iterator->currentItem->leftChild;
		}
		
		return iterator;
	}
}

void SLDestroyIterator(SortedListIteratorPtr iter){ //NOT COMPLETED
	//does not free iter->currentItem because it points to the list, iterator should not mess with list
	if(iter->parentStack != NULL)
		free(iter->parentStack);
	if(iter != NULL)
		free(iter);
}

void *SLNextItem(SortedListIteratorPtr iter){ //NOT COMPLETED
	void * dataReturned = iter->currentItem;

	//need to move pointer to next item
	//how do we know when to move to parent or rightChild of current item?
	//we can currently be in the parent of a previous item
	//we can keep track of stages
	//stage 0 = leftchild so move up to parent
	//stage 1 = parent of previous stage so move to right child
	//stage 2 = rightchild so move up by 2 parents (if not null)
	//never move left since we are at leftmost position and we are working backwards towards right
	iter->currentItem = iter->parentStack;

	//********************************//

	return dataReturned;
}