
#include "header.hpp"


int main(int argc, char **argv) {
    const char *buf_name = "bufer.txt";
    size_t count = 0;
    size_t sum = 0;
    size_t *len = new size_t[200];
    if (argc == 1) {
        write_file(buf_name, count, len);
        std::ifstream file(buf_name);
        for (int i = 0; i < count; ++i) {
            sum += len[i];
        }
        char *text = new char[sum];
        file.getline(text, sum + 1);
        nine(text, count, len);
        size_t cur = 0;
        size_t start[count];
        size_t end[count];
        start[0] = 0;
        for (size_t i = 1; i < count; ++i) {
            cur += len[i - 1];
            start[i] = cur;
            end[i - 1] = start[i - 1] + len[i - 1];
        }
        end[count - 1] = start[count - 1] + len[count - 1];
        cout << "--------------------------------------------------"
                "-------------------------------------------------\n";
        cout << "Answer:\n";
        res_print(text, count, len, start, end);
        remove(buf_name);
        delete[] text;
    } else if (argc == 3) {
        if (strcmp(argv[1], "--fromfile") == 0) {
            const char *from_name = argv[2];
            std::ifstream file(from_name);
            if (!file.is_open()) {
                std::cerr << "ERROR";
                return EXIT_FAILURE;
            }
            size_t cur = 1;
            char f = '\0';
            while (file.get(f)) {//считываем строку
                if (f != '\n' && f != 13) {
                    cur++;
                    if (f == '.') {
                        len[count] = cur;
                        sum += cur;
                        count++;
                        cur = 0;
                    }
                }
            }
            file.close();
            std::ifstream file_t(from_name);
            char *text = new char[sum];
            size_t index = 1;
            while (file_t.get(f)) {//считываем строку
                if (f != '\n' && f != 13) {
                    text[index] = f;
                    index++;
                }
            }
            nine(text, count, len);
            text[0] = ' ';
            cur = 0;
            size_t start[count];
            size_t end[count];
            start[0] = 0;
            for (size_t i = 1; i < count; ++i) {
                cur += len[i - 1];
                start[i] = cur;
                end[i - 1] = start[i - 1] + len[i - 1];
            }
            end[count - 1] = start[count - 1] + len[count - 1];
            cout << "--------------------------------------------------"
                    "-------------------------------------------------\n";
            cout << "Answer:\n";
            res_print(text, count, len, start, end);
            delete[] text;
        } else if (strcmp(argv[1], "--tofile") == 0) {
            const char *to_name = argv[2];
            write_file(buf_name, count, len);
            std::ifstream file(buf_name);
            for (int i = 0; i < count; ++i) {
                sum += len[i];
            }
            char *text = new char[sum];
            file.getline(text, sum + 1);
            nine(text, count, len);
            size_t cur = 0;
            size_t start[count];
            size_t end[count];
            start[0] = 0;
            for (size_t i = 1; i < count; ++i) {
                cur += len[i - 1];
                start[i] = cur;
                end[i - 1] = start[i - 1] + len[i - 1];
            }
            end[count - 1] = start[count - 1] + len[count - 1];
            cout << "--------------------------------------------------"
                    "-------------------------------------------------\n";
            cout << "Answer in " << to_name << std::endl;
            file_res_print(text, count, len, start, end, to_name);
            remove(buf_name);
            delete[] text;
        } else {
            std::cerr << "Enter the correct flags\n";
            return EXIT_FAILURE;
        }

    } else if (argc == 5) {
        const char *from_name = argv[2];
        char *to_name = argv[4];
        if (strcmp(argv[1], "--fromfile") == 0 && strcmp(argv[3], "--tofile") == 0) {
            from_name = argv[2];
            to_name = argv[4];
        } else if (strcmp(argv[3], "--fromfile") == 0 && strcmp(argv[1], "--tofile") == 0) {
            from_name = argv[4];
            to_name = argv[2];
        } else {
            std::cerr << "Enter the correct flags\n";
            return EXIT_FAILURE;
        }
        std::ifstream file(from_name);
        if (!file.is_open()) {
            std::cerr << "ERROR";
            return EXIT_FAILURE;
        }
        size_t cur = 1;
        char f = '\0';
        while (file.get(f)) {//считываем строку
            if (f != '\n' && f != 13) {
                cur++;
                if (f == '.') {
                    len[count] = cur;
                    sum += cur;
                    count++;
                    cur = 0;
                }
            }
        }
        file.close();
        std::ifstream file_t(from_name);
        char *text = new char[sum];
        size_t index = 1;
        while (file_t.get(f)) {//считываем строку
            if (f != '\n' && f != 13) {
                text[index] = f;
                index++;
            }
        }
        text[0] = ' ';
        nine(text, count, len);
        cur = 0;
        size_t start[count];
        size_t end[count];
        start[0] = 0;
        for (size_t i = 1; i < count; ++i) {
            cur += len[i - 1];
            start[i] = cur;
            end[i - 1] = start[i - 1] + len[i - 1];
        }
        end[count - 1] = start[count - 1] + len[count - 1];
        cout << "--------------------------------------------------"
                "-------------------------------------------------\n";
        cout << "Answer:\n";
        file_res_print(text, count, len, start, end, to_name);
        delete[] text;
    }
    delete[] len;
    return 0;
}
