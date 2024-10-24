#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	delete j; //should not create a leak
// 	delete i;

// 	return 0;
// }

// just for testing . don't submit it as it is
int main() {
    // 配列のサイズ
    const int arraySize = 4;

    // Animal型ポインタの配列を作成（half Dog, half Cat）
    Animal* animalArray[arraySize];

    // 配列にCatオブジェクトを2つ配置
    for (int i = 0; i < arraySize / 2; i++) {
        animalArray[i] = new Cat();
    }

    // 配列の後半にもCatオブジェクトを配置
    for (int i = arraySize / 2; i < arraySize; i++) {
        animalArray[i] = new Dog();
    }

    // 配列の各要素のmakeSoundを呼び出す
    for (int i = 0; i < arraySize; i++) {
        animalArray[i]->makeSound();
    }

    // メモリの解放
    for (int i = 0; i < arraySize; i++) {
        delete animalArray[i];  // Animal*型としてdeleteする
    }

    return 0;
}
