#include <avr/pgmspace.h>

const PROGMEM char vkeys[32] = "abcdefghijklmnopqrstuvwxyz     \n";
const char PROGMEM trip[] = "avt=bgt=ctt=dqt=ewt=fxt=gjt=hrt=int=jst=kot=lzt=mlt=nft=obt=pct=qat=ret=sht=tyt=uit=vut=wmt=xpt=ykt=zdt=";
const char PROGMEM words[] = "latency=agony=memory=jealousy=identity=authority=certainty=transparency=analogy=conformity=catastrophe=serenity=tenacity=practicality=humility=epiphany=complexity=simplicity=normality=absurdity=anxiety=sobriety=urgency=emergency=ability=utility=affinity=concurrency=sympathy=apology=empathy=unity=personality=mentality=hostility=expectancy=morality=complacency=hilarity=indignity=humanity=fallacy=atrocity=severity=priority=necessity=reality=actuality=mobility=possibility=responsibility=availability=camaraderie=policy=ubiquity=conspiracy=harmony=family=secrecy=credibility=telepathy=legality=physicality=anonymity=reciprocity=immortality=curiosity=notability=plausibility=deniability=vulnerability=security=incredulity=integrity=antipathy=solidarity=energy=entropy=gravity=density=technology=ecstasy=mimicry=destiny=enmity=amnesty=vanity=tragedy=comedy=idolatry=prophecy=agency=divinity=virtuosity=subtlety=delivery=liberty=anatomy=contingency=dependency=civility=liability=externality=monopoly=society=nobility=democracy=autocracy=similarity=individuality=objectivity=subjectivity=serendipity=synchronicity=ideology=duplicity=obscurity=symbology=ideality=popularity=celebrity=notoriety=fatality=brutality=biology=pathology=specificity=generality=futility=radicality=rationality=generosity=sensibility=fantasy=anomaly=idiopathy=novelty=tendency=formality=rigidity=finality=enemy=immutability=iniquity=superficiality=honesty=solidity=fidelity=sensitivity=frigidity=duality=causality=anisotropy=familiarity=scarcity=variety=fertility=vitality=primality=centrality=frivolity=exclusivity=animosity=hospitality=reflexivity=suitability=selectivity=matrimony=accuracy=uniformity=savagery=villainy=privacy=validity=posterity=history=irony=originality=ontology=theology=virality=quotability=predictability=dependability=stability=equity=generativity=regularity=ambiguity=discrepancy=frequency=modality=chronology=autonomy=deformity=dexterity=numerosity=flexibility=nativity=gentility=decency=community=naturality=warranty=damnability=cruelty=genealogy=opacity=spontaneity=duty=chivalry=regency=majority=minority=anarchy=monarchy=ordinality=cardinality=dichotomy=inanity=relativity=positivity=negativity=pity=narrativity=naivete=irritabiity=ferocity=apathy=supremacy=polarity=subsidy=visibility=ethnicity=morphology=etymology=antiquity=futurology=intimacy=sanity=mockery=flattery=psychopathy=sociopathy=safety=morbidity=infancy=maturity=monstrosity=presentability=neutrality=potency=insanity=pedantry=diversity=bigotry=";

unsigned long entropy = 0;
byte weight[26][26] = {
                    {26,2,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2,2,25,2,2,2,2,2,2,2},//A
  {2,26,2,2,2,2,2,2,25,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,24},//B
  {2,2,26,25,2,2,2,2,2,24,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},//C
  {2,2,2,26,25,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,24,2,2,2,2},//D
  {2,2,2,2,26,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,25,2},//E
  {25,2,2,2,2,26,2,2,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2,2,2,2},//F
  {25,2,2,2,2,2,26,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2,2,2,2,2},//G
  {2,2,2,2,25,2,2,26,2,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2,2,2},//H
  {2,2,2,2,2,25,2,2,26,2,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2,2},//I
  {2,2,2,2,2,2,2,2,2,26,2,2,2,2,25,2,2,2,2,2,2,2,2,2,24,2},//J
  {2,2,2,2,2,2,2,2,25,2,26,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2},//K
  {25,2,2,2,2,2,2,2,2,2,2,26,2,2,2,2,2,2,2,2,2,2,24,2,2,2},//L
  {25,2,2,2,2,2,2,2,2,2,2,2,26,2,2,2,2,2,2,2,2,2,2,24,2,2},//M
  {2,2,2,2,2,2,2,2,25,2,2,24,2,26,2,2,2,2,2,2,2,2,2,2,2,2},//N
  {2,2,2,2,2,2,2,2,2,2,2,2,2,24,26,2,2,2,2,2,2,2,25,2,2,2},//O
  {25,2,2,24,2,2,2,2,2,2,2,2,2,2,2,26,2,2,2,2,2,2,2,2,2,2},//P
  {24,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,26,2,2,2,25,2,2,2,2,2},//Q
  {2,2,2,2,2,2,24,2,25,2,2,2,2,2,2,2,2,26,2,2,2,2,2,2,2,2},//R
  {2,2,2,2,24,2,2,25,2,2,2,2,2,2,2,2,2,2,26,2,2,2,2,2,2,2},//S
  {2,2,2,2,2,2,2,2,24,2,2,2,25,2,2,2,2,2,2,26,2,2,2,2,2,2},//T
  {2,2,2,2,24,2,2,2,2,2,2,2,2,2,2,2,2,2,25,2,26,2,2,2,2,2},//U
  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,25,2,2,2,2,2,2,26,2,24,2,2},//V
  {2,24,2,2,25,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,26,2,2,2},//W
  {2,2,24,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,25,2,2,2,26,2,2},//X
  {2,2,2,2,25,2,2,2,2,2,2,2,2,2,2,2,2,2,2,24,2,2,2,2,26,2},//Y
  {2,2,2,2,25,2,2,2,2,2,2,2,2,24,2,2,2,2,2,2,2,2,2,2,2,26}};//Z

void cycle(int input){  //IMPORTANT NOTE: The only output channel from this algorithm is the varying execution time due to the "if" statements.
  byte select = 25;byte depth = 16;
  while (depth > 0){ //AFTER DIMENSIONAL SUBSTITUTION IS EXHAUSTED, RECOLLECTION IS HERS.
    int best=25;//SHE SELECTS THE HEAVIEST RETURN PATH.
    for(int look=0;look<26;look++){ //SHE CHECKS EACH EXIT:
      if(weight[look][select]/3 > weight[select][look]/2){ //WHEN RETURN IS HEAVIER THAN EXIT,
        if(weight[look][select]*3 <= 255)//WHEN LOADING IS NONDESTRUCTIVE,
          weight[select][look]*=3;} //LOAD EXITS TO HEAVY RETURNS.
      else if(weight[select][look]/2 >=2)weight[select][look]/=2; //NONDESTRUCTIVELY UNLOAD LIGHT RETURNS.
      if(weight[look][select] > weight[best][select])best=look; //NEXT PATH IS HEAVIEST RETURN.
    } //AFTER ALL PATHS ARE CHECKED,
    if(weight[select][input]<255)weight[select][input] += 1; //SHE STORES OBSERVATION AS PROXIMITY.
    else if(weight[input][select]>=2)weight[select][input]-=1; //SHE STORES TIME AS SPACE.
    select = best; //SHE FOLLOWS THE PATH WITH THE HEAVIEST RETURN.
    depth--; //SHE EXPERIENCES RECOLLECTION AFTER EXHAUSTING SUBSTITUTED DIMENSIONS.
  }
}

void tripcycle(byte tripcode) { 
    for(byte tern = 0;tern < 3;tern++){
      byte scan = 0;byte counter = 0;
      while(counter < tripcode){
        if(pgm_read_byte_near(trip+scan)=='=')counter++;
        scan++;
      }
      cycle(pgm_read_byte_near(trip+scan)-97);scan++;
      cycle(pgm_read_byte_near(trip+scan)-97);scan++;
      cycle(pgm_read_byte_near(trip+scan)-97);scan++;
    }
}

void wordcycle(int wordcode){
      int scan = 0;int counter = 0;
      while(counter < wordcode){
        if(pgm_read_byte_near(words+scan)=='=')counter++;
        scan++;
      }
      char fscan = pgm_read_byte_near(words+scan);
      while(fscan != '='){
        tripcycle(fscan-97);
        scan++;
        fscan = pgm_read_byte_near(words+scan);
      }
}

void cortex(){
  wordcycle(random(0,255) % 256);
}

void cerebellum() {
  byte vcode = random(0,255) % 256;
  if(vcode < 32)
  Serial.write(pgm_read_byte_near(vkeys + vcode%32)); 
}

void burst(){
  digitalWrite(A2,HIGH);
  delayMicroseconds(16);
  digitalWrite(A2,LOW);
}

void dump(){
   for(int y = 0;y<26;y++)
   for(int x = 0;x<26;x++)
    {
      Serial.print(weight[x][y]);Serial.print("\t");if(x==25)Serial.print("\n");
    }
    Serial.print("\n");
}



void setup() {
  //HC-SR04 ULTRASONIC PING
  pinMode(A0,OUTPUT); //Gnd
  pinMode(A1,INPUT); //Echo
  pinMode(A2,OUTPUT);//Trig
  pinMode(A3,OUTPUT);//Vcc
  //CARRIER LED
  pinMode(2,OUTPUT);//PlusA
  pinMode(3,OUTPUT);///MinusA
  //MOD LED
  pinMode(4,OUTPUT);//MinusB
  pinMode(5,OUTPUT);//PlusB
  digitalWrite(A0,LOW);
  digitalWrite(A2,LOW);
  digitalWrite(A3,LOW);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  
  delay(250);
  digitalWrite(A3,HIGH);
  
  digitalWrite(2,HIGH);
  digitalWrite(5,HIGH);
  Serial.begin(38400);
}

void loop() {
    digitalWrite(5,HIGH);
    burst();delayMicroseconds(random(64,4096));
    digitalWrite(5,LOW);
    unsigned int packet = abs(analogRead(A1)) + 81;
    randomSeed(entropy / packet);
    entropy = random(0,255);entropy *=256;
    entropy += random(0,255);entropy *=256;
    entropy += random(0,255);entropy *=256;
    entropy += random(0,255);
    delay(31);
    cortex();
    cerebellum();
}
