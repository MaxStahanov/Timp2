#pragma once
#include <string>

class ReplaceException:std::exception // класс-исключение
{
 public:
 const char* what() const noexcept
 {
   return "Replace cipher error";
 }
};


class Replace
{
private:
  std::string values;
  int step;
  std::string dict;
  std::string abc = "abcdefghijklmnopqrstuvwxyz";


public:
  Replace(  std::string in, std::string dict);
  std::string encode();
  std::string decode();
};
