# wfdb4R

Wrapper around physionet wfdb library

## Usage

So far, only the `getvec` function to load a record is implemented.

First download the database of interest (or a single record). See
https://physionet.org/faq.shtml#downloading-databases for an
explanation on how to do that.

Second, load the `wfdb4R` library and load a record:

```
library(wfdb4R)
ecg <- getvec("~/data/mitdb/100")
str(ecg)
```

results:
```
num [1:2, 1:650000] 995 1011 995 1011 995 ...
```

## Installation

Install the Physionet wfdb library and make sure it is visible to your `C/C++` compiler.

From R, first install the `devtools` library, then do

```
library(devtools)
install_github("gdupret/wfdb4R")
```
