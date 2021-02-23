class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* first = new ListNode(0); //加一个哨兵节点
		first->next = head;
		ListNode* p1 = first; //p1为需交换的节点前面一个节点
		ListNode* p2; //将节点p2与p2->next交换。这样不需要额外记录交换节点之前的节点。
		while (p1->next != NULL && p1->next->next != NULL)
		{
			p2 = p1->next;
			p1->next = p2->next;
			p2->next = p2->next->next;
			p1->next->next = p2;
			p1 = p2; //更新p1
		}
		return first->next;
	}
};

//递归
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next)
			return head;
		ListNode *p = head->next;
		head->next = swapPairs(p->next);
		p->next = head;
		return p;
	}
};