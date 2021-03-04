#!/bin/sh
gcc --version
errors=0
for filename in ./a*/*.c; do
	string=$(gcc $filename -o a.out -lm -Werror);
	if [ $? -ne 0 ]; then
	    echo "$filename compiled with errors.";
	    echo $string;
	    errors=$(($errors+1))
	    echo "Total errors so far: $errors.";
	fi
done	
echo "Exiting with $errors"
exit $errors