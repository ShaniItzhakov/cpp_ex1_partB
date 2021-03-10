#include "snowman.hpp"
#include <string>
#include <array>

const int HAT = 0;
const int NOSE = 1;
const int LEFT_EYE = 2;
const int RIGHT_EYE = 3;
const int LEFT_ARM = 4;
const int RIGHT_ARM = 5;
const int TORSO = 6;
const int BASE = 7;
const int MIN_INPUT = 11111111;
const int MAX_INPUT = 44444444;
const int BASE_TEN = 10;
const int NUM_OF_DIGITS = 8;

// Matrix that holds the snowman body parts.
const array<array<string, 4>, 8> matrix = {{
    {" _===_", "  ___\n .....", "   _\n  /_\\", "  ___\n (_*_)"},
    {",", ".", "_", " "},
    {"(.", "(o", "(O", "(-"},
    {".)", "o)", "O)", "-)"},
    {" <", "\\ ", " /", "  "},
    {" >", "/ ", " \\", "  "},
    {"( : )", "(] [)", "(> <)", "(   )"},
    {" ( : )", " (\" \")", " (___)", " (   )"}}};

/**
 * Returns true if the number received is valid.
 * It checks if the range is between 11111111 and 44444444,
 * and that each digit is between 1 and 4, otherwise returns false.
 */
bool is_valid_number(int number) {
    if (number < MIN_INPUT || number > MAX_INPUT) {
        return false;
    }
    while (number != 0) {
        int curr_digit = number % BASE_TEN;
        if (curr_digit < 1 || curr_digit > 4) {
            return false;
        }    
        number /= BASE_TEN;
    }
    return true;
}

/**
 * Returns the expected snowman as a string for the input received.
 * It uses an array to store each digit from the received input.
 * Uses Mathmetical principle to split the number from right to left and insert into the digits array.
 * Gets from the matrix that contains the snowman body parts in the right order and concat it to the expected string. 
 */
string build_snowman(int input) {
    string snowman;
    int number = input;
    array<int, NUM_OF_DIGITS> digits = {0};
    for (int i = 0; i < NUM_OF_DIGITS; i++) {
        int current_digit = NUM_OF_DIGITS-1-i;
        digits.at(current_digit) = number % BASE_TEN;
        number /= BASE_TEN;
    }
    // HHHHH - hat
    snowman += matrix[HAT][digits[HAT]-1];
    snowman += "\n";

    // X[0] - left upper arm
    snowman += matrix[LEFT_ARM][digits[LEFT_ARM]-1][0];
   
    // (L - left eye
    snowman += matrix[LEFT_EYE][digits[LEFT_EYE]-1];
   
    // N - nose
    snowman += matrix[NOSE][digits[NOSE]-1];
   
    // R) - right eye
    snowman += matrix[RIGHT_EYE][digits[RIGHT_EYE]-1];
   
    // Y[0] - right upper arm
    snowman += matrix[RIGHT_ARM][digits[RIGHT_ARM]-1][0];
    snowman += "\n";
   
    // X[1] - left lower arm
    snowman += matrix[LEFT_ARM][digits[LEFT_ARM]-1][1];
   
    // (TTT) - torso
    snowman += matrix[TORSO][digits[TORSO]-1];
   
    // Y[1] - lower right arm
    snowman += matrix[RIGHT_ARM][digits[RIGHT_ARM]-1][1];
    snowman += "\n";
   
    // (BBB) - base
    snowman += matrix[BASE][digits[BASE]-1];
    snowman += "\n";
    return snowman;
}

/**
 * Returns the expected snowman as a string for the input received.
 * It is the main snowman function, checks if the input is a valid number.
 */
string ariel::snowman(int input) {
     if (!is_valid_number(input)) {
        string msg = "Invalid code '" + to_string(input) + "'";
        throw invalid_argument(msg);
    }
    return build_snowman(input);
}