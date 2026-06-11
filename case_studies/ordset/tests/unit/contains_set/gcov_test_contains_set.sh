#!/bin/bash

TEST_EXECUTABLE="test_contains_set"
SOURCE_FILES="bin_search_stub.c contains_set.c element_at_stub.c ord_set.c"
TEST_FILE="test_contains_set.c"
COVERAGE_FLAGS="-fprofile-arcs -ftest-coverage"
COMPILER="gcc"
OUTPUT_DIR="coverage_report"

echo "Compiling with coverage flags..."
$COMPILER -o $TEST_EXECUTABLE $COVERAGE_FLAGS $TEST_FILE $SOURCE_FILES

echo "Running tests..."
./$TEST_EXECUTABLE

echo "Generating gcov files..."
gcov -o . $SOURCE_FILES

echo "Creating coverage report, excluding test file..."
mkdir -p $OUTPUT_DIR
gcovr --root . --html --html-details --exclude "$TEST_FILE" -o $OUTPUT_DIR/coverage_report.html

echo "Cleaning up coverage files..."
rm -f *.gcda *.gcno *.gcov

echo "Coverage report generated at $OUTPUT_DIR/coverage_report.html"
