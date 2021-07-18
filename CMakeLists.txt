cmake_minimum_required(VERSION 3.19)
project(now_leet_code_practice)

set(CMAKE_CXX_STANDARD 14)

add_executable(now_leet_code_practice
        linkded_list/singly_linked_list.cpp
        linkded_list/doubly_linked_list.cpp
        linkded_list/circular_linked_lsit.cpp linkded_list/merge_two_list.cpp "linkded_list/4_Intersection of Two Linked Lists.cpp" "linkded_list/5_Remove Linked List Elements.cpp" "linkded_list/6_Reverse Linked List.cpp" "linkded_list/7_Palindrome Linked List.cpp" "linkded_list/8_Delete Node in a Linked List.cpp" "linkded_list/9_Design HashSet.cpp")

target_link_libraries(now_leet_code_practice)