#include <iostream>
#include <conio.h>
#include <Windows.h>

struct Node {
    int x, y;
    Node* next;
    Node(int x, int y) : x(x), y(y), next(nullptr) {}
};

void clear() {
    system("cls");
}

int main() {
    setlocale(LC_ALL, "Russian");

    const int WIDTH = 20;   
    const int HEIGHT = 10;  
    Node* head = new Node(WIDTH / 2, HEIGHT / 2);

    int foodX[] = { 3, 15, 7, 18, 1, 6, 4 };
    int foodY[] = { 2, 8, 5, 1, 9, 11, 17 };
    int foodIndex = 0;
    int foodX2 = foodX[foodIndex];
    int foodY2 = foodY[foodIndex];

    char direction = 'd'; 

    while (true) {
        Node* body = head->next;
        while (body) {
            if (head->x == body->x && head->y == body->y) {
                clear();
                std::cout << "Игра окончена! Вы врезались в себя.\n";
                while (head) {
                    Node* tmp = head;
                    head = head->next;
                    delete tmp;
                }
                return 0;
            }
            body = body->next;
        }
        clear();
        std::cout << "!";
        for (int i = 0; i < WIDTH; ++i) std::cout << "!";
        std::cout << "!\n";

        for (int y = 0; y < HEIGHT; ++y) {
            std::cout << "!"; 
            for (int x = 0; x < WIDTH; ++x) {
                char c = ' '; 
                if (x == foodX2 && y == foodY2) {
                    c = '*';
                }
                Node* tmp = head;
                while (tmp) {
                    if (x == tmp->x && y == tmp->y) {
                        c = (tmp == head) ? 'O' : 'o';
                        break;
                    }
                    tmp = tmp->next;
                }

                std::cout << c;
            }

            std::cout << "!\n"; 
        }

        std::cout << "!";
        for (int i = 0; i < WIDTH; ++i) std::cout << "!";
        std::cout << "!\n";
        if (_kbhit()) {
            char input = _getch();
            if ((input == 'w' && direction != 's') ||
                (input == 's' && direction != 'w') ||
                (input == 'a' && direction != 'd') ||
                (input == 'd' && direction != 'a')) {
                direction = input;
            }
        }
        int newx = head->x;
        int newy = head->y;
        switch (direction) {
        case 'w': newy--; break;
        case 's': newy++; break;
        case 'a': newx--; break;
        case 'd': newx++; break;
        }
        if (newx < 0 || newx >= WIDTH || newy < 0 || newy >= HEIGHT) {
            std::cout << "\nИгра окончена! Вы врезались в стену.\n";
            while (head) {
                Node* tmp = head;
                head = head->next;
                delete tmp;
            }
            return 0;
        }
        Node* newHead = new Node(newx, newy);
        newHead->next = head;
        head = newHead;
        if (newx == foodX2 && newy == foodY2) {
            foodIndex = (foodIndex + 1) % 5;
            foodX2 = foodX[foodIndex];
            foodY2 = foodY[foodIndex];

        }
        else {
            Node* cur = head;
            while (cur->next->next != nullptr) {
                cur = cur->next;
            }
            delete cur->next;
            cur->next = nullptr;
        }
        Sleep(200); 
    }
}