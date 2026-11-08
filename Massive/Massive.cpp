#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    int zadanie = 0;

    while (true) {
        std::cout << "\nВыберите задание (1-4) или 0 для выхода: ";
        std::cin >> zadanie;

        if (zadanie == 0) {
            std::cout << "Программа завершена.\n";
            break;
        }
        else if (zadanie == 1 || zadanie == 2) {
            int razmer = 0;

            std::cout << "Введите размер массива: ";
            std::cin >> razmer;

            if (razmer <= 0) {
                std::cout << "Размер массива должен быть больше нуля.\n";
                continue;
            }

            int* massiv = new int[razmer];

            std::cout << "\nМассив: ";
            for (int i = 0; i < razmer; i++) {
                massiv[i] = rand() % 201 - 100;
                std::cout << massiv[i] << " ";
            }

            if (zadanie == 1) {
                int minimum = massiv[0];
                int maximum = massiv[0];

                for (int i = 1; i < razmer; i++) {
                    if (massiv[i] < minimum) {
                        minimum = massiv[i];
                    }
                    if (massiv[i] > maximum) {
                        maximum = massiv[i];
                    }
                }

                std::cout << "\n\nМинимальный элемент: " << minimum;
                std::cout << "\nМаксимальный элемент: " << maximum << "\n";
            }
            else {
                int chislo = 0;
                int summa = 0;

                std::cout << "\n\nВведите число: ";
                std::cin >> chislo;

                for (int i = 0; i < razmer; i++) {
                    if (massiv[i] < chislo) {
                        summa += massiv[i];
                    }
                }

                std::cout << "\nСумма элементов меньше " << chislo
                    << ": " << summa << "\n";
            }

            delete[] massiv;
        }
        else if (zadanie == 3) {
            double pribyl[12]{};

            for (int i = 0; i < 12; i++) {
                std::cout << "Введите прибыль за " << i + 1 << "-й месяц: ";
                std::cin >> pribyl[i];
            }

            int nachalo = 0;
            int konec = 0;

            std::cout << "\nВведите первый и последний месяц диапазона (1-12): ";
            std::cin >> nachalo >> konec;

            if (nachalo < 1 || konec > 12 || nachalo > konec) {
                std::cout << "Неправильно введён диапазон месяцев.\n";
                continue;
            }

            int min_mesyac = nachalo - 1;
            int max_mesyac = nachalo - 1;

            for (int i = nachalo; i < konec; i++) {
                if (pribyl[i] < pribyl[min_mesyac]) {
                    min_mesyac = i;
                }
                if (pribyl[i] > pribyl[max_mesyac]) {
                    max_mesyac = i;
                }
            }

            std::cout << "\nМаксимальная прибыль была в месяце "
                << max_mesyac + 1 << ": " << pribyl[max_mesyac];

            std::cout << "\nМинимальная прибыль была в месяце "
                << min_mesyac + 1 << ": " << pribyl[min_mesyac] << "\n";
        }
        else if (zadanie == 4) {
            double prodazhi[3]{};
            double zarplata[3]{};

            for (int i = 0; i < 3; i++) {
                std::cout << "Введите уровень продаж менеджера " << i + 1 << ": ";
                std::cin >> prodazhi[i];

                if (prodazhi[i] < 0) {
                    std::cout << "Продажи не могут быть отрицательными.\n";
                    continue;
                }

                double procent = 0;

                if (prodazhi[i] < 500) {
                    procent = 3;
                }
                else if (prodazhi[i] <= 1000) {
                    procent = 5;
                }
                else {
                    procent = 8;
                }

                zarplata[i] = 200 + (prodazhi[i] / 100 * procent);
            }

            int luchshiy = 0;

            for (int i = 0; i < 3; i++) {
                std::cout << "\nЗарплата менеджера " << i + 1
                    << ": " << zarplata[i] << "$";

                if (prodazhi[i] > prodazhi[luchshiy]) {
                    luchshiy = i;
                }
            }

            zarplata[luchshiy] += 200;

            std::cout << "\n\nЛучший менеджер: " << luchshiy + 1;
            std::cout << "\nЕго зарплата с премией: "
                << zarplata[luchshiy] << "$\n";
        }
        else {
            std::cout << "Такого задания нет.\n";
        }
    }

    return 0;
}