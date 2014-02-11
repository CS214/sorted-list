/*
*sorted-list.c
*
*Big-O analysis:
*
*
*
*/

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
	TreePtr tempRoot = (TreePtr) malloc(sizeof(struct BinaryTree));
	tempRoot->data = newObj;
	tempRoot->left = NULL;
	tempRoot->right = NULL;


	if(list->root == NULL){
		list->root = tempRoot;
	}
	else{
		TreePtr traverse = list->root;
		while(!(traverse->left == NULL && traverse->right == NULL)){ //TEMPORARY CONDITION FIX IT LATER (ONLY THE PLACE TO BE ADDED MUST BE NULL NOT BOTH)
			//can also make condition infinite since code is returned after the addition of object
			if(list->compare(traverse, newObj) == -1){ //if the new object is larger than the node being looked at
				if(traverse->right == NULL){
					traverse->right = tempRoot;
					return 1;
				}
				else{
					traverse = traverse->right;
				}
			}
			else if(cf(traverse, newObj) == 1){ //if the new object is smaller than the node being looked at
				if(traverse->left == NULL){
					traverse->left = tempRoot;
					return 1;
				}
				else{
					traverse = traverse->left;
				}		
			}
			else{ //if the object is a duplicate
				return 0; //return a duplicate error
			}
		}
		
	}
}

int SLRemove(SortedListPtr list, void *newObj){ //NOT COMPLETED
	return 0;
}

SortedListIteratorPtr SLCreateIterator(SortedListPtr list){
	SortedListIteratorPtr iterator = (SortedListIteratorPtr) malloc(sizeof(struct SortedListIterator));
	iterator->data = list->root;
	iterator->parentStack = NULL;

	while(iterator->left != NULL){
		if(iterator)
	}
}

void SLDestroyIterator(SortedListIteratorPtr iter){ //NOT COMPLETED
	if(iter != NULL)
		free(iter);
}

void *SLNextItem(SortedListIteratorPtr iter){ //NOT COMPLETED
	return NULL;
}