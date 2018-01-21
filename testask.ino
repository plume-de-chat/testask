
#ifndef DaKTASK
#define DaKTASK
// la tâche est effectuee avec un delai de PeriodeMilliSecondes entre deux executions. 
// consomme 4 octets de RAM
#define Task(NomTache,PeriodeMilliSecondes)  for( \
    static unsigned long DaKTASK_ ## NomTache = 0; \
    millis() - DaKTASK_ ## NomTache >= (unsigned long)(PeriodeMilliSecondes); \
    DaKTASK_ ## NomTache = millis() \
    )

// la tâche est effectuee toutes les PeriodeMilliSecondes. 
// consomme 8 octets de RAM
#define FTask(NomTache,PeriodeMilliSecondes)  for( \
    static unsigned long DaKTASK_ ## NomTache = 0, millis_ ## NomTache = 0; \
    (millis_ ## NomTache = millis()) - DaKTASK_ ## NomTache >= (unsigned long)(PeriodeMilliSecondes); \
    DaKTASK_ ## NomTache = millis_ ## NomTache \
    )
    
#endif

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  Task( Toto, 1500 ){
      Serial.print("Toto=");
      Serial.println( millis() );
  }
  
  Task( line, 3000) Serial.println(F("-----------------"));
  
  FTask( LED, 100 ){ PORTB ^= 0x20; }  // clignoter la LED  
  
  delay(11);
}
