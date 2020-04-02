#!/bin/bash

exec_name="a.out"
clang++ -O3 -fprofile-instr-generate -fcoverage-mapping $(echo $(find . -maxdepth 1 -regex "^.*\.[hc][pp]*$" | rev | cut -d'/' -f 1 | rev) )
LLVM_PROFILE_FILE="$exec_name.profraw" ./$exec_name
llvm-profdata merge -sparse $exec_name.profraw -o $exec_name.profdata

# terminal line-by-line
llvm-cov show -use-color ./$exec_name -instr-profile=$exec_name.profdata

# Browser line-by-line
llvm-cov show -format=html -use-color ./$exec_name -instr-profile=$exec_name.profdata > long.html
xdg-open long.html && sleep 1 && rm long.html&

# terminal short
llvm-cov report -use-color ./$exec_name -instr-profile=$exec_name.profdata

rm $exec_name
rm *.gch
rm $exec_name.prof*
exit

