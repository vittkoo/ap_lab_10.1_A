#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialnist { IT, PHYSICS, MATHEMATICS, ENGINEERING };

string specialnistStr[] = { "IT", "Physics", "Mathematics", "Engineering" };

struct Student {
    string prizv;
    int kurs;
    Specialnist spec;
    int fizyka;
    int matematika;
    int informatyka;
};

void Create(Student* students, const int N);
void Print(const Student* students, const int N);
void PrintAverages(const Student* students, const int N);
double PercentHighPhysics(const Student* students, const int N);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: ";
    cin >> N;

    Student* students = new Student[N];

    Create(students, N);
    Print(students, N);
    PrintAverages(students, N);

    double percent = PercentHighPhysics(students, N);
    cout << "Процент студентів з оцінками 4 або 5 з фізики: "
        << fixed << setprecision(2) << percent << "%" << endl;

    delete[] students;
    return 0;
}

void Create(Student* students, const int N) {
    int spec;
    for (int i = 0; i < N; i++) {
        cout << "Студент № " << i + 1 << ":" << endl;

        cin.ignore();
        cout << "    Прізвище: ";
        getline(cin, students[i].prizv);

        cout << "    Курс (1-4): ";
        cin >> students[i].kurs;

        cout << "    Спеціальність (0 - IT, 1 - Physics, 2 - Mathematics, 3 - Engineering): ";
        cin >> spec;
        students[i].spec = (Specialnist)spec;

        cout << "    Оцінка з фізики: ";
        cin >> students[i].fizyka;

        cout << "    Оцінка з математики: ";
        cin >> students[i].matematika;

        cout << "    Оцінка з інформатики: ";
        cin >> students[i].informatyka;

        cout << endl;
    }
}

void Print(const Student* students, const int N) {
    cout << "===================================================================================" << endl;
    cout << "| № | Прізвище       | Курс  |  Спеціальність | Фізика | Математика | Інформатика |" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(2) << right << i + 1 << " "
             << "| " << setw(15) << left << students[i].prizv
             << "| " << setw(4) << right << students[i].kurs << " "
             << "| " << setw(13) << left << specialnistStr[students[i].spec]
             << "| " << setw(7) << right << students[i].fizyka
             << "| " << setw(11) << right << students[i].matematika
             << "| " << setw(13) << right << students[i].informatyka << " |" << endl;
    }

    cout << "===================================================================================" << endl;
}

void PrintAverages(const Student* students, const int N) {
    cout << "Середні бали студентів:" << endl;
    for (int i = 0; i < N; i++) {
        double avg = (students[i].fizyka + students[i].matematika + students[i].informatyka) / 3.0;
        cout << setw(15) << left << students[i].prizv
            << ": " << fixed << setprecision(2) << avg << endl;
    }
}

double PercentHighPhysics(const Student* students, const int N) {
    int count = 0, total = 0;

    for (int i = 0; i < N; i++) {
        if (students[i].fizyka >= 4) {
            count++;
        }
        total++;
    }

    return (total > 0) ? (100.0 * count / total) : 0.0;
}