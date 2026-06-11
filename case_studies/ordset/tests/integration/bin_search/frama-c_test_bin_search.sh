#!/bin/bash
set -e

CRITERIA=("ADC" "AUC" "CACC" "CC" "DC" "DUC" "GACC" "GICC" "MCC" "STMT")
SOURCE_FILE="bin_search.c"
DRIVER_FILE="test_bin_search.c"
REQUIRED_FILES=""
INCLUDE_FOLDER="."
TARGET_FUNCTION="bin_search"

if command -v opam >/dev/null 2>&1; then
  eval "$(opam env)"
fi

for criterion in "${CRITERIA[@]}"; do
  echo "Processing criterion: $criterion"

  frama-c -no-annot -lannot="$criterion" -annot -kernel-warn-key annot-error -variadic-no-translation "$SOURCE_FILE" -lannot-functions "$TARGET_FUNCTION"

  LABEL_SOURCE="${SOURCE_FILE%.c}_labels.c"
  LABEL_FILE="${SOURCE_FILE%.c}_labels.labels"
  REPLAY_LABEL="${SOURCE_FILE%.c}.labels"

  frama-c -luncov-eva -eva-precision 11 -eva-verbose 0 "$LABEL_SOURCE" -main "$TARGET_FUNCTION"

  if [ -f "$LABEL_FILE" ]; then
    mv "$LABEL_FILE" "$REPLAY_LABEL"
  fi

  if [ -n "$REQUIRED_FILES" ]; then
    lreplay "$SOURCE_FILE" -drivers "$DRIVER_FILE" -compil-files "$REQUIRED_FILES" -compil-includes "$INCLUDE_FOLDER" 2>>./lreplay_replace.txt
  else
    lreplay "$SOURCE_FILE" -drivers "$DRIVER_FILE" -compil-includes "$INCLUDE_FOLDER" 2>>./lreplay_replace.txt
  fi

  mkdir -p "$criterion"
  mv "$REPLAY_LABEL" "$criterion"/ 2>/dev/null || true
  mv *equiv-in.txt "$criterion"/ 2>/dev/null || true
  mv *_labels.c "$criterion"/ 2>/dev/null || true
  mv lreplay_* "$criterion"/ 2>/dev/null || true

  echo "Completed processing for criterion: $criterion"
done
