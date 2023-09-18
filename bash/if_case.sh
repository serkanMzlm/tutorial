#!/bin/bash
a=`date | awk '{print $1}'`
if [ "$a" == Sal ]
then
echo Today is $a
elif [ "$a" == Paz ]
then
echo Today is $a
else 
echo Today is not Monday
fi

echo "a = ls, b = cd ~"

read choices
case $choices in
a) clear; ls   ;;
b) clear; cd ~ ;;
*) clear; echo "error..";;
esac
