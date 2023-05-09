#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "afet_yardim_sistemi.h"
//afet_yardim_sistemi icindeki fonksiyonlar kullanilmak uzere import ediliyor

/* afetzede_yardim_sistemi.h ICINDEKI FONKSIYONLAR:	
	afetzede_ekle(*param1,*param2,*param3,*param4)
	afetzede_guncelle(id,*param2,*param3,*param4,*param5)
	afetzede_sil(id)
	yardim_talebi_kaydet(id,*param2)
	afetzede_listele()
	afetzede_ara(id)
	yardim_talepleri_listele()
	hata_mesaji(*error)
*/
void menu_goster(){
	int process;
	printf("------------------------------\n");
	printf("ISLEM MENU\n");
	printf("------------------------------\n");
	printf("0 - Afetzede Ekle\n1 - Afetzede Guncelle\n2 - Afetzede Sil\n3 - Yardim Talebi Kaydet\n4 - Afetzede Listele\n5 - Afetzede Ara\n6 - Yardim Talepleri Listele\n");
	printf("\nYapmak Istediginiz Islemi Seciniz: ");
	scanf("%d",&process);
	//Yapýlacak iþlemlerin seçileceði alan
	if (process == 0){
		//Header dosyasýndaki afetzede_ekle fonksiyonu
		afetzede_ekle(afetzede_isimleri[afetzede_sayisi],afetzede_soyisimleri[afetzede_sayisi],afetzede_telefonlari[afetzede_sayisi],afetzede_adresleri[afetzede_sayisi]);
		}
	else if(process == 1){
		int id,i;
		printf("Guncellenecek afetzedenin ID'si: ");
		scanf("%d",&id);
		//Girilen id'nin arraydeki indexi diger verilerin bulundugu arraylerdeki indexler ile eslesiyorsa eslesen verileri dondurur.
		for(i = 0; i < afetzede_sayisi+1; i++){
			if (talep_afetzede_idleri[i] == '\0'){
				hata_mesaji("IDSearchError");
				return;
			}
			if(talep_afetzede_idleri[i] == id){
				//array icindeki aramada deger id'ye esitse afetzede_guncelle modulunu çagirir
				afetzede_guncelle(id,afetzede_isimleri[i],afetzede_soyisimleri[i],afetzede_telefonlari[i],afetzede_adresleri[i]);
			}
		}
	}
	else if(process == 2){
		int id;
		afetzede_sil(id);
	}
	else if(process == 3){
		//Id ile ayni indexte olan verileri kontrol edip ceker ve fonksiyona gonderir
		int id,i;
		printf("------------------------------\n");
		printf("TALEP EKLEME EKRANI\n");
		printf("------------------------------\n");
		printf("Afetzede ID'si giriniz: ");
		scanf("%d",&id);
		//Aranan id'nin var olup olmadiginin aramasini yapan algoritma
		for(i = 0; i < afetzede_sayisi+1; i++){
			if(talep_afetzede_idleri[i] == id){
				break;
				}
			if (talep_afetzede_idleri[i] == '\0'){
				hata_mesaji("IDSearchError");
				return;
				}
			}
		//Id'nin indexi ile eslesen indexteki verileri bulup array icine yazip fonksiyona koyuyoruz.
		for(i = 0; i < afetzede_sayisi; i++){
			if(talep_afetzede_idleri[i] == id){
				yardim_talebi_kaydet(id,talep_aciklamalari[i]);
			}
		}
	}
	else if(process == 4){afetzede_listele();}
	else if(process == 5){
		int id;
		afetzede_ara(id);
	}
	else if(process == 6){yardim_talepleri_listele();}
	//Istenmeyen bir tus girildiginde hata mesaji gonderir
	else{hata_mesaji("SelectionError");}
};
//Main Functions
int main(){
	srand(time(NULL));
	menu_goster();
}


