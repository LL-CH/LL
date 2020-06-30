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

	// 1、原来parent是这颗树的跟，现在subR是根
	// 2、parent为根的树只是整颗树中的子树，改变链接关系，那么subR要顶替他的位置
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