#! /usr/bin/env python3

import subprocess as sb
from sys import argv


# first check if an argument was given
# then check the extension
if len(argv) >= 2 and argv[1].endswith(".cpp"):
    file_name = argv[1] 
else:
    print("A C++ file with a .cpp extension is required.")
    quit()
    
file_split = file_name.rsplit('.', 1)  # separate the extension from the rest of the filename
file_no_ext = file_split[0]  


sb.call(f"g++ {file_name} -o {file_no_ext}", shell=True)  # compile the file
sb.call(f"./{file_no_ext}", shell=True)  # runs the executable file that was created
sb.call(f"rm {file_no_ext}", shell=True)  # removes the executable file after it runs
