//  René Lefebvre 6 decembre 2020

// programme chasse_furet
// Pour éloigner cette merde qui squatte le grenier (et qui chie partout)
// Un bon paquet d'ultra-son entre 13 kHz et 18 kHz (à la louche)
// en mode rafale aléatoire
// plus des flashs lumineux aléatoires eux aussi

// ATTENTION  la fonction tone() ne fonctionne pas avec tous les cores att85
// il faut installer le core suivant: http://drazzy.com/package_drazzy.com_index.json
//
// PINS    ATT85
//        ________U_______
//        | 1:RST  8: Vcc |
//        | 2:PB3  7: PB2 | 
//        | 3:PB4  6: PB1 | 
//        | 4:Gnd  5: PB0 | 
//        -----------------


  
    // PB5----pin 1 0 pin 8----Vcc
// A3  PB3----pin 2   pin 7----PB2 A1
// A2  PB4----pin 3   pin 6----PB1
    // Gnd----pin 4   pin 5----PB0
 
//  la tension lue sur A3 est convertie en valeur entre 0 et 1023
//  on multiple par 15 et cela sert de minimum pour la fréquence
//  quand on n'entend plus rien c'est que on est au choix : 
//					sourd, 
//					agé de plus de 60 ans, 
//					ou dans la gamme des ultra sons !
//
// mes chats ont bougé la tête à 20 m du HP, donc , ça fonctionne 
 
 
#define OUT_PIN PB4     // pin 3    vers la gate du 2N7000 pour le HP
#define AJUST_PIN PB3   // pin 2	vers le curseur du potentiometre  0..5V
#define LAMPE_PIN PB0   // pin 5    vers la gate du  IRFZ44 pour le spot

#define NB_FREQ 25

// les fréquences à zéro allument le spot lumineux
int Tab_FREQ[NB_FREQ]  = {100,200,345,0,550,700,850,0,952,1050,1250,1777,
                          1954,0,2154,2500,2750,3000,3300,0,3700,4050,4500,4990,0};
						  
int Tab_SILENCE[10]    = {20,50,80,100,250,300,450,500,750,800};
int Base = 10;     // Initialisation

//*******************  MAIN   *********************
void setup() {
  pinMode(OUT_PIN, OUTPUT);
  pinMode(LAMPE_PIN, OUTPUT);
 //Initialisation du random avec la clé universelle
  randomSeed(42);     
}

//*******************  LOOP   *********************
void loop() {
int i=0;
long frq, tp;
for (i=0;i<10;i++)
    {
	Base = analogRead(AJUST_PIN) * 15;
    frq  = random(NB_FREQ);
    tp   = random(10);
	if (Tab_FREQ[frq] > 0)
	    {
        tone(OUT_PIN, Tab_FREQ[frq]+ Base );
        delay(Tab_SILENCE[tp]);
        // noTone();
        }
	  else				// fréquence = 0 : on allume le spot
		{
        tone(OUT_PIN, Tab_FREQ[frq-1]+ Base );
		digitalWrite(LAMPE_PIN,HIGH);  
	    delay(Tab_SILENCE[tp]+100);
		digitalWrite(LAMPE_PIN,LOW);  
	    //  noTone();
		}
   }
}
//  
// Rien de plus pour ce code trivial
   
