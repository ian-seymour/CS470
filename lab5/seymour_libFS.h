#ifndef LIBFS_H
#define LIBFS_H

#include <stdio.h>

// functinos
void createFile(const char* filename);
FILE* openFile(const char* filename, const char* mode);
void writeFile(FILE* file, const char* data);
void readFile(FILE* file);
void closeFile(FILE* file);
void removeFile(const char* filename);

#endif
