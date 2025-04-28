#!/bin/bash

make
if [ $# -ge 1 ]; then
	echo -e "\e[32m### PmergeMe with \e[34m$1\e[32m random numbers ###\e[0m"
	./PmergeMe `shuf -i 1-$1 -n $1 | tr "\n" " "` > temp.txt
	cat temp.txt
	cat temp.txt | awk -F'\t' '/After:/ {print $2}' > temp.txt
	tr ' ' '\n' < temp.txt | sort -n -C && echo -e "\e[32mSorted\e[0m" || echo -e "\e[31mNot sorted\e[0m"
else
    numbers=(10 50 100 3000 $((100 + RANDOM % 51)))

    for num in "${numbers[@]}"; do
        for i in {1..20}; do
            echo -e "\e[32m### PmergeMe with \e[34m$num\e[32m random numbers ###\e[0m"
            ./PmergeMe `shuf -i 1-$num -n $num | tr "\n" " "` | awk -F'\t' '/After:/ {print $2}' > temp.txt
            output=$(cat temp.txt | cut -c 1-200)
            if [ $(wc -c < temp.txt) -gt 200 ]; then
                echo "$output..."
            else
                echo "$output"
            fi
            tr ' ' '\n' < temp.txt | sort -n -C && echo -e "\e[32mSorted\e[0m" || { echo -e "\e[31mNot sorted\e[0m"; exit 1; }
        done
    done
fi

rm temp.txt
