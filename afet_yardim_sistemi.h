#include<stdio.h>
#include<stdlib.h>
//Constant Variables
#define MAX_AFETZEDE_SAYISI 10
#define MAX_ISIM_UZUNLUK 10
#define MAX_TELEFON_UZUNLUK 10
#define MAX_TALEP_UZUNLUK 10
#define MAX_ADRES_UZUNLUK 10
#define MAX_TALEP_SAYISI 10


//Global Variables
char afetzede_isimleri[MAX_AFETZEDE_SAYISI][MAX_ISIM_UZUNLUK],afetzede_soyisimleri[MAX_AFETZEDE_SAYISI][MAX_ISIM_UZUNLUK],afetzede_telefonlari[MAX_AFETZEDE_SAYISI][MAX_TELEFON_UZUNLUK],afetzede_adresleri[MAX_AFETZEDE_SAYISI][MAX_ADRES_UZUNLUK],talep_aciklamalari[MAX_TALEP_SAYISI][MAX_TALEP_UZUNLUK];
int talep_afetzede_idleri[MAX_TALEP_SAYISI];
int talep_sayisi,afetzede_sayisi = 0;

//Function Defining
void afetzede_ekle(char *ad, char *soyad, char *telefon, char *adres);
void afetzede_guncelle(int id, char *ad, char *soyad, char *telefon, char *adres);
void afetzede_sil(int id);
void yardim_talebi_kaydet(int id, char *aciklama);
void afetzede_listele();
void afetzede_ara(int id);
void yardim_talepleri_listele();
void hata_mesaji(char *error);
void menu_goster();

//Custom Functions (Kendi Yaptigim fonksiyonlar)
//Girilen stringi baska bir stringe atamak icin fonksiyon
char string_copy(char *str2,char *str1){
	int i;
	//Burada string uzerinde tek tek arama yaparak indexlerdeki elemanlari karsinin indexindeki elemanlarla degistiriyor
	for (i = 0; str1[i] != '\0'; ++i) {
        str2[i] = str1[i];
    }
    str2[i] = '\0';
    return 0;
};
//Girilen stringin uzunlugunu alan fonksiyon
int str_length(char *str){
	int i=0;  
     //Array elemani null olana kadar sayiyi arttir null oldugunda uzunlugunu dondur
    while(str[i] != '\0') i++;  
     
    return i;  
};

//Surekli olarak isleme devam edilip edilmeyecegini kontrol eden fonksiyon
void options(){
	int process;
	printf("Baska Yapmak istediginiz bir islem var mi? (Evet icin 1 Hayir icin 0'i tuslayiniz): ");
	scanf("%d",&process);
	if (process == 1){
		menu_goster();
	}else if(process == 0){
		printf("Program Kapatiliyor...");
		return;
	}else{
		hata_mesaji("SelectionError");
	}
}

//Process Functions (Islem Fonksiyonlari)

void afetzede_ekle(char *ad, char *soyad, char *telefon, char *adres){
	//fonksiyon parametrelerin icinde arraylerdeki elemanlar bulunmaktadir
	char validate_name[MAX_ISIM_UZUNLUK],validate_surname[MAX_ISIM_UZUNLUK],validate_number[MAX_TELEFON_UZUNLUK],validate_adress[MAX_ADRES_UZUNLUK];
	printf("------------------------------\n");
	printf("AFETZEDE EKLEME EKRANI\n");
	printf("------------------------------\n");
	//Burada hatali girisler durumunda bir validasyon yani hata kontrol islemi yapilmaktadir. Girilen inputlar once local degiskenlerde kontrol edilir
	printf("Afetzede Ismi: ");
	scanf("%s",validate_name);
	if (str_length(validate_name) > MAX_ISIM_UZUNLUK){
		hata_mesaji("NameLengthError");
		return;
	}//Hata Kontrolü
	printf("Afetzede Soyadi: ");
	scanf("%s",validate_surname);
	if (str_length(validate_surname) > MAX_ISIM_UZUNLUK){
		hata_mesaji("NameLengthError");
		return;
	}
	printf("Afetzede Telefonu: ");
	scanf("%s",validate_number);
	if (str_length(validate_number) > MAX_TELEFON_UZUNLUK){
		hata_mesaji("NumberLengthError");
		return;
	}
	printf("Afetzede Adresi: ");
	scanf("%s",validate_adress);
	if (str_length(validate_number) > MAX_TELEFON_UZUNLUK){
		hata_mesaji("AdressLengthError");
		return;
	}
	//Yukaridaki islemin ardindan yazmis oldugum string_copy fonksiyonunu icinde local variable ile hocanin vermis oldugu arraylerdeki elemanin yerini degistirerek atama islemi yapiyorum
	string_copy(ad,validate_name);
	string_copy(soyad,validate_surname);
	string_copy(telefon,validate_number);
	string_copy(adres,validate_adress);
	talep_afetzede_idleri[afetzede_sayisi] = rand()%10000+1;
	int i;
	
	afetzede_sayisi += 1;
	printf("Afetzede id: %d\n",talep_afetzede_idleri[i]);
	printf("\nAfetzede basariyla kaydedildi!\n");
	options();
};
//menu_goster fonksiyonu icinde id indexi ile diger veriler arasindaki index iliskisini kurarak parametrelerin her birine array icindeki hedef verileri atadim
void afetzede_guncelle(int id, char *ad, char *soyad, char *telefon, char *adres){
	char validate_id, validate_name[MAX_ISIM_UZUNLUK],validate_surname[MAX_ISIM_UZUNLUK],validate_number[MAX_TELEFON_UZUNLUK],validate_adress[MAX_ADRES_UZUNLUK];
	printf("------------------------------\n");
	printf("AFETZEDE GUNCELLEME EKRANI\n");
	printf("------------------------------\n");
	//Tekrardan afetzede_ekle fonksiyonunda oldugu gibi bir hata kontrol islemi yapiliyor
	printf("Afetzede Ismi: ");
	scanf("%s",validate_name);
	if (str_length(validate_name) > MAX_ISIM_UZUNLUK){
		hata_mesaji("NameLengthError");
		return;
	}//Hata Kontrolü
	printf("Afetzede Soyadi: ");
	scanf("%s",validate_surname);
	if (str_length(validate_surname) > MAX_ISIM_UZUNLUK){
		hata_mesaji("NameLengthError");
		return;
	}
	printf("Afetzede Telefonu: ");
	scanf("%s",validate_number);
	if (str_length(validate_number) > MAX_TELEFON_UZUNLUK){
		hata_mesaji("NumberLengthError");
		return;
	}
	printf("Afetzede Adresi: ");
	scanf("%s",validate_adress);
	if (str_length(validate_number) > MAX_TELEFON_UZUNLUK){
		hata_mesaji("AdressLengthError");
		return;
	}
	//Id ile ayný indexte bulunan veriler ile güncel veriler yer degistiriyor
	string_copy(ad,validate_name);
	string_copy(soyad,validate_surname);
	string_copy(telefon,validate_number);
	string_copy(adres,validate_adress);
	int i;
	printf("Afetzede basariyla Guncellendi!\n");
	options();
};

void afetzede_sil(int id){
	int i;
	printf("------------------------------\n");
	printf("AFETZEDE SILME EKRANI\n");
	printf("------------------------------\n");
	printf("Silinecek afetzedenin ID'si: ");
	scanf("%d",&id);
	//Burada once girilen id'nin var olup olmadigini kontrol ediyoruz
	for(i = 0; i < afetzede_sayisi+1; i++){
		if(talep_afetzede_idleri[i] == id){
			break;
		}
		if (talep_afetzede_idleri[i] == '\0'){
			hata_mesaji("IDSearchError");
			return;
		}
		}
	//Burada ilk for loopta id'nin indexini ariyoruz
	for(i = 0; i < afetzede_sayisi+1; i++){
		if(talep_afetzede_idleri[i] == id){
			int j;
			/*ardindan id bulundugunda ikinci for loop devreye giriyor ve bu sefer idnin bulundugu indexten baslayip her indexteki bir elemani sonraki indexine esitleyerek hedef
			index ve idlerdeki verileri silmis oluyoruz
			*/
			for(j = i; j < afetzede_sayisi+1; j++){
				talep_afetzede_idleri[j] = talep_afetzede_idleri[j+1];
				string_copy(afetzede_isimleri[j],afetzede_isimleri[j+1]);
				string_copy(afetzede_soyisimleri[j],afetzede_soyisimleri[j+1]);
				string_copy(afetzede_adresleri[j],afetzede_adresleri[j+1]);
				string_copy(afetzede_telefonlari[j],afetzede_telefonlari[j+1]);
				string_copy(talep_aciklamalari[j],talep_aciklamalari[j+1]);
			}
		};
		
	}
	afetzede_sayisi -= 1;
	printf("\nAfetzede Basariyla Silindi!\n");
	options();
};

void yardim_talebi_kaydet(int id, char *aciklama){
	//Burada yine menu_goster fonksiyonundan yolladigim hedef indexteki alani aciklama olarak yolluyorum
	int validate_id,i;
	char validate_description[MAX_TALEP_UZUNLUK];
	printf("Talep Aciklamasini Giriniz: ");
	scanf("%s",validate_description);
	//Aciklamanin uzunlugunun validasyonunu yapan algoritma
	if (str_length(validate_description) > MAX_ISIM_UZUNLUK){
		hata_mesaji("DescriptionLengthError");
		return;
	}
	//Yer degistirma islemi
	string_copy(aciklama,validate_description);
	talep_sayisi += 1;
	printf("\nTalep Basariyla Eklendi!\n");
		options();
}

void afetzede_listele(){
	int i = 0;
	printf("------------------------------\n");
	printf("AFETZEDE LISTESI\n");
	//for dongusu ile arraylerin hepsinde arama yapma islemi
	for(i = 0; i < afetzede_sayisi; i++){
		printf("------------------------------\n");
		printf("Afetzede ID'si: %d\n",talep_afetzede_idleri[i]);
		printf("Afetzede Ismi: %s\n",afetzede_isimleri[i]);
		printf("Afetzede Soyismi: %s\n",afetzede_soyisimleri[i]);
		printf("Afetzede Adresi: %s\n",afetzede_adresleri[i]);
		printf("Afetzede Telefonu: %s\n",afetzede_telefonlari[i]);
		printf("Afetzede Talebi: %s\n",talep_aciklamalari[i]);
	}
	printf("------------------------------\n");
	printf("Toplam Afetzede Sayisi: %d\n",afetzede_sayisi);
	options();
};

void afetzede_ara(int id){
	int i;
	printf("------------------------------\n");
	printf("AFETZEDE ARAMA EKRANI\n");
	printf("------------------------------\n");
	printf("Aranacak afetzedenin ID'si: ");
	scanf("%d",&id);
	for(i = 0; i < afetzede_sayisi+1; i++){
		//id hata kontrol islemi
		if (talep_afetzede_idleri[i] == '\0'){
			hata_mesaji("IDSearchError");
			return;
		}
		if(talep_afetzede_idleri[i] == id){
			//Afetzede idsini bulup afetzedenin verilerini dondururyor
			printf("------------------------------\n");
			printf("Afetzede ID'si: %d\n",id);
			printf("Afetzede Ismi: %s\n",afetzede_isimleri[i]);
			printf("Afetzede Soyismi: %s\n",afetzede_soyisimleri[i]);
			printf("Afetzede Adresi: %s\n",afetzede_adresleri[i]);
			printf("Afetzede Telefonu: %s\n",afetzede_telefonlari[i]);
			printf("Afetzede Talebi: %s\n",talep_aciklamalari[i]);
			options();
		};
	}

}
		
void yardim_talepleri_listele(){
	int i;
	//for dongusuyle yardim taleplerinin hepsini listeledim
	for(i = 0; i < talep_sayisi; i++){
		printf("------------------------------\n");
		printf("%d ID'li afetzedenin talebi: %s\n",talep_afetzede_idleri[i],talep_aciklamalari[i]);
	} 
	printf("------------------------------\n");
	printf("Toplam Talep Sayisi: %d\n",talep_sayisi);
	options();
};

//Burada error parametresi icinde gelen string degerine gore if statementler ile hata dondurdum
void hata_mesaji(char *error){
	if(error == "NameLengthError"){
		printf("\nLutfen girdiginiz Isim ya da Soyisim uzunlugunun %d degerinden az olmasina dikkat ediniz!\n",MAX_ISIM_UZUNLUK);	
	}
	if(error == "NumberLengthError"){
		printf("\nLutfen girdiginiz Numara uzunlugunun %d degerinden az olmasina dikkat ediniz!\n",MAX_TELEFON_UZUNLUK);
	}
	if(error == "AdressLengthError"){
		printf("\nLutfen girdiginiz Adres uzunlugunun %d degerinden az olmasina dikkat ediniz!\n",MAX_ADRES_UZUNLUK);
	}
	if(error == "DescriptionLengthError"){
		printf("\nLutfen girdiginiz Aciklama uzunlugunun %d degerinden az olmasina dikkat ediniz!\n",MAX_TALEP_UZUNLUK);
	}
	if(error == "IDSearchError"){
		printf("Lutfen listede varolan bir id giriniz Dogru Yaptiginizdan emin olunuz!\n");
		options();
		return;
	}
	if(error == "SelectionError"){
		printf("Lutfen Tercihlerinizi Dogru Yaptiginizdan emin olunuz!\n");
		options();
		return;
	}
	afetzede_ekle(afetzede_isimleri[afetzede_sayisi],afetzede_soyisimleri[afetzede_sayisi],afetzede_telefonlari[afetzede_sayisi],afetzede_adresleri[afetzede_sayisi]);
};

