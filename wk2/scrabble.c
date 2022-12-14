#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

void print_winner(int score1, int score2);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //Print winner
    print_winner(score1, score2);
}

int compute_score(string word)
{
    int total = 0;

    // Look through each letter
    for (int i = 0, l = strlen(word); i < l; i++)
    {
        //If lower case
        if (word[i] >= 96 && word[i] <= 122)
        {
            total += POINTS[word[i] - 97];
        }
        //If upper case
        else if (word[i] >= 64 && word[i] <= 90)
        {
            total += POINTS[word[i] - 65];
        }
    }

    return total;
}

void print_winner(int score1, int score2)
{
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
    
    printf("\n");
}
