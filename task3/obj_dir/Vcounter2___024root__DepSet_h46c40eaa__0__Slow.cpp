// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcounter2.h for the primary calling header

#include "verilated.h"

#include "Vcounter2___024root.h"

VL_ATTR_COLD void Vcounter2___024root___eval_initial(Vcounter2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter2___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vcounter2___024root___eval_settle(Vcounter2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter2___024root___eval_settle\n"); );
}

VL_ATTR_COLD void Vcounter2___024root___final(Vcounter2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter2___024root___final\n"); );
}

VL_ATTR_COLD void Vcounter2___024root___ctor_var_reset(Vcounter2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter2___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->count = VL_RAND_RESET_I(8);
}
