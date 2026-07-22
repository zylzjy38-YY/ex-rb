cmake_minimum_required(VERSION 4.2)
project(reversewords C)

set(CMAKE_C_STANDARD 11)

# 1. 鑰佺▼搴忥紝鍙 main.c
add_executable(reversewords main.c
        reverse_pointer.c)

# 2. 鎸囬拡缁冧範锛屽彧绠� 鎸囬拡.c
add_executable(pointer_demo 鎸囬拡.c)

# 3. 鏁扮粍缈昏浆缁冧範锛屽彧绠� reverse_array.c
add_executable(reverse_array_demo reverse_array.c)
add_executable(pointer_words reverse_pointer.c)
