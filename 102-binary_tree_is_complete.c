#include <stdlib.h>
#include "binary_trees.h"

/**
 * struct queue_node_s - Structure for a queue node
 * @node: Pointer to the binary tree node
 * @next: Pointer to the next node in the queue
 */
typedef struct queue_node_s
{
	binary_tree_t *node;

	struct queue_node_s *next;
} queue_node_t;

queue_node_t *create_new_node(binary_tree_t *node);
void release_queue(queue_node_t *head);
void enqueue(binary_tree_t *node, queue_node_t *head,
		queue_node_t **tail);
void dequeue(queue_node_t **head);

/**
 * create_new_node - Creates a new node for a queue.
 * @node: The binary tree node for the new node.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */
queue_node_t *create_new_node(binary_tree_t *node)
{
	queue_node_t *new_node;

	new_node = malloc(sizeof(queue_node_t));

	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * release_queue - Frees a queue.
 * @head: A pointer to the head of the queue.
 */
void release_queue(queue_node_t *head)
{
	queue_node_t *temp;

	while (head != NULL)

	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * enqueue - Adds a node to the end of a queue.
 * @node: The binary tree node to enqueue.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 */
void enqueue(binary_tree_t *node, queue_node_t *head,
		queue_node_t **tail)
{
	queue_node_t *new_node;

	new_node = create_new_node(node);

	if (new_node == NULL)

	{
		release_queue(head);
		exit(1);
	}
	(*tail)->next = new_node;
	*tail = new_node;
}

/**
 * dequeue - Removes the front node from a queue.
 * @head: A double pointer to the head of the queue.
 */
void dequeue(queue_node_t **head)
{
	queue_node_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * binary_tree_is_complete - Determines if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_node_t *head, *tail;

	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_new_node((binary_tree_t *)tree);

	if (head == NULL)
		exit(1);

	while (head != NULL)

	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				release_queue(head);
				return (0);
			}
			enqueue(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				release_queue(head);
				return (0);
			}
			enqueue(head->node->right, head, &tail);
		}
		else
	flag = 1;
dequeue(&head);
}
return (1);
}
