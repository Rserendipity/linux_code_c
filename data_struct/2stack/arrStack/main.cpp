#include "arrStack.h"

int main() {
    Stack s{};
    for (int i = 0; i < 10; i++) {
        s.Push(i);
    }
    for (int i = 0; i < 10; i++) {
        std::cout << s.Pop() << " " << std::endl;
    }

    return 0;
}