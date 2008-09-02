#include <boost/date_time.hpp>

namespace RBoostDateTime {
  using namespace boost::gregorian;

  date immDate(const int mon, const int year) {
    typedef nth_day_of_the_week_in_month ndow;
  
    ndow ans_generator(nth_dow::third,
                       Wednesday,
                       mon);

    return ans_generator.get_date(year);
  }

} // namespcace RBoostDateTime
