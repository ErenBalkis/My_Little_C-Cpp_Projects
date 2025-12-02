#include <iostream>
#include <string>


class Yazar {
private:
    std::string ad;
    std::string soyad;
    int dogumYili;
public:
    Yazar(std::string ad, std::string soyad, int dogumYili)
    : ad(ad), soyad(soyad), dogumYili(dogumYili) {}

    void yazdir() {
        std::cout << ad << " " << soyad << ", " << dogumYili << std::endl;
    }
};

class Kitap {
private:
    std::string baslik;
    int yayinYili;
    Yazar yazar;
public:
    Kitap(std::string baslik, int yayinYili, std::string ad, std::string soyad, int dogumYili)
    : baslik(baslik), yayinYili(yayinYili), yazar(ad, soyad, dogumYili) {}
    void goster() {
        std::cout << this->baslik << " " << this->yayinYili <<  std::endl;
        yazar.yazdir();
    }
};


int main() {
    Kitap kitap1("Ben, Robot", 1950, "Isaac", "Asimov", 1920);
    kitap1.goster();

    return 0;
}
