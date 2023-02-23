#include <iostream> // std::cout etc.
#include <utility>  // std::move(), std::swap()

#include "tree_node.h"


// Deep copy another tree_node.
tree_node::tree_node(const tree_node &tn)
	: label(tn.label), children()
{
	// Allocate space in advance, so push_back doesn't have to.
	children.reserve(tn.children.size());

	// Recursive deep copy.
	for (auto child : tn.children)
	{
		children.push_back(new tree_node(*child));
	}
}

// Likewise.
tree_node &tree_node::operator=(const tree_node &tn)
{
	label = tn.label;

	// Make room for the new children.
	free_children();

	// Recursive deep copy.
	for (auto child : tn.children)
	{
		children.push_back(new tree_node(*child));
	}
	return *this;
}

/* Move from a temporary (etc.) tree_node.  This constructor and
 * the corresponding move-assignment operator just below use
 * std::swap(), so we don't have to free our own children (that
 * will happen when tn is destructed).
 */
tree_node::tree_node(tree_node &&tn)
{
	std::swap(label, tn.label);
	std::swap(children, tn.children);
}

// Likewise.
tree_node &tree_node::operator=(tree_node &&tn)
{
	std::swap(label, tn.label);
	std::swap(children, tn.children);
	return *this;
}

tree_node::~tree_node()
{
	free_children();
}

/* Free all children, and empty the children vector.  Since this is called
 * by the destructor, doing so will recursively free all descendants.
 *
 * This is a separate method because it is not only used by the destructor.
 */
void tree_node::free_children()
{
	for (auto child : children)
	{
		delete child;
	}
	children.clear();
}

/* Helper for print_tree().  Print (one row of) vertical connector lines
 * between a node and its children.  count is the number of lines (the
 * depth of the children); negative numbers are allowed, and are treated
 * the same as zero.
 *
 * Each level of the tree is shifted to the right by four spaces.
 */
static void print_vertical_connectors(int count)
{
	for (int i = 0; i < count; ++i) {
		std::cout << "|   ";
	}

}

void print_tree(const tree_node *root, int depth)
{
	// Print, for example:
 	// |   |   +-- great-grandchild
	print_vertical_connectors(depth - 1);
	if (depth > 0)
		std::cout << "+-- ";

	// Code modified to print line and column numbers
	std::cout << root->label << ": " << root->CurrLine << "," << root->CurrColumn << std::endl;

	/* Print the children, separated by vertial lines.  For example, if
	 * depth == 1 (so the children are depth 2), this should give:
	 *
	 * |   |
	 * |   +-- grandchild label
	 * |   |
	 * |   +-- another grandchild label
	 * |   |
	 * |   *
	 *
	 * As a special case, the "*" terminator is omitted if there are
	 * no children.
	 */

	// First the children and the connectors leading to them.
	for (auto child : root->children) {
		print_vertical_connectors(depth + 1);
		std::cout << std::endl;
		print_tree(child, depth + 1);

	}
	// Then the terminator (if necessary) 
	if (root->children.size() > 0) {
		print_vertical_connectors(depth + 1);
		std::cout << std::endl;
		print_vertical_connectors(depth);
		std::cout << "*   ";
		std::cout << std::endl;
	}
}
