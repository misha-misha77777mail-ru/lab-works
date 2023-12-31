# Отчет по лабораторной работе № 12
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Власко Михаил Михайлович

Работа выполнена

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Техника работы с целыми числами. Системы счисления
2. **Цель работы**: Составить программу на языке СИ в целом типе данных, которая для любых допустимых и корректно 
записанных десятичных чисел, поступающих на стандартный ввод программы, выполняет указанное в задании действие.
3. **Задание (вариант №16)**: Проверить, есть ли цифры, не встречающиеся ни разу.

4. **Идея, метод, алгоритм решения задачи**:
    - В введённом числе по очереди считать каждую цифру, сравнить со списком всех цифр, вывести список отсутствующих 
цифр, если таковые имеются. 
5. **Сценарий выполнения работы**:
   1. Создать динамический массив целых чисел, используя функцию ```malloc```;
   2. Заполнить созданный массив десятичными цифрами с помощью цикла ```for```;
   3. Считать введённое число, с помощью получения остатка от деления на 10 в цикле ```while``` считать по очереди все 
цифры числа, заменить в ранее созданном массиве с цифрами соответствующую цифру на -1;
   4. С помощью цикла ```for``` обойти массив, если имеются числа, отличные от -1 (отсутствующие во введённом числе 
цифры), то вывести сообщение о наличии отсутствующих цифр и сами цифры. Иначе, вывести сообщение об отсутствии 
отсутствующих цифр.

6. **Листинг**:
Файл с исходным кодом программы на языке Си: **[lab12.c](lab12.c)**.

7. **Замечания автора** по существу работы: отсутствуют.

8. **Выводы**: Составлена и отлажена программа на языке Си, которая для любых допустимых и корректно 
записанных десятичных чисел, поступающих на стандартный ввод программы, выполняет проверку на наличие остутствующих в 
числе цифр. Получен опыт работы с циклами и динамическими массивами. 
