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
	//不知道哪里有问题？？？？？
	// Node* copyRandomList(Node* head) {
	//     if(head==nullptr)
	//         return head;
	//     Node* cur=head;
	//     Node* clonehead=NULL;
	//     Node* clonenode=NULL;

	//     //创建原链表的复制节点，并将其放在原节点后面
	//     while(cur){
	//         //复制节点
	//         clonenode=new Node(cur->val);
	//         clonenode->next=cur->next;
	//         clonenode->random=nullptr;
	//         cur->next=clonehead;
	//         cur=clonenode->next;
	//     }

	//     //将复制出来的节点的random进行连接
	//     cur=head;
	//     while(cur){
	//         clonenode=cur->next;
	//         if(cur->random)
	//             clonenode->random=cur->random->next;

	//         cur=clonenode->next;
	//     }

	//     //将原链表与复制链表分开
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