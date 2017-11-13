rel1=$1
rel2=$2
memory=$3
ejcute="g++ -std=c++11 -o sort code.cpp tokenize.cpp readData.cpp"
eval $ejcute
ejcute="./sort $rel1 out1.txt $memory asc 1 c1"
eval $ejcute
ejcute="./sort $rel2 out2.txt $memory asc 0 c0"
eval $ejcute
ejcute="g++ -std=c++11 -o sort sort_join.cpp readFiles1.cpp readFiles2.cpp"
eval $ejcute
ejcute="./sort out1.txt out2.txt $memory"
eval $ejcute