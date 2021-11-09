#include <iostream>
#include <string>
#include <string.h>

int size(std::string string)
{
  return string.length();
}
int size(const char* string)
{
  return strlen(string);
}
template <typename T, typename... Ts>
int size(T string, Ts... strings)
{
  return size(string) + size(strings...);
}

void comb(std::string& str1, std::string str2)
{
  str1 = str1 + str2;
}
template <typename... Ts>
void comb(std::string& str1, std::string str2, Ts... strings)
{
  str1 = str1 + str2;
  comb(str1, strings...);
}
template <typename... Ts>
std::string ev(Ts... strings)
{
  int a = size(strings...);
  std::string str="";
  str.reserve(a);
  comb(str, strings...);
  return str;
}

int main()
{
  std::string a = " abdc";
  std::string b = "afdsd";
  std:: cout << ev("abc", "Abd");
}