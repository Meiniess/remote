#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(char *s)
{
  int i, j = 1, count = 0;
  int n = strlen(s);
  char temp[10001] = {0};
  temp[0] = s[0];
  count = 1;
  for (i = 1; i < n; i++)
  {
    while ((temp[j - 1] == '(' && s[i] == ')') || (temp[j - 1] == '[' && s[i] == ']') || (temp[j - 1] == '{' && s[i] == '}'))
    {
      temp[j - 1] = 0;
      j--;
      i++;
      count--;
      if (j - 1 < 0)
      {
        break;
      }
    }
    if (i >= n)
    {
      break;
    }
    temp[j++] = s[i];
    i++;
    count++;
  }
  if (count == 0)
  {
    return true;
  }
  return false;
}

int main()
{
  char s[] = "()[]{}";
  isValid(s);
}