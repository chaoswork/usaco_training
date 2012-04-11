#!/bin/bash
#create a new usaco task,just enter the task name


if [ $# -lt 1 ];then
	echo "no task name"
	exit 0
fi

rm *.in
touch $1.in 
echo "create $1.in"

sed "s/task/$1/" sample.cpp > $1.cpp
echo "create $1.cpp"

ln $1.cpp main.cpp -f
echo "now main.cpp linked to $1.cpp"

echo "just do it~"
