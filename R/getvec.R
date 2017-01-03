#' read a physionet signal from file
#'
#' @param filename The path to the file to read, with or without extension
#' @note The C function in wfdb must be called from the directory where the file resides. This wrapper make sure to move to the directory first, reads the signal and return to the original working directory. In other words, its usage is more in line with what you would normally expect.
#' @return a Matrix with one signal per row
#' @export
getvec <- function(filename){
  cwd <- getwd()
  setwd(dirname(filename))
  filename_without_extension <- sub('\\..*$', '', basename(filename))
  output <- getvec_(filename_without_extension)
  setwd(cwd)
  return(output)
}