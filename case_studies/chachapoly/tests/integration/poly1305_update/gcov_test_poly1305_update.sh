#!/bin/bash

# Set variables for the source and test files
TEST_EXECUTABLE="test_poly1305_update"
SOURCE_FILES="poly1305_update.c poly1305_init.c U8TO32.c poly1305_blocks.c"
TEST_FILE="test_poly1305_update.c"
COVERAGE_FLAGS="-fprofile-arcs -ftest-coverage -DNDEBUG"
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
gcovr --root . --html --html-details \
--exclude "$TEST_FILE" \
--exclude ".*poly1305_init.c" \
-o $OUTPUT_DIR/coverage_report.html


# Step 5: Cleanup .gcda, .gcno, and .gcov files
echo "Cleaning up coverage files..."
rm -f *.gcda *.gcno *.gcov 

echo "Coverage report generated at $OUTPUT_DIR/coverage_report.html"
