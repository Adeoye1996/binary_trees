#include "binary_trees.h"
/**
 * binary_tree_is_leaf - Checks if a node is a leaf,
 * meaning it has no children.
 * @node: The node to checked.
 * Return: 1 if the node is a leaf or 0 otherwise.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
