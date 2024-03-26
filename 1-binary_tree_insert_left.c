#include "binary_trees.h"

/**
 * binary_tree_insert_left - Adds a node as a left-child of
 *                           another node  in a binary tree.
 * @parent: A reference to the node to attach the left-child to.
 * @value: The value to be stored in the new node.
 *
 * Return: If parent node is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the newly attached node.
 *
 * Description: If the parent node already has a left-child, the new node
 * replaces it, and the existing left-child becomes the
 * left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;

	return (new_node);
}
