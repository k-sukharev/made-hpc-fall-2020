#!/bin/bash
my_arr=(Salt Pepper Salt_n_Paper "Salt and Paper" foo bar foobar f o o b a r 1 2 3 4 5 6 7)
for elem in "${my_arr[@]}"
do
  echo $elem
done
