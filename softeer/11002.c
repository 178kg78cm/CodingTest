#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 30000
#define MAX_M 30
#define MAX_CPTI 1048576

typedef struct node {
    int key;
    int value;
    struct node* next;
} node;

typedef struct {
    node* head;
    int count;
} bucket;

typedef struct {
    bucket table[MAX_CPTI];
} hashTable;

int hashFunc(int key) {
    return key % MAX_CPTI;
}

// key에 따른 value 값 반환
int getVal(hashTable* hashTable, int key) {
    int index = hashFunc(key);
    node* node = hashTable->table[index].head;

    while (node != NULL) {
        if (node->key == key) return node->value;
        node = node->next;
    }
    
    return 0;
}

// 노드 추가 (기존 값이 있다면 업데이트)
void createNode(hashTable* hashTable, int key, int value) {
    int index = hashFunc(key);
    node* node = hashTable->table[index].head;

    while (node != NULL) {
        if (node->key == key) {
            node->value = value;
            return;
        }
        node = node->next;
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable->table[index].head;
    hashTable->table[index].head = newNode;
    hashTable->table[index].count++;
}

// 체크 여부 확인
bool isChecked(hashTable* checkedTable, int key) {
    return getVal(checkedTable, key) > 0;
}

// 체크 마킹
void markChecked(hashTable* checkedTable, int key) {
    createNode(checkedTable, key, 1);
}

int main() {
    int N = 0, M = 0;
    int cpti[MAX_N] = {0};
    hashTable cptiTable;
    hashTable checkedCpti;
    int pairCnt = 0;

    // 해시 테이블 초기화
    for (int i = 0; i < MAX_CPTI; i++) {
        cptiTable.table[i].head = NULL;
        cptiTable.table[i].count = 0;
        checkedCpti.table[i].head = NULL;
        checkedCpti.table[i].count = 0;
    }

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        char str[MAX_M + 1];
        int strToNum = 0;

        scanf("%s", str);
        for (int j = 0; j < M; j++) {
            if (str[j] == '1') strToNum |= (1 << (M - j - 1));
        }
        cpti[i] = strToNum;

        createNode(&cptiTable, strToNum, getVal(&cptiTable, strToNum) + 1);
    }

    for (int i = 0; i < MAX_CPTI; i++) {
        node* node = cptiTable.table[i].head;
        while (node != NULL) {
            int orgCpti = node->key;
            int orgCptiCnt = node->value;
            int diffCpti[MAX_N];
            int diffCptiCnt = 0;

            diffCpti[diffCptiCnt++] = orgCpti;

            for (int j = 0; j < M; j++) {
                int oneDiffCpti = orgCpti ^ (1 << j);
                if (getVal(&cptiTable, oneDiffCpti) > 0 && !isChecked(&checkedCpti, oneDiffCpti)) {
                    diffCpti[diffCptiCnt++] = oneDiffCpti;
                }
            }

            for (int j = 0; j < M; j++) {
                for (int k = j + 1; k < M; k++) {
                    int twoDiffCpti = orgCpti ^ (1 << j) ^ (1 << k);
                    if (getVal(&cptiTable, twoDiffCpti) > 0 && !isChecked(&checkedCpti, twoDiffCpti)) {
                        diffCpti[diffCptiCnt++] = twoDiffCpti;
                    }
                }
            }

            for (int j = 0; j < diffCptiCnt; j++) {
                if (diffCpti[j] == orgCpti) {
                    if (orgCptiCnt > 1) {
                        pairCnt += (orgCptiCnt * (orgCptiCnt - 1)) / 2;
                    }
                } else {
                    pairCnt += getVal(&cptiTable, diffCpti[j]) * orgCptiCnt;
                }
            }

            markChecked(&checkedCpti, orgCpti);
            node = node->next;
        }
    }

    printf("%d\n", pairCnt);
    return 0;
}
