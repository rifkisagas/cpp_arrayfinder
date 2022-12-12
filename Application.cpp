#include <iostream>
#include <windows.h>

using namespace std;

//----------------------------------------------------------------------
//global declaration zone
int a[10] = {6,8,9,2,3,7,0,1,4,5};
int a2[10];
int nilai,input,i,j,data,target,status,temp,digit;
int program=0;
int pilihan = 0;
int value = 0;
string jawab;
//global declaration zone

//----------------------------------------------------------------------
//function and procedure declaration zone
int main(),main2(),menu(),insert(),remove(),arrange(),save(),check(),maxinput();
int insert_value(),insert_process(),insert_notif();
int sequential(),binary();
void tampil(),check(int c);
int main(),menu2();
string question();
//function and procedure declaration zone
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//Main Menu
int menu(){
	cout << "Opsi : "<<endl;
	cout << "1. Insert Data"<<endl;
	cout << "2. Remove Data"<<endl;
	cout << "3. Arrange Data"<<endl;
	cout << "4. Sequential Search"<<endl;
	cout << "5. Binary Search"<<endl;
	cout << "6. Exit"<<endl<<endl;
	cout << "Masukan pilihan : ";
	cin >>pilihan;
	return pilihan;
}
//Main Menu
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//Question part
string question(){
	cout <<"Yes / No"<<endl;
	cin >> jawab;
	return jawab;
}
//----------------------------------------------------------------------
//Question part

//----------------------------------------------------------------------
//Save point
int save(){
	if(program==1){
		for(i=0;i<10;i++){
			a[i]=a2[i];
		}
	}
	else{
		for(i=0;i<10;i++){
			a2[i]=a[i];
		}
	}
}
//Save point
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//Maximum Input
int maxinput(){
	if(input > 999 or value > 999){
		system("cls");
		cout << endl;
		cout << "Input melebihi batas maksimal!"<<endl;
		cout << "Maksimal input : 999"<<endl<<endl;
		system("pause");
		status = 1;
		insert();
	}
}
//Maximum Input
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//Main part for insert
int insert(){
	system("cls");
	if (status == 0)
	cout << "Anda memasuki menu Insert Data."<<endl<<endl;
	else{
		//cout << "Data Tersimpan ! "<<endl;
		cout << "Anda dikembalikan ke menu Insert Data."<<endl<<endl;
	}
	tampil();
	cout << "Opsi : "<<endl;
	cout << "1.) Insert by Index"<<endl;
	cout << "2.) Insert Sequentially"<<endl;
	cout << "0.) Back"<<endl;
	cout << "Masukan opsi anda : ";
	cin >> pilihan;
	cout << endl;
	if(pilihan == 0){
		system("cls");
		main();
	}
	else if(pilihan == 1){
		cout << "Inputkan index yang akan diisi : ";
		cin >>input;
		maxinput();
		if (input <=9){
				target = a[input];
				insert_value();
				insert_process();
				a[input]=target;
				status = 1;
				system("cls");
				insert();
			}
		else{
			cout << "Index melebihi batas."<<endl;
			system("pause");
			system("cls");
			insert();
		}
	}
	else{
		system("cls");
		cout << "Operasi Insert Sequentially."<<endl<<endl;
		tampil();
		for(i=0;i<10;i++){
			input = i;
			target = a[i];
			insert_value();
			a[i] = value;
		}
		system("cls");
		cout << endl;
		cout << "Simpan perubahan?"<<endl<<endl;
		question();
		if (jawab == "Yes" or jawab == "yes"){
			status = 1;
			program = 0;
			save();
			insert_notif();
			insert();
		}
		else{
			program = 1;
			save();
			insert();
		}
		
	}
}
//Main part for insert
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//Value part for insert
int insert_value(){
	cout << endl;
	if (status == 1)
		cout << "Silahkan inputkan value."<<endl<<endl;
	cout << "Index = ["<<input<<"]"<<endl;
	cout << "Value = ["<<target<<"]"<<endl<<endl;
			
	cout << "Masukan value : ";
	cin>>value;
	maxinput();
	cout <<endl;
	pilihan =0;
	return value;
		
}
//Value part for insert
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//Data processing for insert
int insert_process(){
	while (pilihan == 0){
		cout << "Anda yakin?"<<endl;
		question();
		if (jawab == "Yes" or jawab == "yes"){
			pilihan = 1;
			target = value;
			value = target;
			insert_notif();
		}
		else{
			status = 1;
			value = target;
			system("cls");
			insert_value();		
		}
	}
}
//Data processing for insert
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//Notification for Insert
int insert_notif(){
	system("cls");
	cout <<endl;
	cout << "Data tersimpan!"<<endl<<endl;
	Sleep(1000);
	cout << "Mengembalikan ke menu insert data..."<<endl;
	Sleep(1000);
}
//Notification for Insert
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//Main part for remove
int remove(){
	system("cls");
	if (status == 0){
		cout << "Anda memasuki menu Remove Data."<<endl<<endl;
	}
	else{
		cout << "Anda dikembalikan ke menu Remove Data."<<endl<<endl;
	}
	tampil();
	cout << "Opsi : "<<endl;
	cout << "1.) Remove Value"<<endl;
	cout << "2.) Remove All"<<endl;
	cout << "0.) Back"<<endl;
	cout << "Masukan opsi anda : ";
	cin >> pilihan;
	cout << endl;
	if (pilihan == 0){
		system("cls");
		main();
	}
	else if (pilihan == 1){
		cout << "Inputkan index yang akan diremove : ";
		cin >>input;
		if (input <=9){
			cout << endl;
			cout << "Index = ["<<input<<"]"<<endl;
			cout << "Value = ["<<a[input]<<"]"<<endl<<endl;
			
			cout << "Anda yakin? "<<endl;
			question();
			if (jawab == "Yes" or jawab == "yes"){
				a[input]=0;
				status = 1;
				system("cls");
				cout << endl;
				cout << "Data Berhasil disimpan!"<<endl<<endl;
				system("pause");
				remove();
			}
			else{
				remove();
			}
		}
		else{
			cout << "Index melebihi batas."<<endl;
			system("pause");
			system("cls");
			remove();
		}
	}
	else{
		system("cls");
		cout << "PERHATIAN!"<<endl<<endl;
		cout << "Anda akan menghapus semua data array."<<endl;
		cout << "Pilihan tidak dapat dikembalikan, anda yakin?"<<endl<<endl;
		Sleep(500);
		question();
		if (jawab == "Yes" or jawab == "yes"){
			for (i=0;i<10;i++){
			a[i]=0;
			}
			system("cls");
			status = 1;
			main2();
		}
		else{
			status = 1;
			remove();
		}
	}
}
//Main part for remove
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//Main part for arrange data
int arrange(){
	system("cls");
	cout << "Anda memasuki menu Arrange Data."<<endl<<endl;
	tampil();
	cout << "Mulai menyusun data?"<<endl;
	question();
	cout << endl;
	cout << "Susunan data : ";
	if (jawab == "yes" or jawab == "Yes"){
		for(i=0;i<10;i++){
			for(j=i+1;j<10;j++){
				if (a[j]<a[i]){
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;		
				}
			}
		}
		a[i]=a[10];
		for (i=0; i<10;i++){
			cout <<a[i]<<" ";
		}
		cout <<endl<<endl;	
		system("pause");
		system("cls");
		status = 1;
		cout <<endl;
		cout << "Data berhasil disusun!"<<endl<<endl;
		system("pause");
		system("cls");
		main2();
	}
	else{
		system("cls");
		status = 2;
		main2();
	}
}
//Main part for arrange data
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//main part for sequential search
int sequential(){
	system("cls");
	if (status==1){
		cout << "Anda dikembalikan ke menu Sequential Search."<<endl<<endl;
	}
	else{
		cout << "Anda memasuki menu Sequential Search."<<endl<<endl;
	}
	tampil();
	cout << "Masukan data yang akan dicari : ";
	cin >> input;
	cout << "Data yang akan dicari : "<<input<<endl<<endl;
	Sleep(1000);
	system("cls");
	for (i=0;i<10;i++){
		cout << "Data yang dicari : "<<input<<endl<<endl;
		cout << "Array ke - [" <<i<<"] berisi data : ["<<a[i]<<"]"<<endl;
		if (input == a[i]){
			cout << "Data Ditemukan!"<<endl;
			system("pause");
			system("cls");
			cout << "Anda dikembalikan ke menu utama."<<endl<<endl;
			return main2();
		}
		else{
			cout << "Data tidak cocok."<<endl;
			Sleep(1000);
			cout << "Program mengulang..."<<endl;
			Sleep(500);
			system("cls");
		}
	}
	if(i>=10){
		status = 1;
		cout <<"Batas Pencarian Array mencapai maksimum."<<endl;
		cout <<"Data tidak ditemukan."<<endl<<endl;
		Sleep(500);
		cout <<"Coba lagi?"<<endl;
		question();
		if (jawab=="Yes" or jawab=="yes"){
			sequential();
		}
		else{
			status = 2;
			system("cls");
			main2();
		}
	}
}
//main part for sequential search
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//display part for binary search
int binarytampil(int awal, int akhir){
	cout << endl;
	cout << "Index = ";
	for(i=awal;i<=akhir;i++){
		if(a[i]>9 and a[i]<99){
			digit = 2;
			check(digit);
		}
		else if (a[i]>99 and a[i]<999){
			digit = 3;
			check(digit);
		}
		else if (a[i]>=0 and a[i]<10){
			digit = 1;
			check(digit);
		}
	}
	cout << endl;
	cout << "Value = ";
	for(i=awal;i<=akhir;i++){
		cout <<" ["<<a[i]<<"] ";
	}
	cout << endl<<endl;
}
//display part for binary search
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//operation part for binary search
int binarysearch(int awal, int akhir){ 
	if (akhir < awal){
			system("cls");
			status = 2;
			cout << "Data tidak ditemukan."<<endl;
			system("pause");
			system("cls");
			main2();
		}
	else if (akhir >= awal){
		int mid = (awal + akhir) / 2;
		binarytampil(awal,akhir);
		cout << "Data yang di cari : "<<input<<endl<<endl;
		cout << "Kondisi ditemukan ketika nilai input == nilai tengah."<<endl<<endl;
		cout << "Sisa index untuk dicari : "<<awal<<" -> "<<akhir<<endl<<endl;
		cout << "Index Awal : "<<awal<<endl;
		cout << "Data : "<<a[awal]<<endl<<endl;
		cout << "Index Tengah : "<<mid<<endl;
		cout << "Data : "<<a[mid]<<endl<<endl;
		cout << "Index Akhir : "<<akhir<<endl;
		cout << "Data : "<<a[akhir]<<endl<<endl;
		system("pause");
		system("cls");
		if (a[mid] == input)
			return mid;
		if (a[mid] > input)
			return binarysearch(awal, mid-1);	
		//else if (a[mid] < x)
		return binarysearch (mid + 1, akhir);
	}
}
//operation part for binary search
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//main part for binary search
int binary(void){
	system("cls");
	cout << "Anda memasuki menu Binary Search."<<endl<<endl;
	tampil();
	cout << "Masukan data yang akan dicari : ";
	cin >> input;
	cout << endl;
	system("cls");
	cout << endl;
	tampil();
	cout << "Data yang akan dicari : "<<input<<endl;
	cout << "Mulai pencarian?"<<endl;
	question();
	if (jawab == "Yes" or jawab == "yes"){
		system("cls");
		int n = sizeof(a) / sizeof(a[0]); //n adalah jumlah array, jumlah array adalah 10
		int result = binarysearch(0, n-1); //Nilai awal, tengah, akhir //n adalah index akhir
		cout << "Data cocok! "<<endl<<endl;
		tampil();
		status = 2;
		cout << "Data " << input<< " ada pada array ke-"<<result<<endl<<endl;
		system("pause");
		system("cls");
		return main2();
	}
	else{
		status = 2;
		return main2();
	}
}
//main part for binary search
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//display data checker
void check(int c){
	if (c==1){
		cout <<" ["<<i<<"] ";
		Sleep(50);
	}
	else if (c==2){
		cout <<" [ "<<i<<"] ";
		Sleep(50);
	}
	else if (c==3){
		cout <<" [ "<<i<<" ] ";
		Sleep(50);	
	}
}
//display data checker
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//display data
void tampil(){
	//index preview
	cout <<"Index = ";
	//Check Digit
	for(i=0;i<10;i++){
		if(a[i]>9 and a[i]<99){
			digit = 2;
			check(digit);
		}
		else if (a[i]>99 and a[i]<999){
			digit = 3;
			check(digit);
		}
		else if (a[i]>=0 and a[i]<10){
			digit = 1;
			check(digit);
		}
	}
	cout << endl;
	//Value preview
	cout <<"Value = ";
	for (i=0;i<10;i++){
		cout <<" ["<<a[i]<<"] ";
		Sleep(50);
	}
	cout <<endl<<endl;
	cout <<endl;
}
//display data
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//main function
main(){	
	save();
	status = 0;
	cout << "Selamat Datang di Program"<<endl;
	cout << "Struktur Data Array 1.0"<<endl<<endl;
	main2();
}
//main function
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//second main function
int main2(){
		if (status == 1){
			cout << "Data Tersimpan!"<<endl<<endl;
		}
		else if (status == 2){
			status = 0;
			cout << "Anda dikembalikan ke menu utama."<<endl<<endl;
		}
		tampil();
		
	menu();
	switch(pilihan){
		case 1:
			insert();
			break;
		case 2:
			remove();
			break;
		case 3:
			arrange();
			break;
		case 4:
			sequential();
			break;
		case 5:
			binary();
			break;
		case 6:
			system("cls");
			for(i=3;i>0;i--){
				cout<<"Program exit in "<<i;
				Sleep(1000);
				system("cls");
			}
			return 0;
		default:
			cout << "Pilihan tidak diketahui";
	}
}
//second main function
//----------------------------------------------------------------------
