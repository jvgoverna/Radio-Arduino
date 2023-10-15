#include <LiquidCrystal.h>
#include <string.h>

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

// Melodies
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

// PINS
int BUZZER = 13;

int PREVIOUS = 10; 
int NEXT = 9;

int PLAY = 3;
int STOP = 2;

int LED_VERMELHO = A0;
int LED_VERDE = A1;

int TEMPO = 170;//Tempo de cada música

// Armazem das músicas
String MusicList[5];

// Armazem das notas músicas
//O primeiro valor dessa lista é a quantidade de notas de cada música
//O segundo valor é o tempo de cada nota!
int MusicNotes[5][100] = {
  {35, 140,
    NOTE_AS4,8, NOTE_AS4,8, NOTE_AS4,8,
    NOTE_F5,2, NOTE_C6,2,
    NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
    NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
    NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,8, NOTE_C5,8, NOTE_C5,8,
    NOTE_F5,2,  
  },
  {58, 170,
    NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
    NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
    NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
    NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,
  },
  {52, 120,
    NOTE_G4,8, NOTE_A4,8, NOTE_B4,4, NOTE_D5,4, NOTE_D5,4, NOTE_B4,4, 
    NOTE_C5,4, NOTE_C5,2, NOTE_G4,8, NOTE_A4,8,
    NOTE_B4,4, NOTE_D5,4, NOTE_D5,4, NOTE_C5,4,
    NOTE_B4,2, REST,8, NOTE_G4,8, NOTE_G4,8, NOTE_A4,8,
    NOTE_B4,4, NOTE_D5,4, REST,8, NOTE_D5,8, NOTE_C5,8, NOTE_B4,8,
    NOTE_G4,4, NOTE_C5,4, REST,8, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8,
  },
  {36, 170,
    NOTE_C4,4, NOTE_E4,4, NOTE_G4,4, NOTE_E4,4, 
    NOTE_C4,4, NOTE_E4,8, NOTE_G4,-4, NOTE_E4,4,
    NOTE_A3,4, NOTE_C4,4, NOTE_E4,4, NOTE_C4,4,
    NOTE_A3,4, NOTE_C4,8, NOTE_E4,-4, NOTE_C4,4,
    NOTE_G3,4, NOTE_B3,4, NOTE_D4,4, NOTE_B3,4,
    NOTE_G3,4, NOTE_B3,8, NOTE_D4,-4, NOTE_B3,4,
  },
  {84, 130,
     NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,4,
     NOTE_E5,-4, NOTE_FS5,-4, NOTE_A5,16, NOTE_G5,16, NOTE_FS5,8,
     NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,2,
     NOTE_A4,16, NOTE_A4,16, NOTE_B4,16, NOTE_D5,8, NOTE_D5,16,
     NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,4,
     NOTE_E5,-4, NOTE_FS5,-4, NOTE_A5,16, NOTE_G5,16, NOTE_FS5,8,
     NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,2,
     NOTE_A4,16, NOTE_A4,16, NOTE_B4,16, NOTE_D5,8, NOTE_D5,16,
     REST,4, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_D5,8, NOTE_E5,8, NOTE_CS5,-8,
     NOTE_B4,16, NOTE_A4,2, REST,4, 
  }
};



// STATES
bool isPlaying = false;
bool isPaused = false;

int CurrentSelection = 0; //Seleção de música

void setup()
{
  
  // Pin Modes
  pinMode(PREVIOUS, INPUT);
  pinMode(NEXT, INPUT);
  
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  
  // Prepara a lista de nomes de musica
  MusicList[0] = "Star Wars";
  MusicList[1] = "Tetris";
  MusicList[2] = "Asa Branca";
  MusicList[3] = "Keyboard Cat";
  MusicList[4] = "Rick Roll";
  

  // Prepara o display LCD 
  lcd.begin(16, 2); 
  lcd.print("Carregando...");
  
  // Prepara os botões
  attachInterrupt(digitalPinToInterrupt(PLAY), setPlay, FALLING);
  attachInterrupt(digitalPinToInterrupt(STOP), setStop, FALLING);
  
  // Prepara LEDs
  digitalWrite(LED_VERDE, 0);
  digitalWrite(LED_VERMELHO, 1);
  
  Serial.begin(9600);
 
}

void setPlay() {
  //Se não estiver tocando
  if (!isPlaying) {
  	
    // Limpar menu
    lcd.clear();

    // Preparar menu
    lcd.setCursor(0,0);
    lcd.print("> Reproduzindo <");

    lcd.setCursor(0, 1);
    //Printa o nome da música!
    lcd.print( MusicList[CurrentSelection] );
    
    isPlaying = true;
    
    digitalWrite(LED_VERDE, 1); //Acende o led verde
    digitalWrite(LED_VERMELHO, 0); //apaga o led vermelho
    
    //Se estiver tocando!
  } else {
    
   	//isPaused será true
    isPaused = !isPaused; 
    
    
    digitalWrite(LED_VERDE, isPaused ? 0 : 1);
    digitalWrite(LED_VERMELHO, isPaused ? 1 : 0);
    
    // Limpar menu
    lcd.clear();
    
    if (isPaused) { //Se clicar duas vezes no 3º botão
        // Preparar menu
        lcd.setCursor(0,0);
        lcd.print("> Pausado <");

        lcd.setCursor(0, 1);
        lcd.print( MusicList[CurrentSelection] );
      
    } else {
      //Ao clicar uma vez no 3º botão a música começara
        lcd.setCursor(0,0);
        lcd.print("> Reproduzindo <");

        lcd.setCursor(0, 1);
        lcd.print( MusicList[CurrentSelection] ); //Printa a música com base a seleção
    }
     	
    
  }
}

void setStop() {
  isPlaying = false;
  isPaused = false;
  
  digitalWrite(LED_VERDE, 0);
  digitalWrite(LED_VERMELHO, 1);
  
  noTone(BUZZER);
} 

void play() {
  
  int Divisor = 0;
  int DuracaoNota = 0;
  
  TEMPO = MusicNotes[CurrentSelection][1]; //usada para acessar o tempo de cada nota
  
  int NotaCompleta = (60000 * 4) / TEMPO;

  for (int i = 2; i < MusicNotes[CurrentSelection][0]; i += 2) { //percorre a lista de música começando do terceiro valor
    
    // Se está pausado, tira -2 do i fazendo ele ficar preso nessa iteração, pois na proxima será somado +2 e tirado -2 dnv
    if (isPaused) {
      i -= 2;
      noTone(BUZZER);   
      continue; // pula uma iteração (um break sem sair do loop)
    }
    
    // Variavel de controle, caso o rádio nao esteja tocando mais, sair do loop
    if (!isPlaying) {
      noTone(BUZZER);
      break;
    }
    
    // Divisor entre as notas, encurta ainda mais a duração da nota baseada no BPM, se o divisor for menor que 0 (negativo) significa que é uma nota 
    //prolongada
    Divisor = MusicNotes[CurrentSelection][i+1];
    if (Divisor > 0) {
      DuracaoNota = (NotaCompleta) / Divisor;
    } else if (Divisor < 0) {
      DuracaoNota = (NotaCompleta) / abs(Divisor);
      DuracaoNota *= 1.5;
    }
    
    // Toca 90% da duração da nota para adicionar aquela "pausa" entre as notas e permitir uma música mais suave e menos robotizada
    tone(BUZZER, MusicNotes[CurrentSelection][i], DuracaoNota * 0.9);
    delay(DuracaoNota);
    
    noTone(BUZZER);
    
  }
  
}

void menu() {
  // Logica com a CurrentSelection
  //Se o current for maior que 4 vai para o primeiro
  if (CurrentSelection > 4) {
    CurrentSelection = 0;
  }
  //Se o current for menor que 0 vai para o ultimo
  if (CurrentSelection < 0) {
    CurrentSelection = 4;
  }
  
  int Selecao = CurrentSelection;
  
  // Apaga Menu
  lcd.clear();
  
  // Renderiza o menu com a música atual e a próxima musica
  String atual = MusicList[Selecao];
  
  Selecao++;
  
  // Pega a proxima musica da lista
  if ((Selecao) > 4) {
    Selecao = 0;
  }
  
  String proxima = MusicList[Selecao];
  
  // Atualiza o display lcd
  String linha1 = "-> ";
  linha1.concat(atual);
  
  lcd.setCursor(0,0);
  lcd.print(linha1);
  
  String linha2 = "   ";
  linha2.concat(proxima);
  
  lcd.setCursor(0, 1);
  lcd.print(linha2);
  
  delay(250);
  
}

void loop()
{

  // Logica do CurrentSelection
  if ( digitalRead(NEXT) ) {
    CurrentSelection++; 
  } else if ( digitalRead(PREVIOUS) ) {
   	CurrentSelection--; 
  }
  
  // Verifica se nenhuma música está tocando
  if (!isPlaying) { 
    menu(); 
  } else {
  	play();
  }
  
}