#pragma once

int lcslen(const char[], const char[], const int, const int);

int dynamic_lcslen(const char[], const char[], const int m, const int n,
                   char[m + 1][n + 1]);

void find_lcs(const int m, const int n, const char l, char result[l],
              const char b[m + 1][n + 1], const char x[m]);
