void RotateL(Node* parent)
{
	Node* subR = parent->_right;
	Node* subRL = subR->_left;

	parent->_right = subRL;
	if (subRL)
		subRL->_parent = parent;

	subR->_left = parent;
	Node* ppNode = parent->_parent;
	parent->_parent = subR;

	// 1��ԭ��parent��������ĸ�������subR�Ǹ�
	// 2��parentΪ������ֻ���������е��������ı����ӹ�ϵ����ôsubRҪ��������λ��
	if (_root == parent)
	{
		_root = subR;
		subR->_parent = nullptr;
	}
	else
	{
		if (ppNode->_left == parent)
			ppNode->_left = subR;
		else
			ppNode->_right = subR;

		subR->_parent = ppNode;
	}

	parent->_bf = subR->_bf = 0;
}