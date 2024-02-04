# Sorting_Pipe_Unix
A program that uses a txt file as input then sorts the content of the file and prints it. All happening using a Unix Pipe

# Usage 
The purpose of this project is to Create a program that uses the name of a text file (e.g., infile) located in the same directory then the program should transfer the file's data through a Unix pipe to the command "sort -n infile." The output of this command, received through another pipe, should be printed with the additional phrase "Data received through pipe" at the beginning of each line followed by the sorted lines of the input file.

# How to run:
Open your terminal in the same directory where the files of this repository are saved and then type the commands
"gcc sorting_pipe.c -o sorting_pipe" 
"./sorting_file infile.txt"

# Info
This project was made by Nikolaos Balatos (inf2021151@ionio.gr) and Maria Mpalasopoulou (inf2021150@ionio.gr)
