#ifndef TREE_NODE_H_INCLUDED
#define TREE_NODE_H_INCLUDED

#include <vector>
#include <string>

// Requires C++11 or higher (rvalue references, parameter packs)

/* A tree node consisting of a string label and an arbitrary number of
 * children.  Defined as a struct, not a class, because the data are
 * public (to avoid having to provide getter methods).
 */
struct tree_node
{
	// Construct a tree_node with a given label and any number of
	// children.  Each argument after the first should be a
	// tree_node *: Enforcing that constraint in the type would
	// require C++20 Concepts, so is not done here.
	//
	// The child nodes should have been allocated with new, as
	// the destructor will free them with delete.  Also, no node
	// should appear twice in the same tree.
	//
	// Call as: tree_node *node = new tree_node("label", child1, child2);
	template<typename... Args>
	tree_node(const std::string &label, Args... children)
		: label(label), children{children...}
	{}

	// By the rule of five, if we define one of these, we should define
	// them all.  Note the destructor is not virtual, so you should not
	// inherit from this struct.

	// (Deep) copy constructor and assignment operator.
	tree_node(const tree_node &tn);
	tree_node &operator=(const tree_node &tn);
	// Move constructor and assignment operator (C++11 and later).
	tree_node(tree_node &&tn);
	tree_node &operator=(tree_node &&tn);
	// Destructor: Frees all the descendants too!
	~tree_node();

	// Free all children and empty the children vector.
	void free_children();

	// Data members
	std::string label;
	std::vector<tree_node *> children;
};

/* Recursively print a tree (to cout), with ASCII art.  Output looks like:
 *
 * root label
 * |
 * +-- child 1 label
 * |   |
 * |   +-- grandchild label
 * |   |
 * |   +-- another grandchild label
 * |   |
 * |   *
 * |
 * +-- child 2 label
 * |   |
 * |   +-- last grandchild label
 * |   |   |
 * |   |   +-- great-grandchild
 * |   |   |
 * |   |   *
 * |   *
 * *
 *
 * It would be possible to eliminate the "*"s that indicate the end of a
 * child list, but that would complicate the interface, since we'd have
 * to track which ancestors have reached the end of their child lists.
 *
 * Depth should be 0 for the initial call.
 */
void print_tree(const tree_node *root, int depth=0);

#endif // TREE_NODE_H_INCLUDED
