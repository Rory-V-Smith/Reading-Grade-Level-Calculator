#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float index(float l, float s);

int main(void)
{
    // prompt user for input using get_string
    string text = get_string("text: ");
    printf("%s\n", text);

    // prints number of letters in text
    float letter_count = 0, word_count = 1, sentence_count = 0;
    float text_length = strlen(text);

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // counts number of letters in text
        if (isalpha(text[i]))
        {
            letter_count++;
        }

        // counts number of words in text
        if (text[i] == ' ')
        {
            word_count++;
        }

        // counts number of sentances in text
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;
        }
    }

    // average number of letters per 100 words in text
    float l = letter_count / word_count * 100;

    // average number of sentences per 100 words in text
    float s = sentence_count / word_count * 100;

    // print grade level
    int grade = index(l, s);
    if (grade < 1)
    {
        printf("before grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade: 16+\n");
    }
    else
    {
        printf("Grade: %i\n", grade);
    }
}

// Coleman-Liau index function
float index(float l, float s)
{
    float grade = 0.0588 * l - 0.296 * s - 15.8;
    return round(grade);
}
