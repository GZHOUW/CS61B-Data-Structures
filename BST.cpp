
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) {
		val = x;
		left = nullptr;
		right = nullptr;
	}
};

class BST {
private:
	TreeNode* root;

	bool search(int x, TreeNode* node) {
		// base case: reached leaf without finding x
		if (!node) {
			return false;
		}

		if (node->val == x) {
			return true;
		}
		else if (node->val < x) {
			// go right
			return search(x, node->right);
		}
		else {
			return search(x, node->left);
		}
	}

	TreeNode* insert(int x, TreeNode* node) {
		if (!node) {
			return new TreeNode(x);
		}
		if (x < node->val) {
			node->left = insert(x, node->left);
		}
		else {
			node->right = insert(x, node->right);
		}
		return node;
	}

public:
	BST(int x) {
		root = new TreeNode(x);
	}

	bool search(int x) {
		return search(x, root);
	}
	
	void insert(int x) {
		insert(x, root);
	}
};