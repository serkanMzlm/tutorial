#! /bin/bash

ip_list="/home/hosts/ip_lists.txt"
for ip in  $(cat $ip_list)
do
	ping -c1 $ip &> /dev/null   # &> /dev/null komutun çıktısının ekranda gözükmesini engeller.
		if [ $? -eq 0 ] # En son yürütülen komutun çıktısını tutar.
		then 
				echo $host is OK
		else
				echo $host is not  OK
		fi
done