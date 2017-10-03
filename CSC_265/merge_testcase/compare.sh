#!/bin/bash

for i in $(seq 1 9); do
	echo "Test $i"
	python3 compare.py my_output$i.csv model_output$i.csv
done
