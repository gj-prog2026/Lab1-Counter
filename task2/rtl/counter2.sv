module counter2 #(
    parameter WIDTH = 8
)(
    input logic                 clk,    // clock
    input logic                 rst,    // reset
    input logic                 en,     // counter enable
    output logic [WIDTH-1:0]    count   // the [WIDTH-1:0] is for [7:0]
);

always_ff @( posedge clk, posedge en)
    if(rst) count <= {WIDTH{1'b0}};
    else if (en) count <= count + {{WIDTH-1{1'b0}}, en};
    else count <= count - {{WIDTH-1{1'b0}}, {1'b1}};

endmodule
