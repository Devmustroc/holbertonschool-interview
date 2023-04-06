#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
/**
* binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of a binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		size += binary_tree_size(tree->left);
	if (tree->right)
		size += binary_tree_size(tree->right);
	size += 1;
	return (size);
}
/**
* binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_size = 0;
	int right_size = 0;

	if (tree == NULL)
		return (0);
	if (tree == NULL)
		return (0);
	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);
	if (left_size == right_size)
		return (1);
	return (0);
}
/**
*  heap_check_parent -checks the parent value is greater than the son value
 * @son: pointer to the son node
 * @parent: pointer to the father node
 * Return: void
 */
 void heap_check_parent(heap_t **son, heap_t **parent)
{
     heap_t *check_left, *check_right, *child = *son, *father = *parent;
     check_right = (*son)->right;
     check_left = (*son)->left;
     if (child->n > father->n)
     {
         if (child->left)
             child->left->parent = father;
            if (child->right)
                child->right->parent = father;
            if (father->left == child)
            {
                if (father->right)
                    father->right->parent = child;
                child->right = father->right;
                child->left = father;
            }
            else
            {
                if (father->left)
                    father->left->parent = child;
                child->left = father->left;
                child->right = father;
            }
            if (father->parent)
            {
                if (father->parent->left == father)
                    father->parent->left = child;
                else
                    father->parent->right = child;
            }
            else
                *parent = child;
            child->parent = father->parent;
            father->parent = child;
            father->left = check_left;
            father->right = check_right;
     }
}
/**
* heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node;

    if ((*root) == NULL)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }
    if (binary_tree_is_perfect(*root) || (!binary_tree_is_perfect((*root)->left)))
    {
        if ((*root)->left != NULL)
        {
            new_node = heap_insert(&((*root)->left), value);
            heap_check_parent(&((*root)->left), root);
            return (new_node);
        }
        else
        {
            new_node = binary_tree_node(*root, value);
            (*root)->left = new_node;
            heap_check_parent(&((*root)->left), root);
            return (new_node);
        }
    }
    else
    {
        if ((*root)->right != NULL)
        {
            new_node = heap_insert(&((*root)->right), value);
            heap_check_parent(&((*root)->right), root);
            return (new_node);
        }
        else
        {
            new_node = binary_tree_node(*root, value);
            (*root)->right = new_node;
            heap_check_parent(&((*root)->right), root);
            return (new_node);
        }
    }
    return (NULL);
}
