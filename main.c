#include <stdio.h>

typedef enum {
    Intercity, Sprinter
} train_type;

typedef enum {
    Amsterdam, Utrecht, Enschede, Amersfoort ,Zwolle ,Deventer
} station_t;

typedef struct {
    train_type kind ;
    int number;
    station_t start;
    station_t dest;
} train_t;

int countTrains(train_t *trainsAtStation [] , int numberOfTrains , train_type t) {
    int count = 0;
    for ( int i = 0; i < numberOfTrains ; i++) {
        if (trainsAtStation[i]->kind == t) {
            count++;
        }
    }
    return count ;
}

train_t redirect(train_t t, station_t s) {
    t.dest = s;
    return t;
}

void printTrain(train_t *train) {
    if (train == NULL){
        printf("NULL");
        return;
    }
    printf("kind: %d, number: %d, start: %d, dest: %d\n", train->kind, train->number, train->start, train->dest);
}

void printTrains(train_t *trains, int numberOfTrains) {
    for (int i = 0; i < numberOfTrains; i++) {
        printTrain(&trains[0]);
    }
}

int checkUniqueness(train_t *trains, int numberOfTrains) {
    for (int i = 0; i < numberOfTrains; i = i + 2) {
        if (trains[i].number == trains[i+1].number) {
            return 0;
        }
    }
    return 1;
}

int main() {
    train_t t1 = {Intercity , 3, Amsterdam, Enschede};
    train_t t2 = {Sprinter , 7, Enschede , Zwolle };
    train_t trains [2] = {t1 , t2};
    int size = sizeof trains / sizeof trains[0];
    printTrains(trains, size);
    checkUniqueness((train_t *) trains, 2);
}
