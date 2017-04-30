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
        printf("Oops! Didn't get memory for a new list :(\n");
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
    if (l->size)
        node_delete(l->head, true);
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
    l->size += 1;
}

/**
 * Push back.
 *
 * This adds a new node containing the given string to the back of the list.
 * @param   l	    List structure.
 * @param   s	    String.
 */
void		list_push_back(struct list *l, char *s) {
    struct node* new_node = node_create(s, 0);      // add new node @ list end
    if (!l->size) {
        l->head = new_node; 
        l->tail = new_node;
    } else {
        l->tail->next = new_node;             // adjust prev. end to pt to new end
        l->tail = new_node;
    }
    l->size += 1;
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
    puts("well at least we didn't crash during qsort.");

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
    struct node* current_node = l->head;
    l-> tail = current_node;
    printf("Current head: %p\n", current_node);
    for (int i = 0; i < l->size; i++) { 
        l->head = reverse(current_node->next, current_node);
        current_node = l->head;
    }
    l->tail->next = NULL;
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

    printf("prev-next: %s and current = %s\n\n", prev->next->string, curr->string);
    struct node *orig_curr_node_next; // next node to recurse w/

    if (!curr->next) {
        printf("whoops that's null\n");
        curr->next = prev;
        return prev;
    }

    orig_curr_node_next = curr->next;

    printf("curr->next = %s\n", curr->next->string);
    printf("orig_curr_node_next = %s\n", orig_curr_node_next->string);
    printf("prev = %s\n\n", prev->string);

    //curr->next = prev;
    prev->next = orig_curr_node_next;

    printf("prev now points to %s\n\n", prev->next->string);

    printf("recursing...\n");
    printf("entering with previous node = %s, current = %s\n", prev->string, prev->next->string);
    orig_curr_node_next = reverse(prev->next, prev); 
    curr->next = orig_curr_node_next;
    printf("%s now points to %s\n", curr->string, curr->next->string);
    return curr;
}

    /**
     * Sort list using merge sort.
     *
     * This sorts the list using a custom implementation of merge sort.
     * @param   l	    List structure.
     * @param   f	    Node comparison function.
     */
    void		list_msort(struct list *l, node_compare f) {
    if ((l->head == NULL) || (l->head->next == NULL)) {
        return; 
    }

    

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
    return NULL;
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
    return NULL;
}
