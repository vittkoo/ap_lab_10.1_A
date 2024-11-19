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
    cout << "������ ������� ��������: ";
    cin >> N;

    Student* students = new Student[N];

    Create(students, N);
    Print(students, N);
    PrintAverages(students, N);

    double percent = PercentHighPhysics(students, N);
    cout << "������� �������� � �������� 4 ��� 5 � ������: "
        << fixed << setprecision(2) << percent << "%" << endl;

    delete[] students;
    return 0;
}

void Create(Student* students, const int N) {
    int spec;
    for (int i = 0; i < N; i++) {
        cout << "������� � " << i + 1 << ":" << endl;

        cin.ignore();
        cout << "    �������: ";
        getline(cin, students[i].prizv);

        cout << "    ���� (1-4): ";
        cin >> students[i].kurs;

        cout << "    ������������ (0 - IT, 1 - Physics, 2 - Mathematics, 3 - Engineering): ";
        cin >> spec;
        students[i].spec = (Specialnist)spec;

        cout << "    ������ � ������: ";
        cin >> students[i].fizyka;

        cout << "    ������ � ����������: ";
        cin >> students[i].matematika;

        cout << "    ������ � �����������: ";
        cin >> students[i].informatyka;

        cout << endl;
    }
}

void Print(const Student* students, const int N) {
    cout << "===================================================================================" << endl;
    cout << "| � | �������       | ����  |  ������������ | Գ���� | ���������� | ����������� |" << endl;
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
    cout << "������ ���� ��������:" << endl;
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