#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
typedef struct stack
{
  int flag;
  int *data;

} MinStack;

/** initialize your data structure here. */

MinStack *minStackCreate()
{
  MinStack *obj = (MinStack*)malloc(sizeof(MinStack));
  if(obj==NULL){return NULL;}
  obj->flag=0;
  obj->data=(int*)malloc(1600*sizeof(int));
  return obj;
}

void minStackPush(MinStack *obj, int val)
{
  
  if(obj==NULL){return NULL;}
  obj->data[obj->flag++]=val;

}

void minStackPop(MinStack *obj)
{
  if(obj==NULL){return NULL;}
  if(obj->flag==0){return NULL;}
  obj->data[--obj->flag]=NULL;
}

int minStackTop(MinStack *obj)
{
  if(obj==NULL){return NULL;}
  if(obj->flag==0||obj->data[obj->flag-1]==NULL){return NULL;}
  return obj->data[obj->flag-1];
}

int minStackGetMin(MinStack *obj)
{
  if(obj==NULL){return NULL;}
  if(obj->flag==0){return NULL;}
  int temp=obj->data[obj->flag-1];
  for(int i=0;i<obj->flag;i++)
  {
    
    if(temp>obj->data[i]){temp=obj->data[i];}
  }
  return temp;
}

void minStackFree(MinStack *obj)
{
  free(obj->data);
  obj->data=NULL;
  free(obj);
  obj=NULL;
}

int main()
{
  MinStack* minstack = minStackCreate();
  minStackPush(minstack,2);
  minStackPush(minstack,0);
  minStackPush(minstack,3);
  minStackPush(minstack,0);
  minStackGetMin(minstack);
  minStackPop(minstack);
  minStackGetMin(minstack);
  minStackPop(minstack);
  minStackGetMin(minstack);
  minStackPop(minstack);
  minStackGetMin(minstack);
}