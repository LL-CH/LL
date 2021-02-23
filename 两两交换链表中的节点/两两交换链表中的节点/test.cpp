class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* first = new ListNode(0); //��һ���ڱ��ڵ�
		first->next = head;
		ListNode* p1 = first; //p1Ϊ�轻���Ľڵ�ǰ��һ���ڵ�
		ListNode* p2; //���ڵ�p2��p2->next��������������Ҫ�����¼�����ڵ�֮ǰ�Ľڵ㡣
		while (p1->next != NULL && p1->next->next != NULL)
		{
			p2 = p1->next;
			p1->next = p2->next;
			p2->next = p2->next->next;
			p1->next->next = p2;
			p1 = p2; //����p1
		}
		return first->next;
	}
};

//�ݹ�
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