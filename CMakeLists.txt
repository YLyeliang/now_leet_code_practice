cmake_minimum_required(VERSION 3.19)
project(now_leet_code_practice)

set(CMAKE_CXX_STANDARD 14)

add_executable(now_leet_code_practice
        #        linkded_list/singly_linked_list.cpp
        #        linkded_list/doubly_linked_list.cpp
        #        linkded_list/circular_linked_lsit.cpp linkded_list/merge_two_list.cpp "linkded_list/4_Intersection of Two Linked Lists.cpp" "linkded_list/5_Remove Linked List Elements.cpp" "linkded_list/6_Reverse Linked List.cpp" "linkded_list/7_Palindrome Linked List.cpp" "linkded_list/8_Delete Node in a Linked List.cpp" "linkded_list/9_Design HashSet.cpp" "linkded_list/10_Middle of the Linked List.cpp" "linkded_list/11_Convert Binary Number in a Linked List to Integer.cpp" "linkded_list/12_Remove Nth Node From End of List.cpp" "linkded_list/13_Swap Nodes in Pairs.cpp" "linkded_list/14_Rotate list.cpp" "linkded_list/15_Remove Duplicates from Sorted List II.cpp"
        #        linkded_list/simple_list.cpp "tree/1_Path sum II.cpp" "array/1_Plus One.cpp" "array/2_Merge sorted array.cpp"
        #        "array/3_pascal triangle.cpp" "array/4_Pascal triangleII.cpp" "array/5_Best time to buy and sell stock II.cpp"
        #        "array/6_single number.cpp" "array/7_Two sum II.cpp" "array/8_Majority Element.cpp" "array/9_Count Primes.cpp" "array/10_Contains Duplicate.cpp" "array/11_Contains Duplicate II.cpp" "array/12_Summary ranges.cpp" "array/13_Missing Number.cpp"
        #        "array/14_Move Zeroes.cpp" "array/15_Intersection of Two Arrays.cpp" "array/16_Intersection of Two Arrays II.cpp"
        #        "array/ 17_Third Maximum Number.cpp"
        #        "array/18_Find All Numbers Disappeared in an Array.cpp" "array/19_Minimum Moves to Equal Array Elements.cpp"
        #        "array/20_Assign cookies.cpp" "array/21_Container With Most Water.cpp" array/22_3sum.cpp "array/23_3sum closest.cpp"
        #        array/24_4sum.cpp string/1_longest_common_prefix.cpp string/2_length_of_last_word.cpp string/3_add_binary.cpp
        #        string/4_valid_palindrome.cpp
        #        string/5_excel_sheet_column_title.cpp "string/6_Excel Sheet Column Number.cpp" string/7_isomorphic_strings.cpp string/8_valid_Anagram.cpp string/9_word_pattern.cpp string/10_reverse_string.cpp string/11_reverse_vowels_of_a_string.cpp
        #        string/12_random_note.cpp string/13_first_unique_character_in_string.cpp string/14_find_the_difference.cpp
        #        string/15_longest_palindrome.cpp string/16_Fizz_Buzz.cpp string/17_add_string.cpp string/18_number_of_segments_in_string.cpp
        #        string/19_repeated_substring_pattern.cpp
        #        string/20_keyboard_row.cpp string/21_student_attendance_record_I.cpp string/22_reverse_words_in_string_III.cpp string/23_minimum_index_sum_of_two_lists.cpp string/24_valid_palindrome_II.cpp Dynamic_program/4_1_jump_games.cpp Dynamic_program/4_2_jump_gamesII.cpp Dynamic_program/5_1_maximum_subarray.cpp
        #        "Dynamic_program/5_2_Maximum Sum Circular Subarray.cpp" "Dynamic_program/6_2_Maximum Length of Subarray With Positive Product.cpp" "Dynamic_program/7_1_Best Sightseeing Pair.cpp" Dynamic_program/7_3_best_time_to_buy_and_sell_stock_II.cpp Dynamic_program/8_1_word_break.cpp
        #        Dynamic_program/8_2_Trapping_rain_water.cpp Dynamic_program/9_1_arithmetic_slices.cpp Dynamic_program/9_2_decode_ways.cpp Dynamic_program/10_2_ugly_number_II.cpp Dynamic_program/10_3_unique_binary_search_trees.cpp Dynamic_program/11_1_pascal_triangle.cpp Dynamic_program/11_2_pascal_triangle_II.cpp Dynamic_program/12_1_minimum_falling_path_sum.cpp Dynamic_program/12_2_Triangle.cpp array/25_subarray_sum_equals_k.cpp
        #        array/25_longest_substring_without_repeating_characters.cpp
        #        "Dynamic_program/10_4_Unique Binary Search Trees II.cpp" "Dynamic_program/13_1_matrix block sum.cpp" "Dynamic_program/13_2_range sum query mutable.cpp" linkded_list/16_Partition_list.cpp linkded_list/6_Reverse_linked_list_II.cpp linkded_list/17_convert_sorted_list_to_BST.cpp linkded_list/18_Flatten_binary_tree_to_linked_list.cpp linkded_list/19_copy_list_with_random_pointer.cpp
        #        top100/m_letter_combinations_of_a_phone_number.cpp top100/m_generate_parentheses.cpp "top100/m_Search in Rotated Sorted Array.cpp" "top100/m_Find First and Last Position of Element in Sorted Array.cpp" "top100/m_Combination sum.cpp"
        #        backtrack/m_permutations.cpp backtrack/m_subsets.cpp backtrack/m_subsets_II.cpp backtrack/m_permutations_II.cpp "backtrack/m_combination sum II.cpp"
        #        "backtrack/m_palindrome partitioning.cpp"
        #        test/test.cpp
        #        "top100/m_search 2D matrix.cpp"
        #        "top_interview/h_largest rectangle in histogram.cpp"
#        "top100/m_Longest Consecutive Sequence.cpp"
        test/thread_test.cpp
        )

target_link_libraries(now_leet_code_practice)