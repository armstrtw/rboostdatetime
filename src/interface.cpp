#include <Rinternals.h>
#include "r.boost.date.time.hpp"

SEXP immDDate(SEXP mon_sexp, SEXP year_sexp) {

  RVector<REALSXP> mon(mon_sexp);
  RVector<REALSXP> year(year_sexp);
  RVector<REALSXP> ans(n);

  R_len_t len = mon.length() > year.length() ? mon.lenght() : year.length();

  for(int i=0; i < len; i++) {
    ans[i] = boost::posix_time::ptime(RBoostDateTime::immDate(year[i% len],mon[i % len]));
  }

  return ans.getSEXP();
}
