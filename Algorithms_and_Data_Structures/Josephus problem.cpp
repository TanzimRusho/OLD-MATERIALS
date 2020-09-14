/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA
 * Technique:
 */

#include<stdio.h>
#include<string.h>


struct person{
    int n;
    struct person* next;
};
typedef struct person node;


node* insertNode( node* p, node* root, int n ){

    node* temp = new node();
    temp->n = n;

    if( p == NULL ){
        temp->next = temp;
        return temp;
    }

    p->next = temp;
    temp->next = root;

    return temp;
}


void printNodes( node* p ){

    node* temp = p;

    while( 1 ){

        printf("%d\n", temp->n);

        if(p->n == temp->next->n)
            return;
        temp = temp->next;

    }
}




int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    int m;
    scanf("%d", &m);

    int c = 0;

    while( m-- ){

        int n, k;
        scanf("%d%d", &n, &k);

        node* p = NULL;
        node* root;

        p = insertNode(p, root, 1);
        root = p;

        for( int i = 2; i <= n; ++i ){
            p = insertNode(p, root, i);
        }

        node* tmp = root;
        for( int i = 0; i < n; ++i ){

            for(int j = 2; j < k; ++j)
                tmp = tmp->next;

            tmp->next = tmp->next->next;
            tmp = tmp->next;
        }

        printf("Case %d: %d\n", ++c, tmp->n);
    }

    return 0;
}
