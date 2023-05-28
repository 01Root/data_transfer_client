#!/bin/bash
# Basic while loop
counter=1
while [ $counter -le 100 ]
do
echo "Running exe." echo $counter
../client/client.exe

echo "Start run the comparison " 

diff ../sended_files/100M.txt ../../multi_threading_server/recved_files/100M.txt || echo "diff says thar the recved 100M file is not equal as the sended 100M file."
# echo "The comparison is done."

((counter++))

done
echo All done