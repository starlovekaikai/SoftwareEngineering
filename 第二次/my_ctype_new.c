#include <stdio.h>
#include "my_ctype_new.h"
int IsNumber(char c)
{
  char temp = c;
  return temp >= 48 && temp <= 57;
}

int IsAlpha(char c)
{
  char temp = c;
  return (temp >= 65 && temp <= 90) || (temp >= 97 && temp <= 122);
}

int IsAlandNum(char c)
{
  char temp = c;
  return IsNumber(temp) || IsAlpha(temp);
}

int IsInvisible(char c)
{
  char temp = c;
  return temp <= 20 || temp == 127;
}

int IsTable(char c)
{
  char temp = c;
  return temp == 9 || temp == 11;
}

int IsSpace(char c)
{
  char temp = c;
  return temp == 32;
}

int IsUpper(char c)
{
  char temp = c;
  return temp >= 90 && temp <= 122;
}

int IsLower(char c)
{
  char temp = c;
  return temp >= 65 && temp <= 90;
}
char Upper2Lower(char c)
{
  if (IsAlpha)
  {
    return c - 32;
  }
  else
  {
    return '\0';
  }
}
char Upper2Lower(char c)
{
  if (IsAlpha)
  {
    return c + 32;
  }
  else
  {
    return '\0';
  }
}