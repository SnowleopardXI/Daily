#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义ELF文件头部的结构
typedef struct {
    unsigned char e_ident[16]; // ELF标识
    unsigned short e_type;     // 文件类型
    unsigned short e_machine;  // 目标机器
    unsigned int e_version;    // 版本信息
    unsigned long e_entry;     // 入口点地址
    unsigned long e_phoff;     // 程序头部表偏移
    unsigned long e_shoff;     // 节头部表偏移
    unsigned int e_flags;      // 标志
    unsigned short e_ehsize;   // ELF头部大小
    unsigned short e_phentsize;// 程序头部表项大小
    unsigned short e_phnum;    // 程序头部表项数目
    unsigned short e_shentsize;// 节头部表项大小
    unsigned short e_shnum;    // 节头部表项数目
    unsigned short e_shstrndx; // 节头部字符串表索引
} Elf64_Ehdr;

typedef struct {
    unsigned long pe_signature;   // PE签名
    unsigned short machine;       // 机器类型
    unsigned short number_of_sections; // 节数量
    unsigned long time_date_stamp; // 时间戳
    unsigned long pointer_to_symbol_table; // 符号表位置
    unsigned long number_of_symbols; // 符号数量
    unsigned short size_of_optional_header; // 可选头大小
    unsigned short characteristics; // 文件特性
} PE_Header;

// 判断文件是否为纯文本文件
int is_text_file(FILE *file) {
    char buffer[1024];
    size_t read_bytes = fread(buffer, 1, sizeof(buffer), file);
    for (size_t i = 0; i < read_bytes; ++i) {
        if (buffer[i] == '\0') {  // 文本文件不应包含空字符
            return 0;
        }
    }
    return 1;
}

// 打印ELF文件头部信息
void print_elf_header(Elf64_Ehdr *eh) {
    printf("ELF Header:\n");
    printf("  Type: %x\n", eh->e_type);
    printf("  Machine: %x\n", eh->e_machine);
    printf("  Version: %x\n", eh->e_version);
    printf("  Entry point address: %lx\n", eh->e_entry);
    printf("  Start of program headers: %lx\n", eh->e_phoff);
    printf("  Start of section headers: %lx\n", eh->e_shoff);
    printf("  Flags: %x\n", eh->e_flags);
    printf("  Size of this header: %d\n", eh->e_ehsize);
    printf("  Size of program headers: %d\n", eh->e_phentsize);
    printf("  Number of program headers: %d\n", eh->e_phnum);
    printf("  Size of section headers: %d\n", eh->e_shentsize);
    printf("  Number of section headers: %d\n", eh->e_shnum);
    printf("  Section header string table index: %d\n", eh->e_shstrndx);
}

// 打印PE文件头部信息
void print_pe_header(PE_Header *pe) {
    printf("PE Header:\n");
    printf("  Machine: %x\n", pe->machine);
    printf("  Number of sections: %d\n", pe->number_of_sections);
    printf("  Timestamp: %lu\n", pe->time_date_stamp);
    printf("  Symbols table address: %lx\n", pe->pointer_to_symbol_table);
    printf("  Number of symbols: %lu\n", pe->number_of_symbols);
    printf("  Size of optional header: %d\n", pe->size_of_optional_header);
    printf("  Characteristics: %x\n", pe->characteristics);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    // 打开文件
    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    unsigned char header[64];  // 读取足够的头部信息以判断文件类型
    fread(header, sizeof(header), 1, file);
    rewind(file);  // 重置文件指针

    // 判断ELF文件
    if (memcmp(header, "\x7F""ELF", 4) == 0) {
        Elf64_Ehdr elf_header;
        fread(&elf_header, sizeof(Elf64_Ehdr), 1, file);
        print_elf_header(&elf_header);
    }
    // 判断PE文件
    else if (header[0] == 'M' && header[1] == 'Z') {
        // 判断PE头的存在
        long pe_offset = *(long *)(header + 0x3C); // PE header offset
        fseek(file, pe_offset, SEEK_SET);
        PE_Header pe_header;
        fread(&pe_header, sizeof(PE_Header), 1, file);
        print_pe_header(&pe_header);
    }
    // 判断文本文件
    else if (is_text_file(file)) {
        printf("This is a text file.\n");
    } else {
        printf("This is a regular file.\n");
    }

    fclose(file);
    return 0;
}
