touch input.txt output.txt
echo 10 >> input.txt
  
echo 1 2 3 4 5 6 7 8 9 0 >> input.txt
   
echo 5 >> input.txt
echo 0 8 9 7 8 6 7 5 6 4 >> input.txt 

mv input.txt output.txt build/

./build/ArrayProject input.txt output.txt
