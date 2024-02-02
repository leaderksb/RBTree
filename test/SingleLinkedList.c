#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct node
{
    int value;  // 값을 저장하는 변수
    struct node* next;  // 다음 노드의 주소를 저장 
} node;

// # define NULL 0
// NULL : Pointer가 가리키는 대상이 없는 경우
node* head = NULL;  // 첫 Node의 주소를 저장하는 변수(Pointer 변수 : 8Byte)

void insertFrontNode(int data);
void displayNode();

int main()
{
	int choice;
    int data;
	while (1)
	{
		system("cls");
		printf("\n\n  *** 단일 연결 리스트(Singly Linked List) ***\n\n");
		printf("=====================================\n");
		printf(" 1. 맨 앞 삽입\n");
		printf(" 2. 맨 뒤 삽입\n");
		printf(" 3. 앞에서부터 N번째 삽입\n");
		printf(" 4. 오름차순 정렬 삽입\n");
		printf("=====================================\n");
		printf(" 5. 맨 앞 삭제\n");
		printf(" 6. 맨 뒤 삭제\n");
		printf(" 7. 전체 노드 삭제\n");
		printf(" 8. 특정 값 삭제\n");
		printf(" 9. 앞에서부터 N번째 삭제\n");
		printf("=====================================\n");
		printf("10. 단일 연결 리스트 출력(노드 순회)\n");
		printf("11. 노드의 개수 구하기\n");
		printf("12. 노드 검색\n");
		printf(" 0. 프로그램 종료\n");
		printf("=====================================\n");
		printf("\n메뉴 선택 : ");
		scanf("%d", &choice);
		while (getchar() != '\n');

		switch (choice)
		{
		case 1:
            printf("\n\n정수 입력 : ");
            scanf("%d", &data);

            insertFrontNode(data);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			displayNode();
			break;
		case 11:
			break;
		case 12:
			break;
		case 0:
			exit(0); //프로그램 강제 종료
		}//end switch

		//switch문을 빠져 나오면 일시 대기 시킨다.
		printf("\n\n\t\t");
		system("pause"); //일시 대기

	}//end while
	return 0;
}

void insertFrontNode(int data)
{
    // 생성된 Node의 주소를 저장하는 변수
    node* newNode;  // Pointer 변수 할당 Size : 8Byte
    newNode = (node*)malloc(sizeof(node));  // Node 생성
    newNode->value = data;
    newNode->next = NULL;

    // 생성된 Node가 없는 First Node인 경우
    if(head == NULL)
    {
        head = newNode;
        // 호출한 곳으로 돌아감
        return;
    }

    newNode->next = head;
    head = newNode;
}

void displayNode()
{
    // 방문한 Node의 주소를 저장하는 변수
    node* curNode;
    if(head == NULL)
        return;

    // 화면 지우기
    system("cls");
    printf("\n\nSimply Linkedlist : ");

    // Firsh Node를 방문 Node로 설정
    curNode = head;

    // 다음 Node가 있다면
    // 마지막 NULL Node는 미포함
    while (curNode->next != NULL)
    {
        // 현재 방문한 Node의 값을 출력
        printf("%d => ", curNode->value);
        // 방문 Node를 다음 Node로 이동
        curNode = curNode->next;
    }

    // 마지막 Node 출력
    printf("%d\n", curNode->value);

}