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
    bool in_set;
    int index;
} s_elem;

int longest_substring(std::string s) {

    int size_string = s.size();
    std::map<char, s_elem> my_table;

    int max_index = 0;

    //Scan for largest substring
    int longest_substring_size = 0;
    for(int i = 0; i < size_string; ++i) {
        bool there_is_duplicate = false;

        int l_index = i;
        int curr_index = max_index;

        while(!there_is_duplicate && curr_index < size_string) {
            char check_char = s[curr_index];

            if(my_table[check_char].in_set && my_table[check_char].index >= l_index) {
                there_is_duplicate = true;
            }
            else {
                my_table[check_char].in_set = true;
                my_table[check_char].index = curr_index;
                curr_index++;
            }

            if(max_index < curr_index) {
                max_index = curr_index;
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
