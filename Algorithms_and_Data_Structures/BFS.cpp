/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 */

#include<stdio.h>

#define size 100

/**
 * Here nodes are represented with characters
 */
char vertex[size], visited_sequence[size], q[size];

/**
 * The graph which is a 2D matrix
 */
int graph[size][size];

/**
 * Counters for visited sequence, queue etc
 */
int count_visited_seq = 0, f = 0, r = 0, n;


/**
 * Update the visited sequence array
 */
void visit(char v)
{
    visited_sequence[count_visited_seq++] = v;
}


/**
 * Check the visited sequence array against a node
 * to see if it is already visited
 */
int isVisited(char v)
{
    for(int i = 0; i != count_visited_seq; ++i)
    {
        if(visited_sequence[i] == v)
        {
            return 1; // means already visited
        }
    }
    return 0; // not visited
}


/**
 * Display the BFS visited sequence
 */
void displayVisitedSequence()
{
    for(int i = 0; i < count_visited_seq; ++i)
    {
        printf("%c ", visited_sequence[i]);
    }
    printf("\n");
}


void enqueue(char v)
{
    int s = (r + 1) % (size + 1);
    if(s == f)
    {
        return;
    }
    q[s] = v;
    r = s;
}


char dequeue()
{
    if(f == r)
    {
        return '\0';
    }
    f = (f + 1) % (size + 1);
    char v = q[f];
    q[f] = '\0';
    return v;
}


/**
 * Check the adjacent nodes of given node to see if there is an edge
 * Also check if it is not already visited then enter it to queue
 */
void checkAdjecency(char v)
{
    for(int i = 0; i != n; ++i)
    {
        if(vertex[i] == v)
        {
            for(int j = 0; j != n; ++j)
            {
                if(graph[i][j] == 1 && !isVisited(vertex[j]))
                {
                    enqueue(vertex[j]);
                }
            }
        }
    }
}


/**
 * Create undirected graph, map characters as nodes identifiers
 * Reset the graph meaning set 0, to point out no edge exist
 */
void createGraph()
{
    int i, j;
    for(i = 0; i < 26; ++i)
    {
        vertex[i] = i + 'A';
    }

    printf("How many vertex:\n");
    scanf("%d", &n);
    for(i = 0; i != n; ++i)
    {
        for(j = 0; j != n; ++j)
        {
            graph[i][j] = 0;
        }
    }

    for(i = 0; i != n; ++i)
    {
        for(j = i + 1; j != n; ++j)
        {
            printf("%c-%c exist:\n", vertex[i], vertex[j]);
            scanf("%d", &graph[i][j]);
            if(graph[i][j] == 1)
            {
                graph[j][i] = graph[i][j];
            }
        }
    }
}


/**
 * Start processing the queue
 */
void BFS()
{
    char v;
    int exit = 0;
    while(1)
    {
        fflush(stdout);
        printf("Enter a node to Enqueue:\n");
        fflush(stdin);
        scanf("%c", &v);
        for(int i = 0; i != n; ++i)
        {
            if(vertex[i] == v)
            {
                enqueue(vertex[i]);
                exit = 1;
            }
        }
        if(exit)
        {
            break;
        }
    }

    while(f != r)
    {
        char v = dequeue();
        if(!isVisited(v))
        {
            visit(v);
        }
        checkAdjecency(v);
    }
}


int main()
{
    createGraph();
    BFS();
    displayVisitedSequence();
    return 0;
}
