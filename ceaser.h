#pragma once
#include <string>

class CeaserException:std::exception // класс-исключение
{
 public:
 const char* what() const noexcept
 {
   return "Replace cipher error";
 }
};

class Ceaser
{
private:
  std::string values;
  int step;


public:
  Ceaser( int step,  std::string in);

  void encode();
  void decode();
  std::string ret();

};
