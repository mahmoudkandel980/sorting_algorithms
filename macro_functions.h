#ifndef MACRO_FUNCTIONS_H
#define MACRO_FUNCTIONS_H

/* CHILD_INDEX - function to get index of child from binary tree. */

/* # PARAMETERS */
/* @I: current index base from to get child.*/
#define CHILD_INDEX(I) (I + 1)

/* LEFT_INDEX - function to get index of left child from binary tree. */

/* # PARAMETERS */
/* @I: current index base from to get child.*/
#define LEFT_INDEX(I) ((CHILD_INDEX(I) * 2) - 1)

/* RIGHT_INDEX - function to get index of right child from binary tree. */

/* # PARAMETERS */
/* @I: current index base from to get child.*/
#define RIGHT_INDEX(I) (LEFT_INDEX(I) + 1)

/* PARENT_INDEX - function to get index of parent from binary tree. */

/* # PARAMETERS */
/* @I: current index base from to get parent.*/
#define PARENT_INDEX(I) (I / 2)

/* IF_PREV_BIGGER - function to check if previous is bigger than current */

/* # PARAMETERS */
/* @NODE: node to check.*/
#define IF_PREV_BIGGER(NODE) ((NODE)->prev && ((NODE)->prev->n > (NODE)->n))

/* SWAP - function to swap two variables. */

/* # PARAMETERS */
/* @VARIABLE_A: first variable. */
/* @VARIABLE_B: second variable. */
/* @TYPE: type of variable. */

/* # LOCALS */
/* @TMP_SWAP: temporal variable for to save value */

/* # MACROS */
/* @false: boolean type data */
#define SWAP(VARIABLE_A, VARIABLE_B, TYPE) \
	do                                     \
	{                                      \
		TYPE TMP_SWAP = VARIABLE_A;        \
		VARIABLE_A = VARIABLE_B;           \
		VARIABLE_B = TMP_SWAP;             \
	} while (false)

/* SWAP_DOUBLE_LIST - function to swap two doubly linked list. */

/* # PARAMETERS */
/* @NODE: first node. */
/* @LIST: first list. */
/* @TYPE: type of variable. */

/* # MACROS */
/* @false: boolean type data */



/* SWAP_DOUBLE_LIST_NEXT - function to swap two doubly linked list. */

/* # PARAMETERS */
/* @NODE: first node. */
/* @LIST: first list. */
/* @TYPE: type of variable. */
#define COPY_FROM_UNTIL(FROM, SINCE, TO, START, LAST) \
	do                                                \
	{                                                 \
		for (; (START) < (LAST); START++, SINCE++)    \
		{                                             \
			TO[START] = FROM[SINCE];                  \
		}                                             \
	} while (false)

/* BUILD_HEAD_STUCTURE - function to build head structure. */

/* # PARAMETERS */
/* @ARRAY: array. */
/* @SIZE: size of array. */

/* # MACROS */
/* @false: boolean type data */
#define BUILD_HEAD_STUCTURE(ARRAY, SIZE)          \
	do                                            \
	{                                             \
		int i = 0;                                \
		for (i = PARENT_INDEX(SIZE); i >= 0; i--) \
		{                                         \
			sift_down(ARRAY, i, SIZE, SIZE);      \
		}                                         \
	} while (false)

/* SWAP_DOUBLE_LIST - function to swap two doubly linked list. */
#define SWAP_DOUBLE_LIST(NODE, HEAD, TYPE)                         \
	do                                                             \
	{                                                              \
		TYPE node_connections[4];                                  \
		node_connections[0] = (NODE)->prev->next;                  \
		node_connections[1] = (NODE)->prev->prev;                  \
		node_connections[2] = (NODE)->next;                        \
		node_connections[3] = (NODE)->prev;                        \
		if (*(HEAD) == node_connections[3])                        \
		{                                                          \
			*(HEAD) = (NODE);                                      \
		}                                                          \
		if (node_connections[3]->prev)                             \
		{                                                          \
			node_connections[3]->prev->next = node_connections[0]; \
		}                                                          \
		if ((NODE)->next)                                          \
		{                                                          \
			(NODE)->next->prev = node_connections[3];              \
		}                                                          \
		node_connections[3]->next = node_connections[2];           \
		node_connections[3]->prev = node_connections[0];           \
		(NODE)->next = node_connections[3];                        \
		(NODE)->prev = node_connections[1];                        \
	} while (false)

/* SWAP_DOUBLE_LIST_NEXT - is used to swap next and current node of double  */
/*                         linked list. */

/* # PARAMETERS */
/* @NODE: pointer to current node to swap . */
/* @HEAD: double pinter to head node of double likend list. */
/* @TYPE: type of the double likend list node. */

/* # LOCALS */
/* @node_connections: array to storage the pointers conections between node.*/

/* # GLOBALS */
/* @false: boolean type data */
#define SWAP_DOUBLE_LIST_NEXT(NODE, HEAD, TYPE)             \
	do                                                      \
	{                                                       \
		TYPE node_connections[4];                           \
		if ((NODE)->prev)                                   \
			node_connections[0] = (NODE)->prev->next;       \
		node_connections[1] = (NODE)->next->next;           \
		node_connections[2] = (NODE)->next;                 \
		node_connections[3] = (NODE);                       \
		if (*(HEAD) == NODE)                                \
		{                                                   \
			*(HEAD) = node_connections[2];                  \
		}                                                   \
		if (NODE->prev)                                     \
		{                                                   \
			(NODE)->prev->next = node_connections[2];       \
		}                                                   \
		if ((NODE)->next->next)                             \
		{                                                   \
			(NODE)->next->next->prev = node_connections[3]; \
		}                                                   \
		(NODE)->next->next = node_connections[3];           \
		(NODE)->next->prev = (NODE)->prev;                  \
		(NODE)->next = node_connections[1];                 \
		(NODE)->prev = node_connections[2];                 \
	} while (false)

#endif /* MACRO_FUNCTIONS_H */
