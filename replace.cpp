#include "replace.h"
#include <string>
#include <iostream>
using namespace std;


Replace::Replace(  string in, string dict)
{
  this->values = in;
  this->dict = dict;
  if (this->dict.size() != 26)
    throw ReplaceException();
  if (this->values.size() == 0)
    throw ReplaceException();
};

string Replace::encode()
{
  for (int i = 0; i < this->values.size(); i++)
  {
    int pos;
    for (int j = 0; j < this->abc.size(); j++)
    {
      if (this->values[i] == this->abc[j])
      {
        pos = j;
        break;
      }
    }
    this->values[i] = this->dict[pos];
  }
  return this->values;
};

string Replace::decode()
{
  cout << this->abc.size() << endl << this->dict.size()<<endl;
  for (int i = 0; i < this->values.size(); i++)
  {
    for (int j = 0; j < this->abc.size(); j++)
    {
      int pos;
      if (this->values[i] == this->dict[j])
      {
        pos = j;
        break;
      }
      this->values[i] = this->abc[pos];
    }
  }
  return this->values;
};
