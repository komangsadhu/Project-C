#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 


//fiturutama

void MenuSignup();
void MenuSignin();
void lupapassword();
int  MenuUtama();
void SignupInventaris();
void SigninInventaris();
void SignupKaryawan();
void SigninKaryawan();
void logout();
void LoginAdmin();
char emailadmin[50] = {"admin"};
char passwordadmin[50] = {"123"};
void menuadmin();


//fitur admin
void listbrgadmin();
void listinvntdankrywn();
void mencariuser();
void hapusinvntdankrywn();
void confirm();
void melihatlistbrg();


struct admingudang{
    char unama[50],password[50];
}adm;

//fitur inventaris
void menuinventaris();
void listbrg();
void menambahdanmengurangibrg();
void melihatbrgyangdipinjam();
void menambahkanbrg();
void mengurangibrg();
void konfirmpeminjaman();
void brgdipinjamdansiapaminjam();
void menagihpeminjaman();
void permintaanpenambahanbrgkeadmin();
void konfirmasipermintaanpeminjamanbrgolehkaryawan();

struct inventaris{
    char unama[50],password[50],question[50],asking[50];
}invnt;

//fitur karyawan
void menukaryawan();
void lihatlistbrg();
void minjambrgkeinventaris();
void listbrgygdipinjamdanmengembalikan();

struct karyawan{
    char unama[50],password[50],asking2[50],question2[50];
}krywn;

FILE *Logininvt;
FILE *loginkrywn;
FILE *unco_ord;
FILE *temp_ord;
FILE *con_ord;
FILE *barangkrywn;



struct barang{
    char nam[50],min[50],jum[50];
}order;

struct bar{
    char useraktif[50];
}aktif;

struct plusbrg{
    char nam2[50],min2[50],jum2[50];
}plus;

int i=3;
int main(){
    MenuUtama();
    return 0;
}

int MenuUtama(){
    int choice;

    printf("    _.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._    \n");
    printf(".-'---      - ---     --     ---   -----   - --       ----  ----   -     ---`-.  \n");
    printf(" )                                                                             ( \n");
    printf(" (                                                                             ) \n");
    printf(" )                                    WELCOME                                  ( \n");
    printf(" (                                    WELCOME                                  ) \n");
    printf(" (                                    WELCOME                                  ) \n");
    printf(" (                                    WELCOME                                  ) \n");
    printf(" )                                                                             ( \n");
    printf(" (                                                                             ) \n");
    printf(" )                                                                             ( \n");    
    printf("     `-._.-' (___ _) (__ _ ) (_   _) (__  _) ( __ _) (__  _) (__ _ ) `-._.-      \n");
    printf("             `-._.-' (  ___) ( _  _) ( _ __) (_  __) (__ __) `-._.-              \n");
    printf("                     `-._.-' (__  _) (__  _) (_ _ _) `-._.-'                     \n");       
    printf("                           `-._.-'   (_ ___) `-._.- '                            \n");                                                           
    printf("                                     `-._.-'                                     \n");   
    printf("=================================================================================\n");
	printf("                   Data Inventaris Laboratorium Dasar komputer                   \n");
	printf("                                 TELKOM UNIVERSITY                               \n");
 	printf("                Jl. Telekomunikasi No. 1, Terusan Buahbatu, Bojongsoang.         \n");
 	printf("                                                                                 \n");
	printf("=================================================================================\n");
	printf("\nMenu: \n");
    printf("\n1. Sign-Up");
	printf("\n2. Sign-in");
    printf("\n3. lupa password");
	printf("\n4. Logout");
    printf("\nPilah satu opsi: ");
    scanf("%d", &choice); getchar();

    switch(choice){
        case 1:
            MenuSignup();
            break;
		case 2:
			MenuSignin();
			break;
		case 3:
			lupapassword();
			break;
        case 4:
            return 0;
            break;
        default:
            printf("\nOpsi tidak ada!");
    }
}

void MenuSignup(){
    int choice;
    system("cls");
    printf("=== Sign Up ===");
    printf("\n1. Inventaris");
    printf("\n2. Karyawan");
    printf("\nPilih satu opsi: ");
    scanf("%d", &choice); getchar();

    switch(choice){
        case 1:
            SignupInventaris();
            break;
        case 2:
            SignupKaryawan();
            break;
        default:
            printf("\nOpsi tidak ada!");
    }
}
void MenuSignin(){
    int choice;
    system("cls");
    printf("=== Sign in ===");
    printf("\n1. Inventaris");
    printf("\n2. Karyawan");
    printf("\n3. Admin");
    printf("\nPilih satu opsi: ");
    scanf("%d", &choice); getchar();

    switch(choice){
        case 1:
            SigninInventaris();
            break;
        case 2:
            SigninKaryawan();
            break;
        case 3:
            LoginAdmin();
            break;
        default:
            printf("\nOpsi tidak ada!");
    }
}
void SignupInventaris(){
    char kor[50];
    
FILE*SignupInventaris;
SignupInventaris = fopen("registerinventaris.dat","ab");

    system("cls");
    printf("\nmasukkan username: ");
	gets(invnt.unama);
    printf("masukkan password :");
    gets(invnt.password);
    printf("masukkan kembali password : ");
    gets(kor);
    printf("masukkan pertanyaan untuk recovery password :");
    gets(invnt.question);
    printf("masukkan jawaban untuk recovery password :");
    gets(invnt.asking);
    fwrite(&invnt, sizeof(invnt), 1, SignupInventaris);
    fclose(SignupInventaris);
    system("pause");
    MenuUtama();
}
void SignupKaryawan(){
    char con[50];

FILE*SignupKaryawan;
SignupKaryawan = fopen("registerkaryawan.dat","ab");
    system("cls");
    printf("\nmasukkan username: ");
    gets(krywn.unama);
    printf("masukkan password :");
    gets(krywn.password);
    printf("masukkan kembali password : ");
    gets(con);
    printf("masukkan pertanyaan untuk recovery password :");
    gets(krywn.question2);
    printf("masukkan jawaban untuk recovery password :");
    gets(krywn.asking2);
    fwrite(&krywn, sizeof(krywn), 1, SignupKaryawan);
    fclose(SignupKaryawan);
    system("pause");
    MenuUtama();
}
void lupapassword(){

	char simpanpass[50],usspas[50];
    char ans[50];
    printf("masukkan username :");
    gets(usspas);
    FILE *passlupa;
    passlupa = fopen("registerinventaris.dat","ab+");
    while(fread(&invnt, sizeof(invnt), 1, passlupa)==1){
        if(strcmp(usspas, invnt.unama)==0){
            printf("%s",invnt.question);
            gets(ans);
            if(strcmp(ans,invnt.asking)==0){
                printf("masukkan username :");
                gets(usspas);
                printf("masukkan password baru: ");
                gets(invnt.password);
                fwrite(&invnt, sizeof(invnt), 1, passlupa);
                fclose(passlupa);
                MenuSignup();
            }
    }
}
    }

void SigninInventaris(){
    struct{
        char usernameinvt[50], passwordinvt[50];
    }input;
    FILE*logininvnt;
    logininvnt = fopen("registerinventaris.dat","rb");
	printf("Masukan Username\t: ");
    fflush(stdin); gets(input.usernameinvt);
    while(fread(&invnt, sizeof(invnt), 1, logininvnt)==1){
        if(strcmp(input.usernameinvt, invnt.unama)==0){
            printf("Masukan Password\t: ");
            gets(input.passwordinvt);
            if(strcmp(input.passwordinvt, invnt.password)==0){
                strcpy(aktif.useraktif, invnt.unama);
                fclose(logininvnt);
                system("cls");
                printf("Berhasil Login\n\n");
                menuinventaris();
                break;
            }else if(strcmp(input.passwordinvt, invnt.password)!=0){
                printf("konfirmasi password yang anda masukkan salah\n");
                system("pause");
                SigninInventaris();
            }
        }
    } 
}

void SigninKaryawan(){
    struct{
        char unamakaryawan[50],passkaryawan[50],useraktif2[50];
    }input2;
    FILE*loginkrywn;
    loginkrywn = fopen("registerkaryawan.dat","rb");
    printf("\nmasukkan username :");
	gets(input2.unamakaryawan);
    while(fread(&krywn, sizeof(krywn), 1, loginkrywn)==1){
         if(strcmp(input2.unamakaryawan,krywn.unama)==0 ){
            printf("masukkan password\t:");
            gets(input2.passkaryawan);
            if(strcmp(input2.passkaryawan,krywn.password)==0){
                strcpy(input2.useraktif2,krywn.unama);
                fclose(loginkrywn);
                system("cls");
                printf("berhasil login\n\n");
                menukaryawan();
                break;
            }else if(strcmp(input2.passkaryawan,krywn.password)!=0){
                printf("konfirmasi password yang anda masukkan salah\n");
                system("pause");
                SigninKaryawan();
            }
        }
     }
}
void LoginAdmin(void)
{
    char loginAdmin[50], loginPassword[50];
    int i=3;

    system("cls");
    printf("=============== Login Admin ===============");
    while(i>0){
        printf("\nEMAIL\t : ");
        fflush(stdin); gets(loginAdmin);
        printf("PASSWORD : ");
        gets(loginPassword);

        if(strcmp(loginAdmin, emailadmin)==0 && strcmp(loginPassword, passwordadmin)==0){
            menuadmin();
            break;
        }else if(strcmp(loginAdmin, emailadmin)!=0 || strcmp(loginPassword, passwordadmin)!=0){
            printf("Password atau Email salah! Silahkan coba lagi! Anda mempunyai %d kesempatan lagi!\n", i-1);
            i--;
        }

    }if(i==0){
    MenuUtama();
    }
}
void menuadmin(void)
{
    int pilihan;

    system("cls");
    printf("=============== Dashboard Admin Gudang ===============");
    printf("\nSelamat datang, %s",adm.unama);
    printf("\n====================================================");
    printf("\n1. list akun inventaris dan karyawan");
    printf("\n2. cari user");
    printf("\n3. hapus user");
    printf("\n4. list barang");
    printf("\n5. konfirmasi penambahan barang");
    printf("\n6. logout ");
    printf("\n pilih menu: "),
    scanf("%d", &pilihan);

    switch(pilihan){
        case 1:
            system("cls");
            listinvntdankrywn();
            break;
        case 2:
            system("cls");
            mencariuser();
            break;
        case 3:
            system("cls");
            hapusinvntdankrywn();
            break;
        case 4:
            system("cls");
        case 5:
            system("cls");
            listbrgadmin();
            break;
        case 6:
            system("cls");
            MenuUtama();
            break;
        default:
            printf("menu tidak ada\n");

    }

}
void menuinventaris(void)
{
    FILE *logininvnt;
    logininvnt = fopen("registerinventaris.dat","rb");

    int pilihan;
    system("cls");
    printf("=============== Dashboard Inventaris ===============");
    printf("\nSelamat datang, %s", invnt.unama);
    printf("\n==================================================");
    printf("\n1. List barang");
    printf("\n2. Tambah barang");
    printf("\n3. Kurangi/hapus barang");
    printf("\n4. konfirmasi peminjaman");
    printf("\n5. List peminjaman dan penagihan");
    printf("\n6. Logout ");
    printf("\nmasukkan opsi pilihan anda :");
    scanf("%d", &pilihan); getchar();

    switch (pilihan){
        case 1:
            system("cls");
            melihatlistbrg();
            break;
        case 2:
            system("cls");
            menambahdanmengurangibrg();
            break;
        case 3:
            system("cls");
            mengurangibrg();
            break;
        case 4:
            system("cls");
            konfirmpeminjaman();
            break;
        case 5:
            system("cls");
            brgdipinjamdansiapaminjam();
            break;
        case 6:
            system("cls");
            MenuUtama();
            break;
        default:
            printf("menu tidak tersedia\n");
    }
}
void menukaryawan(){
    FILE*loginkrywn;
    loginkrywn = fopen("registerkaryawan.dat","rb");

    int pilihan;
    system("cls");
    printf("=============== Dashboard Karyawan ===============");
    printf("\nSelamat datang, %s", krywn.unama);
    printf("\n=================================================");
    printf("\n1. List barang");
    printf("\n2. pinjam barang");
    printf("\n3. list barang yang dipinjam dan pengembalian");
    printf("\n4. Logout\n");
    printf("\n   Pilih menu :");
    scanf("%d",&pilihan);

    switch(pilihan){
        case 1:
            system("cls");
            lihatlistbrg();
            break;
        case 2:
            system("cls");
            minjambrgkeinventaris();
            break;
        case 3:
            system("cls");
            listbrgygdipinjamdanmengembalikan();
            break;
        case 4:
            system("cls");
            MenuUtama();       
    }


}       

void logout(){
	MenuUtama();
}
//fitur admin menghapus akun inventaris dan karyawan

    void hapusinvntdankrywn(void){
        char delU[100];

    FILE *reglog;
    FILE *reglog2;
    FILE *temp_log;

    reglog = fopen("listinventaris.dat", "rb");
    reglog2 = fopen("listkaryawan.dat","rb");
    temp_log = fopen("menghapusakuninventarisdankaryawan", "wb");

    
    fclose(reglog);
    printf("\nMasukkan username yang akan dihapus\t: ");gets(delU);
    reglog = fopen("listinventaris.dat", "rb");
    reglog = fopen("listkaryawan.dat","rb");
    while(fread(&invnt, sizeof(invnt), 1, reglog)==1)
        if(strcmp(delU,invnt.unama)==0){
            fwrite(&invnt, sizeof(invnt), 1, temp_log);
    }while(fread(&krywn, sizeof(krywn), 1, reglog)==1){
        if(strcmp(delU,krywn.unama)==0){
            fwrite(&krywn, sizeof(krywn), 1, temp_log);
        }
    }
    fclose(reglog);
    fclose(reglog2);
    fclose(temp_log);

    remove("listinventaris.dat");
    rename("data_temp.dat","listinventaris.dat");

    remove("listkaryawan.dat");
    rename("data_temp.dat","listkaryawan.dat");

    reglog = fopen("listinventaris.dat", "rb");
    reglog2 = fopen("listkaryawan.dat", "rb");
    while(fread(&invnt, sizeof(invnt), 1, reglog)==1){
        int i=1;
    while(fread(&krywn, sizeof(krywn), 1, reglog)==1){
        int i=1;
        printf("\n%d.\tnama     : %s", i, invnt.unama);
        printf("\n%d.\tNama   \t: %s", i, krywn.unama);
    }
    fclose(reglog);
    printf("\nTekan enter untuk kembali");
    getchar();
    menuadmin();
}
    }

//fitur admin menampilkan list akun inventaris dan karyawan

void listinvntdankrywn(void){

    FILE *listinventaris;
    FILE *listkaryawan;

    listinventaris = fopen("registerinventaris.dat","rb");
    listkaryawan = fopen("registerkaryawan.dat","rb");
    int i=1;
    while(fread(&invnt,sizeof(invnt),1,listinventaris)==1){
        printf("\n%d. Username: %s",i,invnt.unama);
        i++;
    }
    while(fread(&krywn,sizeof(krywn),1,listkaryawan)==1){
        printf("\n%d. Username: %s",i,krywn.unama);
        i++;
    }
    printf("\ntekan enter untuk kembali ke menu admin");
    getchar();
    menuadmin();

}


//fitur admin mencari user (searching) dan menampilkan detail user
void mencariuser(void){
        char cariuser[50];
    


}
//fitur admin melihat list barang
void melihatlistbrg(void){
    FILE *seelistbarang;
    seelistbarang = fopen("baranginventaris.dat","rb");

    while(fread(&order,sizeof(order),1,seelistbarang)==1){
        printf("%s",order.nam);
        printf("%s",order.min);
        printf("%s",order.jum);
    }
}

//fitur admin mengkonfirmasi permintaan penambahan barang dari inventaris
void confirm(){
    char cari[50];

    unco_ord = fopen("baranginvnt.dat", "rb");
    temp_ord = fopen("Order_temporary.dat", "wb");
    con_ord = fopen("baranginvntcon.dat", "wb+");

    printf("Daftar permintaaan penambahan barang");
    while(fread(&order, sizeof(order), 1, unco_ord)==1){
        int i=1;
       
        printf("\n%d.nama barang\t: %s",i, order.nam);
        printf("\npeminta penambahan\t: %s",order.min);
        printf("\njumlah penambahan\t: %d", order.jum);
        i++;
        }fclose(unco_ord);
    printf("Masukkan nama barang yang akan dikonfirmasi\t:");gets(cari);
    unco_ord = fopen("baranginvnt.dat", "rb");
    while(fread(&order, sizeof(order), 1, unco_ord)==1){
        if(strcmp(cari,order.nam)==0){
            fwrite(&order, sizeof(order), 1, con_ord);
        }
        else if(strcmp(cari,order.nam)!=0){
            fwrite(&order, sizeof(order), 1, temp_ord);}
        }
    fclose(unco_ord);
    fclose(temp_ord);
    fclose(con_ord);

    remove("baranginvnt.dat");
    rename("Order_temporary.dat", "baranginvnt.dat");
    fflush(stdin);

}
//fitur inventaris melihat list barang
void listbrg(){
    FILE *seelistbarang;
    seelistbarang = fopen("baranginventaris.dat","rb");

    while(fread(&order,sizeof(order),1,seelistbarang)==1){
        printf("%s",plus.nam2);
        printf("%s",plus.min2);
        printf("%s",plus.jum2);
    }
}
   
//fitur inventaris menambahkan dan mengurangi barang
void menambahdanmengurangibrg(void){
    
   FILE *baranginventaris;
   baranginventaris=fopen("baranginventaris.dat","ab");
   int jumlah;
  
   printf("Masukkan jumlah barang : ");
   scanf("%d",&jumlah);
   int a;
    for(a=0;a<jumlah;a++)
    {
      printf("==========================\n");
      printf("Nama Barang : ");
      fflush(stdin); gets(plus.nam2);
      fwrite(&plus, sizeof(plus),1, baranginventaris);
   }

   fflush(baranginventaris);
   fclose(baranginventaris);
}

//fitur inventaris melihat barang apa saja yang dipinjam dan siapa meminjam
void melihatbrgyangdipinjam(void){
    con_ord = fopen("barangkrywncon.dat", "rb");
    while(fread(&order,sizeof(order),1,con_ord)==1){
        printf("nama barang:%s \n",order.nam);
        printf("nama peminjam:%s\n",order.min);
        printf("jumlah barang:%s\n",order.jum);
            
    }

    fclose(con_ord);
        printf("\n\ntekan enter untuk kembali");
        system("pause");
        menuinventaris();
}

//fitur inventaris menagih karyawan yang sedang meminjam barang
void menagihpeminjaman(void){

}
//fitur inventaris meminta permintaan penambahan barang ke admin
void permintaanpenambahanbrgkeadmin(void){

    unco_ord = fopen("baranginvnt.dat", "ab+");
    printf("nama barang yang bibutuhkan penambahan:%s\n",order.nam);
    printf("jumlah barang yang bibutuhkan penambahan:%s\n",order.jum);
    fwrite(&order,sizeof(order),1,unco_ord);
    printf("\ntekan enter untuk kembali");
    system("pause");
    menuinventaris();

}
//fitur inventaris mengkonfirmasi permintaan peminjaman barang oleh karyawan
void konfirmasipermintaanpeminjamanbrgolehkaryawan(void){

    int i;
    char caria[50];

    unco_ord = fopen("barangkrywn.dat", "rb");
    temp_ord = fopen("Order_temporary.dat", "wb");
    con_ord = fopen("barangkrywncon.dat", "wb+");

    printf("Daftar permintaaan penambahan barang");
    while(fread(&order, sizeof(order), 1, unco_ord)==1){
        int i=1;
       
        printf("\n%d.nama barang\t: %s",i, order.nam);
        printf("\npeminta penambahan\t: %s",order.min);
        printf("\njumlah penambahan\t: %d", order.jum);
        i++;
        }fclose(unco_ord);
    printf("Masukkan nama barang yang akan dikonfirmasi\t:");gets(caria);
    unco_ord = fopen("barangkrywn.dat", "rb");
    while(fread(&order, sizeof(order), 1, unco_ord)==1){
        if(strcmp(caria,order.nam)==0){
            fwrite(&order, sizeof(order), 1, con_ord);
        }
        else if(strcmp(caria,order.nam)!=0){
            fwrite(&order, sizeof(order), 1, temp_ord);}
        }
    fclose(unco_ord);
    fclose(temp_ord); 
    fclose(con_ord);

    remove("barangkrywn.dat");
    rename("Order_temporary.dat", "barangkrywn.dat");
    fflush(stdin);

}

//fitur karyawan melihat list barang
void lihatlistbrg(void){
    FILE *seelistbarang;
    seelistbarang = fopen("baranginventaris.dat","rb");

    while(fread(&order,sizeof(order),1,seelistbarang)==1){
        printf("%s",order.nam);
        printf("%s",order.min);
        printf("%s",order.jum);
    }
}
   
//fitur karyawan meminta permintaan peminjaman barang ke inventaris
void minjambrgkeinventaris(void){
    FILE *barangkrywn;
    barangkrywn = fopen("barangkrywn.dat","ab+");

    int b = 1;
    char back[50];
        printf("==========list peminjaman barang======\n");
        fflush(stdin);
        printf("nama barang: %s",order.nam);
        fwrite(&order,sizeof(order),1,barangkrywn);
        fclose(barangkrywn);
    }

//fitur karyawan melihat list barang yang sedang dipinjam
void listbrgygdipinjamdanmengembalikan(void){
    FILE *barangkrywn;
    barangkrywn = fopen("barangkrywn.dat","rb");
    fread(&order,sizeof(order),1,barangkrywn);
    fclose(barangkrywn);

}


void menambahkanbrg(void){
	
}

void mengurangibrg(void){
	
}

void konfirmpeminjaman(void){
	
}

void brgdipinjamdansiapaminjam(void){
}
	

void listbrgadmin(void){

}