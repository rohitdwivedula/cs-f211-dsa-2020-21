#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

// implementation of vector in C, using realloc()
struct vector
{
    int* arrayptr;
    int element_count;
};

struct vector vector_create()
{
    struct vector temp =  { .arrayptr = NULL, .element_count = 0 };
    return temp;
}

void vector_add(struct vector* vector, int element)
{
    vector->element_count = vector->element_count + 1;   
    vector->arrayptr = realloc(vector->arrayptr, sizeof(int) * vector->element_count);
    (vector->arrayptr)[vector->element_count - 1] = element;    
}

void vector_delete(struct vector* vector, int index)
{
    assert(index < vector->element_count);
    for(int i = index + 1; i < vector->element_count; i++)
    {
        (vector->arrayptr)[i - 1] = (vector->arrayptr)[i];
    }
    vector->element_count = vector->element_count - 1;
    vector->arrayptr = realloc(vector->arrayptr, sizeof(int) * vector->element_count);    
}

struct string_node
{
    char* string;
    bool end_node;
    struct vector connections;
};

// find the difference between two strings, ASSUMING THEY ARE OF EQUAL LENGTH
int char_diff_count(char* input1, char* input2)
{
    int different_characters = 0;
    int strings_size = strlen(input1);

    for(int i = 0; i < strings_size; i++)
    {
        if(input1[i] != input2[i])
        {
            different_characters = different_characters + 1;
        }
    }

    return different_characters;
}

// when a new string is taken as input, this function compares it to the initial_string we start from
// as well as all other strings taken as input. If two strings differ in only one character then we
// can move from string A to string B and an edge is added to their corresponding connections vectors.
// NOTE: strings that are not of same length as initial_string are discarded since they are useless 
// in our calculations.
struct string_node* entry_add_and_update(char* input, char* initial_string, 
    struct string_node* strings, int* current_position)
{
    if(strlen(input) != strlen(initial_string))
    {
        return strings;
    }
    strings = realloc(strings, sizeof(struct string_node) * (*current_position + 1));  

    struct string_node temp;
    temp.connections = vector_create();
    temp.string = malloc((strlen(input) + 1) * sizeof(char));
    strcpy(temp.string, input);
    temp.end_node = false;  
    if(char_diff_count(input, initial_string) == strlen(input))
    {
        temp.end_node = true;
    }

    for(int i = 0; i < *current_position; i++)
    {
        if(char_diff_count(strings[i].string, input) == 1)
        {
            vector_add(&strings[i].connections, *current_position);
            vector_add(&temp.connections, i);
        }
    }

    strings[*current_position] = temp;
    *current_position = *current_position + 1;
    return strings;
}

// finds shortest path between initial node and each "end node" using a traditional algorithm.
int processor(struct string_node* strings, int strings_size, int source_index, int destination_index, bool* processed)
{
    struct vector bfs_queue = vector_create();
    memset(processed, 0, sizeof(bool) * strings_size);
    vector_add(&bfs_queue, source_index);
    int hop_level = 0;
    int prev_level_size = 1;
    int next_level_size = 0;

    while((bfs_queue.arrayptr)[0] != destination_index)
    {
        for(int i = 0; i < strings[(bfs_queue.arrayptr)[0]].connections.element_count; i++)
        {
            if(processed[(strings[(bfs_queue.arrayptr)[0]].connections.arrayptr)[i]] == false)
            {
                vector_add(&bfs_queue, (strings[(bfs_queue.arrayptr)[0]].connections.arrayptr)[i]);
                next_level_size = next_level_size + 1;
            }
        }

        processed[(bfs_queue.arrayptr)[0]] = true;
        vector_delete(&bfs_queue, 0);
        prev_level_size = prev_level_size - 1;

        if(prev_level_size == 0)
        {
            prev_level_size = next_level_size;
            next_level_size = 0;
            hop_level = hop_level + 1;
        }

        if(bfs_queue.element_count == 0)
        {
            hop_level = INT32_MAX;
            break;
        }
    }

    return hop_level;
}

// We need to move from the initial_string given to a string that differs in all characters, so we mark
// such strings as "end nodes" (Refer to entry_add_and_update). We add an undirected edge between any two
// strings that only differ in one character. Then we simply find the shortest path in this "graph" between
// the initial_string and any end node.
int main(void)
{
    int dictionary_size;
    scanf("%i", &dictionary_size);

    char initial_string[13];
    char input[13];
    int current_position = 0;
    struct string_node* strings = NULL;
    scanf("%s", initial_string);
    strings = entry_add_and_update(initial_string, initial_string, strings, &current_position);

    for(int i = 0; i < dictionary_size; i++)
    {
        scanf("%s", input);
        strings = entry_add_and_update(input, initial_string, strings, &current_position);  
    }


    int min_distance = INT32_MAX;
    bool processed[dictionary_size];
    for(int i = 1; i < current_position; i++)
    {
        if(strings[i].end_node == true)
        {
            min_distance = (processor(strings, dictionary_size, 0, i, processed) > min_distance)
                ? min_distance : processor(strings, dictionary_size, 0, i, processed);
        }
    }


    if(min_distance == INT32_MAX)
    {
        printf("-1");
    }
    else
    {
        printf("%i", min_distance - 1);
    }
    fflush(stdout);
    return 0;
}