/* 
Arduino code for MaryLadder 8 bits Edition V1.0, 
upload to Attiny84 via an Arduino used as an ISP programmer

Date : December 2022
Author : MARY Quentin
Open Source Hardware

Reference : Mehran Maleki, (https://electropeak.com/learn/interfacing-74hc4051-8-channel-analog-digital-multiplexer-with-arduino/)
*/


//Definition of I/O
#define IN_DS_A   0
#define IN_DS_B   1
#define IN_DS_C   2
#define IN_DS_D   3
#define M_A       4
#define M_B       5
#define M_C       6
#define M_Y       7
#define DQ_1      10
#define DQ_2      9
#define DQ_3      8  


//Functions
bool read_mux_channel(int channel){
  int controlPinMux[] = {M_C, M_B, M_A};
  int muxChannel[8][3]={
      {0,0,0}, //channel 0
      {0,0,1}, //channel 1
      {0,1,0}, //channel 2
      {0,1,1}, //channel 3
      {1,0,0}, //channel 4
      {1,0,1}, //channel 5
      {1,1,0}, //channel 6
      {1,1,1}, //channel 7
  };

  for(int i=0; i<3; i++){
    digitalWrite(controlPinMux[i], muxChannel[channel][i]);
  }
  bool val_bit = analogRead(M_Y);
  return val_bit;
}

// void read_mux(bool* tab_value){
//   bool value;
//   //bool tab_value[8];
//   for(int i=0; i<8; i++){
//     value = read_mux_channel(i);
//     tab_value[i] = value;
//   }
// }

// int bits_weight(bool tab_value[]){
//   int sum = 0;
//   int table_weight[8] = {128,64,32,16,8,4,2,1};
//   //int table_weight[8] = {1,2,4,8,16,32,64,128};

//   for(int i=0; i<8; i++){
//     if(tab_value[i] == true){
//       sum = sum + table_weight[i];
//     }
//   }

//   return sum;
// }

int test_read_bits_weight(){
  bool value;
  int sum = 0;
  //int table_weight[8] = {128,64,32,16,8,4,2,1};
  int table_weight[8] = {1,2,4,8,16,32,64,128};

  for(int i=0; i<8; i++){
    value = read_mux_channel(i);
    if(value == true){
      sum = sum + table_weight[i];
    }
  }

  return sum;
}


//--- DISPLAY FUNCTIONS ---//
void write_disp(int num){
  int controlPinDisp[] = {IN_DS_D, IN_DS_C, IN_DS_B, IN_DS_A};
  int dispChannel[10][4]={
      {0,0,0,0}, //0
      {0,0,0,1}, //1
      {0,0,1,0}, //2
      {0,0,1,1}, //3
      {0,1,0,0}, //4
      {0,1,0,1}, //5
      {0,1,1,0}, //6
      {0,1,1,1}, //7
      {1,0,0,0}, //8
      {1,0,0,1}, //9
  };
  for(int i=0; i<4; i++){
    digitalWrite(controlPinDisp[i], dispChannel[num][i]);
  }
}

void write_disp_complete(int num){

  int digit_1 = num / 100; 
  int digit_2 = (num / 10)%10; 
  int digit_3 = num % 10;

  turnON_Digit(DQ_1);
  turnOFF_Digit(DQ_2);
  turnOFF_Digit(DQ_3);
  write_disp(digit_1);
  delay(5);

  turnOFF_Digit(DQ_1);
  turnON_Digit(DQ_2);
  turnOFF_Digit(DQ_3);
  write_disp(digit_2);
  delay(5);

  turnOFF_Digit(DQ_1);
  turnOFF_Digit(DQ_2);
  turnON_Digit(DQ_3);
  write_disp(digit_3);
  delay(5);
}


void disp_test(){
  for(int i=0; i<10; i++){
    write_disp(i);
    delay(500);
  }
  delay(3000);
}

void turnON_Digit(int digit){
  digitalWrite(digit, HIGH);
}

void turnOFF_Digit(int digit){
  digitalWrite(digit, LOW);
}
//---//

//End of functions

void setup() {
  //Outputs to activate each digits
  pinMode(DQ_1, OUTPUT);
  pinMode(DQ_2, OUTPUT);
  pinMode(DQ_3, OUTPUT);

  //Outputs to print on 7 segment display
  pinMode(IN_DS_A, OUTPUT);
  pinMode(IN_DS_B, OUTPUT);
  pinMode(IN_DS_C, OUTPUT);
  pinMode(IN_DS_D, OUTPUT);

  //Outputs to select each bit on the mux
  pinMode(M_A, OUTPUT);
  pinMode(M_B, OUTPUT);
  pinMode(M_B, OUTPUT);

  //Input to get the bit selected on the mux
  pinMode(M_Y, INPUT); 


}

//bool array_value[8];
int sum;

void loop() {
  // digitalWrite(IN_DS_A, HIGH);
  // digitalWrite(IN_DS_B, LOW);
  // digitalWrite(IN_DS_C, LOW);
  // digitalWrite(IN_DS_D, LOW);

  //   for (int i=0; i<8; i++){
  //     int val = read_mux(i);
  //     delay(1000);
  // }


  //disp_test();
  //write_disp_complete(123);

  // bool val = read_mux_channel(8);
  // if(val == true){
  //   write_disp_complete(1);
  // }
  // else{
  //   write_disp_complete(0);
  // }

  sum = test_read_bits_weight();
  write_disp_complete(sum);
  sum = 0;

  
  //read_mux(array_value);


  
  //sum = bits_weight(array_value);

  //write_disp_complete(sum);

}
