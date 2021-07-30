#include <stddef.h>
typedef int HPDataType;
typedef struct Heap
{
  HPDataType *_a;
  int _size;
  int _capacity;
} Heap;

void swap(int *a, int *b);
void AdjustDown(int *a, int parent, int n);
void AdjustUp(int *a, int child, int n);

// 堆的构建
void HeapCreate(Heap *hp, HPDataType *a, int n);
// 堆的销毁
void HeapDestory(Heap *hp);
// 堆的插入
void HeapPush(Heap *hp, HPDataType x);
// 堆的删除
void HeapPop(Heap *hp);
// 取堆顶的数据
HPDataType HeapTop(Heap *hp);
// 堆的数据个数
int HeapSize(Heap *hp);
// 堆的判空
int HeapEmpty(Heap *hp);

// 对数组进行堆排序
void HeapSort(int *a, int n);
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void AdjustUp(int *a, int child, int n)
{
  int parent = (child - 1) / 2;
  while (child > 0)
  {
    if (a[child] > a[parent])
    {
      swap(&a[child], &a[parent]);
      child = parent;
      parent = (child - 1) / 2;
    }
    else
    {
      break;
    }
  }
}

void AdjustDown(int *a, int parent, int n)
{
  int child = parent * 2 + 1;
  while (child < n)
  {
    if (child + 1 < n && a[child] < a[child + 1])
    {
      ++child;
    }
    if (a[child] > a[parent])
    {
      swap(&a[child], &a[parent]);
      parent = child;
      child = (parent * 2) + 1;
    }
    else
    {
      break;
    }
  }
}
void HeapCreate(Heap *hp, HPDataType *a, int n)
{
  assert(hp);
  hp->_a = (HPDataType *)malloc(sizeof(HPDataType) * n);
  if (hp->_a == NULL)
  {
    printf("malloc fail");
    exit(-1);
  }
  for (int i = 0; i < n; ++i)
  {
    hp->_a[i] = a[i];
  }
  hp->_size = hp->_capacity = n;
  for (int i = (n - 2) / 2; i >= 0; --i)
  {
    AdjustDown(hp->_a, i, hp->_size);
  }
}

// 堆的销毁
void HeapDestory(Heap *hp)
{
  assert(hp);
  hp->_size = hp->_capacity = 0;
  free(hp);
}
// 堆的插入
void HeapPush(Heap *hp, HPDataType x)
{
  assert(hp);
  if (hp->_size == hp->_capacity)
  {
    HPDataType *tmp = (HPDataType *)realloc(hp->_a, sizeof(HPDataType) * 2 * hp->_capacity);
    if (tmp == NULL)
    {
      printf("realloc fail");
      exit(-1);
    }
    hp->_a = tmp;
    hp->_a[hp->_size] = x;
    ++hp->_size;
    hp->_capacity *= 2;
  }
  else
  {
    hp->_a[hp->_size] = x;
    ++hp->_size;
  }
  AdjustUp(hp->_a, hp->_size - 1, hp->_size);
}
// 堆的删除
void HeapPop(Heap *hp)
{
  assert(hp);
  assert(hp->_size > 0);
  swap(&hp->_a[hp->_size - 1], &hp->_a[0]);
  --hp->_size;
  AdjustDown(hp->_a, 0, hp->_size);
}
// 取堆顶的数据
HPDataType HeapTop(Heap *hp)
{
  assert(hp);
  assert(hp->_size > 0);
  return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap *hp)
{
  assert(hp);
  return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap *hp)
{
  assert(hp);
  return hp->_size == 0 ? 1 : 0;


}

// 对数组进行堆排序
void HeapSort(int *a, int n)
{
  assert(a);
  for (int i = (n - 2) / 2; i >= 0; --i)
  {
    AdjustDown(a, i, n);
  }
  int end = n - 1;
  while (end > 0)
  {
    swap(&a[0], &a[end]);
    AdjustDown(a, 0, end);
    --end;
  }
}
