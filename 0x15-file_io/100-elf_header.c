#include "main.h"

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Description:
 * This program reads the ELF header of an ELF file and displays information
 * such as the ELF header, magic number, class, data encoding, version,
 * OS/ABI, ABI version, type, and entry point.
 *
 * Return: 0 on success, or the corresponding error code on failure
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr *header;
	int elf_fd, bytes_read;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	elf_fd = open(argv[1], O_RDONLY);
	if (elf_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(elf_fd);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	bytes_read = read(elf_fd, header, sizeof(Elf64_Ehdr));
	if (bytes_read == -1)
	{
		free(header);
		close_elf(elf_fd);
		dprintf(STDERR_FILENO, "Error: [%s]: No such file\n", argv[1]);
		exit(98);
	}
	check_elf(header->e_ident);
	printf("ELF Header:\n");
	handle_magic(header->e_ident);
	handle_class(header->e_ident);
	handle_data(header->e_ident);
	handle_version(header->e_ident);
	handle_osabi(header->e_ident);
	handle_abi(header->e_ident);
	handle_type(header->e_type, header->e_ident);
	handle_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(elf_fd);
	return (0);
}

/**
 * check_elf - Check if the provided data represents an ELF file
 * @e_ident: The ELF identification bytes
 *
 * Description:
 * This function checks the first four bytes of the ELF identification
 * to determine if the provided data represents a valid ELF file.
 * If the identification bytes are not as expected, it prints an error
 * message and exits the program with an error code.
 *
 * @e_ident: An array containing the ELF identification bytes
 */
void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
			e_ident[index] != 'E' &&
			e_ident[index] != 'L' &&
			e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * handle_magic - Print the ELF magic bytes
 * @e_ident: The ELF identification bytes
 *
 * Description:
 * This function prints the ELF magic bytes, which are the first 16 bytes
 * of the ELF identification. The magic bytes uniquely identify the file
 * as an ELF file.
 *
 */
void handle_magic(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * handle_class - Print the ELF class
 * @e_ident: An array containing the ELF identification bytes
 *
 * Description:
 * This function prints the ELF class, which is specified by the byte at
 * index EI_CLASS in the ELF identification. The ELF class defines whether
 * the file is a 32-bit ELF or a 64-bit ELF.
 *
 */
void handle_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * handle_data - Print the ELF data encoding
 * @e_ident: An array containing the ELF identification bytes
 *
 * Description:
 * This function prints the ELF data encoding, which is specified by
 * the byte at index EI_DATA in the ELF identification.
 * The data encoding defines whether the data is in little-endian
 * or big-endian format.
 */
void handle_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * handle_version - Print the ELF version
 * @e_ident: The ELF identification bytes
 *
 * Description:
 * This function prints the ELF version, which is specified by the byte at
 * index EI_VERSION in the ELF identification. The version is an integer that
 * represents the version of the ELF format being used.
 */
void handle_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
			e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * handle_osabi - Print the ELF OS/ABI
 * @e_ident: The ELF identification bytes
 *
 * Description:
 * This function prints the ELF OS/ABI, which is specified by the byte at
 * index EI_OSABI in the ELF identification. The OS/ABI field identifies the
 * target operating system and ABI (Application Binary Interface).
 */
void handle_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * handle_abi - Print the ELF ABI version
 * @e_ident: The ELF identification bytes
 *
 * Description:
 * This function prints the ELF ABI version, which is specified by the byte at
 * index EI_ABIVERSION in the ELF identification. The ABI version field
 * represents the version of the ABI (Application Binary Interface).
 */
void handle_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
			e_ident[EI_ABIVERSION]);
}

/**
 * handle_type - Print the ELF file type
 * @e_type: The value of the e_type field from the ELF header
 * @e_ident: An array containing the ELF identification bytes
 *
 * Description:
 * This function prints the ELF file type, which is specified by the value
 * stored in the e_type field of the ELF header. The file type defines whether
 * the file is a relocatable, executable, shared object, core, or unknown type.
 */
void handle_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * handle_entry - Print the ELF entry point address
 * @e_entry: The value of the e_entry field from the ELF header
 * @e_ident: The ELF identification bytes
 *
 * Description:
 * This function prints the ELF entry point address, which is specified by the
 * value stored in the e_entry field of the ELF header. The entry point address
 * represents the starting address where the process or program should begin
 * executing after loading into memory.
 */
void handle_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Close the ELF file descriptor
 * @elf_fd: The file descriptor of the ELF file
 *
 * Description:
 * This function closes the file descriptor associated with the ELF file. It
 * takes an integer parameter representing the file descriptor to be closed.
 * If the close operation encounters an error, it prints an error message to
 * the standard error and exits the program with a status code of 98.
 */
void close_elf(int elf_fd)
{
	if (close(elf_fd) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf_fd);

		exit(98);
	}
}

/**
 * print_usage - Print usage information and exit
 *
 * Description:
 * This function prints information about the correct usage of the program,
 * specifically indicating the expected format for providing the ELF filename
 * as a command-line argument. After printing the usage information, the
 * function exits the program with a status code of 98.
 */
void print_usage(void)
{
	dprintf(2, "Usage: elf_header elf_filename\n");
	exit(98);
}
