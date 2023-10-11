#!/bin/bash
python3 ../generators/random_gen.py
python3 ../generators/worst_case_gen.py

for i in {0..12}
do
	../meuzamigo < ../inout/in_$i.in > ../inout/in_$i.out
done