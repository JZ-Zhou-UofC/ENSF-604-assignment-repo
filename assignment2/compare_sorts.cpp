/*
 *  compare_sorts.cpp
 *  ENSF 694 Lab 2 Exercise E
 * Created by Mahmood Moussavi
 *  Completed by: John Zhou
 */

#include "compare_sorts.h"
void to_lower(char *str)
{
    while (*str)
    {
        *str = std::tolower(*str);
        ++str;
    }
}

void strip_punctuation(char *word)
{
    int i = 0, j = 0;
    while (word[i])
    {
        if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z') || word[i] == '-' || (word[i] >= '0' && word[i] <= '9'))
        {
            word[j] = word[i];
            j++;
        }
        i++;
    }
    word[j] = '\0';
}

bool is_unique(char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int num_words, const char *word)
{
    for (int i = 0; i < num_words; i++)
    {
        if (std::strcmp(words[i], word) == 0)
        {
            return false;
        }
    }
    return true;
}

void quicksort(int *indices, char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int left, int right)
{
    if (left >= right)
        return;
    int pivot = indices[right];
    int i = left;
    for (int j = left; j <= right - 1; j++)
    {

        if (strcmp(words[indices[j]], words[pivot]) < 0)
        {

            std::swap(indices[i], indices[j]);
            i++;
        }
    }

    std::swap(indices[i], indices[right]);
    int pivotPoint = i;
    quicksort(indices, words, left, pivotPoint - 1);
    quicksort(indices, words, pivotPoint + 1, right);
}

void shellsort(int *indices, char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int size)
{

    for (int gap = size / 2; gap > 0; gap /= 2)
    {

        for (int i = gap; i < size; i++)
        {

            int temp = indices[i];
            int j = i;

            while (j >= gap && std::strcmp(words[indices[j - gap]], words[temp]) > 0)
            {
                indices[j] = indices[j - gap];
                j -= gap;
            }

            indices[j] = temp;
        }
    }
}

void bubblesort(int *indices, char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (std::strcmp(words[indices[j]], words[indices[j + 1]]) > 0)
            {

                std::swap(indices[j], indices[j + 1]);
            }
        }
    }
}

void read_words(const char *input_file, char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int &num_words)
{
    std::ifstream infile(input_file);
    if (!infile)
    {
        std::cerr << "Error opening input file.\n";
        exit(1);
    }

    char word[MAX_WORD_SIZE + 1];
    num_words = 0;

    while (infile >> word)
    {
        strip_punctuation(word);
        to_lower(word);
        if (word[0] != '\0' && num_words < MAX_UNIQUE_WORDS && is_unique(words, num_words, word))
        {
            std::strncpy(words[num_words++], word, MAX_WORD_SIZE);
        }
    }

    infile.close();
}

void write_words(const char *output_file, char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int *indices, int num_words)
{
    std::ofstream outfile(output_file);
    if (!outfile)
    {
        std::cerr << "Error opening output file.\n";
        exit(1);
    }

    for (int i = 0; i < num_words; ++i)
    {
        outfile << words[indices[i]] << '\n';
    }

    outfile.close();
}

void sort_and_measure_quicksort(char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int *indices, int num_words, void (*sort_func)(int *, char[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int, int), const char *sort_name)
{
    auto start = std::chrono::high_resolution_clock::now();
    sort_func(indices, words, 0, num_words - 1);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_taken = end - start;
    std::cout << sort_name << " completed in " << time_taken.count() << " seconds.\n";
}

void sort_and_measure_shell_bubble(char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int *indices, int num_words, void (*sort_func)(int *, char[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int), const char *sort_name)
{
    auto start = std::chrono::high_resolution_clock::now();
    sort_func(indices, words, num_words);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_taken = end - start;
    std::cout << sort_name << " completed in " << time_taken.count() << " seconds.\n";
}

int main()
{
    const char *input_file = "C:\\Users\\john2\\OneDrive\\Desktop\\uofc\\c\\ENSF-604-assignment-repo\\assignment2\\input.txt";

    char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE];
    int num_words;

    read_words(input_file, words, num_words);

    int indices[num_words];
    for (int i = 0; i < num_words; ++i)
    {
        indices[i] = i;
    }

    sort_and_measure_quicksort(words, indices, num_words, quicksort, "Quick Sort");
    write_words("C:\\Users\\john2\\OneDrive\\Desktop\\uofc\\c\\ENSF-604-assignment-repo\\assignment2\\output_quicksort.txt", words, indices, num_words);

    sort_and_measure_shell_bubble(words, indices, num_words, shellsort, "Shell Sort");
    write_words("C:\\Users\\john2\\OneDrive\\Desktop\\uofc\\c\\ENSF-604-assignment-repo\\assignment2\\output_shellsort.txt", words, indices, num_words);

    sort_and_measure_shell_bubble(words, indices, num_words, bubblesort, "Bubble Sort");
    write_words("C:\\Users\\john2\\OneDrive\\Desktop\\uofc\\c\\ENSF-604-assignment-repo\\assignment2\\output_bubblesort.txt", words, indices, num_words);

    return 0;
}
