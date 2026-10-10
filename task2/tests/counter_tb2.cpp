#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "../../vbuddy.cpp"

int main(int argc, char **argv, char **env){
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);
    // init top verilog instance
    Vcounter* top = new Vcounter;
    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("counter.vcd");

    if(vbdOpen() != 1) return (-1);
    vbdHeader("Lab 1: Counter");

    //initialize simulation inputs
    top->clk = 1;
    top->rst = 1;
    top->en = 0;

    //specify the number of cycles to run
    for(i=0; i<800; i++){

        //dump variables into VCD file and toggle clock
        for (clk=0; clk<2; clk++){
            tfp->dump(2*i + clk);       // unit in ps
            top->clk = !top->clk;
            top->eval();
        }
        // +++++ Send count value to Vbuddy
        vbdPlot(int(top->count), 0, 255);
        // ----- end of Vbuddy output section

        top->rst = (i < 2) | (i == 15);
        top->en = (i > 4);
        if(Verilated::gotFinish())  exit(0);
    }
    top->en = vbdFlag();
    vbdClose();
    tfp->close();
    exit(0);
}