// pr6_zabelina.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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

	Node* head = new Node(5, 2);
	
	int foodX[] = { 2, 7, 4, 0, 9 };
	int foodY[] = { 1, 0, 3, 4, 2 };
	int foodIndex = 0;

	int foodX2 = foodX[foodIndex];
	int foodY2 = foodY[foodIndex];

	while (true) {

		clear();
		Node* body = head->next;
		while (body) {
			if (head->x == body->x && head->y == body->y) {
				std::cout << "Игра окончена! Вы врезались в себя.\n";
				return 0;
			}
			body = body->next;
		}

		
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 10; x++) {
				char c = '.';
				if (x == foodX2 && y == foodY2) c = '*';

				Node* tmp = head;
				while (tmp) {
					if (x == tmp->x && y == tmp->y) {
						if (tmp == head) {
							c = 'O';
						}
						else {
							c = 'o';
						}
						break;
					}
					tmp = tmp->next;
				}
				std::cout << c;
			}
			std::cout << "\n";
		}

	
		if (_kbhit()) {
			char input = _getch();
			int newx = head->x;
			int newy = head->y;
			if (input == 'w') newy--;
			else if (input == 's') newy++;
			else if (input == 'a') newx--;
			else if (input == 'd') newx++;
			else std::cout << "Ошибка! Неверная раскладка.";
			Sleep(100);

			
			if (newx < 0 || newx > 9 || newy < 0 || newy > 4) {
				std::cout << "Игра окончена! Вы врезались в стену.\n";
				break;
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
				
				Node* node = head;
				while (node->next->next) node = node->next;
				delete node->next;
				node->next = nullptr;
			}
		}

		Sleep(50);
	}
}
		



	


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
