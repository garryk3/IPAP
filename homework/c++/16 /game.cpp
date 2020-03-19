#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

const string DATA = "/mnt/d/web/IPAP/homework/c++/16 /person.txt";

class Person {
    private:
        string name = "";
        int force = 0;
        Person* nextPerson;
    public:
        Person(string name = "", int force = 0);
        void setNextPerson(Person* person);
        void createPerson(string name, int force);
        Person* getNextPerson();
        int getForce();

        ~Person() {
            if(nextPerson != nullptr) {
                delete nextPerson;
            }
        }
};

Person::Person(string name, int force) {
    this->name = name;
    this->force = force;
};

void Person::setNextPerson(Person *person) {
    nextPerson = person;
};

Person *Person::getNextPerson() {
    return nextPerson;
};

int Person::getForce() {
    return force;
}

void Person::createPerson(string name, int force) {
    this->name = name;
    this->force = force;
}

class Enemy {
    private:
        int force = 1500;
    public:
        int getForce();
        void kickedByForce(int enemyForce);
};

int Enemy::getForce() {
    return this->force;
};

void Enemy::kickedByForce(int enemyForce) {
    this->force -= enemyForce;
};

class FileReader {
    private:
        Person* firstPerson = new Person; 
    public:
        void read(const string filename);
        void deleteDataSet();
        Person* getFirstDataPointer();
};

Person* FileReader::getFirstDataPointer() {
    return firstPerson;
};

void FileReader::read(const string filename = DATA) {
    ifstream infile;
    infile.open(filename);
    Person* activePerson = this->firstPerson;

    if(infile.is_open()) {
        string num;
        int force;
        // значения идут парами (имя - значение силы)
        while(infile >> num >> force) {
            activePerson->createPerson(num, force);
            Person* nextPerson = new Person();
            activePerson->setNextPerson(nextPerson);
            activePerson = nextPerson;
        }
        delete activePerson; // последний объект лищний без данных
        infile.close();
    } else {
        cout << "File not found!" << endl;
    }
};

void FileReader::deleteDataSet() {
    delete this->firstPerson;
};

class Game {
    private:
        FileReader reader;
        Enemy enemy;
    public:
        void startGame();
        void finishGame();
};

void Game::startGame() {
    this->reader.read();
    Person* activePerson = this->reader.getFirstDataPointer();

    while(activePerson != nullptr) {
        this->enemy.kickedByForce(activePerson->getForce());
        if(activePerson->getNextPerson() != nullptr) {
            activePerson = activePerson->getNextPerson();
        } else {
            activePerson = nullptr;
        }
    }
};

void Game::finishGame() {
    if(this->enemy.getForce() > 0) {
        cout << "You loose! Enemy force is" << this->enemy.getForce() << endl;
    } else {
        cout << "You win! Enemy force is" << this->enemy.getForce() << endl;
    }
    if(this->reader.getFirstDataPointer() != nullptr) {
        this->reader.deleteDataSet();
    }
}

int main() {
    Game game;
    game.startGame();
    game.finishGame();
    return 0;
}