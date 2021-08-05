//堆的向下调整算法
void AdjustDown(int *a, int n, int root)
{
  int parent = root;
  int child = 2 * parent + 1; //假设左孩子较大
  while (child < n)
  {
    if (child + 1 < n && a[child + 1] > a[child]) //右孩子存在，并且比左孩子大
    {
      child++; //左右孩子的较大值
    }
    if (a[child] > a[parent])
    {
      Swap(&a[child], &a[parent]);
      parent = child;
      child = 2 * parent + 1;
    }
    else //已成堆
    {
      break;
    }
  }
}
