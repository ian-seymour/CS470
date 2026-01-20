# !/bin/bash

# Author: Ian Seymour
# File: create_files_with_subdirs.sh
# Description: Creates a directory with 10 subdirectories and each subdirectory gets 10 files with
# a random programming language written to it.

# create log
LOG="subdirs.log"

echo "[$(date)] Script initiated." >> "$LOG"

CURR_TIME="$(date +%Y-%m-%d-%H-%M)"

mkdir "$CURR_TIME"
echo "[$(date)] Main directory created." >> "$LOG"

cd "$CURR_TIME"

# Array of languages
LANGUAGES=("Python" "C" "C++" "Pascal" "Fortran" "Java" "Assembly" "VHDL" "ML" "Basic" "Visual Basic" "Ruby" "Rust" "Haskell" "C#" "Go" "CUDA" "Ada" "Prolog")

# loop to create directory
for i in {101..110}; do
	DIRECTORY="file$i"
	
	mkdir -p "$DIRECTORY"
	echo "[$(date)] Created $DIRECTORY directory." >> "../$LOG"

	# inner loop to make files in each directory
	for j in {501..510}; do
		FILE="$DIRECTORY/tuser$j.txt"

		CURR_LANG="${LANGUAGES[$RANDOM % ${#LANGUAGES[@]}]}"

		echo "$CURR_LANG" > "$FILE"
		echo "[$(date)] Created file $FILE." >> "../$LOG"

	done
done

cd ..

echo "[$(date)] Script complete." >> "$LOG"
