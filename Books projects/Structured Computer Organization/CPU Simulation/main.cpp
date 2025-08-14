#include <cstdio>
#include <iostream>
using namespace std;


class Interp{

  private:
    int PC; //program counter holds address of next instr
    int AC; //the accumulator, a register for doing arithmetic
    int instr; //a holding register for the current instruction
    int instr_type; //the instruction type (opcode)
    int data_loc; //the address of the data, or -1 if none
    int data; //holds the current operand
    bool run_bit = true; //a bit that ca be turned off to halt the machine

    void execute(int data[], int* type){

      int result;
      
      if (*type == 1){
        
        result = data[0] + data[1];
      
      }else if(*type == 0){
        
        result = data[0] + (-data[1]);
      
      }

      printf("After executing, it results:  %i", result);

      run_bit = false;

    }


      


  public:
    void interpret(int memory[], int* starting_address){

      /*
       * This procedure interprets programs for a simple machine with instructions having
       * one memory operand. The machine has a register AC (accumulator), used for arithmetic. 
       * The ADD instruction adds an integer in memory to the AC, for exemple.
       * The interpreter keeps running until te run bit is turned off by the HALT instruction 
       * The state of a process running on this machine consist of the memory, the program counter,
       * the run bit, and the AC. The input parameters consist of the memory image and the starting 
       * address.
       * */

      PC = *starting_address;

      while(run_bit){

        instr = memory[PC]; //fetch next instruction into instr
        PC += 1; //increment program counter
        instr_type = memory[1]; 
        
          

      }


    }//void interpret



};//class


int main (int argc, char *argv[]) {
  
  


  return 0;
}
