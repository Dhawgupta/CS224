#!/bin/bash

# This is a sample script for automating the result generation.
# This script will NOT work for the given assignment. To make this
# code working, you may need to edit this intelligently!! This  is
# just for your reference.


# Here is the list of file names, executable names, etc.
QSORT_FILE="qsort.c"
RAND_GEN_FILE="RandomInput.c"
TESTCASE_SIZE="10000 20000 30000 40000"
NUMBER_OF_INSTANCE="50"
QSORT_EXE="myqsort"
RAND_GEN_EXE="RandInput"
CC="cc"
inputfile="randInput.txt"
outFile="outTime.txt"

datafile="datafile.txt"
gnuplotdatafile="gnuplotdatafile.txt"
gnuscriptfile="gnuscriptfile.scr"

rm -f $datafile

#compile QSORT_FILE
$CC $QSORT_FILE -g -o $QSORT_EXE -lm
#compile RAND_GEN_FILE
$CC $RAND_GEN_FILE -g -o $RAND_GEN_EXE -lm


# looping over test case size that is by varying 'n'
for size in $TESTCASE_SIZE
do
	iteration="0";
	printf  "SIZE:%s"  $size >> $datafile
	
	# Looping over different test cases of the same size
	while test $iteration -ne $NUMBER_OF_INSTANCE
	do
		#generate test case .. this takes command line argument!
		./$RAND_GEN_EXE $size > $inputfile 
		
		#Here input file format as follows:
		# 1   // using median  , 2 for random pivot
		# 10  // number of numbers
		# 4   // numbers
		# ... // numbers
		###################################
		echo "1" > $inputfile.median 
		cat $inputfile >> $inputfile.median

		#run test case with time .. note the time ..
		# use 'man time' for more information on time command
		/usr/bin/time --format="EXECUTION_TIME: %U"  -o $outFile  ./$QSORT_EXE < $inputfile.median
		
		#take the execution time
		exeTime=`awk '/^EXECUTION_TIME/ {print $2}' $outFile`
		
		#Storing the time in a file
		printf ":%s" $exeTime >> $datafile

	    #Repeating the same steps as above when the pivot is chosen randomly.
		echo "2" > $inputfile.random 
		cat $inputfile >> $inputfile.random
		/usr/bin/time --format="EXECUTION_TIME: %U"  -o $outFile  ./$QSORT_EXE < $inputfile.random
		#take the execution time
		exeTime=`awk '/^EXECUTION_TIME/ {print $2}' $outfile`
		printf ":%s" $exeTime >> $datafile

		iteration=`expr $iteration + 1`
	done
done


#gnuplot data file generation
 
# computing the average time 
awk -F":" '{  sum_M = 0; sum_R = 0; count = (NF - 2)/2;
		for(i=3;i<=NF;i++){
			if(i%2 == 1){
				sum_M = sum_M + $i;
			}else{
				sum_R = sum_R + $i;
			}
		}
		avTime_M = sum_M/count;
		avTime_R = sum_R/count;
		printf("%d  %f  %f\n",$2,avTime_M,avTime_R);
}' $datafile > $gnuplotdatafile 


# gnuplot script generation
echo "set terminal postscript color" > $gnuscriptfile
echo "set output \"qsort_plot.ps\"" >> $gnuscriptfile
echo "set xlable \"Size\"" >> $gnuscriptfile
echo "set ylable \"Execution time\"" >> $gnuscriptfile
echo "plot \"$gnuplotdatafile\" using 1:2 title \"median\" with lines, \"$gnuplotdatafile\" using 1:3 title \"random\" with  lines"  >> $gnuscriptfile
echo "quit" >> $gnuscriptfile

# genrating the plot
gnuplot $gnuscriptfile

# Now view the plot in any ps-viewer.. like gv or kghostview or ggv etc.
