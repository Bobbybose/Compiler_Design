target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define dso_local i32 @main() {
  %t1 = alloca i32
  store i32 2, i32* %t1
  %t2 = alloca i32
  %t3 = alloca i32
  store i32 1, i32* %t3
  %t4 = load i32, i32 *%t3
  store i32 %t4, i32* %t2
  %t5 = load i32, i32 *%t1
  %t6 = alloca i32
  store i32 %t5, i32* %t6
  %t7 = load i32, i32 *%t6
  ret i32 %t7
}
