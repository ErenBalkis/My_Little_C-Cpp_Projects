#include <iostream>

// Ana sınıf oluşturulur.
class Karakter {
public:
    // Sanal saldir() fonksiyonu
    virtual void saldir() {
        std::cout << "Bilinmeyen karakter saldırdı" << std::endl;
    }
};

// Karakter sınıfından türetilmiş alt sınıf
class Savasci : public Karakter {
public:
    // Ana sınıftaki(Karakter) saldir() fonksiyonu override edilir. Bu sınıf için özelleştirilir.
    void saldir() override {
        std::cout << "Savaçı saldırdı" << std::endl;
    }
};

// Karakter sınıfından türetilmiş alt sınıf
class Buyucu : public Karakter {
public:
    // Ana sınıftaki(Karakter) saldir() fonksiyonu override edilir. Bu sınıf için özelleştirilir.
    void saldir() override {
        std::cout << "Büyücü saldırdı" << std::endl;
    }
};

int main() {
    Karakter* karakter;

    // 1. Durum: Standart Karakter
    karakter = new Karakter();
    karakter->saldir();
    delete karakter; // Öncekini temizler, bellek sızıntısını önler.

    std::cout << "--------------------" << std::endl;

    // 2. Durum: Savasci
    karakter = new Savasci();
    karakter->saldir();
    delete karakter;

    std::cout << "--------------------" << std::endl;

    // 3. Durum: Buyucu
    karakter = new Buyucu();
    karakter->saldir();
    delete karakter;

    return 0;
}
