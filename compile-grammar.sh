#!/bin/bash

current_directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

grammar_directory="$current_directory/src/grammar"

java -jar "$current_directory/bin/antlr-4.9.1-complete.jar" -Dlanguage=Cpp -no-listener -visitor -o "$grammar_directory/runtime" "$grammar_directory/FooLexer.g4" "$grammar_directory/FooParser.g4"
