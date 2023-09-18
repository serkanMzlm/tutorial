#! /bin/bash


host="192.185.12.2"
ping -c1 $host &> /dev/null   # &> /dev/null komutun çıktısının ekranda gözükmesini engeller.
if [ $? -eq 0 ] # En son yürütülen komutun çıktısını tutar.
then 
    echo $host is OK
else
    echo $host is not  OK
fi