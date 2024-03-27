#include "binary_trees.h"

/**
 * next_inorder - Returns the next value in the in-order traversal.
 * @root: A pointer to the root node of the BST to search.
 *
 * Return: The next value in the in-order traversal.
 */
bst_t *next_inorder(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = NULL, *parent = NULL, *successor = NULL;

	node = root;
	while (node != NULL)
	{
		if (node->n == value)
			break;
		parent = node;
		if (node->n < value)
			node = node->right;
		else
			node = node->left;
	}
	if (node == NULL)
		return (root);

	if (node->left == NULL)
	{
		if (parent != NULL)
		{
			if (parent->left == node)
				parent->left = node->right;
			else
				parent->right = node->right;
		}
		else
			root = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
	}
	else if (node->right == NULL)
	{
		if (parent != NULL)
		{
			if (parent->left == node)
				parent->left = node->left;
			else
				parent->right = node->left;
		}
		else
			root = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
	}
	else
	{
		successor = next_inorder(node->right);
		node->n = successor->n;
		return (bst_remove(node->right, successor->n));
	}
	return (root);
}
