#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
#include <fstream> // Dosya işlemleri için gerekli kütüphane

// Akıllı lamba sistemini temsil eden sınıf
class Lamba {
public:
    // Lambanın durumunu tutan değişken: true (Açık), false (Kapalı)
    bool durum;

    // Lamba sınıfının yapıcı (constructor) metodu
    Lamba() {
        // Program başladığında, kaydedilmiş son durumu dosyadan okur
        durumuDosyadanOku();
    }

    // Durumu dosyadan okuyan yardımcı fonksiyon
    void durumuDosyadanOku() {
        // Okuma için nesne oluşturur ve "durum.txt" dosyasını açmayı dener
        std::ifstream durumOku("durum.txt");

        // Eğer okuma başarılı olursa (dosya varsa ve açılmışsa)
        if (durumOku.is_open()) {
            int okunanDeger;

            // Dosyadan bir int değer okumayı dener (kod daha önce çalışmışsa 0 veya 1 olarak kaydetmiştir.)
            if (durumOku >> okunanDeger) {
                // Okunan int değeri (0 veya 1) bool'a dönüştürerek durumu günceller.
                if (okunanDeger) {
                    durum = true;
                } else durum = false;

                std::cout << "Son kaydedilen durum dosyadan okundu. Lamba baslangic durumu: "
                          << (durum ? "AÇIK" : "KAPALI") << std::endl; //durum==1 ise AÇIK, değilse KAPALI yazar.
            } else {
                // Dosya boşsa veya okunamıyorsa (içinde geçerli bir sayı yoksa)
                durum = false;
                std::cout << "Durum dosyasi okunamadi veya bos. Lamba KAPALI olarak baslatildi." << std::endl;
            }

            // Dosyayı kapat
            durumOku.close();
        } else {
            // Dosya bulunamazsa veya açılamazsa varsayılan durumu ayarla
            durum = false;
            std::cerr << "Durum dosyasi (durum.txt) bulunamadi/acilamadi. Lamba KAPALI olarak baslatildi." << std::endl;
        }
    }

    // Durumu dosyaya yazan yardımcı fonksiyon (Çıkışta çağrılır)
    void durumuDosyayaYaz() {
        // Yazdırma için nesne oluşturur ve "durum.txt" dosyasını açar.
        std::ofstream durumYaz("durum.txt");

        if (durumYaz.is_open()) {
            durumYaz << durum; // bool değeri int olarak dosyaya kaydet: true -> 1, false -> 0

            // Dosyayı kapat
            durumYaz.close();
            std::cout << "\nSon durum 'durum.txt' dosyasina kaydedildi." << std::endl;
        } else {
            std::cerr << "\nHATA: Durum dosyasi kaydedilemedi!" << std::endl;
        }
    }

    // Lambayı açma fonksiyonu
    void ac() {
        if (durum) {
            std::cout << "Lamba zaten açık." << std::endl;
        } else {
            durum = true; // Durumu AÇIK yap
            std::cout << "Lamba açıldı." << std::endl;
        }
    }

    // Lambayı kapatma fonksiyonu
    void kapat() {
        if (!durum) {
            std::cout << "Lamba zaten kapalı." << std::endl;
        } else {
            durum = false; // Durumu KAPALI yap
            std::cout << "Lamba kapatıldı." << std::endl;
        }
    }

    // Lambanın mevcut durumunu ekrana gösterir
    void durumuGoster() {
        if (durum) {
            std::cout << "Lamba şu anda AÇIK." << std::endl;
        } else {
            std::cout << "Lamba şu anda KAPALI." << std::endl;
        }
    }

    // Kullanıcı menüsü
    void menu() {
        int secim = 0;
        while (true) {
            std::cout << "\n--- AKILLI LAMBA SİSTEMİ ---" << std::endl;
            std::cout << "1-> Lambayı aç" << std::endl;
            std::cout << "2-> Lambayı kapat" << std::endl;
            std::cout << "3-> Durumu göster" << std::endl;
            std::cout << "0-> Çıkış" << std::endl;
            std::cout << "Seçiminiz: ";

            // Kullanıcıdan seçim al ve girişin geçerliliğini kontrol et
            if (!(std::cin >> secim) || secim < 0 || secim > 3) {
                std::cout << "Geçersiz seçim, tekrar deneyiniz!" << std::endl;
                std::cin.clear(); // Hata bayraklarını temizle
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Geri kalan hatalı girdiyi yok sayar (sonsuz döngü oluşmaması için)
            } else {
                if (secim == 1) {
                    ac();
                } else if (secim == 2) {
                    kapat();
                } else if (secim == 3) {
                    durumuGoster();
                } else { // secim == 0
                    // Programdan çıkmadan önce son durumu dosyaya kaydet
                    durumuDosyayaYaz();
                    std::cout << "Program Sonlandırıldı!" << std::endl;
                    break;
                }
            }
        }
    }
};

int main() {
    // Lamba nesnesi oluşturulur. Constructor (Yapıcı) çağrılır ve durum dosyadan okunur.
    Lamba lamba;

    // Ana menüyü başlat
    lamba.menu();

    return 0;
}
