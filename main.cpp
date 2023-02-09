#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

class BirthdayList {
private:
    map<string, Date> birthdays;

public:
    void addBirthday(string name, int day, int month, int year) {
        birthdays[name] = { day, month, year };
    }

    void editBirthday(string name, int day, int month, int year) {
        birthdays[name] = { day, month, year };
    }

    void displayBirthday(string name) {
        auto birthday = birthdays.find(name);
        if (birthday == birthdays.end()) {
            cout << "No birthday found for " << name << endl;
        }
        else {
            cout << name << "'s birthday is on " << birthday->second.day << "/" << birthday->second.month << "/" << birthday->second.year << endl;
        }
    }

    void displayMonthlyBirthdays(int month) {
        cout << "Birthdays in month " << month << ":" << endl;
        vector<string> names;
        for (auto birthday : birthdays) {
            if (birthday.second.month == month) {
                names.push_back(birthday.first);
            }
        }
        sort(names.begin(), names.end());
        for (auto name : names) {
            cout << name << endl;
        }
    }

    void searchBirthday(string name) {
        auto birthday = birthdays.find(name);
        if (birthday == birthdays.end()) {
            cout << "No birthday found for " << name << endl;
        }
        else {
            cout << name << "'s birthday is on " << birthday->second.day << "/" << birthday->second.month << "/" << birthday->second.year << endl;
        }
    }
};

int main() {
    BirthdayList list;

    list.addBirthday("Vaibhav", 20, 5, 2000);
    list.addBirthday("Adarsh", 25, 5, 2002);
    list.addBirthday("Aaryan", 10, 5, 2001);
    list.addBirthday("Joel", 15, 7, 2003);
    list.addBirthday("Shubh", 30, 9, 2004);

    list.displayBirthday("Aaryan");
    list.displayBirthday("Vaibhav");
    list.displayBirthday("Shubh");
    list.displayMonthlyBirthdays(5);

    list.searchBirthday("Piyush");


    return 0;
}
