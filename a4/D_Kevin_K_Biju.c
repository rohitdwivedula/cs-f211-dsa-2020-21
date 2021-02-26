#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

struct edge
{
    int32_t link;
    float probablity;
};

struct vector
{
    struct edge* arrayptr;
    int32_t element_count;
    bool processed;
    float last_page_probablity;
    float getting_here_probablity;    
};

struct probablity_sort
{
    int32_t original_index;
    float probablity;
};

int sort_probablities(const void* a, const void* b)
{
    if((*(struct probablity_sort*)a).probablity == (*(struct probablity_sort*)b).probablity)
    {
        return (*(struct probablity_sort*)a).original_index
         > (*(struct probablity_sort*)b).original_index;
    }
    return (*(struct probablity_sort*)a).probablity < (*(struct probablity_sort*)b).probablity;
}

struct vector vector_create()
{
    struct vector temp =  { .arrayptr = NULL, .element_count = 0, .processed = false,
    .last_page_probablity = 1, .getting_here_probablity = 0 };
    return temp;
}

void vector_add(struct vector* vector, int32_t link, float probablity)
{
    vector->element_count = vector->element_count + 1;   
    vector->arrayptr = realloc(vector->arrayptr, sizeof(struct edge) * vector->element_count);
    struct edge temp = { .link = link, .probablity = probablity };
    (vector->arrayptr)[vector->element_count - 1] = temp;    
}

void processor(struct vector* graph, int32_t index, float probablity_so_far)
{
    graph[index].getting_here_probablity = graph[index].getting_here_probablity + probablity_so_far;
    for(int32_t i = 0; i < graph[index].element_count; i++)
    {
        processor(graph, (graph[index].arrayptr)[i].link, 
        probablity_so_far * ((graph[index].arrayptr)[i].probablity));
    }
    graph[index].processed = true;
    return;
}

int main(void)
{
    int32_t nodes;
    int32_t edges;
    int32_t initial_node;
    scanf("%i %i %i", &nodes, &edges, &initial_node);

    int temp1;
    int temp2;
    float temp3;
    struct vector graph[nodes];
    struct probablity_sort output[nodes];
    for(int32_t i = 0; i < nodes; i++)
    {
        graph[i] = vector_create();
    }

    for(int32_t i = 0; i < edges; i++)
    {
        scanf("%i %i %f", &temp1, &temp2, &temp3);
        vector_add(&graph[temp1].arrayptr, temp2, temp3);
        graph[temp1].last_page_probablity = graph[temp1].last_page_probablity - temp3;
    }
    processor(graph, initial_node, 1);
    for(int32_t i = 0; i < nodes; i++)
    {
        output[i].original_index = i;
        output[i].probablity = (graph[i].getting_here_probablity) * (graph[i].last_page_probablity);
    }
    qsort(output, nodes, sizeof(struct probablity_sort), sort_probablities);

    for(int32_t i = 0; i < nodes; i++)
    {
        printf("%i ", output[i].original_index); 
    }
    fflush(stdout);
    return 0;
}