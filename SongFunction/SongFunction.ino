#define C = 101;
#define D = 200;
#define E = 300;
#define F = 400;
#define  c     3830    // 261 Hz 
#define  d     3400    // 294 Hz 
#define  e     3038    // 329 Hz 
#define  f     2864    // 349 Hz 
#define  g     2550    // 392 Hz 
#define  a     2272    // 440 Hz 
#define  b     2028    // 493 Hz 
#define  C     1912    // 523 Hz 
// Define a special note, 'R', to represent a rest
#define  R     0

//global
int durations[] = {5,6,8,3};
int notes[] = {c,d,e,f};

//Both of these would be in scope of moveUno/Deux...
int sum=durations[0];
int counter=0;
int start = millis();

move(){
int counter = 0; 
loops();
}

void song(int dur[], int song[], int & counter){

	if(millis()-start<sum){
		tone(pin,song[counter]);
	}else{
		counter++;
		sum+=dur[counter];
	}
}
