struct ListNode {
    int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//��ȡ������
	int getlen(ListNode* head){
		int len = 0;
		while (head != nullptr){
			len++;
			head = head->next;
		}
		return len;
	}

	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		// ���������������κ�һ��Ϊ�գ������֮�䲻�������ཻ�ڵ�
		if (headA == nullptr || headB == nullptr)
			return nullptr;
		//��������
		int lenA = getlen(headA);
		int lenB = getlen(headB);
		//�����Ȳ�
		int n = lenA - lenB;

		//p1ָ������p2ָ�������
		ListNode* p1 = headA;
		ListNode* p2 = headB;

		if (lenA<lenB){
			p1 = headB;
			p2 = headA;
			n = lenB - lenA;
		}
		//����������n����ֱ�����ߴ���ͬһλ����
		while (n>0){
			p1 = p1->next;
			n--;
		}
		// ������ͬʱ�ߣ�ֱ�������ཻ�ڵ㣬���߶��߶�Ϊ��
		while (p1 != p2){
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	}
};