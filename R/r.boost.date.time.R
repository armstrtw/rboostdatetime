imm.date <- function(mon,year) {
    .Call("immDate",as.integer(mon),as.integer(year),PACKAGE="RBoostDateTime")
}

to.end.of.month <- function(x) {
    .Call("to_end_of_month",x,PACKAGE="RBoostDateTime")
}

to.first.of.next.month <- function(x) {
    .Call("to_first_of_next_month",x,PACKAGE="RBoostDateTime")
}
