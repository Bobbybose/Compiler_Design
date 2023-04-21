target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define dso_local i32 @main() {
  %t1 = alloca i32
  %t2 = alloca float
  %t3 = alloca i8
  store i32 2, i32* %t1
  store float 0x4008CCCCC0000000, float* %t2
  store i8 97, i8* %t3
  %t4 = load i32, i32 *%t1
  ret i32 %t4
}
