#include <string>
#include <vector>

#include <iostream>

#include "tkmaglib.h"


bool isQuietDay(::std::string strday)
{
  return isQuietDay(strday, 30);
}


bool isQuietDay(::std::string strday, double threshold)
{
  ::std::vector<double> aDst(24, -999);
  getDst(strday, aDst);
  for (unsigned int i = 0; i < aDst.size(); i++)
    if (aDst[i] < -threshold || aDst[i] > threshold)
      return false;
  return true;
}
