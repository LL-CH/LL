/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
typedef struct ListNode Node;
struct ListNode *detectCycle(struct ListNode *head) {
	Node* slow = head;
	Node* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		//�ߵ�������
		if (slow == fast)
		{
			// �󻷵���ڵ�
			Node* meet = slow;
			Node* start = head;
			while (meet != start)
			{
				meet = meet->next;
				start = start->next;
			}
			return meet;
		}
	}
	return NULL;
}
