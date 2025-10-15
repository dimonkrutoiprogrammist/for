/*
*  Пользователь вводит число. Определить количествоцифр 
в этом числе, посчитать их сумму и среднее арифметическое. 
Определить количество нулей в этом числе. Общение с поль
зователем организовать через меню
*/
/*
#include <iostream>
#include <string>
using namespace std;

int main() {
    int vibor;
    setlocale(LC_ALL, "ru");
    cout << "--- Меню ---\n";
    cout << "1. Ввести число и посчитать информацию\n";
    cout << "2. Выйти\n";
    cout << "Сделайте выбор: ";
    cin >> vibor;

    if (vibor == 1) {
        string chislo;
        cout << "Введите число: ";
        cin >> chislo;

        int kolichestvo = 0;  
        int summa = 0;         
        int nuli = 0;          

        for (int i = 0; i < chislo.length(); i++) {
            char simvol = chislo[i];

            
            if (simvol == '-') {
                continue;
            }

            
            if (simvol >= '0' && simvol <= '9') {
                kolichestvo = kolichestvo + 1;
                int tsifra = simvol - '0';      
                summa = summa + tsifra;
                if (tsifra == 0) {
                    nuli = nuli + 1;
                }
            }
        }

        
        cout << "кол-во цифр: " << kolichestvo << "\n";
        cout << "сумма цифр: " << summa << "\n";

        if (kolichestvo > 0) {
            double srednee = (double)summa / kolichestvo;
            cout << "Среднеареф.: " << srednee << "\n";
        }

        cout << "Кол-во нулей: " << nuli << "\n";
    }

    if (vibor == 2) {
        cout << "Do svidaniya!\n";
    }

    return 0;
}
*/

/*
* Написатьпрограмму,котораявыводитнаэкраншахматную 
доску с заданным размером клеточки.
*/
/*
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Запрашиваем у пользователя размер доски
    int razmer;
    cout << "Введите размер доски (от 1 до 26, например 8): ";
    cin >> razmer;

    // Проверяем, что размер нормальный
    if (razmer <= 0 || razmer > 26) {
        cout << "Ошибка: размер должен быть от 1 до 26.\n";
        return 0;
    }

    // Выводим верхнюю строку с буквами
    cout << "   ";  // Отступ под цифры слева
    for (int i = 0; i < razmer; i++) {
        char bukva = 'a' + i;  // Получаем букву
        cout << bukva << " ";
    }
    cout << "\n";

    // Основной цикл
    for (int stroka = razmer; stroka >= 1; stroka--) {
        // Выводим номер строки слева 
        cout << stroka << " ";

        // Внутренний цикл
        for (int stolbec = 0; stolbec < razmer; stolbec++) {
            // Формируем обозначение клетки
            char bukva = 'a' + stolbec;
            string kletka = "";
            kletka += bukva;
            kletka += ('0' + stroka);  // Преобразуем ол

            // Определяем цвет клетки
            if ((stroka + stolbec) % 2 == 0) {
                // Светлая клетка 
                cout << kletka << " ";
            }
            else {
                // Тёмная клетка 
                cout << "**" << " ";
            }
        }
        cout << "\n";  // Переход на новую строку 
    }

    // Выводим нижнюю строку 
    cout << "   ";
    for (int i = 0; i < razmer; i++) {
        char bukva = 'a' + i;
        cout << bukva << " ";
    }
    cout << "\n";

    return 0;
}
*/

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // Меню
    string nazvaniya[4] = { "1. Кофе", "2. Чай", "3. Пончик", "4. Кекс" };
    double tseny[4] = { 50.0, 30.0, 40.0, 35.0 };

    int skolko_chelovek;
    cout << "На сколько человек заказ? ";
    cin >> skolko_chelovek;

    // Проверка
    if (skolko_chelovek <= 0) {
        cout << "Ошибка: количество людей должно быть больше 0.\n";
        return 0;
    }

    double obshchaya_summa = 0.0;

    // Цикл по каждому человеку
    for (int chelovek = 1; chelovek <= skolko_chelovek; chelovek++) {
        cout << "\n--- Заказ для человека №" << chelovek << " ---\n";
        cout << "Меню:\n";
        for (int i = 0; i < 4; i++) {
            cout << nazvaniya[i] << " — " << tseny[i] << " руб.\n";
        }

        double summa_cheloveka = 0.0;
        int skolko_pozitsiy = 0;

        // Разрешим выбрать до 10 позиций
        for (int popytka = 0; popytka < 10; popytka++) {
            cout << "Выберите номер позиции (1-4) или 0, чтобы закончить: ";
            int vybor;
            cin >> vybor;

            if (vybor == 0) {
                break;  // Выход из цикла добавления
            }

            if (vybor >= 1 && vybor <= 4) {
                // Добавляем цену выбранной позиции
                summa_cheloveka = summa_cheloveka + tseny[vybor - 1];
                skolko_pozitsiy = skolko_pozitsiy + 1;
                cout << "Добавлено: " << nazvaniya[vybor - 1] << "\n";
            }
            else {
                cout << "Неверный номер. Попробуйте снова.\n";
            }
        }

        cout << "Сумма заказа для человека №" << chelovek << ": " << summa_cheloveka << " руб.\n";
        obshchaya_summa = obshchaya_summa + summa_cheloveka;
    }

    cout << "\n--- ИТОГО ---\n";
    cout << "Общая сумма заказа всей компании: " << obshchaya_summa << " руб.\n";

    return 0;
}