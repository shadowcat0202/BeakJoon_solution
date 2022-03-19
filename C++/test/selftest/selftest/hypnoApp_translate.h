#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <io.h>
#include <cstdio>

bool openfile(std::ifstream& readfile, std::string path);

bool run(std::ifstream& readfile);

char* UTF8ToANSI(const char* pszCode);

char* ANSIToUTF8(const char* pszCode);

