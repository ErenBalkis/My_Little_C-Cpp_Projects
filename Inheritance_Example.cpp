#include <iostream>

// Ana Dikdörtgen sınıfı oluşturulur.
class Dikdortgen {
protected:
    // Kenar uzunlukları için değişkenler tanımlanır.
    int genislik;
    int yukseklik;
public:
    // Yapıcı metod nesne oluşturulunca kenar uzunluklarını alır ve bu değişkenlere eşitler.
    Dikdortgen(int g, int y){
        genislik = g;
        yukseklik = y;
        std::cout << genislik << " " << yukseklik << std::endl;
    }
    // Dikdörtgen nesnesinin alanını hesaplayan fonksiyon.
    int alanHesapla() {
        return genislik * yukseklik;
    }
};

// Dikdörtgen sınıfından türetilmiş Kare sınıfı
class Kare : public Dikdortgen {
public:
    // Yapıcı metod, kare nesnesi oluşturulunca bir tane kenar uzunluğu alır ve
    // ana sınıftaki yapıcı metoda iki kenar uzunluğu için de kare nesnesinin tek kenar
    uzunluğunu gönderir.
    Kare(int kenar): Dikdortgen(kenar,kenar) {
        std::cout<<"Karenin kenarı: " << kenar <<std::endl;
    }
};

int main() {
    // Dikdörtgen nesnesi oluşturulur ve alanı hesaplanır.
    Dikdortgen dikdortgen1(5,10);
    std::cout<<"Dikdortgenin alanı: " << dikdortgen1.alanHesapla()<<std::endl;
  
    // Kare nesnesi oluşturulur ve ana sınıftaki fonksiyon ile alanı hesaplanır.
    Kare kare(5);
    std::cout<< "Karenin alanı: " << kare.alanHesapla()<<std::endl;return 0;
}
