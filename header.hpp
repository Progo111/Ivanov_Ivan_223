
#ifndef MAIN_CPP_HEADER_HPP
#define MAIN_CPP_HEADER_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>

using std::cin;
using std::cout;

void write_file(const char *, size_t &, size_t *&len);

void res_print(char *, size_t , size_t len[], size_t start[], size_t end[]);

void nine(const char *, const size_t, const size_t len[]);

void file_res_print(char *, size_t, size_t len[], size_t start[], size_t end[], const char *);

#endif //MAIN_CPP_HEADER_HPP
