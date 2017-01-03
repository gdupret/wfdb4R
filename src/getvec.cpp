#include <Rcpp.h>

#include <stdio.h>
#include <malloc.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <wfdb/wfdb.h>

//' read the signals from a MIT database file
//' @param  filename The path to the signal file, without extension
//' @return a Matrix object with one signal per row
//' @note This function needs to be called from the directory where the file resides. Use getvec to go over this restriction
// [[Rcpp::export]]
Rcpp::NumericMatrix getvec_(const std::string & filename){
  using Rcpp::Rcout;
  using Rcpp::stop;

  char * filename_p = const_cast<char * >(filename.c_str());
  int i, j, nsig;
  WFDB_Sample *v;
  WFDB_Siginfo *s;

  nsig = isigopen(filename_p, NULL, 0);
  if (nsig < 1){
    std::ostringstream oss;
    oss << "nsig = " << nsig;
    stop(oss.str());
  }
  s = (WFDB_Siginfo *)malloc(nsig * sizeof(WFDB_Siginfo));

  if (isigopen(filename_p, s, nsig) != nsig){
    std::ostringstream oss;
    oss << "expect nsig = " << nsig;
    stop(oss.str());
  }

  v = (WFDB_Sample *)malloc(nsig * sizeof(WFDB_Sample));

  std::vector<double> data;
  while(getvec(v) >= 0){
    for(int s =0; s < nsig; ++s){
      data.push_back(v[s]);
    }
  }
  Rcpp::NumericMatrix output(nsig, data.size() / nsig, data.begin());
  return output;
}
