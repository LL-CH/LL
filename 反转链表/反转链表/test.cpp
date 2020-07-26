
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* pnode = head;
		//���ص�ͷ�ڵ�
		ListNode* phead = nullptr;

		while (pnode != nullptr){
			//������һ���ڵ�
			ListNode* pnext = pnode->next;
			if (pnext == nullptr)
				phead = pnode;

			pnode->next = prev;
			prev = pnode;
			pnode = pnext;
		}
		return phead;
	}
};