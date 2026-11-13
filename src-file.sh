#!/bin/bash

[[ $# -eq 1 ]] || exit

set -o noclobber

pp="${1//[![:alnum:]]/_}"; pp="${pp^^}"
cat > "$1.h" <<- EOF
	#ifndef ${pp}_H
	#define ${pp}_H



	#endif
	EOF

cat > "$1.cpp" <<- EOF
	#include "$1.h"
	EOF
