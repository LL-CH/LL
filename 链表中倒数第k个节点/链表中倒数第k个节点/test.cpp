
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		if (head == nullptr || k == 0)
			return nullptr;
		//构建两个节点
		ListNode* prev = nullptr;
		ListNode* cur = head;
		//让一个节点先走k-1步，第二个节点才走
		//两个节点间差k-1步，则当第一个到尾节点时，第二个则为倒数第k个节点
		for (int i = 0; i<k - 1; i++){
			//判断链表节点数要大于k-1
			if (head->next != nullptr){
				cur = cur->next;
			}
			else{
				return nullptr;
			}
		}
		prev = head;
		while (cur->next != nullptr){
			cur = cur->next;
			prev = prev->next;
		}

		return prev;
	}
};