#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *next;
} Node;


Node *head;

Node *make_node_instance(int data) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void add_after(Node *target, int data) {
    if (target == NULL)      // TODO 기준 노드가 NULL이면 함수를 종료. 실무에서 매우 중요!!!
        return;
    Node *p = make_node_instance(data);
    if (p == NULL)           // TODO 동적 메모리 할당이 실패했을 때 함수를 종료. 실무에서 매우 중요!!
        return;

    p->next = target->next;
    target->next = p;
}

void remove_after(Node *target) {

    if (target == NULL)       // TODO 기준 노드가 NULL이면 함수를 종료. 실무에서 매우 중요!!!
        return;

    Node *p = target->next;
    if (p == NULL)            // TODO target 노드가 마지막 노드라 next가 없는 경우도 함수 종료. 실무에서 매우 중요!!!
        return;

    target->next = p->next;
    free(p);
}

Node *find_node(Node *p, int data) {

    while (p != NULL)
    {
        if (p->data == data)
            return p;
        p = p->next;
    }
    return NULL;
}


Node *init_list(void) {
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

void remove_list(Node *head) {
    while (head != NULL)
    {
        Node *tmp = head->next;
        free(head);
        head = tmp;
    }
}


int main() {

    // 1. 연결 리스트 구현하기
    // Node *head = (Node *)malloc(sizeof(Node));  // head노드에는 데이터를 저장하지 않음
    // head->data = NULL; -> // TODO NULL은 처음 선언 때가 아닌 경우 할당 불가 
    // head->next = NULL;

    Node *head = init_list();

    // Node *node1 = make_node_instance(10);
    // head->next = node1;

    // Node *node2 = make_node_instance(20);
    // node1->next = node2;

    // free(head);
    // free(node1);
    // free(node2);


    // 2. 노드 추가 함수 만들기
    add_after(head, 10);
    add_after(head, 20);
    add_after(head, 30);
    add_after(head, 40);


    // 3. 노드 삭제 함수 만들기
    remove_after(head);
    remove_after(head);


    printf("find! : %d\n", find_node(head, 10)->data);
    printf("find! : %d\n", find_node(head, 20)->data);


    Node *cur = head->next; // -> 노드 순회용 포인터

    while (cur != NULL)
    {
        printf("%d\n", cur->data);

        Node *tmp = cur;
        cur = cur->next;
        free(tmp);

    // 아래와 같은 형태로도 제거 가능 (next 포인터 주소를 임시 변수에 저장해놓기)
/*         Node *next = cur->next;
        free(cur);
        cur = next; */
    }
    
    free(head);


    return 0;
}