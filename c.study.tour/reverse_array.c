#include <stdio.h>
#include <string.h>

// 辅助函数：通过数组下标翻转指定范围内的字符
void reverse(char str[], int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// 主函数：通过数组下标翻转句子中的单词顺序
void reverseWords(char str[]) {
    int len = strlen(str);
    // 如果字符串为空或只有一个字符，无需翻转
    if (len <= 1) {
        return;
    }

    // 步骤 1：翻转整个字符串（下标从 0 到 len - 1）
    reverse(str, 0, len - 1);

    // 步骤 2：逐个翻转每个单词
    int i = 0;
    while (str[i] != '\0') {
        // 跳过可能存在的连续空格，找到单词的起点下标
        while (str[i] == ' ' && str[i] != '\0') {
            i++;
        }
        // 如果直接到了字符串末尾，说明后续没有单词了
        if (str[i] == '\0') {
            break;
        }
        int word_start = i;

        // 找到单词的终点下标（遇到空格或字符串结束符）
        while (str[i] != ' ' && str[i] != '\0') {
            i++;
        }
        int word_end = i - 1;

        // 翻转这单个单词
        reverse(str, word_start, word_end);
    }
}

int main() {
    // 测试标准用例
    char str1[] = "i like you";
    printf("原字符串: \"%s\"\n", str1);
    reverseWords(str1);
    printf("翻转以后: \"%s\"\n\n", str1);

    // 测试带有多余空格的复杂用例
    char str2[] = "  hello   world  ";
    printf("原字符串: \"%s\"\n", str2);
    reverseWords(str2);
    printf("翻转以后: \"%s\"\n", str2);

    return 0;
}
// Created by zjyjq on 2026/7/11.
//
