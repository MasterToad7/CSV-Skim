# CSV Skim
A tool to count how many times a token or a column is repeated in a csv file.

# How to compile
CSV SKIM can be compiled with cmake
```
mkdir build
cd build
cmake ../
cmake --build .
```

# How to use
***WARNING!*** Max tokens is 16384 and the max length per token is 32
1. Drag the csv file you want to check into the same directory as the program.
2. Run the program named csv_skim (can be ran in terminal.)
3. Enter your csv filename when prompted to enter a "CSV Victim."
4. Enter your seperation type when prompted to and enter t for token or c for column
5. The outputted token count data will be in a csv file titled "csvskimlog.csv."
