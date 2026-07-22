// #include <stdio.h>
//
// int main(void) {
//     printf("Hello, World!\n");
//     return 0;
// }
#include <stdio.h>

// 辅助函数：翻转字符串中指定的区间（通过指针原地头尾交换）
void reverseString(char *start, char *end) {
    char temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// 核心处理函数：逆序句子中的单词
void reverseWords(char *str) {
    if (str == NULL) return;

    char *word_start = str;
    char *temp = str;

    // 第一步：逐个翻转句子中的单词
    while (*temp != '\0') {
        // 遇到字符串结束符时，翻转最后一个单词
        if (*(temp + 1) == '\0') {
            reverseString(word_start, temp);
        }
        // 遇到空格时，翻转当前的单词
        else if (*temp == ' ') {
            reverseString(word_start, temp - 1);
            word_start = temp + 1; // 单词起始指针移动到下一个单词的首字母
        }
        temp++;
    }

    // 第二步：翻转整个完整的句子（此时 temp 指向 '\0'，所以 end 是 temp - 1）
    reverseString(str, temp - 1);
}

int main() {
    // 必须使用字符数组，不能用 char *str = "i am boy"，因为常量字符串只读
    char str[] = "我喜欢 你 刘恒延 ";

    printf("原字符串: \"%s\"\n", str);
    reverseWords(str);
    printf("翻转以后: \"%s\"\n", str);

    return 0;
}
