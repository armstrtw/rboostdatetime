#include <boost/date_time/gregorian/gregorian.hpp>

namespace RBoostDateTime {
  boost::gregorian::date fromPOSIXct(const double x);
  boost::gregorian::date immDate(const int mon, const int year);
}
