#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
struct DoubleLinkedList
{
	int data;
	struct DoubleLinkedList* next, *prev;
};
DoubleLinkedList* head;

void createList(DoubleLinkedList* list)
{
    int n = rand() % 9 + 2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            list->next = new DoubleLinkedList();
            list->next->prev = list;
            list = list->next;
            list->next = NULL;
        }
        else
        { // додавання першого елемента списку
            list = new DoubleLinkedList();
            head = list;
            list->next = NULL;
            list->prev = NULL;
        }
        list->data = (int)(rand() % 100 + 1);
    }
}

void printList(DoubleLinkedList* list)
{
    do
    {
        cout << list->data << " ";
        list = list->next;
    } while (list != NULL);
    cout << endl;
}

void deleteElem(DoubleLinkedList* list, int elem) 
{
    DoubleLinkedList* list1 = NULL;
    int k = 0;
    bool flag = false;
    do
    {
        flag = false;
        if (list == head && list->data == elem)
        {
            list1 = list;
            head = list->next;
            list = list->next;
            list->prev = NULL;
            delete list1;
            k++;
            flag = true;
        }
        else if ((list->next->next == NULL) && (list->next->data == elem)) 
        {
            list1 = list->next;
            list->next = NULL;
            delete list1;
            flag = true;
            k++;
        }
        else if (list->next->data == elem)
        {
            list1 = list->next;
            list->next = list1->next;
            list1->next->prev = list;
            list = list->next;
            delete list1;
            k++;
            flag = true;
        }
        if (flag == false)
        {
            list = list->next;
        }
    } while (list->next != NULL);
    if (k == 0)
    {
        cout << "Даного елемента немає в списку." << endl;
    }
    else
    {
        cout << "Список після видалення даного елемента: " << endl;
        printList(head);
    }
}

struct Stack 
{
    int data;
    Stack* next;
};
Stack* top;

bool isEmpty(Stack* stack) 
{
    return !stack;
}


void push(Stack** stack, int data) 
{
    Stack* temp = new Stack();
    temp->data = data;
    temp->next = *stack;
    top = temp;
    *stack = temp;
}

void createStack(Stack** stack, int size)
{
    int data;
    for (int i = 0; i < size; i++) 
    {
        data = rand() % 20 - 10;
        push(stack, data);
    }
}

int pop(Stack** stack)
{
    Stack* temp = (*stack)->next;
    int data = (*stack)->data;
    delete* stack;
    *stack = temp;
    return data;
}

int peek(Stack* stack) 
{
    if (!isEmpty(stack)) return stack->data;
    else return 0;
}

void printStack(Stack* stack) 
{
    while (!isEmpty(stack)) 
    {
        cout << peek(stack) << " ";
        stack = stack->next;
    }
    cout << endl;
}

Stack* rewrite(Stack* stack)
{
    Stack* tmp = NULL;
    int data;
    while (!isEmpty(stack))
    {
        data = pop(&stack);
        if (data >= 0) push(&tmp, data);
    }
    return tmp;
}

int main()
{
    system("chcp 1251>nul");
	srand(time(NULL));
	DoubleLinkedList list;
    createList(&list);
    cout << "Двозв'язний список: " << endl;
    printList(head);
    int elem;
    cout << "Введіть елемент, який потрібно видалити: ";
    cin >> elem;
    deleteElem(head, elem);
    Stack* stack = NULL;
    cout << "Введіть кількість елементів стеку: ";
    int num;
    cin >> num;
    createStack(&stack, num);
    cout << "Стек: ";
    printStack(top);
    Stack* stack2 = NULL;
    stack2 = rewrite(top);
    cout << "Стек, в який переписали всі додатні числа: ";
    printStack(stack2);
    return 0;
}