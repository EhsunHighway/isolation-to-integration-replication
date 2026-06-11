# Replication Package: Case-Study Subjects and Test Scaffolding

This directory contains the subject code and test scaffolding needed to replicate the test executions used in the thesis and publication: "From Isolation to Integration: An Empirical Study on Differences Between Unit and Integration Testing with Applications to C Programs" (DOI: 10.22215/etd/2025-16598).

## Contents

```text
case_studies/
  chachapoly/
    source/
    tests/unit/
    tests/integration/
  ordset/
    source/
    tests/unit/
    tests/integration/
  tcas/
    source/
    tests/unit/
    tests/integration/
```

Each test leaf directory is self-contained: it includes the test driver plus the source and header files needed to compile that driver. Unit-test directories may include stubs; integration-test directories use the non-stubbed collaborators needed by that integration scenario.

Each test leaf directory includes one local script for each workflow:

- `frama-c_*.sh`: Frama-C/LTest execution scripts.
- `gcov_*.sh`: gcov/gcovr coverage execution scripts.
- `mutation_*.sh`: mutation-analysis execution scripts.

## Running The Tests

Run each script from the directory where it is located so that relative source and driver paths resolve correctly. The package keeps one local Frama-C, gcov, and mutation script.

The scripts assume the relevant tools are installed locally:

- gcov scripts: `gcc`, `gcov`, and `gcovr`.
- Frama-C scripts: `frama-c`, `LTest`; `LAnno`, `Luncov` and `lreplay`
- Mutation scripts: `universalmutator`

Test drivers include a commented `exit(1);` line immediately after failure-reporting prints:

```c
// exit(1); // use this for mutation analysis
```

Uncomment that line when a mutation-analysis run should treat a failed assertion as a nonzero process exit.

## Provenance

- `chachapoly`: C implementation of ChaCha/Poly1305 used as an open-source subject, packaged here as the studied source snapshot plus paper-specific test scaffolding.
- `ordset`: C reimplementation of an ordered-set Java subject.
- `tcas`: TCAS subject derived from the Software-artifact Infrastructure Repository (SIR) benchmark.


