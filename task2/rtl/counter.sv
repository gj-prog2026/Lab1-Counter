module counter #(
    parameter WIDTH = 8
)(
    input logic                 clk,    // clock
    input logic                 rst,    // reset
    input logic                 en,     // counter enable
    output logic [WIDTH-1:0]    count   // the [WIDTH-1:0] is for [7:0]
);

always_ff @( posedge clk)
    if(rst) count <= {WIDTH{1'b0}};
    else count <= count + {{WIDTH-1{1'b0}}, en};

endmodule
