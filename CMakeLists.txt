cmake_minimum_required(VERSION 3.10)
project(code)

set(CMAKE_CXX_STANDARD 17)

add_executable(code main.cpp src/medium/StringToInteger_8.cpp src/medium/StringToInteger_8.h src/easy/ReverseInteger_7.cpp src/easy/ReverseInteger_7.h src/easy/PalindromeNumber_9.cpp src/easy/PalindromeNumber_9.h src/hard/RegularExpressionMatching_10.h src/algorithm/sort/QuickSort.h src/Common.cpp src/Common.h src/algorithm/sort/ShellSort.h src/algorithm/sort/SelectionSort.h src/algorithm/structure/BinaryHeap.h src/algorithm/Comparable.h src/data_structure/line_table/LinkedList.h src/data_structure/graph/Graph.h src/pat/A_Plus_B_Format_1.h "src/pat/A_Plus_B_For_Polynomials_2.h")