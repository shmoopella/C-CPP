#!/bin/bash

TEST1="-b file.txt"
TEST2="-e file.txt"
TEST3="-n file.txt"
TEST4="-s file.txt"
TEST5="-t file.txt"
TEST6="-v file2.txt"

./s21_cat $TEST1 >res1
cat $TEST1 >res2
DIF_RES="$(diff -s res1 res2)"
if [ "$DIF_RES" = "Files res1 and res2 are identical" ]
then
    echo test1 success
else
    echo test1 fail
fi

./s21_cat $TEST2 >res1
cat $TEST2 >res2
DIF_RES="$(diff -s res1 res2)"
if [ "$DIF_RES" = "Files res1 and res2 are identical" ]
then
    echo test2 success
else
    echo test2 fail
fi

./s21_cat $TEST3 >res1
cat $TEST3 >res2
DIF_RES="$(diff -s res1 res2)"
if [ "$DIF_RES" = "Files res1 and res2 are identical" ]
then
    echo test3 success
else
    echo test3 fail
fi

./s21_cat $TEST4 >res1
cat $TEST4 >res2
DIF_RES="$(diff -s res1 res2)"
if [ "$DIF_RES" = "Files res1 and res2 are identical" ]
then
    echo test4 success
else
    echo test4 fail
fi

./s21_cat $TEST5 >res1
cat $TEST5 >res2
DIF_RES="$(diff -s res1 res2)"
if [ "$DIF_RES" = "Files res1 and res2 are identical" ]
then
    echo test5 success
else
    echo test5 fail
fi

./s21_cat $TEST6 >res1
cat $TEST6 >res2
DIF_RES="$(diff -s res1 res2)"
if [ "$DIF_RES" = "Files res1 and res2 are identical" ]
then
    echo test6 success
else
    echo test6 fail
fi
