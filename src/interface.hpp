#include <Rinternals.h>

extern "C" {
  SEXP immDate(SEXP mon_sexp, SEXP year_sexp);
  SEXP to_end_of_month(SEXP x);
  SEXP to_end_of_week(SEXP x);
  SEXP to_first_of_next_month(SEXP x);
}
