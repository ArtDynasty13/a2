#!/bin/bash

# Check if the user provided a value for n
if [ -z "$1" ]; then
    echo "Usage: $0 <n>"
    echo "Example: $0 1000000"
    exit 1
fi

# Get the value of n from the command line
n=$1

# Compile your program (if needed)
gcc luhns.c -o luhns

# Loop through numbers from 0 to n
for ((i = 0; i <= n; i++)); do
    number=$(printf "%0${#n}d" $i)  # Pad with leading zeros to match the length of n
    echo "Testing: $number"

    # Run your program
    your_output=$(echo -n "$number" | ./luhns)
    
    # Run the sample executable
    sample_output=$(echo -n "$number" | ./luhns_sample)

    # Compare the outputs
    if [ "$your_output" == "$sample_output" ]; then
        echo "  ✅ Pass: Output matches sample."
    else
        echo "  ❌ Fail: Output does not match sample."
        echo "    Your output: $your_output"
        echo "    Sample output: $sample_output"
        exit 1  # Exit on the first failure
    fi
done

echo "All tests passed for numbers from 0 to $n."