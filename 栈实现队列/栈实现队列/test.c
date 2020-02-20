typedef struct {
	int size;
	int first;
	int end;
	int *arry;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue *a;
	a = malloc(sizeof(MyQueue));
	a->arry = malloc(sizeof(int)* 1024);
	a->size = 0;
	a->first = 0;
	a->end = 0;
	return a;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	obj->size++;
	obj->arry[obj->end] = x;
	obj->end++;

}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	obj->size--;
	int num = obj->arry[0];
	obj->arry++;
	obj->end--;
	return num;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	return obj->arry[0];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	if (obj->size == 0) {
		return true;
	}
	else {
		return false;
	}
}

void myQueueFree(MyQueue* obj) {
	free(obj);
}