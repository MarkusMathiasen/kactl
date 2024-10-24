g++ -O2 stupid.cpp -o stupid.out
g++ -O2 main.cpp -o smart.out
for (( i=1; i<=$1; ++i )) do
  python gen.py > test.txt
  ./stupid.out < test.txt > stupid_out.txt
  ./smart.out < test.txt > smart_out.txt
  if [[ $(diff stupid_out.txt smart_out.txt) ]]
  then
    echo "$(diff -Z supid_out.txt smart_out.txt)" > diff.txt
    echo "WA on test $i\nTESTS FAILED!"
    break
  else echo "AC on test $i"
fi done
echo "TESTS PASSED!"