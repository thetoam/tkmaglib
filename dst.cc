#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "tkmaglib.h"

::std::string getSciencePath();


int getDst(::std::string strday, ::std::vector<double> &aDst)
{
  ::std::string path = getSciencePath() + "/dst/" + strday.substr(0, 4) + "/" + strday + ".dst";
  ::std::cerr << path << ::std::endl;
  ::std::ifstream infile (path.c_str(), ::std::ifstream::in);
  ::std::string line;

  while (std::getline(infile, line))
  {
    // Format:
    // 0        9 11  15  19  23  27  ... etc
    // |        | |   |   |   |   |
    // 20030605 f -023-025-026-027-021-015-012-012-015-015-011-016-014-017-018-019-021-021-022-020-013-010-017-017
    for (int i = 0; i < 24; i++)
      aDst[i] = atof(line.substr(11 + (4 * i), 4).c_str());
  }
  infile.close();

  return 0;
}


::std::string getSciencePath()
{
  ::std::string envName = "SCIENCEPATH";
  ::std::string envValue;
  char* cEnvValue;
  cEnvValue = ::std::getenv(envName.c_str());
  if (!cEnvValue)
    throw ::std::runtime_error("Environmental variable SCIENCEPATH not defined");
  envValue = ::std::string(cEnvValue);
  return envValue;
}
