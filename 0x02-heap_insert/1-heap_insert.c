#include "binary_trees.h"

/**
 * create_node - creates a heap_t node.
 * @parent: pointer to the parent of the node.
 * @value:  value to store in the node.
 * Return: pointer to new node or NULL on failure.
 */
heap_t *create_node(heap_t *parent, int value)
{
	heap_t *new_node;

	new_node = malloc(sizeof(heap_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * binary_tree_is_leaf - checks if a node is a leaf.
 * @node: pointer to the node to check.
 * Return: 1 if node is a leaf, otherwise 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node && !node->left && !node->right)
		return (1);
	return (0);
}

/**
 * binary_tree_height_depth - measures the depth/height of a node/tree.
 * @tree: pointer to the root node of the tree to measure the height
 * or the node to measure the depth.
 * @depth: 1 to measures the depth or 0 to measures the height.
 * Return: depth/height of the node/tree or NULL on failure.
 */
size_t binary_tree_height_depth(const binary_tree_t *tree, int depth)
{
	size_t right_height, left_height;

	if (depth)
	{
		if (!tree || !tree->parent)
			return (0);
		return (binary_tree_height_depth(tree->parent, 1) + 1);
	}

	if (!tree || binary_tree_is_leaf(tree))
		return (0);
	right_height = binary_tree_height_depth(tree->right, 0);
	left_height = binary_tree_height_depth(tree->left, 0);
	if (right_height >= left_height)
		return (1 + right_height);
	return (1 + left_height);
}

/**
 * insert_node - inserts a node into a Max Binary Heap.
 * @tree: pointer to the tree.
 * @level: depth of @tree.
 * @value: value to store in the node.
 * Return: pointer to new node or NULL on failure.
 */
heap_t *insert_node(heap_t *tree, size_t level, int value)
{
	heap_t *aux;

	if (!tree)
		return (NULL);
	if (binary_tree_height_depth(tree, 1) == level)
	{
		if (!tree->left && !tree->right)
			return (tree->left = create_node(tree, value));
		if (tree->left && !tree->right)
			return (tree->right = create_node(tree, value));
		return (NULL);
	}
	aux = insert_node(tree->left, level, value);
	if (aux)
		return (aux);
	return (insert_node(tree->right, level, value));
}

/**
 * heap_insert - inserts a node into a Max Binary Heap.
 * @root: double pointer to the root of the heap.
 * @value: value to store in the node.
 * Return: pointer to new node or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	size_t level, aux;
	heap_t *parent;
	heap_t *new_node = NULL;

	if (!*root)
	{
		*root = create_node(*root, value);
		return (*root);
	}
	for (level = 0; level <= binary_tree_height_depth(*root, 0); level++)
	{
		new_node = insert_node(*root, level, value);
		if (new_node)
			break;
	}
	parent = new_node->parent;
	if (new_node->n > parent->n)
	{
		aux = new_node->n;
		new_node->n = parent->n;
		parent->n = aux;
	}
	return (new_node);
}
