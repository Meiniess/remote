#include <iostream>
using namespace std;

inline int Translate(char str)
{
  return (str - 48);
}

int _tmain(int argc, _TCHAR *argv[])
{
  char NumStr1[3] = {'2', '3', '4'};
  char NumStr2[3] = {'4', '5', '6'};
  int temp[3][6] = {0};
  signed int flag = -1;

  int Temp_x = 0;
  int Temp_y;

  int _index, index;

  for (_index = 2; _index >= 0; --_index) //这里的两重循环是分别赋值到二维数组里面
  {
    Temp_y = 5 - Temp_x;

    for (index = 2; index >= 0; --index, --Temp_y)
    {
      temp[Temp_x][Temp_y] = Translate(NumStr2[_index]) * Translate(NumStr1[index]);

      if (flag != -1)
      {
        temp[Temp_x][Temp_y] += flag;
        flag = -1;
      }

      if (temp[Temp_x][Temp_y] >= 10)
      {
        flag = temp[Temp_x][Temp_y] / 10;
        temp[Temp_x][Temp_y] %= 10;
      }
    }

    if (flag != -1)
    {
      temp[Temp_x][Temp_y] += flag;
      flag = -1;
    }
    ++Temp_x;
  }

  int temp_sum[6] = {0};
  flag = -1;

  for (int j = 5; j >= 0; --j) //接下来这个循环是加每一列的数组到最后的结果数组里面
  {
    for (int i = 2; i >= 0; --i)
      temp_sum[j] += temp[i][j];
    if (flag != -1)
    {
      temp_sum[j] += flag;
      flag = -1;
    }

    if (temp_sum[j] >= 10)
    {
      flag = temp_sum[j] / 10;
      temp_sum[j] %= 10;
    }
  }

  flag = -1;

  for (int i = 0; i != 6; ++i) //这里是输出结果

    cout << temp_sum[i];
  cout << endl;
  system("pause");
  return 0;
}