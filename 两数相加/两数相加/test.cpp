
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = nullptr;
		ListNode* cur = nullptr;
		//进位
		int flag = 0;
		while (l1 || l2) {
			//取节点值
			int n1 = l1 ? l1->val : 0;
			int n2 = l2 ? l2->val : 0;
			int sum = n1 + n2 + flag;
			if (!head) {
				head = cur = new ListNode(sum % 10);

			}
			else {
				cur->next = new ListNode(sum % 10);
				cur = cur->next;
			}
			//取进位
			flag = sum / 10;
			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;

			if (flag)
				cur->next = new ListNode(flag);
		}

		return head;
	}
};