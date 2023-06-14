#include <iostream>
#include <vector>
using namespace std;

class pengarang;
class buku {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;
	buku(string pNama) :nama(pNama) {};
	~buku();
	void tambahPengarang(pengarang*);
	void cetakPengarang();
};
class pengarang {
public:
	string nama;
	vector<buku*>  daftar_buku;

	pengarang(string pNama) :nama(pNama) {};
	~pengarang();
	void tambahBuku(buku*);
	void cetakBuku();
};
void buku::tambahPengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
}
void buku::cetakPengarang() {
	cout << "daftar Pengarang pada penerbit : \"" << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
void pengarang::tambahBuku(buku* pBuku) {
	daftar_buku.push_back(pBuku);
	pBuku->tambahPengarang(this);
}
void pengarang::cetakBuku() {
	cout << "Daftar Buku yang Dikarang : \"" << this->nama << "\":\n";
	for (auto& a : daftar_buku) {
		cout << a->nama << "\n";
	}
	cout << endl;

	for (auto& a : daftar_buku) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
int main() {
	pengarang* varPengarang1 = new pengarang("");
	pengarang* varPengarang2 = new pengarang("");
	pengarang* varPengarang3 = new pengarang("");
	pengarang* varPengarang4 = new pengarang("");
	buku
	dokter* varDokter1 = new dokter("Lia");
	dokter* varDokter2 = new dokter("Asroni");
	dokter* varDokter3 = new dokter("Joko");
	dokter* vardokter4 = new dokter("Giga");
	pasien* varpasien1 = new pasien("Gama Press");
	pasien* varpasien2 = new pasien("Intan Pariwara");

	varDokter1->tambahPasien(varpasien1);
	varDokter1->tambahPasien(varpasien2);
	varDokter2->tambahPasien(varpasien1);

	varDokter1->cetakPasien();
	varDokter2->cetakPasien();
	varpasien1->cetakDokter();
	varpasien2->cetakDokter();

	return 0;
}
