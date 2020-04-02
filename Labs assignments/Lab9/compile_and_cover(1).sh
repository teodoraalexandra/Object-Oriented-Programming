#!/bin/bash

path=/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
exec_name="a.out"
clang++ -O3 -fprofile-instr-generate -fcoverage-mapping $(echo $(find . -maxdepth 1 -regex "^.*\.[hc][pp]*$" | rev | cut -d'/' -f 1 | rev) )
LLVM_PROFILE_FILE="$exec_name.profraw" ./$exec_name
$path/llvm-profdata merge -sparse $exec_name.profraw -o $exec_name.profdata

# terminal line-by-line
$path/llvm-cov show -use-color ./$exec_name -instr-profile=$exec_name.profdata

# Browser line-by-line
$path/llvm-cov show -format=html -use-color ./$exec_name -instr-profile=$exec_name.profdata > long.html
$path/xdg-open long.html && sleep 1 && rm long.html&

# terminal short
$path/llvm-cov report -use-color ./$exec_name -instr-profile=$exec_name.profdata

rm $exec_name
rm *.gch
rm $exec_name.prof*
exit
