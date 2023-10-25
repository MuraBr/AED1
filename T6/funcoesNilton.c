void esvazia() {
    long long int var_10 = 0;
    long long int var_8 = *(long long int*)0x0;
    while (var_8 != 0) {
        var_10 = var_8;
        var_8 = *(long long int*)(var_8 + 0x8);
        free((void*)var_10);
    }
    *(long long int*)0x0 = 0;
}

int inicializa() {
    return 0;
}

void insere(int value) {
    int* rbp = (int*)malloc(sizeof(int));
    *rbp = value;
    rbp->next = NULL;
    if (head == NULL) {
        head = rbp;
    } else {
        int* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = rbp;
    }
}

//Essa função ta pela metade
void insereOrdem(int num) {
    int *ptr = NULL;
    int *temp = NULL;
    ptr = (int*)malloc(sizeof(int));
    *ptr = num;
    if (head == NULL || num < *head) {
        *ptr->next = head;
        head = ptr;
    } else {
        temp = head;
        while (temp->next != NULL && num > *(temp->next)) {
            temp = temp->next;
        }
        *ptr->next = temp->next;
        temp->next = ptr;
    }
}

void imprime() {
    printf("Hello, World!\n");
    long long int *ptr = 0;
    while (*ptr != 0) {
        int val = *ptr;
        printf("%d\n", val);
        ptr = *(ptr + 2);
    }
    printf("Goodbye!\n");
}

#include <stdbool.h>

bool vazia(int arg) {
    bool result;
    if (arg == 0) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

int busca(int edi) {
    int rbp = edi;
    long rax = 0;
    long rax_temp;
    while (1) {
        rax_temp = rax;
        if (rax_temp == rbp) {
            return 1;
        }
        rax = *(long *)rax_temp;
        if (rax == 0) {
            return 0;
        }
    }
}

void retira(int edi) {
    int ebp = edi;
    long long rax = 0;
    long long rax_2 = 0;
    while (rax != 0) {
        rax_2 = rax;
        rax = *(long long *)rax;
    }
    if (rax_2 != 0 && *(int *)rax_2 == ebp) {
        *(long long *)rax_2 = *(long long *)(rax_2 + 8);
    }
}
