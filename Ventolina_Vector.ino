#define ingresso 3
#define ventolina 6
#define led 7

bool stato = LOW;
unsigned long t0;
unsigned long countDown = 3600000;
bool input = LOW;

void setup() {
  
pinMode(ingresso,INPUT);
pinMode(ventolina,OUTPUT);
pinMode(led,OUTPUT);

}


void loop() {

input = digitalRead(ingresso); // leggo il segnale dal sensore

if(input == LOW){   //se Vector non è presente  , quindi segnale basso , spegni ventolina , azzera il timer e "tiene pronto" la variabile _stato_ per l'arrivo di Vector

  stato = HIGH;

  digitalWrite(ventolina,LOW);
  digitalWrite(led,HIGH); // vector è fuori dalla sua casetta , accendiamo la luce , cosi quando vuole ritornare la vede.
  
  t0 = millis();
  
}else{
  
 digitalWrite(led,LOW); // VECTOR è nella sua casetta , possiamo spegnere la luce
 
 if(stato == HIGH){  //se lo stato era tenuto "pronto" dalla condizione precedente , all'arrivo di vector il segnale diventa alto, ed inizia il countdown per 30min e ventola ON
  if((millis()-t0) <= countDown){

    digitalWrite(ventolina,HIGH);
    
     }else {    // Quando il countDown termina , spengo la ventolina e metto a "riposo"lo _stato_ in modo da non far ripartire la ventola al suo spegnimento quando vector è gia presente.
            digitalWrite(ventolina,LOW); 
             stato = LOW; 
              }
              
 }else t0 = millis(); // in questo caso , terminato il countdown e vector presente , mi limito solo ad azzerare la variabile tempo in modo da non gonfiarla di dati.
}


}
