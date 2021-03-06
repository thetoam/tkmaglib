#include <string>
#include <vector>

/**
* Library for various magnetic functions
*
* @author  Tom Kane
* @version 1.0
* @since   2016-09-22
*/


/**
* Get 24 hourly Dst values for a given day
*
* @param strday String value of the day in question
* @param aDst Vector<double> for storing Dst values (passed as reference)
*/
int getDst(::std::string strday, ::std::vector<double> &aDst);


/**
* Determine if a day is geomagnetically quiet
*
* @param strday String value of the day in question
*/
bool isQuietDay(::std::string strday);

/**
* Determine if a day is geomagnetically quiet
*
* Determine is a day is geomagnetically quiet based on arbitrary threshold
*
* @param strday String value of the day in question
*/
bool isQuietDay(::std::string strday, double threshold);
