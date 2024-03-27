#include "binary_trees.h"
#include <limits.h>

/**
 * is_valid_bst - Checks if the binary tree,
 * is a valid Binary Search Tree.
 *
 * @tree: A pointer to the root node of the tree to examine.
 * @min: The minimum value allowed for a node in the tree.
 * @max: The maximum value allowed for a node in the tree.
 *
 * Return: 1 if the tree is a valid Binary Search Tree, 0 otherwise.
 */
int is_valid_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (
			is_valid_bst(tree->left, min, tree->n - 1) &&
			is_valid_bst(tree->right, tree->n + 1, max)
			);
}

/**
 * binary_tree_is_bst - Determines if a binary tree,
 * is a valid Binary Search Tree.
 *
 * @tree: A pointer to the root node of the tree to examine.
 *
 * Return: 1 if the tree is a valid Binary Search Tree, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_valid_bst(tree, INT_MIN, INT_MAX));
}
