#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n; scanf("%d", &n);
    char command[6];
    int operand;

    int totalCommands = n, flag = 0;
    int *exp = (int *)calloc(n, sizeof(int));
    int *loop_itrs = (int *)calloc(n, sizeof(int));
    while(n--){
        scanf("%s", command);
        if(strcmp(command, "FD") == 0 && flag == 0){
            scanf("%d", &operand);
            exp[flag] += operand;
        }
        else if(strcmp(command, "LOOP") == 0){
            flag++;
            scanf("%d", &loop_itrs[flag]);
        }
        else if(strcmp(command, "FD") == 0 && flag){
            int loop_op;
            scanf("%d", &loop_op);
            exp[flag] += loop_op;
        }
        else if(strcmp(command, "END") == 0){
            exp[flag - 1] += exp[flag] * loop_itrs[flag];
            flag--;

            if(flag == 0){
                for(int i = 1; i < totalCommands; ++i){
                    exp[i] = 0;
                }
            }
        }
    }

    printf("%d", exp[0]);
}