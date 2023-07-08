#pragma once

int lcslen(const char[], const char[], const int, const int);

int dynamic_lcslen(const char[], const char[], const int m, const int n,
                   char[m + 1][n + 1]);

void _find_lcs(const int m, const int n, const int i, const int j, const int l,
               char result[m], int *result_index, const char b[m + 1][n + 1],
               const char x[m]);

void print_lcs(const int m, const int n, const int i, const int j,
               char b[m + 1][n + 1], const char x[m]);
