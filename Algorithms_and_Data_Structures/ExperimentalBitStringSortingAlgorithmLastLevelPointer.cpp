/**
 * By:   Asif Ahmed
 * TODO: Instead of set increment val_count to reflect duplicate values.
 * Current State: Currently it behaves like a set. To print duplicate elements increase value count
 *                and in print function do a loop for printing same element.
 * Speed: on 16 bit integers it gets faster than merge sort as N gets larger
 *        on 32 bit integers it gets slightly faster as N gets very large.
 */



#include<bits/stdc++.h>
using namespace std;

#define TOTALBITS 16
#define N 100000


typedef struct alist anode;
struct alist{
    int val_count;
    int val;
};

typedef struct bstree bnode;
struct bstree{
    bnode *left;
    bnode *right;
    anode *p;
};


//int executionCount = 0;
void printGivenLevel(bnode* root, int level)
{
    //++executionCount;
    if (root == NULL)
        return;
    if (level == 1){
        int c = root->p->val_count;
        //for(int i = 0; i < c; ++i){
            printf("%d ", root->p->val);
        //}
    }
    else{
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}


int main(){

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist(1, pow(2,TOTALBITS) );

    int unsorted[N];
    for(int i = 0; i < N; ++i){
        unsorted[i] = dist(mt);
        //printf("%d ", unsorted[i]);
    }



    // create R root
    bnode *R;
    R = new bnode();


    // access inside main
    anode* aroot;


    // For the first time this is needed but can be avoided
    if(unsorted[0]){
        //cout << S << endl;

        // create anode beforehand for the first time
        aroot = new anode();
        aroot->val = unsorted[0];
        aroot->val_count = 1;

        // create temp root
        bnode* r = R;
        int val = unsorted[0];

        // For each of the bits create node and connect to tree
        for(int i = TOTALBITS - 1; i >= 0; --i){
            bnode *temp = new bnode();
            temp->p = aroot;
            if((val >> i) & 1){
                r->right = temp;
            }else{
                r->left = temp;
            }
            r = temp;
        }
        r->left = NULL;
        r->right = NULL;
    }


    // hold bottom level alist root in a temporary root
    anode *arootTemp = aroot;
    anode *an;
    bnode *tmp;

    // For all other inputs
    for(int j = 1; j < N; ++j){

        // create temp root
        bnode* r = R;

        //
        bool createOnce = true;
        //
        //cout << "==================\n";
        //cout << "USING: " << S << "\n";

        int val = unsorted[j];

        //printf("FOR:: %d\n", val);
        int x = 0;

        // For each of the bits create node and connect to tree
        for(int i = TOTALBITS - 1; i >= 0; --i){
            //cout << "USING BIT: " << ((val >> i) & 1)  << "\n";

            // If bit is zero then go left otherwise go right
            if( (val >> i) & 1 ){
                if(r->right){
                    //cout << "FOLLOWING LAID OUT PATH RIGHT: " << "\n";
                    r = r->right;
                    ++x;
                }else{
                    x = 0;
                    //cout << "CREATING NEW NODE RIGHT: " << "\n";
                    if(createOnce){
                        an = new anode();
                        an->val = unsorted[j];
                        an->val_count = 1; // If this is done it acts as a set
                        createOnce = false;
                    }
                    tmp = new bnode();
                    tmp->left = NULL;
                    tmp->right = NULL;

                    // now mark tmp as the new r
                    r->right = tmp;
                    r = tmp;
                }
            }else{
                if(r->left){
                    //cout << "FOLLOWING LAID OUT PATH LEFT: " << "\n";
                    r = r->left;
                    ++x;
                }else{
                    x = 0;
                    //cout << "CREATING NEW NODE LEFT: " << "\n";
                    if(createOnce){
                        an = new anode();
                        an->val = unsorted[j];
                        an->val_count = 1; // If this is done it acts as a set
                        createOnce = false;
                    }
                    tmp = new bnode();
                    tmp->left = NULL;
                    tmp->right = NULL;

                    // now mark tmp as the new r
                    r->left = tmp;
                    r = tmp;
                }
            }
        }
        tmp->p = an;

        if(x == TOTALBITS){
            r->p->val_count = r->p->val_count + 1;
        }
    }
   // printf("===================\nDone\n===================\n");


    // now run DFS to sort
    // r is a node* that was defined above


    /**
     * UNCOMMENT LINES BELOW TO PRINT SET RESULT.
     */

    bnode* r;
    r = R->left;
    printGivenLevel(r, TOTALBITS);
    r = R->right;
    printGivenLevel(r, TOTALBITS);



    //printf("\n===========================================\n");
    //printf("\nLOOP EXECUTION COUNT: %d \n", executionCount);

    return 0;
}
