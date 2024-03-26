#include "binary_trees.h"

/**
 * binary_tree_insert_right - Addsa node as the right-child
 *                            of another in a binary tree.
 * @parent: A reference to the node to insert the right-child in.
 * @value: The value to stored in the new node.
 *
 * Return: If parent is node is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the newly inserted node.
 *
 * Description: If parent node already has a right-child, the new node
 *              replaces it,and the existing right-child becomes
 *              the right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
