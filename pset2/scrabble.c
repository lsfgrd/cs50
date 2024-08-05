#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int get_score(string input);

const int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string p1_input = get_string("Player 1: ");
    string p2_input = get_string("Player 2: ");

    int p1_score = get_score(p1_input);
    int p2_score = get_score(p2_input);

    if (p1_score > p2_score)
    {
        printf("Player 1 wins!");
    }
    else if (p1_score < p2_score)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
}

int get_score(string input)
{
    int input_length = strlen(input);
    int score = 0;

    for (int i = 0; i < input_length; i++)
    {
        char lowercase_char = tolower(input[i]);
        score += POINTS[lowercase_char - 'a'];
    }

    return score;
}
