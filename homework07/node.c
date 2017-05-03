/* node.c */

#include "node.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/**
 * Create node. 
 *
 * This allocates and configures a node that the user must later deallocate.
 * @param   string      String value.
 * @param   next        Reference to next node.
 * @return  Allocated node structure.
 */
struct node *	node_create(char *string, struct node *next) {
    struct node* new_node;

    if ((new_node = malloc(sizeof(struct node))) == NULL) {
    	printf("Oh no! Didn't get memory for new node :(\n");
    	return NULL;
	}

    if ((new_node->string  = strdup(string)) == NULL) {
    	printf("Oh no! Didn't get memory for new string :(\n");
    	return NULL;
    }
    new_node->next = next;
    new_node->number = atoi(string);

    return new_node;
}

/**
 * Delete node.
 *
 * This deallocates the given node (recursively if specified).
 * @param   n           Node to deallocate.
 * @param   recursive   Whether or not to deallocate recursively.
 * @return  NULL pointer.
 */
struct node *   node_delete(struct node *n, bool recursive) {
    struct node * temp_next = n->next;

    free(n->string);
    free(n);

    if (recursive)
        if (temp_next) {
            //printf("recursing with node %s\n", temp_next->string);
            node_delete(temp_next, true);
        }

    return NULL;

    /*      unsure if the following implementation works correctly.  trying
     *      again...
    struct node* temp;

    if (recursive) {
        while (n != NULL) {
            temp = n;
            n = n->next;
            temp->next = NULL;
            free(temp->string);
            free(temp);
            //temp = NULL;
        }

        return temp;
    } else {
        n->next = NULL;
        free(n->string);
        free(n);
        n = NULL;

        return n;
    }
    */




/*    if (recursive) {
        if (n->next) {
            node_delete(n->next, true); 
        }
        free(n->string);
        free(n);
    } else {
        n->next = NULL;
        free(n->string);
        free(n);
    }*/     // avoided this implementation due to possible stack overflow

}


/**
 * Dump node to stream.
 * 
 * This dumps out the node structure (Node{string, number, next}) to the stream.
 * @param   n       Node structure.
 * @param   stream  File stream.
 **/
void            node_dump(struct node *n, FILE *stream) {
    fprintf(stream, "Node{%s, %d, %p}\n", n->string, n->number, n->next);
}

/**
 * Compare node structures by number
 *
 * This compares two node structures by their number values.
 * @param   a       First node structure.
 * @param   b       Second node structure.
 * @return  < 0 if a < b, 0 if a == 0, > 0 if a > b
 */
int		node_compare_number(const void *a, const void *b) {
    struct node ** A = (struct node **)a;
    struct node ** B = (struct node **)b;

    int num_A = ((*A)->number);    int num_B = ((*B)->number);
    return (num_A - num_B);

    /*      this is also not super clear... let's make it more readable
     *
    if (((struct node*)a)->number == 0) {
        return 0; 
    } else {
        return ((((struct node*)a)->number) - (((struct node*)b)->number));
    }
    */
}

/**
 * Compare node structures by string
 *
 * This compares two node structures by their string values.
 * @param   a       First node structure.
 * @param   b       Second node structure.
 * @return  < 0 if a < b, 0 if a == 0, > 0 if a > b
 */
int		node_compare_string(const void *a, const void *b) {

    struct node ** A = (struct node **)a;
    struct node ** B = (struct node **)b;

    int len_a = strlen((*A)->string);
    int len_b = strlen((*B)->string);

    if (len_a != len_b) {
        if (len_a < len_b)
            return -1;
        else
            return 1;
    }

    return (strcmp((*A)->string, (*B)->string));

    /*      // this implementation is not clear and I shouldn't be comparing
     *      lengths of the strings... this is a hacky way to fix a shortcoming 
     *      of msort which we aren't supposed to be fixing
    int len_a = strlen(((struct node*)a)->string);
    int len_b = strlen(((struct node*)b)->string);
    if (len_a != len_b) {
        if (len_a < len_b)
            return -1;
        else
            return 1;
    }

    return strcmp((((struct node*)b)->string), (((struct node*)a)->string));
    */
}

/* vim: set sts=4 sw=4 ts=4 expandtab ft=c: */
