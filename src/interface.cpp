#include <vector>
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <time.h>
#include <Rinternals.h>
#include <Rvector.hpp>
#include "r.boost.date.time.hpp"
#include "interface.hpp"

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
