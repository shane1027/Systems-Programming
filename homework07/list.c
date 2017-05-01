/* list.c */

#include "list.h"

/* Internal Function Prototypes */

static struct node*	reverse(struct node *curr, struct node *next);
static struct node *	msort(struct node *head, node_compare f);
static void		split(struct node *head, struct node **left, struct node **right);
static struct node *	merge(struct node *left, struct node *right, node_compare f);

/**
 * Create list.
 *
 * This allocates a list that the user must later deallocate.
 * @return  Allocated list structure.
 */
struct list *	list_create() {
    struct list* new_list;

    if ((new_list = malloc(sizeof(struct list))) == NULL) {
        fprintf(stderr, "Oops! Didn't get memory for a new list :(\n");
        return NULL;
    } else {
        new_list->head = NULL;
        new_list->tail = NULL;
        new_list->size = 0;
        return new_list; 
    }
}

/**
 * Delete list.
 *
 * This deallocates the given list along with the nodes inside the list.
 * @param   l	    List to deallocate.
 * @return  NULL pointer.
 */
struct list *	list_delete(struct list *l) {
    if (l->size) {
        node_delete(l->head, true);
    }
    free(l);
    return NULL;
}

/**
 * Push front.
 *
 * This adds a new node containing the given string to the front of the list.
 * @param   l	    List structure.
 * @param   s	    String.
 */
void		list_push_front(struct list *l, char *s) {
    struct node* new_node = node_create(s, l->head);// add new node @list front         
    //printf("head is %p\n", l->head);
    l->head = new_node;                    // update list structure head + size
    if (!l->size) {
        l->tail = new_node; 
    }
    l->size++;
}

/**
 * Push back.
 *
 * This adds a new node containing the given string to the back of the list.
 * @param   l	    List structure.
 * @param   s	    String.
 */
void		list_push_back(struct list *l, char *s) {
    struct node* new_node = node_create(s, NULL);      // add new node @ list end
    if (!l->size) {
        l->head = new_node; 
        l->tail = new_node;
    } else {
        l->tail->next = new_node;             // adjust prev. end to pt to new end
        l->tail = new_node;
    }
    l->size++;
}

/**
 * Dump list to stream.
 *
 * This dumps out all the nodes in the list to the given stream.
 * @param   l	    List structure.
 * @param   stream  File stream.
 */
void		list_dump(struct list *l, FILE *stream) {
    struct node* current_node = l->head;
    do {
        if (!l->size)       // if there are no nodes, nothing to dump, silly!
            break;
        node_dump(current_node, stream);
        //printf("Next node: %p\n", current_node->next);
    } while ((current_node = current_node->next));
}

/**
 * Convert list to array.
 *
 * This copies the pointers to nodes in the list to a newly allocate array that
 * the user must later deallocate.
 * @param   l	    List structure.
 * @return  Allocate array of pointers to nodes.
 */
struct node **	list_to_array(struct list *l) {
    struct node** p = malloc(sizeof(struct node*)*l->size);
    struct node* current_node = l->head;
    int i;

    for (i = 0; i < l->size; i++) {
        p[i] = current_node; 
        current_node = current_node->next;
        /*
        if (current_node == NULL) {
            fprintf(stderr, "node is NULL\n"); 
            break;
        }
        */
    }

    return p;
}

/**
 * Sort list using qsort.
 *
 * This sorts the list using the qsort function from the standard C library.
 * @param   l	    List structure.
 * @param   f	    Node comparison function.
 */
void		list_qsort(struct list *l, node_compare f) {
    struct node ** node_array = list_to_array(l);
    qsort(node_array, (size_t)l->size, (size_t)sizeof(struct node*), f);
    //puts("well at least we didn't crash during qsort.");

    int i;
    for (i = 0; i < (l->size)-1; i++) {
        node_array[i]->next = node_array[i+1];
    }
    node_array[i]->next = NULL;    // i is the index of last node in list here
    l->head = node_array[0];
    l->tail = node_array[(l->size)-1];

    free(node_array);
    
}

/**
 * Reverse list.
 *
 * This reverses the list.
 * @param   l	    List structure.
 */
void		list_reverse(struct list *l) {
    l->tail = l->head;              // swap 'em out, reverse 'em up
    l->head = reverse(l->head, NULL);
}

/**
 * Reverse node.
 *
 * This internal function recursively reverses the node.
 * @param   curr    The current node.
 * @param   prev    The previous node.
 * @return  The new head of the singly-linked list.
 */
struct node*	reverse(struct node *curr, struct node *prev) {

    struct node *orig_curr_node_next = curr; // next node to recurse w/
    // initialize above so that it has a value when reaching first case
    //
    //puts("in the reversing function");

    if (curr->next == NULL) {
        curr->next = prev;
        //puts("made it to case 1");
        return curr;
    } else {
        //puts("made it to case 2");
        //fprintf(stdout, "recursing with node next as %s...\n", prev->next->string);
        orig_curr_node_next = reverse(curr->next, curr); 
    }

    curr->next = prev;
    return orig_curr_node_next;

}

/**
 * Sort list using merge sort.
 *
 * This sorts the list using a custom implementation of merge sort.
 * @param   l	    List structure.
 * @param   f	    Node comparison function.
 */
void		list_msort(struct list *l, node_compare f) {
    //if ((l->head == NULL) || (l->head->next == NULL))
        //return; 

    struct node *curr = NULL;
    l->head = msort(l->head, f);
    //puts("phew got past line 205");
    curr = l->head;

    while (curr->next)
        curr = curr->next;

    l->tail = curr;
    l->tail->next = NULL;

}

/**
 * Performs recursive merge sort.
 *
 * This internal function performs a recursive merge sort on the singly-linked
 * list starting with head.
 * @param   head    The first node in a singly-linked list.
 * @param   f	    Node comparison function.
 * @return  The new head of the list.
 */
struct node *	msort(struct node *head, node_compare f) {
    if ((head == NULL) || (head->next == NULL))
        return head; 

    struct node *left, *right;

    split(head, &left, &right);
    left = msort(left, f); right = msort(right, f);

    //puts("finished msort func");

    return merge(left, right, f);
}

/**
 * Splits the list.
 *
 * This internal function splits the singly-linked list starting with head into
 * left and right sublists.
 * @param   head    The first node in a singly-linked list.
 * @param   left    The left sublist.
 * @param   right   The right sublist.
 */
void		split(struct node *head, struct node **left, struct node **right) {

    //puts("made it to split");

    struct node *temp = head;           // use to find tail of left list

    struct node *first = head->next;
    struct node *second = first->next;

    // fast-slow pointer approach

    while (second && second->next) {          // once 
        temp = first;
        second = second->next->next;        // move twice
        first = first->next;        // this will never hit null since
                                    // it's always behind the ptr 'second'
    }


    *left = head;           // left starts at head and ends at temp
    *right = first;         // right ends at the old tail, no need to add NULL
    temp->next = NULL;      // close off left list




    /* having trouble with this implementation.  starting again from scratch..
    if (head == NULL || head->next == NULL) {
        *left = head;
        *right = NULL;
    } else {        // move one pointer twice as fast as other to find midpt
        struct node * first = head;
        struct node * second = head->next;
        
        while (second) {
            second = second->next; 
            if (second) {
                first = first->next;
                second = second->next;
            }
        }

        first = first->next;
        *right = first->next;
        first->next = NULL;

    }
    */

    //puts("finished split");
}

/**
 * Merge sublists.
 *
 * This internal function merges the left and right sublists into one ordered
 * list.
 * @param   left    The left sublist.
 * @param   right   The right sublist.
 * @param   f	    Node comparison function.
 * @return  The new head of the list.
 */
struct node *	merge(struct node *left, struct node *right, node_compare f) {
    
    struct node * merged_list = NULL;

    // potentially need new pointers for left and right to not modify
    // accidentally
    
    struct node * temp_left = left;
    struct node * temp_right = right;

    //puts("started merging");
    if (f(&temp_left, &temp_right) < 0) {merged_list = temp_left; temp_left = temp_left->next;}
    else {merged_list = temp_right; temp_right = temp_right->next;}
    struct node * merged_head = merged_list;

    while (temp_left && temp_right) {
        if (f(&temp_left, &temp_right) < 0) {   // compare the two nodes.  < 0, use left
            merged_list->next = temp_left;
            temp_left = temp_left->next;
        } else {
            merged_list->next = temp_right;
            temp_right = temp_right->next;
        }

        merged_list = merged_list->next;
    }
    //puts("no");

    if (left != NULL) {          // append rest of leftover list to merged_list
        //puts("entered case 1");
        merged_list->next = left;
        //puts("why won't it get here");
    }
    else {
        //puts("entered case two");
        merged_list->next = temp_right;
    }

    //puts("finished merging");

    return merged_head;

}
