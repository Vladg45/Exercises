/*3.20 Вам необходимо проверить домашнюю работу Васи Пупкина, в которой он написал равенство.
Например, запись вида «2+3=5» является правильной, а «23*7=421 » неверная,
но корректная.Корректной записью выражения будем называть последовательность :
число, операция(« + », « - », «* », « / »), число, знак равенства, число.
Числом будем считать последовательность из одной или более десятичных цифр,
перед которой может стоять один знак минус.В корректной записи выражения нет пробелов.
Если запись не соответствует описанному правилу, то она считается некорректной.
Например, записи «2*=3», «173» и «2+2=a» некорректны.
Выведите «ДА», если указанная запись правильна(т.е.равенство представляет собой тождество),
«НЕТ» – если корректная, но неверная и «ОШИБКА», если запись некорректная.*/


#include <iostream>
#include <clocale>
#include <string>
#include <regex>

using namespace std;

// Вывод сообщения в зависимости от верности уравнения
void if_equation_then_massage(int left_number, int rigtht_number)
{
    if (left_number == rigtht_number)
        printf("Да, эта запись верна.\n");
    else
        printf("Нет, эта запись не верна.\n");
}

int main()
{
    setlocale(LC_ALL, "Russian");

    string text;
    smatch result;
    // Регулярка проверяет на соответствие шаблоку:
    // начало строки (0 или больше пробелов) (0 или 1 минус) (1 или более цифр) (один из операторов - + * /)
    // (0 или 1 минус) (1 или более цифр) (знак =) (0 или 1 минус) (1 или более цифр) (0 или больше пробелов) конец строки
    const regex r(R"(^( *)(\-?)([0-9]+)(\-|\+|\*|\/)(\-?)([0-9]+)(=)(\-?)([0-9]+)( *)$)");

    // Проверка на ввод уравнения
    while (true)
    {
        printf("Проверка на ввод уравнения.\nВведите уравнение без пробелов: ");
        getline(cin, text);

        if (regex_search(text, result, r))
        {
            if ((result[3].length() < 10) && (result[6].length() < 10) && (result[9].length() < 10))
                break;
            else
                printf("Введены слишком большие числа! Введите меньше десятизначного!\n");
        }
        else
            printf("Ошибка, запись некорректна.\n");
        system("pause");
        system("cls");
    }

    int first_number = stoi(result[2].str() + result[3].str());
    string operation = result[4].str();
    int second_number = stoi(result[5].str() + result[6].str());
    int result_number = stoi(result[8].str() + result[9].str());

    if (operation == "-")
        if_equation_then_massage(first_number - second_number, result_number);
    else if (operation == "+")
        if_equation_then_massage(first_number + second_number, result_number);
    else if (operation == "*")
        if_equation_then_massage(first_number * second_number, result_number);
    else if (operation == "/")
        if_equation_then_massage(first_number / second_number, result_number);

    printf("Нажмите Enter  без символов, чтобы начать программу сначала: ");
    if (getchar() == '\n')
        main();
    else
        system("pause");
}
