#include <string>
#include <vector>

#include <iostream>

#include "tkmaglib.h"


bool isQuietDay(::std::string strday)
{
  ::std::vector<double> aDst(24, -999);
  getDst(strday, aDst);
  for (int i = 0; i < aDst.size(); i++)
    if (aDst[i] < -30 || aDst[i] > 30)
      return false;
  return true;
}
