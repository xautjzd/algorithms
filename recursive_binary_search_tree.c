/************************************
 * 功能: 二叉查找树的地归查找
 * 作者: xautjzd
 * 时间: 2014.07.11
 ***********************************/

typedef struct element {
	int value;
	struct element *leftchild;
	struct element *rightchild;
}element;

element *search(element *root, int key)
{
	/* return the element whose value is key, if there is no such element, return NULL */
	if (!root)
		return NULL;
	if (key == root->value)
		return root;
	if (key < root->value)
		return search(root->leftchild, key);
	return search(root->rightchild, key);
}
