`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:28:46 11/27/2016 
// Design Name: 
// Module Name:    Left_2_Shifter 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module Left_2_Shifter(
    input  [31:0] d ,
	 output [31:0] o
    );

    assign o = { d[29:0] , 2'b00};

endmodule
