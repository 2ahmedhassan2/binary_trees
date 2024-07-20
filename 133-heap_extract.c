#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: The value stored in the root node, or 0 if the function fails
 */
int heap_extract(heap_t **root)
{
    heap_t *last, *parent;
    int value;

    if (!root || !*root)
        return (0);

    value = (*root)->n;
    last = get_last_node(*root);

    if (last == *root)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    /* Swap the value of root with the last node */
    (*root)->n = last->n;
    parent = last->parent;
    if (parent->left == last)
        parent->left = NULL;
    else
        parent->right = NULL;
    free(last);

    /* Restore Max Heap property */
    sift_down(*root);

    return (value);
}
