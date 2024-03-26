#include "binary_trees.h"

/**
 * binary_tree_node - Generates a new binary tree node.
 * @parent: A refrence to the parent node.
 * @value: The value to be stored in the new node.
 *
 * Return: If memory allocation fails - NULL.
 *         Otherwise - a pointer to the newly created node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
