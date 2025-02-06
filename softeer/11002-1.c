#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(void){
    int N, M;
    int bitmasks[30000];
    char strings[30];
    int out = 0;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++){
        int bits = 0;
        scanf("%s", strings);
        for (int j = 0; j < M; j++) {
            if (strings[j] == '1') {
                bits |= (1 << (M - j - 1));
            }
        }
        bitmasks[i] = bits;
    }
    int *hash_table = (int *)calloc((1 << M), sizeof(int));

    for (int n = 0; n < N; n++) {

        int neighbors[500];
        int count = 0;
        neighbors[count++] = bitmasks[n];
        for (int i = 0; i < M; i++) {
            neighbors[count++] = bitmasks[n] ^ (1 << (M - i - 1));
        }

        for (int i = 0; i < M; i++) {
            for (int j = i + 1; j < M; j++) {
                neighbors[count++] = bitmasks[n] ^ (1 << (M - i - 1)) ^ (1 << (M - j - 1));
            }
        }
        for (int i = 0; i < count; i++)  {
                if (hash_table[neighbors[i]]) {
                    out += hash_table[neighbors[i]];
                }
        }
    
        hash_table[bitmasks[n]]++;
    }
    
     printf("%d", out);
    return 0;
}


