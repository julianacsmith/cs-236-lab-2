cmake_minimum_required(VERSION 3.16.3)
project(cs_236_lab_1)

set(CMAKE_CXX_STANDARD 14)

include_directories("Project-1-Code (1)")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

add_executable(cs_236_lab_1
        "Project-1-Code/Automaton.h"
        "Project-1-Code/ColonAutomaton.cpp"
        "Project-1-Code/ColonAutomaton.h"
        "Project-1-Code/ColonDashAutomaton.cpp"
        "Project-1-Code/ColonDashAutomaton.h"
        "Project-1-Code/Lexer.cpp"
        "Project-1-Code/Lexer.h"
        "Project-1-Code/main.cpp"
        "Project-1-Code/Token.cpp"
        "Project-1-Code/Token.h"
        "Project-1-Code/CommaAutomaton.h"
        "Project-1-Code/CommaAutomaton.cpp"
        "Project-1-Code/QMarkAutomaton.h"
        "Project-1-Code/QMarkAutomaton.cpp"
        "Project-1-Code/PeriodAutomaton.h"
        "Project-1-Code/PeriodAutomaton.cpp" "Project-1-Code/LeftParenAutomaton.h" "Project-1-Code/LeftParenAutomaton.cpp" "Project-1-Code/RightParenAutomaton.h" "Project-1-Code/RightParenAutomaton.cpp" "Project-1-Code/MultiplyAutomaton.h" "Project-1-Code/MultiplyAutomaton.cpp" "Project-1-Code/AddAutomaton.h" "Project-1-Code/AddAutomaton.cpp" "Project-1-Code/SchemesAutomaton.h" "Project-1-Code/SchemesAutomaton.cpp" "Project-1-Code/FactsAutomaton.h" "Project-1-Code/FactsAutomaton.cpp" "Project-1-Code/RulesAutomaton.h" "Project-1-Code/QueriesAutomaton.h" "Project-1-Code/RulesAutomaton.cpp" "Project-1-Code/QueriesAutomaton.cpp" "Project-1-Code/IDAutomaton.h" "Project-1-Code/IDAutomaton.cpp" "Project-1-Code/StringAutomaton.h" "Project-1-Code/StringAutomaton.cpp" "Project-1-Code/EOFAutomaton.h" "Project-1-Code/CommentAutomaton.h" "Project-1-Code/CommentAutomaton.cpp" "Project-1-Code/UndefinedAutomaton.h" "Project-1-Code/UndefinedAutomaton.cpp" "Project-1-Code/EOFAutomaton.cpp")
