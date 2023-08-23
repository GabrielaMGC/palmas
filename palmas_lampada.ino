int rele = 7;
#define micro 3

bool valor = false; //var do microfone

//estagios da palma
bool estagio1 = false;
bool estagio2 = false;
bool estagio3 = false;

//limite da onda por tempo
int a;
int b;

void setup() {
  // put your setup code here, to run once:
  pinMode(rele,OUTPUT);
  pinMode(micro,INPUT);
}

void loop() {
  // pegar o valor do microfone:
  valor = digitalRead(micro);

  if(valor==true && estagio1==false){
    estagio1 = true;
    a = 0;
    }
  if(valor==false && estagio1==true && estagio2==false){
    estagio2 = true;
    a = 0;
    }
    
  //tempo da segunda palma em 200 milisegundos
  if(estagio1==true && estagio2==false){
    delay(1);
    a++;
    if(a>200){
      estagio1 = false;
      }
    }

  //tempo da onda passar 700ms
  if(estagio2==true){
    if(estagio3==false){
       delay(1);
       a++;
       if(a>700){
        estagio1 = false;
        estagio2 = false;
        }
      }
      
  if(a>70){
    if(valor==true && estagio2==true && estagio3==false){
      estagio3 = true;
      b = 0;
      }
      
    if(valor==false && estagio3==true){
      digitalWrite(rele,!digitalRead(rele));
      estagio1 = false;
      estagio2 = false;
      estagio3 = false;
      delay(1000);
      }
      
    if(estagio3==true){
      delay(1);
      b++;
      if(b>200){
        estagio1 = false;
        estagio2 = false;
        estagio3 = false;
         }
       }
     } 
   }

  delayMicroseconds(1/44100*1000000); //delay de 44Khz do audio
}
