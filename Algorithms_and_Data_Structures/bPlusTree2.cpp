#include<bits/stdc++.h>
#define N 4

// Do type definition to make life easier.
typedef struct bptree node;


// Holds the pointers to other b plus tree nodes.
// Allocate memory for the |p| = |k| + 1 number of links
// thats why double pointer is needed.
struct links{
    struct bptree **nodeLinks;
};


// The structure of a b plus tree node where k is an integer array.
// Here p is pointer array of b plus tree nodes. The next pointer is
// used to mark the next node in the same level, currently singly linked
// list to make things easy. isLeaf is a boolean value to check if the
// current node is a leaf or not.
struct bptree{
    int *k;
    bool isLeaf;
    int keyCount;
    struct links *p;
    struct bptree *next;
};


int main(){

    node *root = NULL;

    // Input until ans is zero.
    int ans;
    int val;
    while( scanf("%d", &ans) && ans ){
        printf("Enter value:\n");
        scanf("%d", &val);

        if(root == NULL){
            // allocate memory for root node
            root = new bptree();
            // allocate memory for integer values
            root->k = new int[N-1];
            // allocate memory for links
            root->p = new links();
            // create memory allocation for b plus tree node links
            root->p->nodeLinks = new bptree*[N];
            // root does not have other node in the same level
            root->next = NULL;
            // mark root as a non leaf node
            root->isLeaf = true;
            // assign given value to root node in zeroth position since no other values there
            root->k[0] = val;
            // Set all the child node reference all null since there are none yet
            for(int i = 0; i < N; ++i){
                root->p->nodeLinks[i] = NULL;
            }
            // update number of keys in current node
            root->keyCount = 1;

        }else{

            // Means root a no more space time to split, otherwise keep inserting at root
            // Make the tree grow in height
            if(root->keyCount == N - 1){
                node *newRoot = new bptree();
                newRoot->k = new int[N-1];
                newRoot->p = new links();
                newRoot->p->nodeLinks = new bptree*[N];
                newRoot->isLeaf = false;
                for(int i = 0; i < N; ++i){
                    newRoot->p->nodeLinks[i] = NULL;
                }
                newRoot->keyCount = 0;


                // make newRoot's first child the old root node
                newRoot->p->nodeLinks[0] = root;


                // split the old root and send value to parent
                // Must create a new node
                node *temp = new bptree();
                temp->k = new int[N-1];
                temp->p = new links();
                temp->p->nodeLinks = new bptree*[N];
                temp->isLeaf = true;
                for(int i = 0; i < N; ++i){
                    temp->p->nodeLinks[i] = NULL;
                }
                temp->keyCount = 0;

                // Mark it next to old root since they should be on same level
                // and the old root must now be leaf with the temp node.
                root->next = temp;
                root->isLeaf = true;

                // Now split the value in half and send representing value to new root
                // Starting at the half mark of the old root copy the values to temp node
                // Then set both old root and temp node key count
                for( int i = (N-1)/2 + 1, j = N - 1, x = 0; i < j; ++i, ++x ){
                    temp->k[x] = root->k[i];
                    temp->keyCount = temp->keyCount + 1;
                }

                // Insert the given value in temp
                temp->k[temp->keyCount] = val;
                temp->keyCount = temp->keyCount + 1;
                root->keyCount = root->keyCount - temp->keyCount;

                // now connect temp to new roots right arm
                newRoot->p->nodeLinks[1] = temp;


                // now make the newRoot as root
                root = newRoot;

                // Get the value from temp to new root
                newRoot->k[0] = temp->k[0];


            }else{
                // Root is not full keep inserting at root
                root->k[ root->keyCount ] = val;
                root->keyCount = root->keyCount + 1;
            }

        }

    }



    printf("%d\n", root->p->nodeLinks[1]->k[1] );

    return 0;
}
