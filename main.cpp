/*
 * main.cpp
 *
 *  Created on: Jun 16, 2021
 *      Author: d-w-h
 */

#include <stdio.h>
#include <string>
#include <map>

typedef struct string_element {
    bool is_stored;
    int index;
} s_elem;

int longest_substring(std::string s) {

    int size_string = s.size();
    std::map<char, s_elem> my_table;

    int curr_index = 0;

    //Scan for largest substring
    int longest_substring_size = 0;
    for(int i = 0; i < size_string; ++i) {
        bool there_is_duplicate = false;
        int l_index = i;

        while(!there_is_duplicate && curr_index < size_string) {
            char check_char = s[curr_index];
            bool char_is_stored = my_table[check_char].is_stored;
            bool index_in_set = my_table[check_char].index >= l_index;
            bool char_in_set = char_is_stored && index_in_set;

            if(char_in_set) {
                there_is_duplicate = true;
            }
            else {
                my_table[check_char].is_stored = true;
                my_table[check_char].index = curr_index;
                curr_index++;
            }

            if((curr_index - l_index) > longest_substring_size) {
                longest_substring_size = curr_index - l_index;
            }
        }
    }

    return longest_substring_size;
}


int main(int argc, char* argv[]) {

	std::string s = "abcabcbb";

    int longest_substring_size = longest_substring(s);

    printf("longest substring size: %i\n", longest_substring_size);
    printf("done\n");

    return 0;
}
