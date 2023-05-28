#!/bin/bash
# Basic while loop
counter=1
while [ $counter -le 100 ]
do
echo "Running exe." echo $counter
./client/client.exe

echo "Start run the comparison " 
# cmp  --silent ./sended_files/1M.txt ../multi_threading_server/recved_files/1M.txt || echo "--------------------cmp says that files are different.----------------------"
# cmp  --silent ./sended_files/1M.txt ../multi_threading_server/recved_files/1M.txt || echo $?
# hexdump -C ./sended_files/1M.txt > sended.hex
# hexdump -C ../multi_threading_server/recved_files/1M.txt > recved.hex
# diff sended.hex recved.hex || echo "----------------------files are different.-----------------------"
diff ./sended_files/1M.txt ../multi_threading_server/recved_files/1M.txt || echo "diff says that the two files are not equal."
# echo "The comparison is done."

((counter++))

done
echo All done