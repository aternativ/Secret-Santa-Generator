#!/bin/bash

if [ ! -d partners ]; then
    mkdir partners
fi

if [ -f out.txt ]; then 
    rm out.txt
fi

make
./secret

if [ ! -z "$(ls -A ./partners)" ]; then
    rm ./partners/*
fi


nr=$(cat out.txt | wc -l)

for i in $(seq 1 $nr); do
    cat out.txt | head -n $i | tail -1 > ./partners/"$(cat out.txt | head -n $i | tail -1 | cut -d',' -f1).txt"
done

rm out.txt
