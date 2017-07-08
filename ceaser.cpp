#include "ceaser.h"
#include <iostream>
#include <string>
using namespace std;


Ceaser::Ceaser(int step,  std::string in)
{
  this->step = step;
  this->values = in;
  if (this->values.size() == 0)
    throw CeaserException();
  if(this->step == 0)
    throw CeaserException();
};

void Ceaser::encode()
{
  for (int i = 0; i < values.size(); i++)
  {
    if ((this->values[i] > 64) && (this->values[i]<91))
    {
      this->values[i] += this->step;
      if (this->values[i] > 90) {
        this->values[i] = 65 + this->values[i] % 91 ;
      }
    }
    else if ((this->values[i] > 96) && (this->values[i]<120))
      {
        this->values[i] = this->values[i] + this->step;
        if (this->values[i] > 120) {
          this->values[i] = 97 + this->values[i] % 121;
        }
      }

      }
};

void Ceaser::decode()
{

  for (int i = 0; i < values.size(); i++)
  {
    if ((this->values[i] > 62) && (this->values[i]<91))
    {
      this->values[i] -= step;
      if (this->values[i] < 65) {
        this->values[i] = 90 - step + ((this->values[i] + step) % 64) ;
      }
    }
    if ((this->values[i] > 94) && (this->values[i]<123))
    {
      this->values[i] -= step;
      if (this->values[i] < 97) {
        this->values[i] = 122 - step + ((this->values[i] + step) % 96) ;
      }
    }

  }
};

std::string Ceaser::ret()
{
  return this->values;
}
