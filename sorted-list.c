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

void SLDestroy(SortedListPtr list){
	if(list != NULL) //when list is done make loop to traverse through entire tree
		free(list);
}

SortedListPtr

int SLInsert(SortedListPtr list, void *newObj){
	TreePtr tempRoot = (TreePtr) malloc(sizeof(struct AVLTree));
	tempRoot->balanceFactor = 0;
	tempRoot->data = newObj;
	tempRoot->left = NULL;
	tempRoot->right = NULL;


	if(list->root == NULL){
		list->root = tempRoot;
	}
	else{
		TreePtr traverse = list->root;
		while(!(traverse->left == NULL && traverse->right == NULL)){ //TEMPORARY CONDITION FIX IT LATER (ONLY THE PLACE TO BE ADDED MUST BE NULL NOT BOTH)
			if(list->compare(traverse, newObj) == -1){ //if the new object is larger than the node being looked at
				traverse = traverse->right;
			}
			else if(cf(traverse, newObj) == 1){ //if the new object is smaller than the node being looked at
				traverse = traverse->left;
			}
			else{ //if the object is a duplicate
				return 0; //return a duplicate error
			}
		}
		
	}
}

int SLRemove(SortedListPtr list, void *newObj){
	return 0;
}

SortedListIteratorPtr SLCreateIterator(SortedListPtr list){

	SortedListIteratorPtr itr = (SortedListIteratorPtr)malloc(sizeof(SortedListIteratorPtr));
	if(list->front != NULL)
	{
		itr->ptr = list->front;
		list->front->reCount++;
		return itr;
	}
	return NULL;
}

void SLDestroyIterator(SortedListIteratorPtr iter){
	if(iter != NULL)
		free(iter);
}

void *SLNextItem(SortedListIteratorPtr iter){
	return NULL;
}