#include <boost/date_time/gregorian/gregorian.hpp>
#include "r.boost.date.time.hpp"

namespace RBoostDateTime {
  using namespace boost::gregorian;

  date fromPOSIXct(const double x) {
    struct tm x_tm;
    const time_t x_tt = static_cast<const time_t>(x);
    gmtime_r(&x_tt,&x_tm);
    return date_from_tm(x_tm);
  }

  date immDate(const int mon, const int year) {
    typedef nth_day_of_the_week_in_month nth_dow;

    nth_dow ans_generator(nth_dow::third,
                          Wednesday,
                          mon);

    return ans_generator.get_date(year);
  }


} // namespace RBoostDateTime
