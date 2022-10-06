#include <stdio.h>
bool IsNumber(char c);
bool IsAlpha(char c);
bool IsAlandNum(char c);
bool IsInvisible(char c);
bool IsTable(char c);
bool IsSpace(char c);
bool IsUpper(char c);
bool IsLower(char c);

bool IsNumber(char c)
{
  char temp = c;
  return temp >= 48 && temp <= 57;
}

bool IsAlpha(char c)
{
  char temp = c;
  return (temp >= 65 && temp <= 90) || (temp >= 97 && temp <= 122);
}

bool IsAlandNum(char c)
{
  char temp = c;
  return IsNumber(temp) || IsAlpha(temp);
}

bool IsInvisible(char c)
{
  char temp = c;
  return temp <= 20 || temp == 127;
}

bool IsTable(char c)
{
  char temp = c;
  return temp == 9 || temp == 11;
}

bool IsSpace(char c)
{
  char temp = c;
  return temp == 32;
}

bool IsUpper(char c)
{
  char temp = c;
  return temp >= 90 && temp <= 122;
}

bool IsLower(char c)
{
  char temp = c;
  return temp >= 65 && temp <= 90;
}