#include "header.hpp"

void write_file(const char *name, size_t &count, size_t *&len) {
    std::ofstream file(name, std::ios_base::out | std::ios_base::trunc);
    file.clear();
    std::noskipws(cin);
    size_t cur_len = 0;
    char symb = '\0';
    file << " ";
    while (cin.peek() != EOF) {
        for (;;) {
            if (cin.peek() == '\n') {
                break;
            }
            cin >> symb;
            ++cur_len;
            file << symb;
            if (symb == '.') {
                len[count] = cur_len;
                ++count;
                cur_len = 0;
            }
        }
        cin >> symb;
    }
    len[0]++;
    file.close();
}

void res_print(char *text, size_t count, size_t len[], size_t start[], size_t end[]) {
    for (size_t i = 0; i < count - 1; ++i) {
        for (size_t j = count - 1; j > i; --j) {
            if (len[j - 1] > len[j]) {
                std::swap(len[j - 1], len[j]);
                std::swap(start[j - 1], start[j]);
                std::swap(end[j - 1], end[j]);
            }
        }
    }

    for (size_t i = 0; i < count; ++i) {
        for (size_t j = start[i]; j < end[i]; ++j) {
            cout << text[j];
        }
        cout << "\n";
    }
}

void nine(const char *text, const size_t count, const size_t len[]) {
    std::ofstream file_b("NINE.txt", std::ios_base::out | std::ios_base::trunc);
    size_t number_of_ms = 0, dought_index1 = 1, len_max = 0;
    for (size_t i = 0; i < count; ++i) {
        if (len[i] > len_max) {
            number_of_ms = i;
            len_max = len[i];
        }
    }
    len_max--;
    for (size_t i = 0; i < number_of_ms; ++i) {
        dought_index1 += len[i];
    }
    char NINE[len_max];
    size_t count_word = 0, cur_word = 0;
    int j = 0;
    for (int i = dought_index1; i < dought_index1 + len_max; ++i) {
        if (text[i] == ' ' || text[i] == '.') {
            count_word++;
        }
        NINE[j] = text[i];
        j++;
    }
    NINE[len_max - 1] = ' ';
    if (count_word > 1) {
        size_t len_word[count_word];
        size_t start[count_word];
        start[0] = 0;
        j = 0;
        for (int i = 0; i < len_max; i++) {
            cur_word++;
            if (NINE[i] == ' ' || NINE[i] == '.') {
                len_word[j] = cur_word;
                j++;
                if (j < count_word) {
                    start[j] = start[j - 1] + cur_word;
                }
                cur_word = 0;
            }
        }
        for (int i = count_word - 1; i >= 0; i--) {
            for (j = start[i]; j < start[i] + len_word[i]; j++) {
                file_b << NINE[j];
            }
        }
    } else {
        file_b << NINE;
    }
    file_b.close();
}

void file_res_print(char *text, size_t count, size_t len[], size_t start[], size_t end[], const char *file_name) {
    for (size_t i = 0; i < count - 1; ++i) {
        for (size_t j = count - 1; j > i; --j) {
            if (len[j - 1] > len[j]) {
                std::swap(len[j - 1], len[j]);
                std::swap(start[j - 1], start[j]);
                std::swap(end[j - 1], end[j]);
            }
        }
    }
    std::ofstream file(file_name);
    for (size_t i = 0; i < count; ++i) {
        for (size_t j = start[i]; j < end[i]; ++j) {
            file << text[j];
        }
        file << "\n";
    }
}