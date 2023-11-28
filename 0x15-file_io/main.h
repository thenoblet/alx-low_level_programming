#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>

#define BUFFER_SIZE 1024


ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void copy(int fd_from, int fd_to, char *buffer, const char *src, const char *dest);

/* advanced task helper funcs */
void check_elf(unsigned char *e_ident);
void handle_magic(unsigned char *e_ident);
void handle_class(unsigned char *e_ident);
void handle_data(unsigned char *e_ident);
void handle_version(unsigned char *e_ident);
void handle_abi(unsigned char *e_ident);
void handle_osabi(unsigned char *e_ident);
void handle_type(unsigned int e_type, unsigned char *e_ident);
void handle_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf_fd);
void print_usage(void);

#endif /* FILE_H */
