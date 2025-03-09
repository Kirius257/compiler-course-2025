// RUN: %clang_cc1 -load %llvmshlibdir/PrefixesPlugin_KholinKirill_FIIT3_ClangAST%pluginext -plugin PrefixesPlugin_KholinKirill_FIIT3_ClangAST %s -fsyntax-only 2>&1 | FileCheck -v %s

// CHECK: Found variable: var1 -> global_var1
// CHECK: Found parameter: a -> param_a
// CHECK: Found parameter: b -> param_b
// CHECK: Found variable: var2 -> static_var2
// CHECK: Found variable: var3 -> local_var3
// CHECK: Found reference: var1 -> global_var1
// CHECK: Found reference: var2 -> static_var2
// CHECK: Found reference: var3 -> local_var3

int var1 = 0;

int foo(int a, int b) {
  static int var2 = 0;
  int var3 = 123;
  ++var2;
  return a + b + var1 + var2 + var3;
}