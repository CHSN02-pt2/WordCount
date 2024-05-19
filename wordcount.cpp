#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 函数声明
int countWords(const char *file); // 返回文件词的数目
int countCharacters(const char *file); // 返回文件的字符数

int main(int argc, char *argv[]) {
    if (argc != 3) { // 检查命令行参数的数量是否正确
        fprintf(stderr, "Usage: %s [-w|-c] <input_file_name>\n", argv[0]);
        return 1; // 参数数量不正确，程序退出
    }

    const char *parameter = argv[1];
    const char *filename = argv[2];

    if (strcmp(parameter, "-w") == 0) {
        countWords(filename); // 统计单词数
    } else if (strcmp(parameter, "-c") == 0) {
        countCharacters(filename); // 统计字符数
    } else {
        fprintf(stderr, "Invalid parameter. Use -w for word count or -c for character count.\n");
        return 1; // 参数无效，程序退出
    }

    return 0;
}

// 统计单词数的函数
int countWords(const char *file) {
    FILE *fp = fopen(file, "r"); // 打开文件
    if (fp == NULL) { // 检查文件是否成功打开
        perror("Error opening file");
        exit(EXIT_FAILURE); // 打开失败，程序退出
    }

    int wordCount = 0;
    int inWord = 0; // 状态变量，用于跟踪当前是否在单词中
    char c;

    while ((c = fgetc(fp)) != EOF) { // 遍历文件中的每个字符
        if (c == ' ' || c == ',') { // 如果遇到空格或逗号
            if (inWord) { // 当前在单词中
                wordCount++; // 单词计数加一
                inWord = 0; // 状态置为0
            }
        } else if (c != '\n' && c != '\r') { // 如果不是换行或回车
            inWord = 1; // 状态置为1，表示在单词中
        }
    }
    // 最后一个单词的计数
    if (inWord) {
        wordCount++;
    }

    fclose(fp); // 关闭文件
    printf("WordNum: %d\n", wordCount); // 打印单词计数
    return wordCount;
}

// 统计字符数的函数
int countCharacters(const char *file) {
    FILE *fp = fopen(file, "r"); // 打开文件
    if (fp == NULL) { // 检查文件是否成功打开
        perror("Error opening file");
        exit(EXIT_FAILURE); // 打开失败，程序退出
    }

    int charCount = 0;
    char c;

    while ((c = fgetc(fp)) != EOF) { // 遍历文件中的每个字符
        charCount++; // 字符计数加一
    }

    fclose(fp); // 关闭文件
    printf("CharNum: %d\n", charCount); // 打印字符计数
    return charCount;
}

