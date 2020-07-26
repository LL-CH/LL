
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
		//返回的头节点
		ListNode* phead = nullptr;

		while (pnode != nullptr){
			//保存下一个节点
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