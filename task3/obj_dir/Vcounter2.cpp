// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcounter2.h"
#include "Vcounter2__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vcounter2::Vcounter2(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vcounter2__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , en{vlSymsp->TOP.en}
    , count{vlSymsp->TOP.count}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vcounter2::Vcounter2(const char* _vcname__)
    : Vcounter2(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vcounter2::~Vcounter2() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vcounter2___024root___eval_initial(Vcounter2___024root* vlSelf);
void Vcounter2___024root___eval_settle(Vcounter2___024root* vlSelf);
void Vcounter2___024root___eval(Vcounter2___024root* vlSelf);
#ifdef VL_DEBUG
void Vcounter2___024root___eval_debug_assertions(Vcounter2___024root* vlSelf);
#endif  // VL_DEBUG
void Vcounter2___024root___final(Vcounter2___024root* vlSelf);

static void _eval_initial_loop(Vcounter2__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vcounter2___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vcounter2___024root___eval_settle(&(vlSymsp->TOP));
        Vcounter2___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vcounter2::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcounter2::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcounter2___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vcounter2___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vcounter2::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vcounter2::final() {
    Vcounter2___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vcounter2::hierName() const { return vlSymsp->name(); }
const char* Vcounter2::modelName() const { return "Vcounter2"; }
unsigned Vcounter2::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vcounter2::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vcounter2___024root__trace_init_top(Vcounter2___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcounter2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcounter2___024root*>(voidSelf);
    Vcounter2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vcounter2___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vcounter2___024root__trace_register(Vcounter2___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vcounter2::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vcounter2___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
