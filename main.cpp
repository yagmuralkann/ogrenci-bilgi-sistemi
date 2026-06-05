#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    const double ARA = 0.30;
    const double KISA = 0.10;
    const double ODEV = 0.20;
    const double FINAL = 0.40;

    string arananNo;
    cout <<"Ogrenci No: ";
    cin >> arananNo;

    ifstream dosyaOku("C:/Users/Lenovo/Documents/ogrencidosya.txt");
    ifstream yoklamaOku("C:/Users/Lenovo/Documents/yoklama.dat.txt");
    if (!dosyaOku.is_open()|| !yoklamaOku.is_open()) {
        cout << "Hata:dosyalar bulunamadi!" << endl;
        return 1;
    }


    string no, adSoyad;
    string yNo,yAdSoyad;
    int ara, kisa, odev, finalNotu,devamsizlikSaat;
    bool bulundu = false;

    double sinifToplam = 0;
    int ogrenciSayisi = 0;

    while (dosyaOku >> no >> adSoyad >> ara >> kisa >> odev >> finalNotu &&
           yoklamaOku >>yNo >> yAdSoyad >> devamsizlikSaat){

            if (no==arananNo){
                bulundu = true;

                string durum = (devamsizlikSaat > 16) ? "DZ" : "DV";
                int gosterilecekFinal = finalNotu;
                if (durum =="DZ") {
                        gosterilecekFinal = -9;
                }

          double ort = 0;
          if (durum =="DV") {

        int hAra   = (ara == -1) ? 0 : ara;
        int hKisa  = (kisa == -1) ? 0 : kisa;
        int hOdev  = (odev == -1) ? 0 : odev;
        int hFinal = (finalNotu == -1) ? 0 : finalNotu;

        ort = (hAra * ARA)+(hKisa * KISA) + (hOdev * ODEV) + (hFinal * FINAL);
        }

        string harf, durumSonuc;
        if (durum == "DZ") {
            harf = "DZ";
            durumSonuc= "KALDI (DZ)";
            ort = 0.00;

        }else {
        if(ort >= 90) harf = "AA";
        else if (ort >= 80) harf = "BA";
        else if (ort >= 70) harf = "BB";
        else if (ort >= 60) harf = "CB";
        else if (ort >= 50) harf = "CC";
        else if (ort >= 45) harf = "DC";
        else if (ort >= 40) harf = "DD";
        else harf = "FF";

        if (ort >= 50)durumSonuc = "GECTI";
        else durumSonuc = "KALDI";
        }

     cout << "\n------------------------------------------------------------------------------------------------" << endl;
     cout<<left << setw(12) << "No" << setw(14) << "Ad Soyad"<< setw(8) << "Ara S." << setw(10) << "Kisa S." << setw(8) << "Odev"
         << setw(10) << "Final S." << setw(12) << "Devam S."<< setw(12)<< "Ortalama" << setw(12)<< "Harf Notu"<< endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << left << setw(12) << no;
    cout << setw(15) << adSoyad;
    cout << setw(9) << (ara == -1 ? "GRM" : to_string(ara));
    cout << setw(10) << (kisa == -1 ? "GRM" : to_string(kisa));
    cout << setw(9) << (odev == -1 ? "GRM" : to_string(odev));
    cout << setw(10) << (finalNotu == -1 ? "GRM" : to_string(finalNotu));
    cout << setw(10) << devamsizlikSaat;
    cout << setw(15) << fixed << setprecision(2) << ort;
    cout << setw(10) << harf;
    cout << setw(15) << durumSonuc << endl;
             break;
            }
    }
    if (!bulundu) {
    cout << "\nGirilen numaraya ait ogrenci bulunamadi!" << endl;

    }
    dosyaOku.close();
    return 0;
}
 
