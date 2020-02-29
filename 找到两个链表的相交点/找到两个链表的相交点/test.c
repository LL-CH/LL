/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode *h1, *h2;
	h1 = headA;  h2 = headB;
	while (h1 && h2){
		h1 = h1->next;
		h2 = h2->next;
	}
	if (h1){  //h1 长
		while (h1)
		{
			h1 = h1->next;
			headA = headA->next;
		}
		while (headA){
			if (headA == headB)
				return headA;
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;
	}
	else{   // h2 长 或  h1 和 h2一样长
		while (h2){
			h2 = h2->next;
			headB = headB->next;
		}
		while (headB){
			if (headA == headB)
				return headB;
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;
	}
}