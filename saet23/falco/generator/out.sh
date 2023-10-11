#!/bin/bash

# Create an array of input file names
input_files=("in_1.in" "in_2.in" "in_3.in" "in_4.in" "in_5.in" "in_6.in" "in_7.in" "in_8.in")

# Loop through each input file
for input_file in "${input_files[@]}"; do
    # Construct the corresponding output file name
    output_file="${input_file%.in}.out"

    # Check if the input file exists
    if [ -e "$input_file" ]; then
        # Execute the binary with input redirection and save the output
        ./a.out < "$input_file" > "$output_file"

        # Check the exit status of the previous command
        if [ $? -eq 0 ]; then
            echo "Binary executed successfully for $input_file. Output saved in $output_file"
        else
            echo "Binary execution failed for $input_file."
        fi
    else
        echo "Input file $input_file not found."
    fi
done

