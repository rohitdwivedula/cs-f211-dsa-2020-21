#include <stdio.h>
#include <stdlib.h>

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

int stack[100001];
int visited[100001];
int top = -1;

void push(int i)
{
    stack[++top] = i;
}

int pop()
{
    return stack[top--];
}

int attached_nodes_count(int i)
{
    if (visited[i] == 1)
    {
        return -1;
    }
    int count = 1;
    visited[i] = 1;
    push(i);
    while (top != -1)
    {
        int current = pop();
        struct Node *temp = adj_list[current];
        while (temp != NULL)
        {
            if (visited[temp->vertex] == 0)
            {
                push(temp->vertex);
                count++;
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
    return count;
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[m + 1 + i];
    }
    int i, j, k;
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d %d asf", n, m);
    initialize_graph(1000);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
    int clusters[100001] = {0};
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        int d = attached_nodes_count(i);
        if (d != -1)
        {
            clusters[++index] = d;
        }
    }
    merge_sort(clusters, 0, index);
    int target, count = 0, shots = 0;
    if ((8 * n) % 10 == 0)
    {
        target = 8 * n / 10;
    }
    else
    {
        target = 8 * n / 10;
        target++;
    }
    for (int i = index; i >= 0; i--)
    {
        count += clusters[i];
        shots++;
        if (count >= target)
        {
            break;
        }
    }
    printf("%d", shots);
}