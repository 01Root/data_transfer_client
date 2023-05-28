#!/bin/bash
# Basic while loop

diff ../sended_files/1K.txt ../../multi_threading_server/recved_files/1K.txt || echo "diff says that the two files are not equal."
diff ../sended_files/1M.txt ../../multi_threading_server/recved_files/1M.txt || echo "diff says that the two files are not equal."
diff ../sended_files/100M.txt ../../multi_threading_server/recved_files/100M.txt || echo "diff says that the two files are not equal."
# diff ../sended_files/1G.txt ../../multi_threading_server/recved_files/1G.txt || echo "diff says that the two files are not equal."
