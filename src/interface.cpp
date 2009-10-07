#include <vector>
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <time.h>
#include <Rinternals.h>
#include <Rvector.hpp>
#include "r.boost.date.time.hpp"
#include "interface.hpp"

using namespace boost::gregorian;
using namespace RBoostDateTime;

SEXP immDate(SEXP mon_sexp, SEXP year_sexp) {

  RAbstraction::RVector<INTSXP> mon(mon_sexp);
  RAbstraction::RVector<INTSXP> year(year_sexp);

  R_len_t len = mon.len() > year.len() ? mon.len() : year.len();
  RAbstraction::RVector<REALSXP> ans(len);

  for(int i=0; i < len; i++) {
    struct tm tm_time = to_tm(RBoostDateTime::immDate(mon(i),year(i)));
    ans[i] = static_cast<double>(mktime(&tm_time));
  }

  std::vector<std::string> date_class;
  date_class.push_back("POSIXt");
  date_class.push_back("POSIXct");
  ans.setClass(date_class.begin(),date_class.end());

  return ans.getSEXP();
}

// takes a POSIXct date
SEXP to_end_of_month(SEXP x) {
  RAbstraction::RVector<REALSXP> xv(x);
  R_len_t len = length(x);
  RAbstraction::RVector<REALSXP> ans(len);
  for(int i=0; i < len; i++) {
    struct tm tm_time = to_tm(fromPOSIXct(xv[i]).end_of_month());
    ans[i] = static_cast<double>(mktime(&tm_time));
  }
  std::vector<std::string> date_class;
  date_class.push_back("POSIXt");
  date_class.push_back("POSIXct");
  ans.setClass(date_class.begin(),date_class.end());

  return ans.getSEXP();
}

// takes a POSIXct date
SEXP to_end_of_week(SEXP x) {
  const greg_weekday friday(Friday);
  RAbstraction::RVector<REALSXP> xv(x);
  R_len_t len = length(x);
  RAbstraction::RVector<REALSXP> ans(len);
  for(int i=0; i < len; i++) {
    date this_date = fromPOSIXct(xv[i]);
    struct tm tm_time = to_tm(this_date + days_until_weekday(this_date,friday));
    ans[i] = static_cast<double>(mktime(&tm_time));
  }
  std::vector<std::string> date_class;
  date_class.push_back("POSIXt");
  date_class.push_back("POSIXct");
  ans.setClass(date_class.begin(),date_class.end());

  return ans.getSEXP();
}

// takes a POSIXct date
SEXP to_first_of_next_month(SEXP x) {
  RAbstraction::RVector<REALSXP> xv(x);
  R_len_t len = length(x);
  RAbstraction::RVector<REALSXP> ans(len);
  for(int i=0; i < len; i++) {
    struct tm tm_time = to_tm(fromPOSIXct(xv[i]).end_of_month() + days(1));
    ans[i] = static_cast<double>(mktime(&tm_time));
  }
  std::vector<std::string> date_class;
  date_class.push_back("POSIXt");
  date_class.push_back("POSIXct");
  ans.setClass(date_class.begin(),date_class.end());

  return ans.getSEXP();
}

