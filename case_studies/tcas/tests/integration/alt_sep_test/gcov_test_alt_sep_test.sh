#!/bin/bash

# Set variables for the source and test files
TEST_EXECUTABLE="test_alt_sep_test"
SOURCE_FILES="Non_Crossing_Biased_Descend.c initialize.c Non_Crossing_Biased_Climb.c Own_Above_Threat.c alt_sep_test.c Own_Below_Threat.c Inhibit_Biased_Climb.c ALIM.c"
TEST_FILE="test_alt_sep_test.c"
COVERAGE_FLAGS="-fprofile-arcs -ftest-coverage"
COMPILER="gcc"
OUTPUT_DIR="coverage_report"

# Step 1: Compile the test file and source files with coverage flags
echo "Compiling with coverage flags..."
$COMPILER -o $TEST_EXECUTABLE $COVERAGE_FLAGS $TEST_FILE $SOURCE_FILES


# Step 2: Run the test executable
echo "Running tests..."
./$TEST_EXECUTABLE


# Step 3: Generate gcov files
echo "Generating gcov files..."
gcov -o . $SOURCE_FILES


# Step 4: Create a coverage report with gcovr, excluding the test file
echo "Creating coverage report, excluding test file..."
mkdir -p $OUTPUT_DIR
gcovr --root . --html --html-details --exclude "$TEST_FILE" -o $OUTPUT_DIR/coverage_report.html


# Step 5: Cleanup .gcda, .gcno, and .gcov files
echo "Cleaning up coverage files..."
rm -f *.gcda *.gcno *.gcov 

echo "Coverage report generated at $OUTPUT_DIR/coverage_report.html"
