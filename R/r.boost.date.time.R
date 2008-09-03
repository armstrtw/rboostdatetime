imm.date <- function(mon,year) {
    .Call("immDate",as.integer(mon),as.integer(year),PACKAGE="RBoostDateTime")
}
