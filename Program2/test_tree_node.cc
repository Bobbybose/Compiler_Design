#include "tree_node.h"

/* Run this under valgrind to verify that all memory is freed, and
 * that there are no double-frees or other memory errors.
 *
 * The output should look like the example in tree_node.h.
 */
int main()
{
	tree_node *gc1 = new tree_node("grandchild label");
	tree_node *gc2 = new tree_node("another grandchild label");
	tree_node *ch1 = new tree_node("child 1 label", gc1, gc2);

	tree_node *ggc = new tree_node("great-grandchild");
	tree_node *gc3 = new tree_node("last grandchild label", ggc);
	tree_node *ch2 = new tree_node("child 2 label", gc3);

	tree_node *root = new tree_node("root label", ch1, ch2);

	tree_node root2("junk");
	root2 = *root; // copy construct

	print_tree(root);
	print_tree(&root2);

	delete(root);
	// root2 will be freed at end of function.

	return 0;
}
