//Program to display no.s from 0 to 99 in 2 digit 7-segment Cathode type display
//Note: thier are two of 7 segment display
//1. Anode type- with glow the led on giving 0 as input
//2. Cathode type- with glow the led on giving 1 as input
//program:
// defining the coma and comb and all the leds from a to g.
#define coma 9
#define comb 10
#define led1  2
#define led2  3
#define led3  4
#define led4  5
#define led5  6
#define led6  7
#define led7  8
//defining the array of led inputs
int led[]={led1,led2,led3,led4,led5,led6,led7};
//function to set up pin mode of the leds
void setup() {

  for(int i=2;i<=10;i++)
  {
    pinMode(i,OUTPUT);
  }
}
//function to display no.s on 7 segment
void num(int x)
{
  if(x==0)
  {
    glow(1,1,1,1,1,1,0);
  
    
  }
  if(x==1)
  {
    glow(0,1,1,0,0,0,0);
    
  }
  if (x==2)
  {
    glow(1,1,0,1,1,0,1);
  
  }
  if(x==3){
    glow(1,1,1,1,0,0,1);
    
  }
  if(x==4){
    glow(0,1,1,0,0,1,0);
   
  }
  if(x==5){
    glow(1,0,1,1,0,1,1);
    
  }
  if(x==6)
  {
    glow(1,0,1,1,1,1,1);
   
  }
  if(x==7)
  {
    glow(1,1,1,0,0,0,0);
    
  }
  if(x==8){
    glow(1,1,1,1,1,1,1);
  
  }
  if(x==9){
    glow(1,1,1,1,0,1,1);
   
  }
}
//function to define the com to write as 0 or 1 as required.
void segment(int x, int y)
{
  digitalWrite(coma, x);
  digitalWrite(comb, y);
}
//function to glow the leds by receiving the input for led array made above
void glow(int a,int b, int c, int d, int e,int f, int g){
  int x[]={a,b,c,d,e,f,g};
  for(int i=0;i<=7;i++)
  {
    digitalWrite(led[i], x[i]);
  }
}

void loop() {

  for(int i=0; i<=99; i++)  //to write the no.s from 1 to 99 we apply a for loop

  {
    for(int j=0;j<=50;j++) //for giving a delay of some time so that display is observable
{  // method to get the ones and tens place of the no. and getting is displayed
    int rem=i%10;         
    int divi=i/10;
    segment(0,1);    //calling the segment function so that only one segemt is used to display the once place
    num(divi);       //calling the no. to be displayed
    delay(10);
    segment(1,0);    //calling the segment function so that other segemt is used to display the tens place
    num(rem);        //calling the no. to be displayed
    delay(10);
}

  }
}
