#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct std
{
  int val;
  struct std *next;

} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList *myLinkedListCreate()
{
  MyLinkedList *L = (MyLinkedList *)malloc(sizeof(MyLinkedList));
  L->val = 0;
  L->next = NULL;
  return L;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList *obj, int index)
{
  if (index < 0 || obj->next == NULL)
  {
    return -1;
  }

  int now = 0;
  MyLinkedList *listNow = obj->next;
  while (now < index)
  {
    if (listNow == NULL)
    {
      return -1;
    }

    listNow = listNow->next;
    now++;
  }

  if (listNow != NULL)
  {
    return listNow->val;
  }

  return -1;
}
/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
  MyLinkedList *L = myLinkedListCreate();
  L->next = obj;
  L->val = val;
  if (obj->next == NULL)
  {
    obj->next = L;
    return;
  }
  else
  {
    L->next = obj->next;
    obj->next = L;
  }
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
  MyLinkedList *L = myLinkedListCreate();
  L->next = NULL;
  L->val = val;
  while (obj->next != NULL)
  {
    obj = obj->next;
  }

  obj->next = L;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
  if (index <= 0)
  {
    myLinkedListAddAtHead(obj, val);
  }
  int now = 0;
  MyLinkedList *nowList = obj->next;
  while (nowList->next != NULL)
  {
    if (now == index - 1)
    {
      break;
    }
    nowList = nowList->next;
    now++;
  }
  if (index - 1 != now)
  {
    return;
  }
  MyLinkedList *L = (MyLinkedList *)malloc(sizeof(MyLinkedList));
  L->val = val;
  L->next = nowList->next;
  nowList->next = L;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
  if (index < 0 || obj->next == NULL)
  {
    return;
  }
  if (index == 0)
  {
    obj->next = obj->next->next;
    return;
  }
  MyLinkedList *nowList = obj->next;
  int now = 0;
  while (nowList->next != NULL)
  {
    if (now == index - 1)
    {
      break;
    }
    nowList = nowList->next;
    now++;
  }

  if (now == index - 1 && nowList->next != NULL)
  {
    nowList->next = nowList->next->next;
  }
}

void myNodeFree(MyLinkedList *Node)
{
  if (Node->next != NULL)
  {
    myNodeFree(Node->next);
    Node->next = NULL;
  }
  free(Node);
}

void myLinkedListFree(MyLinkedList *obj)
{
  myNodeFree(obj);
}
