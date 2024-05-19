#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ��������
int countWords(const char *file); // �����ļ��ʵ���Ŀ
int countCharacters(const char *file); // �����ļ����ַ���

int main(int argc, char *argv[]) {
    if (argc != 3) { // ��������в����������Ƿ���ȷ
        fprintf(stderr, "Usage: %s [-w|-c] <input_file_name>\n", argv[0]);
        return 1; // ������������ȷ�������˳�
    }

    const char *parameter = argv[1];
    const char *filename = argv[2];

    if (strcmp(parameter, "-w") == 0) {
        countWords(filename); // ͳ�Ƶ�����
    } else if (strcmp(parameter, "-c") == 0) {
        countCharacters(filename); // ͳ���ַ���
    } else {
        fprintf(stderr, "Invalid parameter. Use -w for word count or -c for character count.\n");
        return 1; // ������Ч�������˳�
    }

    return 0;
}

// ͳ�Ƶ������ĺ���
int countWords(const char *file) {
    FILE *fp = fopen(file, "r"); // ���ļ�
    if (fp == NULL) { // ����ļ��Ƿ�ɹ���
        perror("Error opening file");
        exit(EXIT_FAILURE); // ��ʧ�ܣ������˳�
    }

    int wordCount = 0;
    int inWord = 0; // ״̬���������ڸ��ٵ�ǰ�Ƿ��ڵ�����
    char c;

    while ((c = fgetc(fp)) != EOF) { // �����ļ��е�ÿ���ַ�
        if (c == ' ' || c == ',') { // ��������ո�򶺺�
            if (inWord) { // ��ǰ�ڵ�����
                wordCount++; // ���ʼ�����һ
                inWord = 0; // ״̬��Ϊ0
            }
        } else if (c != '\n' && c != '\r') { // ������ǻ��л�س�
            inWord = 1; // ״̬��Ϊ1����ʾ�ڵ�����
        }
    }
    // ���һ�����ʵļ���
    if (inWord) {
        wordCount++;
    }

    fclose(fp); // �ر��ļ�
    printf("WordNum: %d\n", wordCount); // ��ӡ���ʼ���
    return wordCount;
}

// ͳ���ַ����ĺ���
int countCharacters(const char *file) {
    FILE *fp = fopen(file, "r"); // ���ļ�
    if (fp == NULL) { // ����ļ��Ƿ�ɹ���
        perror("Error opening file");
        exit(EXIT_FAILURE); // ��ʧ�ܣ������˳�
    }

    int charCount = 0;
    char c;

    while ((c = fgetc(fp)) != EOF) { // �����ļ��е�ÿ���ַ�
        charCount++; // �ַ�������һ
    }

    fclose(fp); // �ر��ļ�
    printf("CharNum: %d\n", charCount); // ��ӡ�ַ�����
    return charCount;
}

