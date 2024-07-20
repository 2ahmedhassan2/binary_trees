#include "binary_trees.h"

/**
 * create_queue - Creates an empty queue
 * Return: Pointer to the new queue
 */
queue_t *create_queue(void)
{
    return (NULL);
}

/**
 * enqueue - Adds a node to the end of the queue
 * @queue: Double pointer to the queue
 * @node: Node to add to the queue
 */
void enqueue(queue_t **queue, heap_t *node)
{
    queue_t *new_node, *temp;

    new_node = malloc(sizeof(queue_t));
    if (!new_node)
        return;
    new_node->node = node;
    new_node->next = NULL;

    if (!*queue)
    {
        *queue = new_node;
        return;
    }

    temp = *queue;
    while (temp->next)
        temp = temp->next;
    temp->next = new_node;
}

/**
 * dequeue - Removes and returns the node at the front of the queue
 * @queue: Double pointer to the queue
 * Return: Node at the front of the queue
 */
heap_t *dequeue(queue_t **queue)
{
    queue_t *temp;
    heap_t *node;

    if (!*queue)
        return (NULL);

    temp = *queue;
    node = temp->node;
    *queue = (*queue)->next;
    free(temp);

    return (node);
}

/**
 * is_empty - Checks if the queue is empty
 * @queue: Pointer to the queue
 * Return: 1 if the queue is empty, 0 otherwise
 */
int is_empty(queue_t *queue)
{
    return (queue == NULL);
}

/**
 * free_queue - Frees the queue
 * @queue: Pointer to the queue
 */
void free_queue(queue_t *queue)
{
    queue_t *temp;

    while (queue)
    {
        temp = queue;
        queue = queue->next;
        free(temp);
    }
}
