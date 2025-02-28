#include <stdlib.h>
#include <stdio.h>


typedef struct Animal Animal;
typedef struct Dog Dog;

typedef struct {
    void    (*speak)(Animal*);
    void    (*destroy)(Animal*);
} AnimalVtable;

struct Animal {
    AnimalVtable* vptr;
};

struct Dog {
    Animal base;
    int age;
};


//virtual in base class
void    AnimalSpeak(Animal* this) {
    printf("Animal sound!\n");
}
//virtual in base class
void    AnimalDestroy(Animal* this) {
    printf("Animal destroyed!\n");
    free(this);
}

void    DogSpeak(Animal* this) {
    Dog* dog = (Dog*)this;
    printf("Dog sound!\n");
}

void    DogDestroy(Animal *this) {
    Dog* dog = (Dog*)this;
    printf("Dog destroyed!\n");
    free(this);
}



AnimalVtable animalvtable = {
    .speak = AnimalSpeak,
    .destroy = AnimalDestroy
};

AnimalVtable DogVtable = {
    .speak = DogSpeak,
    .destroy = DogDestroy
};


//new
Animal *newAnimal() {
    Animal* animal = (Animal*)malloc(sizeof(Animal));
    animal->vptr = &(animalvtable);
    return animal;
}

Dog *newDog(int age) {
    Dog* dog = (Dog*)malloc(sizeof(Dog));
    dog->base.vptr = &DogVtable;
    dog->age = age;
    return dog;
}

int main() {
    Animal *animal = newAnimal();
    Dog *dog = newDog(5);

    animal->vptr->speak(animal);
    dog->base.vptr->speak((Animal*)dog);

    animal->vptr->destroy(animal);
    dog->base.vptr->destroy((Animal*)dog);
    return 0;
}
