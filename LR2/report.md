# Отчет по лабораторной работе № 2
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Власко Михаил Михайлович

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Bash, linux terminal, SSH, tar.
2. **Цель работы**: Ознакомиться с работой терминала Linux, основными его командами, 
работой с удалённой машиной, использованием архиватора.
3. **Задание**: 
- Использовать основные команды.
- Сохранить листинг в файл.
- Заархивировать.
- Отправить на удаленную машину, там разархивировать.
- Скачать разархивированный файл к себе на машину.
- Составить отчет с листингом в формате markdown.
- Выложить на github через merge веток.
4. **Идея, метод, алгоритм решения задачи**:
- Опробовать работу основных команд терминала Linux.
- Сохранить листинг использования команд в файл.
- Установить SSH-соединение с удалённой машиной.
- Заархивировать полученный файл, отправить на удалённую машину, там разархивировать, 
скачать обратно на свою машину.
- Финальный отчёт запушить на Github.
5. **Сценарий выполнения работы**:
- Опробовать основные команды терминала Linux на локальной машине.
- Сохранить получившийся листинг в файл ```report.md```.
- Установить соединение с удалённой машиной по протоколу SSH.
- Сгенерировать ssh-ключ с помощью команды ```ssh-keygen```.
- Добавить созданный ключ с помощью ```ssh-copy-id```.
- Создать архив tar.gz из файла ```report.md``` на локальной машине при помощи ```tar```.
- Отправить полученный архив на удалённую машину при помощи ```scp```.
- Разархивировать полученный на удалённой машине архив с помощью ```tar```.
- Скачать разархивированный файл обратно на локальную машину при помощи ```scp```.
- Запушить получившийся файл отчёта в отдельную ветку, затем смёржить её в ```main```.

6. **Протокол**: 
```shell
mihail@mihail-Aspire-7520:~$ who
mihail   tty7         2023-09-18 14:56 (:0)
mihail@mihail-Aspire-7520:~$ pwd
/home/mihail
mihail@mihail-Aspire-7520:~$ ls
 2023-09-06-192207_1440x900_scrot.png   packages.microsoft.gpg   Изображения
'index.html?banerid=6302000000'         PycharmProjects          Музыка
 jupyter                                wget-log                 Общедоступные
 lab-works                              Безимени1.abw.saved     'Рабочий стол'
 mai-python                             Видео                    Шаблоны
 microsoft.asc                          Документы
 my_repository                          Загрузки
mihail@mihail-Aspire-7520:~$ mkdir temp
mihail@mihail-Aspire-7520:~$ cd temp
mihail@mihail-Aspire-7520:~/temp$ touch tmp.txt
mihail@mihail-Aspire-7520:~/temp$ cp tmp.txt temp.txt
mihail@mihail-Aspire-7520:~/temp$ ls
temp.txt  tmp.txt
mihail@mihail-Aspire-7520:~/temp$ mv temp.txt tmp1.txt
mihail@mihail-Aspire-7520:~/temp$ ls
tmp1.txt  tmp.txt
mihail@mihail-Aspire-7520:~/temp$ mkdir dir
mihail@mihail-Aspire-7520:~/temp$ mv tmp1.txt dir/tmp1.txt
mihail@mihail-Aspire-7520:~/temp$ ls
dir  tmp.txt
mihail@mihail-Aspire-7520:~/temp$ rm -r dir
mihail@mihail-Aspire-7520:~/temp$ ls
tmp.txt
mihail@mihail-Aspire-7520:~/temp$ nano tmp.txt
mihail@mihail-Aspire-7520:~/temp$ cat tmp.txt
hello
mihail@mihail-Aspire-7520:~/temp$ echo "Hello, MAI" > echo.txt
mihail@mihail-Aspire-7520:~/temp$ cat echo.txt
Hello, MAI
mihail@mihail-Aspire-7520:~/temp$ echo "Hello, 3-Cat!" >> echo.txt
mihail@mihail-Aspire-7520:~/temp$ cat echo.txt
Hello, MAI
Hello, 3-Cat!
mihail@mihail-Aspire-7520:~/temp$ nano tmp.txt
mihail@mihail-Aspire-7520:~/temp$ tail tmp.txt
21
22
23
24
25
26
27
28
29
30
mihail@mihail-Aspire-7520:~/temp$ head tmp.txt
1
2
3
4
5
6
7
8
9
10
mihail@mihail-Aspire-7520:~/temp$ tail tmp.txt -n 3
28
29
30
mihail@mihail-Aspire-7520:~/temp$ ps
  PID TTY          TIME CMD
 1185 pts/0    00:00:00 bash
 1254 pts/0    00:00:00 tail
 1257 pts/0    00:00:00 ps
mihail@mihail-Aspire-7520:~/temp$ kill -9 1254
[1]+  Убито              tail -n 3
mihail@mihail-Aspire-7520:~/temp$ grep -i 23 tmp.txt
23
mihail@mihail-Aspire-7520:~/temp$ history | grep -i ta
    1  sudo apt install apt-transport-https
    3  sudo apt-get install wget gpg
    6  sudo install -D -o root -m 644 packages.microsoft.gpg /etc/apt/keyrings/packages.microsoft.gpg
   15  sudo apt-get install ubuntu-make
   22  sudo apt install python3.8
   26  sudo snap install pycharm-community --classic
   27  sudo apt install snapd
   29  sudo snap install pycharm-community --classic
   31  snap switch --channel 2019.1/stable pycharm-community
   32  sudo snap info pycharm-community --channel=2019.1/stable --classic
   33  sudo apt-get install pycharm-community
   34  sudo apt install checkinstall build-essential autoconf automake
   37  sudo apt install libreoffice libreoffice-gnome
   39  tar -xvf pycharm-community-2019.1.4.tar.gz
   50  sudo tar xfz pycharm-community-2019.1.4.tar.gz -C /opt/
   56  pip install requests
   57  sudo apt install python-pip
   59  pip install tkinter
   60  pip install requests
   68  sudo apt install --no-install-recommends gnome-panel
  113  sudo apt install build-essential
  125  pip install jupyter
  126  pip install --upgrade setuptools
  127  pip install jupyter
  130  sudo apt install python3-pip python3-dev
  131  sudo -H pip3 install --upgrade pip
  132  sudo -H pip3 install virtualenv
  137  pip install jupyter
  149  sudo apt install git
  171  sudo apt install rwho
  179  sudo apt install finger
  188  sudo apt install emacs25
  219  sudo apt install gnuplot-nox
  228  sudo apt-get install yandex-browser-stable
  252  git status
  254  git status
  257  git status
  259  git status
  280  git status
  286  git status
  290  pip install taichi
  302  pip install taichi
  304  pip3 install taichi
  325  git status
  327  git status
  331  git status
  353  pip3 install pyTelegramBotAPI
  355  pip install pyTelegramBotAPI
  358  ls | tail bot
  389  tail tmp.txt
  391  tail -n 3
  392  tail tmp.txt -n 3
  396  history | grep -i ta
mihail@mihail-Aspire-7520:~/temp$ cd
mihail@mihail-Aspire-7520:~$ rmdir temp
rmdir: не удалось удалить 'temp': Каталог не пуст
mihail@mihail-Aspire-7520:~$ rm -r temp
mihail@mihail-Aspire-7520:~$ ls
 2023-09-06-192207_1440x900_scrot.png   packages.microsoft.gpg   Изображения
'index.html?banerid=6302000000'         PycharmProjects          Музыка
 jupyter                                wget-log                 Общедоступные
 lab-works                              Безимени1.abw.saved     'Рабочий стол'
 mai-python                             Видео                    Шаблоны
 microsoft.asc                          Документы
 my_repository                          Загрузки
mihail@mihail-Aspire-7520:~$ sudo apt update
[sudo] пароль для mihail: 
Сущ:1 http://ru.archive.ubuntu.com/ubuntu bionic InRelease
Пол:2 http://ru.archive.ubuntu.com/ubuntu bionic-updates InRelease [88,7 kB]   
Пол:3 http://ru.archive.ubuntu.com/ubuntu bionic-backports InRelease [83,3 kB] 
Пол:4 http://ppa.launchpad.net/libreoffice/ppa/ubuntu bionic InRelease [20,8 kB]
Пол:5 http://security.ubuntu.com/ubuntu bionic-security InRelease [88,7 kB]    
Сущ:6 http://ppa.launchpad.net/ubuntu-desktop/ubuntu-make/ubuntu bionic InRelease
Пол:7 http://ru.archive.ubuntu.com/ubuntu bionic-updates/main i386 DEP-11 Metadata [295 kB]
Пол:8 http://ppa.launchpad.net/libreoffice/ppa/ubuntu bionic/main i386 Packages [34,5 kB]
Пол:9 http://ru.archive.ubuntu.com/ubuntu bionic-updates/universe i386 Packages [1 663 kB]
Пол:10 http://security.ubuntu.com/ubuntu bionic-security/main i386 DEP-11 Metadata [76,8 kB]
Пол:11 http://security.ubuntu.com/ubuntu bionic-security/universe i386 Packages [1 078 kB]
Пол:12 http://ru.archive.ubuntu.com/ubuntu bionic-updates/universe Translation-en [421 kB]
Пол:13 http://security.ubuntu.com/ubuntu bionic-security/universe Translation-en [308 kB]
Пол:14 http://ru.archive.ubuntu.com/ubuntu bionic-updates/universe i386 DEP-11 Metadata [303 kB]
Пол:15 http://security.ubuntu.com/ubuntu bionic-security/universe i386 DEP-11 Metadata [62,5 kB]
Пол:16 http://security.ubuntu.com/ubuntu bionic-security/multiverse i386 DEP-11 Metadata [2 464 B]
Пол:17 http://ru.archive.ubuntu.com/ubuntu bionic-updates/multiverse i386 DEP-11 Metadata [2 468 B]
Пол:18 http://ru.archive.ubuntu.com/ubuntu bionic-backports/main i386 DEP-11 Metadata [5 376 B]
Пол:19 http://ru.archive.ubuntu.com/ubuntu bionic-backports/universe i386 DEP-11 Metadata [10,0 kB]
Получено 4 544 kB за 5с (842 kB/s)                                   
Чтение списков пакетов… Готово
Построение дерева зависимостей       
Чтение информации о состоянии… Готово
Может быть обновлён 391 пакет. Запустите «apt list --upgradable» для показа.
mihail@mihail-Aspire-7520:~$ echo "OKOKOKOK"
OKOKOKOK
mihail@mihail-Aspire-7520:~$ ssh m_vlasko@185.5.249.140
m_vlasko@185.5.249.140's password: 
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Mon Sep 18 14:01:57 2023 from 95.27.141.242
m_vlasko@vds2476450:~$ ls
bot.py                   pyTelegramBotAPI-4.13.0.tar.gz  stools
nohup.out                setuptools-68.2.2               telebot
pyTelegramBotAPI-4.13.0  setuptools-68.2.2.tar.gz        telebot.tar.gz
m_vlasko@vds2476450:~$ pwd
/home/m_vlasko
m_vlasko@vds2476450:~$ who
t_grigoriev pts/0        2023-09-18 15:19 (95.24.62.154)
d_kuleshov pts/1        2023-09-18 13:19 (188.66.38.91)
m_vlasko pts/2        2023-09-18 15:20 (95.27.141.242)
m_vlasko@vds2476450:~$ logout
Connection to 185.5.249.140 closed.
mihail@mihail-Aspire-7520:~$ ssh-keygen
Generating public/private rsa key pair.
Enter file in which to save the key (/home/mihail/.ssh/id_rsa): 
Enter passphrase (empty for no passphrase): 
Enter same passphrase again: 
Your identification has been saved in /home/mihail/.ssh/id_rsa.
Your public key has been saved in /home/mihail/.ssh/id_rsa.pub.
The key fingerprint is:
SHA256:klOBw+0M4pP/JOcMkG6nd3RSiiBgGRon/zD1sbKBst8 mihail@mihail-Aspire-7520
The key's randomart image is:
+---[RSA 2048]----+
|o.+ ...o.        |
|oB o..=o..       |
|+.=.o+o=.        |
| o.+B+ oo .      |
|.  oo=+.So       |
| . .o *o* .      |
|  ..Eo X o       |
|    . . =        |
|     . .         |
+----[SHA256]-----+
mihail@mihail-Aspire-7520:~$ ssh-copy-id m_vlasko@185.5.249.140
/usr/bin/ssh-copy-id: INFO: Source of key(s) to be installed: "/home/mihail/.ssh/id_rsa.pub"
/usr/bin/ssh-copy-id: INFO: attempting to log in with the new key(s), to filter out any that are already installed
/usr/bin/ssh-copy-id: INFO: 1 key(s) remain to be installed -- if you are prompted now it is to install the new keys
m_vlasko@185.5.249.140's password: 

Number of key(s) added: 1

Now try logging into the machine, with:   "ssh 'm_vlasko@185.5.249.140'"
and check to make sure that only the key(s) you wanted were added.

mihail@mihail-Aspire-7520:~$ ssh m_vlasko@185.5.249.140
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Mon Sep 18 15:20:04 2023 from 95.27.141.242
m_vlasko@vds2476450:~$ logout
Connection to 185.5.249.140 closed.
mihail@mihail-Aspire-7520:~$ nano report.md
mihail@mihail-Aspire-7520:~$ tar -czvf report.tar.gz report.md
report.md
mihail@mihail-Aspire-7520:~$ scp report.tar.gz m_vlasko@185.5.249.140:/home/m_vlasko/tars
report.tar.gz                                 100%  193    18.7KB/s   00:00    
mihail@mihail-Aspire-7520:~$ ssh m_vlasko@185.5.249.140
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Mon Sep 18 15:32:38 2023 from 95.27.141.242
m_vlasko@vds2476450:~$ cd tars
m_vlasko@vds2476450:~/tars$ ls
report.tar.gz
m_vlasko@vds2476450:~/tars$ tar -xzvf report.tar.gz
report.md
m_vlasko@vds2476450:~/tars$ logout
Connection to 185.5.249.140 closed.
mihail@mihail-Aspire-7520:~$ scp m_vlasko@185.5.249.140:/home/m_vlasko/tars/report.md ~/
report.md                                     100% 1715    50.9KB/s   00:00    
mihail@mihail-Aspire-7520:~$ ls
 2023-09-06-192207_1440x900_scrot.png   packages.microsoft.gpg   Документы
'index.html?banerid=6302000000'         PycharmProjects          Загрузки
 jupyter                                report.md                Изображения
 lab-works                              report.tar.gz            Музыка
 mai-python                             wget-log                 Общедоступные
 microsoft.asc                          Безимени1.abw.saved     'Рабочий стол'
 my_repository                          Видео                    Шаблоны
mihail@mihail-Aspire-7520:~$ echo "That's all!"
That's all!


```
8. **Выводы**: Получен опыт работы с основными командами терминала Linux, работы с удалённой машиной при помощи ``SSH``,
архивирования и разархивирования файлов с помощью ```tar```, передачи и скачивания файлов с удалённой машины при
помощи ```scp```.
