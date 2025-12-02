/*
 * Proje Ismi: Arac ve Motor Kontrol Sistemi
 * Yazar: Eren Balkış/ ErenBalkis
 * Tarih: Aralık 2025
 * * Aciklama: 
 * Bu proje, C++ Nesne Yönelimli Programlama (OOP) prensiplerini göstermektedir.
 * Özellikle "Bileşim" (Composition) ve "Arkadaş Sınıf" (Friend Class) kavramları 
 * üzerine odaklanılmıştır. Bir araç nesnesi, motor nesnesini içerir ve 
 * motorun private (özel) durumunu arkadaşlık yetkisiyle yönetir.
 */

#include <iostream>
#include <string>

// --- MOTOR SINIFI ---
// Motorun özelliklerini ve çalışma durumunu tutar.
class Motor {
private:
    std::string marka;
    int hp; // Beygir Gücü

    // Varsayılan olarak motor kapalıdır (false).
    // Private olduğu için normalde dışarıdan değiştirilemez.
    bool calisiyorMu = false;

public:
    Motor(std::string marka, int hp)
    : marka(marka), hp(hp) {}

    // Motorun durumunu ekrana yazdıran fonksiyon
    void bilgiVer() {
        std::cout << "Motorun markası: " << marka << " ve gücü: " << hp << " HP" << std::endl;
        if (calisiyorMu) {
            std::cout << "Motor şu anda çalışıyor!" << std::endl;
        }
        else std::cout << "Motor şu anda çalışmıyor!" << std::endl;

    }
    // --- FRIEND CLASS (ARKADAŞ SINIF) TANIMLAMASI ---
    // Arac sınıfına "arkadaş" yetkisi veriyoruz.
    // Böylece Arac sınıfı, Motor'un 'private' olan 'calisiyorMu' değişkenine erişebilir.
    friend class Arac;
};

// --- ARAC SINIFI ---
// Motoru içerisinde barındıran ana sınıftır.
class Arac {
private:
    std::string plaka;

    // --- COMPOSITION (BİLEŞİM) İLİŞKİSİ ---
    // Arac "has-a" (sahiptir) Motor.
    // Arac nesnesi oluşturulduğunda motor da oluşturulur.
    Motor motor;

public:
    // Arac Kurucusu
    // Parametre olarak gelen motor bilgilerini, içteki 'motor' nesnesini başlatmak için kullanır.
    Arac(std::string plaka, std::string marka, int hp)
    : plaka(plaka), motor(marka, hp) {}

    // Motoru çalıştıran fonksiyon
    void calistir() {
        // Friend ilişkisi sayesinde 'calisiyorMu' private değişkenine doğrudan erişim.
        motor.calisiyorMu = true;
        std::cout << plaka << " plakali arac calistirildi." << std::endl;
    }
    // Motoru durduran fonksiyon
    void durdur() {
        // Friend ilişkisi ile durum güncellemesi.
        motor.calisiyorMu = false;
        std::cout << plaka << " plakali arac durduruldu." << std::endl;
    }
    // Aracın ve içindeki motorun bilgilerini gösteren fonksiyon
    void bilgiVer() {
        std::cout << "--- Arac Bilgisi ---" << std::endl;
        std::cout << "Plaka: " << plaka << std::endl;

        motor.bilgiVer(); // Bileşim (Composition) içindeki nesnenin fonksiyonunu çağırma.
    }
};


int main() {
    // Nesne Oluşturma (Arac ve Motor aynı anda oluşturulur)
    Arac araba("34 TR 123", "Toyota", 122);

    // Başlangıç Durumu Kontrolü
    araba.bilgiVer();
    std::cout << std::endl;

    // Aracı Çalıştırma (State Change)
    araba.calistir();
    araba.bilgiVer(); // Durumun değiştiğini gözlemleme
    std::cout << std::endl;

    // Aracı Durdurma
    araba.durdur();
    araba.bilgiVer();

    return 0;
}
