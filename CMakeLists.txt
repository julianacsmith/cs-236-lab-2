cmake_minimum_required(VERSION 3.16.3)
project(cs_236_lab_1)

set(CMAKE_CXX_STANDARD 14)

include_directories("Project1_Starter_Code (1)")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

add_executable(cs_236_lab_1
        "Project1_Starter_Code (1)/Automaton.h"
        "Project1_Starter_Code (1)/ColonAutomaton.cpp"
        "Project1_Starter_Code (1)/ColonAutomaton.h"
        "Project1_Starter_Code (1)/ColonDashAutomaton.cpp"
        "Project1_Starter_Code (1)/ColonDashAutomaton.h"
        "Project1_Starter_Code (1)/Lexer.cpp"
        "Project1_Starter_Code (1)/Lexer.h"
        "Project1_Starter_Code (1)/main.cpp"
        "Project1_Starter_Code (1)/Token.cpp"
        "Project1_Starter_Code (1)/Token.h" "Project1_Starter_Code (1)/CommaAutomaton.h" "Project1_Starter_Code (1)/CommaAutomaton.cpp" "Project1_Starter_Code (1)/QMarkAutomaton.h" "Project1_Starter_Code (1)/QMarkAutomaton.cpp" "Project1_Starter_Code (1)/PeriodAutomaton.h" "Project1_Starter_Code (1)/PeriodAutomaton.cpp" "Project1_Starter_Code (1)/LeftParenAutomaton.h" "Project1_Starter_Code (1)/LeftParenAutomaton.cpp" "Project1_Starter_Code (1)/RightParenAutomaton.h" "Project1_Starter_Code (1)/RightParenAutomaton.cpp" "Project1_Starter_Code (1)/MultiplyAutomaton.h" "Project1_Starter_Code (1)/MultiplyAutomaton.cpp" "Project1_Starter_Code (1)/AddAutomaton.h" "Project1_Starter_Code (1)/AddAutomaton.cpp" "Project1_Starter_Code (1)/SchemeAutomaton.h" "Project1_Starter_Code (1)/SchemesAutomaton.h" "Project1_Starter_Code (1)/SchemesAutomaton.cpp" "Project1_Starter_Code (1)/FactsAutomaton.h" "Project1_Starter_Code (1)/FactsAutomaton.cpp" "Project1_Starter_Code (1)/RulesAutomaton.h" "Project1_Starter_Code (1)/QueriesAutomaton.h" "Project1_Starter_Code (1)/RulesAutomaton.cpp" "Project1_Starter_Code (1)/QueriesAutomaton.cpp" "Project1_Starter_Code (1)/IDAutomaton.h" "Project1_Starter_Code (1)/Lab1PassOffCases/IDAutomaton.cpp" "Project1_Starter_Code (1)/IDAutomaton.cpp" "Project1_Starter_Code (1)/StringAutomaton.h" "Project1_Starter_Code (1)/StringAutomaton.cpp" "Project1_Starter_Code (1)/EOFAutomaton.h" "Project1_Starter_Code (1)/CommentAutomaton.h" "Project1_Starter_Code (1)/CommentAutomaton.cpp" "Project1_Starter_Code (1)/UndefinedAutomaton.h" "Project1_Starter_Code (1)/UndefinedAutomaton.cpp" "Project1_Starter_Code (1)/EOFAutomaton.cpp")
