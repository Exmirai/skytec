typedef struct node_s
{
	int data;
	node* left;
	node* right;
} node;

void insert(node** tree, int val){
	node* temp = 0;
	if (!(*tree)) {
		temp = (node*)malloc(sizeof(node));
		temp->left = temp->right = 0;

		temp->data = val;
		*tree = temp;
		return;
	}
	if (val < (*tree)->data) {
		insert(&(*tree)->left, val);
	}
	else if (val > (*tree)->data) {
		insert(&(*tree)->right, val);
	}
}


int getRightMin(node* root){
    node* temp = root;
    while (temp->left != 0) { temp = temp->left; }

    return temp->data;
}

node *delete(node** tree, int val){
    node* root = *tree;
    if (root == 0)
        return 0;
    if (root->data < val)
        root->right = removeNode(root->right, val);
    else if (root->data > val)
        root->left = removeNode(root->left, val);
    else
    {
        if (root->left == 0 && root->right == 0)
        {
            free(root);
            return 0;
        }
        else if (root->left == 0)
        {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == 0)
        {
            node* temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            int rightMin = getRightMin(root->right);
            root->data = rightMin;
            root->right = removeNode(root->right, rightMin);
        }

    }
    return root;
}