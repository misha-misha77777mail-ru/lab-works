# Отчет по лабораторной работе № 1
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Власко Михаил Михайлович

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Git, Github, Gitlab etc
2. **Цель работы**: Ознакомиться с основными командами Git и работой хостинга репозиториев Github, создать репозиторий 
для хранения отчётов по лабораторным работам.
3. **Задание**: 
 - Завести репозиторий (**общий под все лабораторные работы с отдельной папкой под каждую лр!**).
- Отчет с листингом в Markdown (листинг - ctrl+c -> ctrl+v из терминала с форматированием в markdown).
- Создать отдельную ветку в репозитории под задание.
- Создать коммит с листингом и отчетом.
- Смёржить ветку в мейн.
4. **Идея, метод, алгоритм решения задачи**:
- Создать папку в репозитории под первую лабораторную работу.
- В папке создать файл отчета.
- Создать отдельную ветку в репозитории для выполнения первой лабораторной работы.
- Запушить в эту ветку отчёт с листингом процесса из терминала.
- Смёржить созданную ветку в ветку "main".
5. **Сценарий выполнения работы**:
- Создать репозиторий на Github с названием "lab-works".
- В локальном репозитории создать папку "LR1".
- Внутри папки создать файл отчета "report.md".
- Создать ветку "first-branch" для выполнения задания.
- Создать коммит и запушить изменения в локальном репозитории на удалённый.
- Отредактировать файл "report.md", добавив в него текст отчёта и листинг команд.
- Повторно запушить изменения на Github.
- Смёржить ветку "first-branch" с веткой "main" с помощью Merge Request.
6. **Протокол**: 
``` bash
mihail@mihail-Aspire-7520:~$ mkdir lab-works
mihail@mihail-Aspire-7520:~$ ls
 2023-09-06-192207_1440x900_scrot.png   packages.microsoft.gpg   Изображения
'index.html?banerid=6302000000'         PycharmProjects          Музыка
 jupyter                                wget-log                 Общедоступные
 lab-works                              Безимени1.abw.saved     'Рабочий стол'
 mai-python                             Видео                    Шаблоны
 microsoft.asc                          Документы
 my_repository                          Загрузки
mihail@mihail-Aspire-7520:~$ cd lab-works
mihail@mihail-Aspire-7520:~/lab-works$ git init
Инициализирован пустой репозиторий Git в /home/mihail/lab-works/.git/
mihail@mihail-Aspire-7520:~/lab-works$ mkdir LR1
mihail@mihail-Aspire-7520:~/lab-works$ cd LR1
mihail@mihail-Aspire-7520:~/lab-works/LR1$ touch report.md
mihail@mihail-Aspire-7520:~/lab-works/LR1$ nano report.md
mihail@mihail-Aspire-7520:~/lab-works/LR1$ cd ~/lab-works
mihail@mihail-Aspire-7520:~/lab-works$ git add LR1/report.md
mihail@mihail-Aspire-7520:~/lab-works$ git status
На ветке master

Еще нет коммитов

Изменения, которые будут включены в коммит:
  (используйте «git rm --cached <файл>…», чтобы убрать из индекса)

	новый файл:    LR1/report.md

mihail@mihail-Aspire-7520:~/lab-works$ git commit -m "first commit"
[master (корневой коммит) 9b1ddf1] first commit
 1 file changed, 1 insertion(+)
 create mode 100644 LR1/report.md
mihail@mihail-Aspire-7520:~/lab-works$ git status
На ветке master
нечего коммитить, нет изменений в рабочем каталоге
mihail@mihail-Aspire-7520:~/lab-works$ git remote add origin https://github.com/misha-misha77777mail-ru/lab-works.git
mihail@mihail-Aspire-7520:~/lab-works$ git checkout -b first-branch
Переключено на новую ветку «first-branch»
mihail@mihail-Aspire-7520:~/lab-works$ git push -u origin first-branch
Username for 'https://github.com': misha-misha77777mail-ru
Password for 'https://misha-misha77777mail-ru@gitub.com': 
Подсчет объектов: 4, готово.
Запись объектов: 100% (4/4), 257 bytes | 257.00 KiB/s, готово.
Total 4 (delta 0), reused 0 (delta 0)
To https://github.com/misha-misha77777mail-ru/lab-works.git
 * [new branch]      first-branch -> first-branch
Ветка «first-branch» отслеживает внешнюю ветку «first-branch» из «origin».
mihail@mihail-Aspire-7520:~/lab-works$ git status
На ветке first-branch
Ваша ветка обновлена в соответствии с «origin/first-branch».

нечего коммитить, нет изменений в рабочем каталоге
mihail@mihail-Aspire-7520:~/lab-works$ nano LR1/report.md
mihail@mihail-Aspire-7520:~/lab-works$ git diff
diff --git a/LR1/report.md b/LR1/report.md
index 72943a1..e85eaeb 100644
--- a/LR1/report.md
+++ b/LR1/report.md
@@ -1 +1,102 @@
+# Отчет по лабораторной работе № 1
+## по курсу "Фундаментальная информатика"
+
+Студент группы М8О-108Б-23 Власко Михаил Михайлович
+
+Работа выполнена 
+
+Преподаватель: каф. 806 Севастьянов Виктор Сергеевич
+
+1. **Тема**: Git, Github, Gitlab etc
+2. **Цель работы**: Ознакомиться с основными командами терминала Unix и работой Git.
+5. **Сценарий выполнения работы**: 1) Запустить терминал, создать с его помощью директорию,  
+6. **Протокол**: 
+```
mihail@mihail-Aspire-7520:~/lab-works$ git commit -m "second commit"
[first-branch 231dec8] second commit
 1 file changed, 101 insertions(+)
mihail@mihail-Aspire-7520:~/lab-works$ git push -u origin first-branch
Username for 'https://github.com': misha-misha77777mail-ru
Password for 'https://misha-misha77777mail-ru@github.com': 
Подсчет объектов: 4, готово.
Delta compression using up to 2 threads.
Сжатие объектов: 100% (2/2), готово.
Запись объектов: 100% (4/4), 1.98 KiB | 1.98 MiB/s, готово.
Total 4 (delta 0), reused 0 (delta 0)
To https://github.com/misha-misha77777mail-ru/lab-works.git
   9b1ddf1..231dec8  first-branch -> first-branch
Ветка «first-branch» отслеживает внешнюю ветку «first-branch» из «origin».
mihail@mihail-Aspire-7520:~/lab-works$ 
```
8. **Выводы**: Получен первый опыт работы с Git'ом, использования Merge Requests, создан удалённый репозиторий 
для хранения отчётов по лабораторным работам.
