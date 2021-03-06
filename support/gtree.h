#ifndef _SUPPORT_TREE_H_
#define _SUPPORT_TREE_H_

#include "../headers.h"
#include "gstats.h"
#include "gstring.h"
#include "gpath.h"

// #define TREE_DEBUG

struct node {

    struct stats *stats;
    int size;
    int capacity;
    struct node **children;
    char *name;
    
};

typedef struct node node_t;
typedef node_t * tree_t;

/*
 * creates a new directory tree with the root directory;
 * 
 * @1: pointer to the location, where the tree will be stored;
 * 
 * returns: 0 on success, -1 otherwise
 */
int gtreenew(struct node **);

/*
 * adds a new file, or rather its path and information about it, to the 
 * directory tree;
 * 
 * @1: pointer to the directory tree;
 * @2: pointer to the information about the file;
 * @3: path used to position element in the tree
 * 
 * returns: 0 on sucess, -1 otherwise
 */
int gtreeadd(tree_t, struct stats *, char *);

/*
 * finds and returns array of names of all children of a given
 * directory;
 * 
 * @1: pointer to the directory tree;
 * @2: path of a directory;
 * 
 * returns: array of strings on success or NULL otherwise;
 */
char** gtreecld(struct node *tree, const char *path);

int gtreeget(struct node *, const char *, struct stats **);

int gtreedel(struct node *, const char *);

/*
 * sets hard link counters in the given tree
 */
void gtreenlinks(tree_t);

#endif
