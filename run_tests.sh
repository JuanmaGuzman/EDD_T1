#!/usr/bin/bash

# for level in 'easy' 'medium' 'hard'; do
#     for part in 'A' 'B'; do
#         for i in `seq 1 3`; do
#             echo "Running test $i for $level $part"
#             filename=$(printf "%s/test-%s-0%d.txt" $level $part $i)
#             solutions=$(printf "%s/output-%s-0%d.txt" $level $part $i)

#             ./bstmate "TestsT1/tests_bstmate/tests/$filename" out.txt
#             cp out.txt "TestsT1/tests_bstmate/student_outputs/$filename"

#             diff -bq "TestsT1/tests_bstmate/solutions/$solutions" "TestsT1/tests_bstmate/student_outputs/$filename"
#             if [ $? -ne 0 ]; then
#                 echo "Test failed\n"
#             else
#                 echo "Test passed\n"
#             fi
#         done
#     done
# done

# for level in 'easy' 'medium' 'hard'; do
#     for part in 'a' 'b' 'c'; do
#             echo "Running test for $level $part"
#             filename=$(printf "%s_%s.txt" $level $part)
#             solutions=$(printf "%s_%s.txt" $level $part)

#             ./qsortcars "TestsT1/test_quicksort/tests/$filename" out.txt
#             cp out.txt "TestsT1/test_quicksort/student_outputs/$filename"

#             diff -bq "TestsT1/test_quicksort/solutions/$solutions" "TestsT1/test_quicksort/student_outputs/$filename"
#             if [ $? -ne 0 ]; then
#                 echo "Test failed\n"
#             else
#                 echo "Test passed\n"
#             fi
#     done
# done