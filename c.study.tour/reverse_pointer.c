#include <stdio.h>
#include <string.h>

// 辅助函数：翻转指定范围内的字符
void reverse(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// 主函数：翻转句子中的单词顺序
void reverseWords(char *s) {
    if (s == NULL || *s == '\0') {
        return;
    }

    // 步骤 1：翻转整个字符串
    char *end = s + strlen(s) - 1;
    reverse(s, end);

    // 步骤 2：逐个翻转每个单词
    char *word_start = s;
    char *p = s;

    while (*p != '\0') {
        // 跳过可能存在的领先空格，找到单词的起点
        while (*p == ' ' && *p != '\0') {
            p++;
        }
        if (*p == '\0') {
            break;
        }
        word_start = p;

        // 找到单词的终点（遇到空格或字符串结束符）
        while (*p != ' ' && *p != '\0') {
            p++;
        }
        char *word_end = p - 1;

        // 翻转这单个单词
        reverse(word_start, word_end);
    }
}

int main() {
    // 测试标准用例
    char str1[] = "i like you";
    printf("原字符串: \"%s\"\n", str1);
    reverseWords(str1);
    printf("翻转以后: \"%s\"\n\n", str1);

    // 测试普适性（带有多余空格的复杂用例）
    char str2[] = "  hello   world  ";
    printf("原字符串: \"%s\"\n", str2);
    reverseWords(str2);
    printf("翻转以后: \"%s\"\n", str2);

    return 0;
}
