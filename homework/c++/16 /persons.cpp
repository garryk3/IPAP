#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

const string DATA = "/home/projects/my/ipap/homework/c++/16 /person.txt";

class Person {
    private:
        string name;
        int force;
        Person* nextPerson;
    public:
        Person(string name, int force);
        void setNextPerson(Person* person);
        Person* getNextPerson();
        int getForce();

        ~Person() {
            cout << "Person delete: " << name << endl;
            delete nextPerson;
        }
};

Person::Person(string name, int force) {
    this->name = name;
    this->force = force;
}

void Person::setNextPerson(Person *person) {
    nextPerson = person;
}

Person *Person::getNextPerson() {
    return nextPerson;
}

int Person::getForce() {
    return force;
}

class Enemy {
    private:
        int force = 1000;
    public:
        int getForce();
        void kickedByForce(int enemyForce);
};

int Enemy::getForce() {
    return this->force;
}

void Enemy::kickedByForce(int enemyForce) {
    this->force -= enemyForce;
};

class FileReader {
    private:
        Person* firstPerson; 
    public:
        void read(const string filename);
        void deleteDataSet();
        Person* getFirstDataPointer();
};

Person* FileReader::getFirstDataPointer() {
    return firstPerson;
};

void FileReader::read(const string filename = DATA) {

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

    while(activePerson->getNextPerson()) {
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