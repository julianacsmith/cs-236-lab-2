cmake_minimum_required(VERSION 3.16.3)
project(cs_236_lab_1)

set(CMAKE_CXX_STANDARD 14)

include_directories("Project-1-Code (1)")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

add_executable(cs_236_lab_2
        "Project-2-Code/Automaton.h"
        "Project-2-Code/ColonAutomaton.cpp"
        "Project-2-Code/ColonAutomaton.h"
        "Project-2-Code/ColonDashAutomaton.cpp"
        "Project-2-Code/ColonDashAutomaton.h"
        "Project-2-Code/Lexer.cpp"
        "Project-2-Code/Lexer.h"
        "Project-2-Code/main.cpp"
        "Project-2-Code/Token.cpp"
        "Project-2-Code/Token.h"
        "Project-2-Code/CommaAutomaton.h"
        "Project-2-Code/CommaAutomaton.cpp"
        "Project-2-Code/QMarkAutomaton.h"
        "Project-2-Code/QMarkAutomaton.cpp"
        "Project-2-Code/PeriodAutomaton.h"
        "Project-2-Code/PeriodAutomaton.cpp" "Project-2-Code/LeftParenAutomaton.h" "Project-2-Code/LeftParenAutomaton.cpp" "Project-2-Code/RightParenAutomaton.h" "Project-2-Code/RightParenAutomaton.cpp" "Project-2-Code/MultiplyAutomaton.h" "Project-2-Code/MultiplyAutomaton.cpp" "Project-2-Code/AddAutomaton.h" "Project-2-Code/AddAutomaton.cpp" "Project-2-Code/SchemesAutomaton.h" "Project-2-Code/SchemesAutomaton.cpp" "Project-2-Code/FactsAutomaton.h" "Project-2-Code/FactsAutomaton.cpp" "Project-2-Code/RulesAutomaton.h" "Project-2-Code/QueriesAutomaton.h" "Project-2-Code/RulesAutomaton.cpp" "Project-2-Code/QueriesAutomaton.cpp" "Project-2-Code/IDAutomaton.h" "Project-2-Code/IDAutomaton.cpp" "Project-2-Code/StringAutomaton.h" "Project-2-Code/StringAutomaton.cpp" "Project-2-Code/EOFAutomaton.h" "Project-2-Code/CommentAutomaton.h" "Project-2-Code/CommentAutomaton.cpp" "Project-2-Code/UndefinedAutomaton.h" "Project-2-Code/UndefinedAutomaton.cpp" "Project-2-Code/EOFAutomaton.cpp" Project-2-Code/Parser.cpp Project-2-Code/Parser.h)
