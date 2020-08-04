/*
// Definition for a Node.
class Node {
public:
int val;
Node* next;
Node* random;

Node(int _val) {
val = _val;
next = NULL;
random = NULL;
}
};
*/
class Solution {
public:
	//��֪�����������⣿��������
	// Node* copyRandomList(Node* head) {
	//     if(head==nullptr)
	//         return head;
	//     Node* cur=head;
	//     Node* clonehead=NULL;
	//     Node* clonenode=NULL;

	//     //����ԭ����ĸ��ƽڵ㣬���������ԭ�ڵ����
	//     while(cur){
	//         //���ƽڵ�
	//         clonenode=new Node(cur->val);
	//         clonenode->next=cur->next;
	//         clonenode->random=nullptr;
	//         cur->next=clonehead;
	//         cur=clonenode->next;
	//     }

	//     //�����Ƴ����Ľڵ��random��������
	//     cur=head;
	//     while(cur){
	//         clonenode=cur->next;
	//         if(cur->random)
	//             clonenode->random=cur->random->next;

	//         cur=clonenode->next;
	//     }

	//     //��ԭ�����븴������ֿ�
	//     cur=head;
	//     clonehead=clonenode=cur->next;
	//     cur->next=clonenode->next;
	//     cur=cur->next;

	//     while(cur){
	//         clonenode->next=cur->next;
	//         clonenode=clonenode->next;
	//         cur->next=clonenode->next;
	//         cur=cur->next;
	//     }

	//     return clonehead;
	// }

	Node* copyRandomList(Node* head) {
		if (!head) return head;
		Node* CopyHead = NULL;
		Node* CopyCur = NULL;
		Node* cur = head;
		while (cur) {
			CopyCur = new Node(cur->val);
			CopyCur->next = cur->next;
			cur->next = CopyCur;
			cur = CopyCur->next;
		}
		cur = head;
		while (cur) {
			CopyCur = cur->next;
			if (cur->random)
				CopyCur->random = cur->random->next;
			cur = CopyCur->next;
		}
		cur = head;
		CopyCur = CopyHead = head->next;
		cur->next = CopyCur->next;
		cur = cur->next;
		while (cur) {
			CopyCur->next = cur->next;
			CopyCur = CopyCur->next;
			cur->next = CopyCur->next;
			cur = cur->next;
		}
		return CopyHead;
	}
};