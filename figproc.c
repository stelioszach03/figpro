#include <stdio.h>
#include <ctype.h>

int main(void) {
	int mg1, mg2,wc1,pl,maxv=0,R,G,B,gray,platos=0,ypsos=0,pl1=0,x=0,sum,k,bl=1,plat;
	mg1 = getchar();//protos magikos xaraktiras 'P'
	mg2 = getchar();// Defteros magikos xaraktiras [1,6]
	if (mg1 == 80 && (mg2 == 50 || mg2 == 51)) {
		putchar(mg1);
		if(mg2=='3'&& bl==0){//tha typonei to P6 otan kanei tin metatropi apo p3 se p6
			putchar(mg2+3);
		}
		else{//alliws na sinexizei tin metatropi xwris na lamvanei ypopsin to bonus
			putchar(mg2-1);
		}
		wc1 = getchar();//diavazei enan ypopsifio lefko xaraktira
		pl = 0;//plithos lefkwn xaraktirwn
		while (isspace(wc1) != 0) {//oso yparxei toulaxiston enas lefkos xaraktiras
			putchar(wc1);//ektyposi lefkou diastimatos
			pl++;
			wc1 = getchar();//edw, stin teleftaia epanalipsi, diavazete o xaraktiras o opoios elegxetai sto amesws epomeno while
		}
		if (pl == 0) {//ean den yparxei lefkos xaraktiras
			printf("Input error!\n");
			return -1;//termatismos programmatos
		}
		while (wc1==35) {//ean o xaraktiras=='#',tote yparxoun sxolia
			wc1=getchar();//diavase ton epomeno  haraktira
			while(wc1!=10){//diavaze mexri na vreis tin allagi grammis
				wc1=getchar();
			}
			wc1=getchar();
		}
		putchar('\n');
		if(wc1!=35 && (wc1<'0'|| wc1>'9')){//ean o xaraktiras den einai # kai den einai oute arithmos, diladi arithmos tou platous pou akolouthei
			printf("Input error!\n");
			return -1;
		}
		while(wc1<='9'&& wc1>='0'){//afou einai arithmos diavase oti apemeine apo to platos
			platos=10*platos + (wc1-'0');
			wc1= getchar();
		}
		printf("%d",platos);
		pl = 0;
		while (isspace(wc1) != 0) {//lefko diastima meta to platos
			putchar(wc1);
			pl++;
			wc1 = getchar();
		}
		if (pl== 0) {
			printf("Input error!\n");
			return -1;
		}
		if(wc1<'0'|| wc1>'9'){//ean meta to lefko diastima den akolouthei arithmos diladi to ipsos
			printf("Input error!\n");
			return -1;
		}
		while(wc1<='9'&& wc1>='0'){//oso einai arithmos sinexise na diavazeis to ipsos
			ypsos=10*ypsos + (wc1-'0');
			wc1= getchar();
		}
		printf("%d",ypsos);
		pl = 0;//meta to ipsos yparxei lefko diastima
		while (isspace(wc1) != 0) {
			putchar(wc1);
			pl++;
			wc1 = getchar();
		}
		if (pl == 0) {
			printf("Input error!\n");
			return -1;
		}
		while(wc1>='0'&& wc1<='9'){//vriskei to maxnum tis ekastote eikonas
			x=1;//elegxei an diavase toulaxiston ena psifio pou tha einai o megistos arithmos
			maxv= 10*maxv + (wc1-'0');	
			wc1=getchar();//stin teleftea epanalipsi diavazei tin arxi tou epomenou lefko diastimatos
		}
		if(x==0){
			printf("Input error!\n");
			return -1;	
		}
		if(maxv>=0 && maxv<=255){//elegxei an to maxnum einai metaksy 0 kai 255 pou einai ta kathorismena oria
			if(mg2=='3'){
				printf("%d",maxv);
			}	
		}
		else{
			printf("Input error!\n");
			return -1;	
		}
		pl = 0;//meta tin megisti timi yparxei lefko diastima
		while (isspace(wc1) != 0) {
			putchar(wc1);
			pl++;
			wc1 = getchar();
		}
		if (pl == 0) {
			printf("Input error!\n");
			return -1;
		}
		if(mg2=='3'){//an o magikos airthmos einai isos me P3
			while(wc1!=EOF){//oso den teliose to arxeio
				pl1=0;//oso to plithos den kseperase tis diastaseis tis eikonas
				while((pl1<= platos*ypsos)&&((wc1>='0'&& wc1<='9')||(isspace(wc1) != 0))){//oso to plithos den kseperase tis diastaseis tis eikonas kai sinexizei na diavazei arithmous, i diavazei lefko diastima
					pl1++;
					R=0;
					while(wc1>='0'&& wc1<='9'){//evresi timis gia to Red
						R= 10*R + (wc1-'0');	
						wc1=getchar();
					}
					pl = 0;//meta tin timi tou red yparxei lefko diastima
					while (isspace(wc1) != 0) {//se ola ta simeia pou diavazei lefko diastima, an dosei lathos timi to programma telionei
						if(bl!=0){//an tha sinexistei kanonika i epanalipsi xoris na lithoun ypopsin ta bonus typose to lefko diastima
							putchar(wc1);
						}	
						pl++;
						wc1 = getchar();
					}
					if (pl == 0) {
						printf("Input error!\n");
						return -1;
					}
					G=0;
					while(wc1>='0'&& wc1<='9'){//evresi timis gia to Green
						G= 10*G + (wc1-'0');	
						wc1=getchar();
					}
					pl = 0;//meta tin timi tou green yparxei lefko diastima
					while (isspace(wc1) != 0) {
						if(bl!=0){
							putchar(wc1);
						}	
						pl++;
						wc1 = getchar();
					}
					if (pl == 0) {
						printf("Input error!\n");
						return -1;
					}
					B=0;
					while(wc1>='0'&& wc1<='9'){//evresi timis gia to Blue
						B= 10*B + (wc1-'0');	
						wc1=getchar();
					}
					if((R>=0 && R<=255) && (G>=0 && G<=255) && (B>=0 && B<=255)){//elegxos kai metatropi eikonostoixeiwn
						if(bl==0){//an to bl einai iso me 0 tote prepei na kanei tin metatropi apo p3 se p6
							putchar(R);
							putchar(G);
							putchar(B);
						}
						else{
							gray=(299*R + 587*G + 114*B)/1000;
							printf("%d",gray);	
						}
					}
					else{//an oi times twn xromatwn den vriskontai anamesa sta kathorismena oria to programma telionei
						printf("Input error!\n");
						return -1;
					}
					pl = 0;//meta tin timi tou blue yparxei lefko diastima
					while (isspace(wc1) != 0) {
						if(bl!=0){
							putchar(wc1);
						}	
						pl++;
						wc1 = getchar();
					}
					if (pl == 0) {
						printf("Input error!\n");
						return -1;
					}
				}
			}
		}
		else if(mg2=='2'){//An o magikos arithmos einai isos me P2
			while(wc1!=EOF){
				pl1=0;
				while((pl1<= platos*ypsos)&&((wc1>='0'&& wc1<='9')||(isspace(wc1) != 0))){
					pl1++;
					gray=0;
					while(wc1>='0'&& wc1<='9'){//evresi timis gia to gray eikonidio
						gray= 10*gray + (wc1-'0');	
						wc1=getchar();
					}
					if(gray>=0&&gray<=255){//metatropi apo eikona se apoxrwseis tou gkri se aspromavri
						if(gray>(maxv+1)/2){
							gray=0;
						}
						else{
							gray=1;
						}
						printf("%d",gray);
						pl = 0; //meta akolouthei lefko diastima
						while (isspace(wc1) != 0) {
							putchar(wc1);
							pl++;
							wc1 = getchar();
						}
						if (pl == 0) {
							printf("Input error!\n");
							return -1;
						}
					}
				}
			}
		}
	}
	if (mg1 == 80 && (mg2 == 53|| mg2 == 54)) {
		putchar(mg1);
		if(mg2=='6'&& bl==0){//tha typonei to P3 otan kanei tin metatropi apo p6 se p3
			putchar(mg2-3);
		}
		else{//alliws na sinexizei tin metatropi xwris na lamvanei ypopsin to bonus
			putchar(mg2-1);
		}
		wc1 = getchar();//diavazei enan ypopsifio lefko xaraktira
		pl = 0;//plithos lefkwn xaraktirwn
		while (isspace(wc1) != 0) {//oso yparxei toulaxiston enas lefkos xaraktiras
			putchar(wc1);//ektyposi lefkou diastimatos
			pl++;
			wc1 = getchar();//edw, stin teleftaia epanalipsi, diavazete o xaraktiras o opoios elegxetai sto amesws epomeno while
		}
		if (pl == 0) {//ean den yparxei lefkos xaraktiras
			printf("Input error!\n");
			return -1;//termatismos programmatos
		}
		while (wc1==35) {//ean o xaraktiras=='#',tote yparxoun sxolia
			wc1=getchar();//diavase ton epomeno  haraktira
			while(wc1!=10){//diavaze mexri na vreis tin allagi grammis
				wc1=getchar();
			}
			wc1=getchar();
		}
		putchar('\n');
		if(wc1!=35 && (wc1<'0'|| wc1>'9')){//ean o xaraktiras den einai # kai den einai oute arithmos
			printf("Input error!\n");
			return -1;
		}
		while(wc1<='9'&& wc1>='0'){//afou einai arithmos diavase oti apemeine apo to platos
			platos=10*platos + (wc1-'0');
			wc1= getchar();
		}
		printf("%d",platos);
		pl = 0;
		while (isspace(wc1) != 0) {//lefko diastima meta to platos
			putchar(wc1);
			pl++;
			wc1 = getchar();
		}
		if (pl== 0) {
			printf("Input error!\n");
			return -1;
		}
		if(wc1<'0'|| wc1>'9'){//ean meta to lefko diastima den akolouthei arithmos diladi to ipsos
			printf("Input error!\n");
			return -1;
		}
		while(wc1<='9'&& wc1>='0'){//oso einai arithmos sinexise na diavazeis to ipsos
			ypsos=10*ypsos + (wc1-'0');
			wc1= getchar();
		}
		printf("%d",ypsos);
		pl = 0;//meta to ipsos yparxei lefko diastima
		while (isspace(wc1) != 0) {
			pl++;
			wc1 = getchar();
		}
		if (pl == 0) {
			printf("Input error!\n");
			return -1;
		}
		while(wc1>='0'&& wc1<='9'){//vriskei to maxnum tis ekastote eikonas
			x=1;//elegxei an diavase toulaxiston ena psifio pou tha einai o megistos arithmos
			maxv= 10*maxv + (wc1-'0');	
			wc1=getchar();//stin teleftea epanalipsi diavazei tin arxi tou epomenou lefko diastimatos
		}
		if(x==0){
			printf("Input error!\n");
			return -1;	
		}
		if(maxv>=0 && maxv<=255){//elegxei an o maxnum vrisketai sta kathorismena oria
			if(mg2=='6'){
				printf("\n%d",maxv);
			}	
		}
		else{
			printf("Input error!\n");
			return -1;	
		}	
		pl = 0;//meta tin megisti timi yparxei ena monadiko lefko diastima
		while (isspace(wc1) != 0) {
			putchar(wc1);
			pl++;
			wc1 = getchar();
		}
		if ((pl == 0)|| (pl > 1)){
			printf("Input error!\n");
			return -1;
		}
		while(wc1!=EOF && pl1<= platos*ypsos ){//oso den teleiose to arxeio kai den exoun kseperastei oi diastaseis tis eikonas
			pl1++;
			if(mg2=='6'){
				R=wc1;//diavazei ena byte gia to kathe xroma
				wc1 = getchar();
				G=wc1;
				wc1 = getchar();
				B=wc1;
				wc1 = getchar();
				if((R>=0 && R<=255) && (G>=0 && G<=255) && (B>=0 && B<=255)){
					if(bl==0){//an to bl einai iso me 0 tote prepei na kanei tin metatropi apo p6 se p3
						printf(" %d",R);
						printf(" %d",G);
						printf(" %d",B);
					}
					else{
						gray=(299*R + 587*G + 114*B)/1000;//alliws to metatrepei se gray eikonidio
						putchar(gray);
					}	
				}
				else{
					printf("Input error!\n");
					return -1;
				}	
			}	
			else if(mg2=='5'){//metatropi se aspromavri apo eikona me apoxroseis tou gkri
				if(platos%8==0){//periptosi pou to platos einai pollaplasio tou 8
					pl1=0;
					while(wc1!=EOF && pl1<=platos*ypsos){
						pl1++;
						gray=0;
						sum=0;
						while(sum<8){//diamorfonw ana oktades ta bits
							if(wc1>(maxv+1)/2){
								gray=2*gray+('0'-'0');//sti thesi tou xaraktira wc1 xrisimopoiw 0 kai 1 antistoixa, se sxesi me tis proigoumenes epanalipseis
							}
							else{
								gray=2*gray+('1'-'0');
							}
							sum++;
							wc1=getchar();
						}//molis diamorfothei i oktada stamata to while kai ksana ksekina
						if(gray>maxv || gray<0){
							printf("Input error!\n");
							return -1;		
						}
						putchar(gray);
					}
				}
				else{//periptosi pou to platos den einai pollaplasio tou 8
					pl1=0;
					plat=0;
					while(wc1!=EOF && pl1<=platos*ypsos){
						pl1++;
						gray=0;
						sum=0;
						while(sum<8 && plat<platos){//diamorfosi oktadwn mexri to telos tis grammis stin opoia vriskomai
							if(wc1>(maxv+1)/2){
								gray=2*gray+('0'-'0');//xrisimopoiw ton typo tis getinteger gia na pragmatopoihsw tin metatropi
							}
							else{
								gray=2*gray+('1'-'0');	
							}
							sum++;
							plat++;
							wc1=getchar();
						}
						if(sum<8){
							while(sum<8){//vazw assous se osa byte den einai simpliromena simfwna me tin ekfonisi
								gray=2*gray+('1'-'0');	
								sum++;
							}
							plat=0;//midenizw ksana to platos gia na ksekinisei i idia diadikasia stin epomeni grammi
						}
						if(gray>maxv || gray<0){
							printf("Input error!\n");
							return -1;		
						}
						putchar(gray);
					}
						
				}
			
			}
		}
	}
	return 0;			
}
