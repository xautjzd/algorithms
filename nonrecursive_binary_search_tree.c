typedef struct element {
	int value;
	struct element *leftchild;
	struct element *rightchild;
}element;

element *search(element *root, int key)
{
	while (root) {
		if (key == root->value)
			return root;
		if (key < root->value)
			root = root->leftchild;
		else
			root = root->rightchild;
	}
	return NULL;
}
