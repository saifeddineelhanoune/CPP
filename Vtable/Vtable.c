#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct Animal Animal;
typedef struct Dog Dog;
typedef struct Cat Cat;

typedef struct {
    void    (*speak)(Animal*);
    void    (*destroy)(Animal*);
} Vtable;

struct Animal {
   Vtable* vptr;
};

struct Dog {
    Animal base;
    int age;
};

struct Cat {
    Animal base;
    char name[19];
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

void    CatSpeak(Animal* this) {
    Cat* cat = (Cat*)this;
    printf("Cat sound!\n");
}

void    CatDestroy(Animal *this) {
    Cat* cat = (Cat*)this;
    printf("Cat destroyed!\n");
    free(this);
}


Vtable animalvtable = {
    .speak = AnimalSpeak,
    .destroy = AnimalDestroy
};

Vtable DogVtable = {
    .speak = DogSpeak,
    .destroy = DogDestroy
};

Vtable CatVtable = {
    .speak = CatSpeak,
    .destroy = CatDestroy
};


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

Cat *newCat(char *name) {
    Cat* cat = (Cat*)malloc(sizeof(Cat));
    cat->base.vptr = &CatVtable;
    strcpy(cat->name, name);
    return cat;
}

int main() {
    Animal *animal = newAnimal();
    Dog *dog = newDog(5);
    char name[] = "mimi";
    Cat* cat = newCat(name);

    animal->vptr->speak(animal);
    dog->base.vptr->speak((Animal*)dog);
    cat->base.vptr->speak((Animal*)cat);

    animal->vptr->destroy(animal);
    dog->base.vptr->destroy((Animal*)dog);
    cat->base.vptr->destroy((Animal*)cat);
    return 0;
}
