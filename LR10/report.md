# Отчет по лабораторной работе № 10
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Власко Михаил Михайлович

Работа выполнена

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Издательская система LATEX
2. **Цель работы**: Вёрстка документа с использованием издательской системы LATEX.
3. **Задание (вариант №31)**: Сверстать копию [страницы 31](input.pdf) из книги "Курс математического анализа" 
(Л. Д. Кудрявцев), максимально соответствующую оригиналу.

4. **Идея, метод, алгоритм решения задачи**:
    - Написать исходный код копии в онлайн-редакторе Overleaf, скомпилировать его в PDF-файл.
5. **Сценарий выполнения работы**:
   - Необходимо составить исходный код результирующей страницы с использованием разметки LATEX.
   - При разметке документа использованы следующие команды:
        - ```\documentclass{}``` - определяет тип документа (```article```).
        - ```\usepackage{}```  - подключает модули:
          - ```babel``` - устанавливает язык документа (```russian```);
          - ```inputenc``` - устанавливает кодировку документа (```utf8```);
          - ```geometry``` - устанавливает размеры станицы в соответствии с оригиналом и отступы по краям листа;
          - ```mathtools``` - используется для вставки математических формул.
        - ```\title{}``` - устанавливает заголовок документа.
        - ```\author{}``` - устанавливает автора документа.
        - ```\date{}``` - устанавливает дату создания документа.
        - ```\begin{document}``` ```\end{document}``` - оборачивает текст документа.
        - ```\setlength{\parindent}{0cm}``` - устанавливает нулевой отступ перед первым абзацем.
        - ```\pagenumbering{\textsl{31}}``` - искусственно устанавливает 31 номер страницы и выделяет его курсивом.
        - ```\Large``` - делает размер шрифта документа соответствующим оригиналу.
        - ```\textit{}``` - выделяет текст курсивом.
        - ```\textbf{}``` - делает текст полужирным.
        - ```\begin{flushleft}``` ```\end{flushleft}``` - выделяют абзац текста без абзацного отступа.
        - ```\[ ... \]``` - выделяет математическую формулу, помещаемую посередине отдельной строки.
        - ```\( ... \)``` - выделяет математическую формулу, помещаемую непосредственно в тексте.
        - ```\frac{}``` - задаёт дробь.
        - ```\tag{}``` - устанавливает номер формулы, помещаемый в крайнем правом участке строки.
        - ```\textsc{}``` - выделяет текст, набранный чуть более крупным шрифтом (слова "ТЕОРЕМА", "СЛЕДСТВИЕ" и т. д.).
        - ```\par{}``` - выделяет абзац с абзацным отступом.
        - ```\stackrel{\text{def}}{=}``` - устанавливает не курсивное слово "def" над знаком "=" в формуле.
        - ```\centering``` - центрирует идущий далее текст.
        - ```\newline```  вынужденный перенос текста на новую строку.
   - Скомпилировать код в PDF-файл, добавить получившийся файл в отчёт.


6. **Листинг**:
- Исходный код документа в формате LATEX находится в файле [source.tex](source.tex).
- Выходной файл документа в формате PDF находится в файле [output.pdf](output.pdf).


7. **Замечания автора** по существу работы: отсутствуют.


8. **Выводы**: Свёрстан документ с помощью издательской системы LATEX, получен опыт работы с издательской 
системой LATEX и создание с её помощью документов в формате PDF.
