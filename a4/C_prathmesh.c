#include <stdio.h>
#include <stdlib.h>

/**
 * First of all we can ignore all strings that are not of the same length as the base string
 * Then we consider all pair of strings and create an edge between them if they differ by one letter
 * Then we perform BFS on our graph with a distance[] and output the the least distance to reach the target string
 * Note: target string is the string that has all the letters different from the base string
**/

char strings[10001][12];

// finds the no of characters that are different across both strings
int compare(char s1[], char s2[], int count)
{
    int ans = 0;
    for (int i = 0; i < count; i++)
    {
        if (s1[i] != s2[i])
        {
            ans++;
        }
    }
    return ans;
}

/* IMPLEMENTING GRAPH */
struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *adj_list[100001];

void initialize_graph(int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        adj_list[i] = NULL;
    }
};

void add_edge(int u, int v)
{
    struct Node *new_node = (struct Node *)(malloc(sizeof(struct Node)));
    new_node->vertex = v;
    new_node->next = adj_list[u];
    adj_list[u] = new_node;

    new_node = (struct Node *)(malloc(sizeof(struct Node)));
    new_node->vertex = u;
    new_node->next = adj_list[v];
    adj_list[v] = new_node;
};
/* IMPLEMENTING GRAPH */

/* IMPLEMENTING QUEUE */
int queue[1001];
int insert_pointer = -1, remove_pointer = -1;
void push(int i)
{
    queue[++insert_pointer] = i;
}
int pop()
{
    return queue[++remove_pointer];
}

int size()
{
    return insert_pointer - remove_pointer;
}
/* IMPLEMENTING QUEUE */

void bfs(int length)
{
    int visited[1001] = {0};
    int distance[1001] = {0};
    push(0);
    visited[0] = 1;
    while (size() > 0)
    {
        int current = pop();
        struct Node *temp = adj_list[current];
        while (temp != NULL)
        {
            if (visited[temp->vertex] == 0)
            {
                visited[temp->vertex] = 1;
                push(temp->vertex);
                distance[temp->vertex] = distance[current] + 1;
                if (compare(strings[0], strings[temp->vertex], 12) == length)
                {
                    printf("%d", distance[temp->vertex] - 1);
                    return;
                }
            }
            temp = temp->next;
        }
    }
    printf("%d", -1);
}

int main()
{
    int n, l = 0;
    scanf("%d", &n);
    initialize_graph(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        char temp[12];
        scanf("%s", strings[i]);
        for (int j = 0; j < 12; j++)
        {
            int ascii = (int)strings[i][j];
            if (ascii < 97 && ascii > 122)
            {
                strings[i][j] = '0';
            }
        }
    }
    while (strings[0][l])
    {
        l++;
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = i + 1; j < n + 1; j++)
        {
            if (compare(strings[i], strings[j], 12) == 1)
            {
                add_edge(i, j);
            }
        }
    }
    bfs(l);
}