#include "binary_trees.h"

/**
 * find_successor - Finds the in-order successor of a given node.
 * @node: A pointer to the node.
 *
 * Return: The in-order successor of the node.
 */
bst_t *find_successor(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the tree.
 * @value: The value to be removed.
 *
 * Return: A pointer to the new root node after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);

	} else if (value > root->n)

	{
		root->right = bst_remove(root->right, value);

	} else

	{
		if (root->left == NULL)

		{
			bst_t *temp = root->right;
			free(root);
			return (temp);

		} else if (root->right == NULL)

		{
			bst_t *temp = root->left;
			free(root);
			return (temp);

		} else

		{
			bst_t *successor = find_successor(root->right);
			root->n = successor->n;
			root->right = bst_remove(root->right, successor->n);
		}
	}
	return (root);
}
