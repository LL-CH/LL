
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
		//���������ڵ�
		ListNode* prev = nullptr;
		ListNode* cur = head;
		//��һ���ڵ�����k-1�����ڶ����ڵ����
		//�����ڵ���k-1�����򵱵�һ����β�ڵ�ʱ���ڶ�����Ϊ������k���ڵ�
		for (int i = 0; i<k - 1; i++){
			//�ж�����ڵ���Ҫ����k-1
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