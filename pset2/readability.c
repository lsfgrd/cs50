#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

struct count_result
{
    int sentences;
    int letters;
    int words;
};

struct count_result count(string text);

/*
A number of “readability tests” have been developed over the years that define formulas for
computing the reading level of a text. One such readability test is the Coleman-Liau index. The
Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to
understand some text.

The formula is

index = 0.0588 * L - 0.296 * S - 15.8

where L is the average number of letters per 100 words in the text, and S is the average number of
sentences per 100 words in the text.
*/

int main(void)
{
    string text = get_string("Text: ");

    struct count_result result = count(text);

    float words = (float) result.words;
    float sentences = (float) result.sentences;
    float letters = (float) result.letters;

    float avg_letters = (letters / words) * 100.0;
    float avg_sentences = (sentences / words) * 100.0;

    int index = round(0.0588 * avg_letters - 0.296 * avg_sentences - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

struct count_result count(string text)
{
    struct count_result result;
    result.sentences = 0;
    result.letters = 0;
    result.words = 1;

    int i = 0;

    while (text[i] != '\0')
    {
        if (text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            result.sentences++;
        }
        else if (isspace(text[i]))
        {
            result.words++;
        }
        else if (isalpha(text[i]))
        {
            result.letters++;
        }

        i++;
    }

    return result;
}
