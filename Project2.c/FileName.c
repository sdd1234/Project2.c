#include <stdlib.h>
#include <stdio.h>
#define MAX_LIST_SIZE 100

typedef int element;

typedef struct {
    element array[MAX_LIST_SIZE];
    int size;
} ArrayListType;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
}

void init(ArrayListType* L) {
    L->size = 0;
}

int is_full(ArrayListType* L) {
    return (L->size == MAX_LIST_SIZE);
}

int insert(ArrayListType* L, int pos, element item) {
    int count = 0;
    if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
        for (int i = (L->size - 1); i >= pos; i = i - 1) {
            L->array[i + 1] = L->array[i];
            count++;
        }
        L->array[pos] = item;
        L->size++;
    }
    return count;
}

void insert_last(ArrayListType* L, element item) {
    if (L->size == MAX_LIST_SIZE) {
        error("����Ʈ �����÷ο�");
    }
    L->array[L->size++] = item;
}

void insert_first(ArrayListType* L, element item) {
    insert(L, 0, item);
}

void clear(ArrayListType* L) {
    init(L);
}

element get_entry(ArrayListType* L, int pos) {
    if (pos >= 0 && pos < L->size)
        return L->array[pos];
    else
        error("��ġ ����");
}

int get_length(ArrayListType* L) {
    return L->size;
}

int is_empty(ArrayListType* L) {
    return (L->size == 0);
}

void print_list(ArrayListType* L) {
    for (int i = 0; i < L->size; i++)
        printf("%d -> ", L->array[i]);
    printf("NULL\n");
}

int delete_item(ArrayListType* L, int pos) {
    int count = 0;
    element item;

    if (pos < 0 || pos >= L->size)
        error("��ġ ����");
    else {
        item = L->array[pos];
        for (int i = pos; i < (L->size - 1); i++) {
            L->array[i] = L->array[i + 1];
            count++;
        }
        L->size = L->size - 1;
    }

    return count;
}

int main(void) {
    int choice;
    int num;
    int pos;
    int count;
    ArrayListType list;
    init(&list);

    while (1) {
        printf("\n�޴� : \n");
        printf("1. ����Ʈ�� �߰� \n");
        printf("2. ����Ʈ���� ���� \n");
        printf("3. ����Ʈ ��� \n");
        printf("0. ���α׷� ���� \n");
        printf("���� : ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            if (is_full(&list)) {
                printf("����Ʈ�� �� á���ϴ�. \n");
            }
            else {
                printf("���ڸ� �Է��ϼ���: ");
                scanf_s("%d", &num);
                printf("�߰��� ��ġ�� �Է��ϼ���: ");
                scanf_s("%d", &pos);
                count = insert(&list, pos, num);
                printf("���� �Ϸ�, ������ �̵� Ƚ��: %d\n", count);
            }
            break;
        case 2:
            if (is_empty(&list)) {
                printf("����Ʈ�� ����ֽ��ϴ�. \n");
            }
            else {
                printf("������ ��ġ�� �Է��ϼ���:");
                scanf_s("%d", &pos);
                count = delete_item(&list, pos);
                printf("���� �Ϸ�, ������ �̵� Ƚ��: %d\n", count);
            }
            break;
        case 3:
            print_list(&list);
            break;
        case 0:
            printf("���α׷� ����\n");
            return 0;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���\n");
        }
    }
}
