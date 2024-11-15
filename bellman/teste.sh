#!/bin/bash

# Binários
bellman=./bellman.bin


echo "Testando Algoritmo de Bellman"
for i in instances/*.dat
do
	echo -e "\e[33mInstância $i\e[0m";
	$bellman -f $i -i 1 -o temp;

	j=$(basename $i);
	diff -w temp ./results/$j > /dev/null ;
	if [ $? -eq 0 ]; then
		echo -e "\e[32mOK\e[0m"
	else
		echo -e "\e[31mErro\e[0m";
	fi
	rm temp;

done
