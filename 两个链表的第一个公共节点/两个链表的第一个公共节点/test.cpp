struct ListNode {
    int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//获取链表长度
	int getlen(ListNode* head){
		int len = 0;
		while (head != nullptr){
			len++;
			head = head->next;
		}
		return len;
	}

	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		// 若两个链表其中任何一个为空，则二者之间不可能有相交节点
		if (headA == nullptr || headB == nullptr)
			return nullptr;
		//求链表长度
		int lenA = getlen(headA);
		int lenB = getlen(headB);
		//链表长度差
		int n = lenA - lenB;

		//p1指向长链表，p2指向短链表
		ListNode* p1 = headA;
		ListNode* p2 = headB;

		if (lenA<lenB){
			p1 = headB;
			p2 = headA;
			n = lenB - lenA;
		}
		//长链表先走n步，直到二者处于同一位置上
		while (n>0){
			p1 = p1->next;
			n--;
		}
		// 二者再同时走，直到遇到相交节点，或者二者都为空
		while (p1 != p2){
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	}
};