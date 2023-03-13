/*
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StudentList {
public:
    struct Student {
        string surname;
        int course;
        string direction;
    };

    vector<Student> students;

    void setCourse(int index, int course) {
        students[index].course = course;
    }
    
    void getStudentsByCourse(int course) {
        cout << "Студенты на курсе " << course << ":\n" << endl;

        bool found = false; // флаг наличия студентов на данном курсе в списке

        for (int i = 0; i < students.size(); i++) {
            if (students[i].course == course) {
                cout << "\t" << students[i].surname << " - " << students[i].direction << endl;
                found = true; // обновляем флаг, если студенты на курсе есть в списке
            }
        }

        if (!found) {
            cout << "Студентов на курсе " << course << " нет в списке" << endl;
        }
    }
    
   


    bool readFromFile(string filename) {
        ifstream infile;
        infile.open(filename);

        if (!infile.is_open()) {
            cerr << "Ошибка: не удалось открыть файл " << filename << endl;
            return false;
        }

        students.clear();

        while (infile) {
            Student newStudent;
            if (!(infile >> newStudent.surname >> newStudent.course >> newStudent.direction)) {
                if (infile.eof()) {
                    break;
                } else {
                    cout << "Ошибка: некорректный формат данных в файле " << filename << endl;
                    students.clear();
                    infile.close();
                    return false;
                }
            }
            students.push_back(newStudent);
        }

        infile.close();

        return true;
    }
};

int main() {
    StudentList list;

    string filename = "test.txt";
    //cout << "Введите имя файла: ";
    //cin >> filename;

    bool success = list.readFromFile(filename);

    if (success) {
        int course;
        cout << "Введите номер курса (от 1 до 6): ";
        cin >> course;

        if (course >= 1 && course <= 6) {
            list.getStudentsByCourse(course);
        } else {
            cout << "Ошибка: введен некорректный номер курса" << endl;
        }
    }

    return 0;
}








#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class StudentList {
public:
    struct Student {
        string surname;
        int course;
        string direction;
    };

    vector<Student> students;

    void setCourse(int index, int course) {
        students[index].course = course;
    }
    
    void getStudentsByCourse(int course) {
        cout << "Студенты на курсе " << course << ":\n" << endl;

        bool found = false; // флаг наличия студентов на данном курсе в списке

        for (int i = 0; i < students.size(); i++) {
            if (students[i].course == course) {
                cout << "\t" << students[i].surname << " - " << students[i].direction << endl;
                found = true; // обновляем флаг, если студенты на курсе есть в списке
            }
        }

        if (!found) {
            cout << "Студентов на курсе " << course << " нет в списке" << endl;
        }
    }
    
    void printStudentsByGroup() {
        // Сортируем студентов по группам, курсу и фамилиям
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            if (a.direction != b.direction) {
                return a.direction < b.direction;
            } else if (a.course != b.course) {
                return a.course < b.course;
            } else {
                return a.surname < b.surname;
            }
        });

        string currentGroup = "";
        int currentCourse = -1;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].direction != currentGroup) {
                currentGroup = students[i].direction;
                cout << "\nГруппа " << currentGroup << ":\n";
                currentCourse = -1;
            }
            if (students[i].course != currentCourse) {
                currentCourse = students[i].course;
                cout << "\nКурс " << currentCourse << ":\n";
            }
            cout << "\t" << students[i].surname << endl;
        }
    }

    bool readFromFile(string filename) {
        ifstream infile;
        infile.open(filename);

        if (!infile.is_open()) {
            cerr << "Ошибка: не удалось открыть файл " << filename << endl;
            return false;
        }

        students.clear();

        while (infile) {
            Student newStudent;
            if (!(infile >> newStudent.surname >> newStudent.course >> newStudent.direction)) {
                if (infile.eof()) {
                    break;
                } else {
                    cout << "Ошибка: некорректный формат данных в файле " << filename << endl;
                    students.clear();
                    infile.close();
                    return false;
                }
            }
            students.push_back(newStudent);
        }

        infile.close();

        return true;
    }
};

int main() {
    StudentList list;

    string filename = "test.txt";
    //cout << "Введите имя файла: ";
    //cin >> filename;

    bool success = list.readFromFile(filename);

    if (success) {
        list.printStudentsByGroup();
    }

    return 0;
}

*/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class StudentList {
public:
    struct Student {
        string surname;
        int course;
        string direction;
    };

    vector<Student> students;

    void setCourse(int index, int course) {
        students[index].course = course;
    }
    
    void getStudentsByCourse(int course) {
        cout << "Студенты на курсе " << course << ":\n" << endl;

        bool found = false; // флаг наличия студентов на данном курсе в списке

        for (int i = 0; i < students.size(); i++) {
            if (students[i].course == course) {
                cout << "\t" << students[i].surname << " - " << students[i].direction << endl;
                found = true; // обновляем флаг, если студенты на курсе есть в списке
            }
        }

        if (!found) {
            cout << "Студентов на курсе " << course << " нет в списке" << endl;
        }
    }
    
    void printStudentsByGroup(int course) {
        // Фильтруем студентов по курсу
        vector<Student> filteredStudents;
        copy_if(students.begin(), students.end(), back_inserter(filteredStudents), [course](const Student& s) {
            return s.course == course;
        });

         // Сортируем отфильтрованных студентов по группам, курсу и фамилиям
        sort(filteredStudents.begin(), filteredStudents.end(), [](const Student& a, const Student& b) {
            if (a.direction != b.direction) {
               return a.direction < b.direction;
            } else if (a.course != b.course) {
               return a.course < b.course;
            } else {
               return a.surname < b.surname;
            }
        });

        // Выводим отфильтрованных и отсортированных студентов на экран
        cout << "Студенты на курсе " << course << ":\n" << endl;

        if (filteredStudents.empty()) {
            cout << "Студентов на курсе " << course << " нет в списке" << endl;
            return;
        }

        string currentGroup = "";
        for (int i = 0; i < filteredStudents.size(); i++) {
            if (filteredStudents[i].direction != currentGroup) {
               currentGroup = filteredStudents[i].direction;
               cout << "\nГруппа " << currentGroup << ":\n";
            }
            cout << "\t" << filteredStudents[i].surname << endl;
        }
    }


    bool readFromFile(string filename) {
        ifstream infile;
        infile.open(filename);

        if (!infile.is_open()) {
            cerr << "Ошибка: не удалось открыть файл " << filename << endl;
            return false;
        }

        students.clear();

        while (infile) {
            Student newStudent;
            if (!(infile >> newStudent.surname >> newStudent.course >> newStudent.direction)) {
                if (infile.eof()) {
                    break;
                } else {
                    cout << "Ошибка: некорректный формат данных в файле " << filename << endl;
                    students.clear();
                    infile.close();
                    return false;
                }
            }
            students.push_back(newStudent);
        }

        infile.close();

        return true;
    }
};

int main() {
    StudentList list;

    string filename = "test.txt";
    //cout << "Введите имя файла: ";
    //cin >> filename;

    bool success = list.readFromFile(filename);

    if (success) {
        int course;
        cout << "Введите номер курса: ";
        cin >> course;
        list.printStudentsByGroup(course);
    }

    return 0;
}




Смирнов 1 ИТ-22 
Иванов 1 ИТ-22 
Кузнецов 5 ИТ-19
Соколов 5 ИТ-19
Попов 1 ИТ-22 
Лебедев 1 ИТ-22 
Козлов 5 ИТ-19
Новиков 5 ИТ-19
Морозов 5 ИТ-19
Петров 5 ИТ-19
Волков 5 ИТ-19
Соловьёв 5 ИТ-19
Васильев 1 ИТ-22 
Зайцев 5 ИТ-19
Павлов 5 ИТ-19
Семёнов 5 ИТ-19
Голубев 5 ИТ-19
Виноградов 5 БИ-18
Богданов 1 ИТ-22 
Воробьёв 5 БИ-18
Фёдоров 5 БИ-18
Михайлов 5 БИ-18
Беляев 5 БИ-18
Тарасов 5 БИ-18
Белов 5 БИ-18
Комаров 5 БИ-18
Орлов 5 БИ-18
Киселёв 5 БИ-18
Макаров 5 БИ-18
Андреев 5 БИ-18
Ковалёв 5 БИ-18
Ильин 5 БИ-18
Гусев 1 ИТ-22 
Титов 5 БИ-18
Кузьмин 5 БИ-18
Кудрявцев 5 БИ-18
Баранов 5 БИ-18
Куликов 5 БИ-18
Алексеев 5 БИ-18
Степанов 5 БИ-18
Яковлев 5 БИ-18
Сорокин 5 БИ-18
Сергеев 5 БИ-18
Романов 5 БИ-18
Захаров 4 БИ-19
Борисов 4 БИ-19
Королёв 4 БИ-19
Герасимов 4 БИ-19
Пономарёв 1 ИТ-22 
Григорьев 4 БИ-19
Лазарев 4 БИ-19
Ершов 4 БИ-19
Никитин 4 БИ-19
Соболев 4 БИ-19
Рябов 4 БИ-19
Поляков 4 БИ-19
Цветков 4 БИ-19
Данилов 4 БИ-19
Жуков 4 БИ-19
Фролов 4 БИ-19
Журавлёв 3 БИ-20
Николаев 3 БИ-20
Крылов 3 БИ-20
Максимов 3 БИ-20
Сидоров 3 БИ-20
Осипов 3 БИ-20
Белоусов 1 ИТ-22 
Федотов 1 ИТ-22 
Дорофее 1 ИТ-22 
Егоров 1 ИТ-22 
Матвеев 1 ИТ-22 
Бобров 3 БИ-20
Дмитриев 3 БИ-20
Калинин 3 БИ-20
Анисимов 3 БИ-20
Петухов 3 БИ-20
Антонов 3 БИ-20
Тимофеев 1 ИТ-22 
Никифоров 1 ИТ-22 
Веселов 3 БИ-20
Филиппов 1 ИТ-22 
Марков 1 ИТ-22 
Большаков 1 ИТ-22 
Суханов 1 ИТ-22 
Миронов 1 ИТ-22 
Ширяев 1 ИТ-22 
Александров 1 ИТ-22 
Коновалов 3 БИ-22
Шестаков 3 БИ-22
Казаков 3 БИ-22
Ефимов 3 БИ-22
Денисов 3 БИ-22
Громов 2 ИСТ-21
Фомин 2 ИСТ-21
Давыдов 2 ИСТ-21
Мельников 2 ИСТ-21
Щербаков 2 ИСТ-21
Блинов 2 ИСТ-21
Колесников 2 ИСТ-21
Карпов 2 ИСТ-21
Афанасьев 2 ИСТ-21
Власов 2 ИСТ-21
Маслов 2 ИСТ-21
Исаков 2 ИСТ-21
Тихонов 2 ИСТ-21
Аксёнов 2 ИСТ-21
Гаврилов 2 ИСТ-21
Родионов 2 ИСТ-21
Котов 2 ИСТ-21
Горбунов 2 ИСТ-21
Кудряшов 2 ИСТ-21
Быков 2 ИСТ-21
Зуев 2 ИСТ-21
Третьяков 2 ИСТ-21
Савельев 2 ИСТ-21
Панов 2 ИСТ-21
Рыбаков 2 ИСТ-21
Суворов 2 ИСТ-21
Абрамов 2 ИСТ-21
Воронов 2 ИСТ-21
Мухин 2 ИСТ-21
Архипов 2 ИСТ-21
Трофимов 4 ИВТ-19
Мартынов 4 ИВТ-19
Емельянов 4 ИВТ-19
Горшков 4 ИВТ-19
Чернов 4 ИВТ-19
Овчинников 4 ИВТ-19
Селезнёв 4 ИВТ-19
Панфилов 4 ИВТ-19
Копылов 4 ИВТ-19
Михеев 4 ИВТ-19
Галкин 4 ИВТ-19
Назаров 4 ИВТ-19
Лобанов 4 ИВТ-19
Лукин 4 ИВТ-19
Беляков 4 ИВТ-19
Потапов 4 ИВТ-19
Некрасов 4 ИВТ-19
Хохлов 4 ИВТ-19
Жданов 4 ИВТ-19
Наумов 4 ИВТ-19
Шилов 4 ИВТ-19
Воронцов 4 ИВТ-19
Ермаков 6 ИТ-17
Дроздов 6 ИТ-17
Игнатьев 6 ИТ-17
Савин 6 ИТ-17
Логинов 6 ИТ-17
Сафонов 6 ИТ-17
Капустин 6 ИТ-17
Кириллов 6 ИТ-17
Моисеев 6 ИТ-17
Елисеев 6 ИТ-17
Кошелев 6 ИТ-17
Костин 6 ИТ-17
Горбачёв 6 ИТ-17
Орехов 6 ИТ-17
Ефремов 6 ИТ-17
Исаев 6 ИТ-17
Евдокимов 6 ИТ-17
Калашников 6 ИТ-17
Кабанов 6 ИТ-17
Носков 6 ИТ-17
Юдин 6 ИТ-17
Кулагин 6 ИТ-17
Лапин 6 ИТ-17 
Прохоров 6 ИТ-17  
Нестеров 5 ИТ-18
Харитонов 5 ИТ-18
Агафонов 5 ИТ-18
Муравьёв 5 ИТ-18
Ларионов 5 ИТ-18
Федосеев 5 ИТ-18
Зимин 5 ИТ-18
Пахомов 5 ИТ-18
Шубин 5 ИТ-18
Игнатов 5 ИТ-18
Филатов 5 ИТ-18
Крюков 5 ИТ-18
Рогов 5 ИТ-18
Кулаков 5 ИТ-18
Терентьев 5 ИТ-18
Молчанови 5 ИТ-18
Владимиров 5 ИТ-18
Артемьев 4 ИСТ-20
Гурьев 3 ИСТ-20
Зиновьев 3 ИСТ-20
Гришин 3 ИСТ-20
Кононов 3 ИСТ-20
Дементьев 3 ИСТ-20
Ситников 3 ИСТ-20
Симонов 3 ИСТ-20
Мишин 3 ИСТ-20
Фадеев 3 ИСТ-20
Комиссаров 2 ИСТ-22
Мамонтов 2 ИСТ-22
Носов 2 ИСТ-22
Гуляев 2 ИСТ-22
Шаров 2 ИСТ-22
Устинов 2 ИСТ-22
Вишняков 2 ИСТ-22
Евсеев 1 ПИ-22
Лаврентьев 1 ПИ-22
Брагин 1 ПИ-22
Константинов 1 ПИ-22
Корнилов 1 ПИ-22
Авдеев 1 ПИ-22
Зыков 1 ПИ-22
Бирюков 1 ПИ-22
Шарапов 1 ПИ-22
Никонов 1 ПИ-22
Щукин 1 ПИ-22
Дьячков 1 ПИ-22
Одинцов 1 БИ-22
Сазонов 1 БИ-22
Якушев 1 БИ-22
Красильников 1 БИ-22
Гордеев 1 БИ-22
Самойлов 1 БИ-22
Князев 1 БИ-22
Беспалов 1 БИ-22
Уваров 1 БИ-22
Шашков 1 БИ-22
Бобылёв 1 БИ-22
Доронин 1 ИСТ-22
Белозёров 1 ИСТ-22
Рожков 1 ИСТ-22
Самсонов 1 ИСТ-22
Мясников 1 ИСТ-22
Лихачёв 1 ИСТ-22
Буров 1 ИСТ-22
Сысоев 1 ИСТ-22
Фомичёв 1 ИСТ-22
Русаков 1 ИВТ-22
Стрелков 1 ИВТ-22
Гущин 1 ИВТ-22
Тетерин 1 ИВТ-22
Колобов 1 ИВТ-22
Субботин 1 ИВТ-22
Фокин 1 ИВТ-22
Блохин 1 ИВТ-22
Селиверстов 1 ИВТ-22
Пестов 1 ИВТ-22
Кондратьев 1 ИТ-22 
Силин 1 ИТ-22 
Меркушев 1 ИТ-22 
Лыткин 1 ИТ-22 
Туров 1 ИТ-22 