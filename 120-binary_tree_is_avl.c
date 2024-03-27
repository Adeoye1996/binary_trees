#include "binary_trees.h"
#include <limits.h>

size_t calculate_height(const binary_tree_t *tree);
int is_valid_avl_helper(const binary_tree_t *tree, int min_val, int max_val);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * calculate_height - Determines the height of a binary tree.
 * @tree: A pointer to the root node of the tree to calculate the height.
 *
 * Return: If the tree is NULL, return 0; otherwise, return the height.
 */
size_t calculate_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_height = 0, right_height = 0;

left_height = tree->left ? 1 + calculate_height(tree->left) : 1;
right_height = tree->right ? 1 + calculate_height(tree->right) : 1;

return ((left_height > right_height) ? left_height : right_height);
	}

	return (0);
}

/**
 * is_valid_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @min_val: The smallest value encountered so far.
 * @max_val: The largest value encountered so far.
 *
 * Return: If the tree is a valid AVL tree, return 1; otherwise, return 0.
 */
int is_valid_avl_helper(const binary_tree_t *tree, int min_val, int max_val)
{
	size_t left_height, right_height, difference;

	if (tree != NULL)
	{
		if (tree->n < min_val || tree->n > max_val)
			return (0);
	left_height = calculate_height(tree->left);
	right_height = calculate_height(tree->right);
	difference = left_height > right_height ?
		left_height - right_height :
		right_height - left_height;
	if (difference > 1)
		return (0);
return (is_valid_avl_helper(tree->left, min_val, tree->n - 1) &&
	is_valid_avl_helper(tree->right, tree->n + 1, max_val));
	}

	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid AVL tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_valid_avl_helper(tree, INT_MIN, INT_MAX));
}
