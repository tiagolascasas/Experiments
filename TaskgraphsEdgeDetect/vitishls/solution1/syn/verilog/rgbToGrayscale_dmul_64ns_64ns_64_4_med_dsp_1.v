// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
// Version: 2022.1
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================

`timescale 1ns/1ps

module rgbToGrayscale_dmul_64ns_64ns_64_4_med_dsp_1
#(parameter
    ID         = 1,
    NUM_STAGE  = 3,
    din0_WIDTH = 32,
    din1_WIDTH = 32,
    dout_WIDTH = 32
)(
    input  wire                  clk,
    input  wire                  reset,
    input  wire                  ce,
    input  wire [din0_WIDTH-1:0] din0,
    input  wire [din1_WIDTH-1:0] din1,
    output wire [dout_WIDTH-1:0] dout
);
//------------------------Local signal-------------------
wire                  aclk;
wire                  aclken;
wire                  a_tvalid;
wire [din0_WIDTH-1:0] a_tdata;
wire                  b_tvalid;
wire [din1_WIDTH-1:0] b_tdata;
wire                  r_tvalid;
wire [dout_WIDTH-1:0] r_tdata;
//------------------------Instantiation------------------
rgbToGrayscale_dmul_64ns_64ns_64_4_med_dsp_1_ip rgbToGrayscale_dmul_64ns_64ns_64_4_med_dsp_1_ip_u (
    .aclk                 ( aclk ),
    .aclken               ( aclken ),
    .s_axis_a_tvalid      ( a_tvalid ),
    .s_axis_a_tdata       ( a_tdata ),
    .s_axis_b_tvalid      ( b_tvalid ),
    .s_axis_b_tdata       ( b_tdata ),
    .m_axis_result_tvalid ( r_tvalid ),
    .m_axis_result_tdata  ( r_tdata )
);
//------------------------Body---------------------------
assign aclk     = clk;
assign aclken = ce;
assign a_tvalid = 1'b1;
assign a_tdata  = din0;
assign b_tvalid = 1'b1;
assign b_tdata  = din1;
assign dout   = r_tdata;

endmodule
