//插入排序
void InsertSort(int *a, int n)
{
  int i = 0;
  for (i = 0; i < n - 1; i++)
  {
    int end = i;          //记录有序序列的最后一个元素的下标
    int tmp = a[end + 1]; //待插入的元素
    while (end >= 0)
    {
      if (tmp < a[end]) //还需继续比较
      {
        a[end + 1] = a[end];
        end--;
      }
      else //找到应插入的位置
      {
        break;
      }
    }
    a[end + 1] = tmp;
    //代码执行到此位置有两种情况:
    //1.待插入元素找到应插入位置（break跳出循环到此）。
    //2.待插入元素比当前有序序列中的所有元素都小（while循环结束后到此）。
  }
}
