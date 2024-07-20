#include "binary_trees.h"

/**
 * get_last_node - Gets the last node in level order
 * @root: Pointer to the root node
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
    heap_t *last = NULL;
    queue_t *queue = create_queue();

    if (!queue)
        return (NULL);

    enqueue(&queue, root);
    while (!is_empty(queue))
    {
        last = dequeue(&queue);
        if (last->left)
            enqueue(&queue, last->left);
        if (last->right)
            enqueue(&queue, last->right);
    }

    free_queue(queue);
    return (last);
}

/**
 * sift_down - Restores the Max Heap property by sifting down
 * @node: Pointer to the node to sift down
 */
void sift_down(heap_t *node)
{
    heap_t *largest;
    int temp;

    while (node->left || node->right)
    {
        largest = node;
        if (node->left && node->left->n > largest->n)
            largest = node->left;
        if (node->right && node->right->n > largest->n)
            largest = node->right;
        if (largest == node)
            break;

        /* Swap values */
        temp = node->n;
        node->n = largest->n;
        largest->n = temp;

        node = largest;
    }
}
