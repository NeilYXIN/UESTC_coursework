
module mainboard(
    input wire clk,
	input wire res,
	output wire [31:0] inst,
	output wire [31:0] pc,
	output wire [31:0] result,
	output wire [31:0] memout
);
    wire [31:0] b_data;
    wire MemWrite;
    wire MemRead;
    
    mips_cpu uut (
	    .Inst(inst), 
	    .res(res), 
	    .clk(clk), 
	    .ReadData(memout), 
	    .result(result), 
	    .b_data(b_data), 
	    .InstAddr(pc), 
	    .MemWrite(MemWrite), 
	    .MemRead(MemRead)
    );

    data_mem U1 (
	    .Clock(clk),
	    .dataout(memout),
	    .datain(b_data),
	    .addr(result),
	    .write(MemWrite),
	    .read(MemRead)
    );

    inst_mem U2 (
	    .address(pc),
	    .inst(inst)
    ); 
    
endmodule
