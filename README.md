# Com_org_HW2

## Fast Fourier Transform Calculation:
**Development process:** 
* 熟悉 float 指令後，按照函式要求寫出 assembly code 並不難，但做完後，發現計算結果一直不對，反覆檢查各個函式的演算法後仍未發現問題

**解決:** 
* 使用 C program 寫每一個函式，再一個個把函式改成 assembly code，以檢查是哪個函式出錯。最後發現是 `complex_mul.c` 出錯，就詳細檢查了這個檔案，確定演算法沒錯但答案仍舊不對，後來覺得可能 `mul` & `add` & `sub` 會影響答案，就把指令順序改了一下，答案就對了。
後來查了一下原因，雖然仍不確定是否正確，但我覺得可能是 pipeline 設計影響指令的執行，又 `add` & `sub` 的執行相較 `mul` 慢，而導致這個錯誤。

##  Array Multiplication without V Extension:
這個實作部分不難，認為重點在下一題，所以把這題寫得更有架構、更簡單，讓下一題可以重複使用這題的程式

## Array Multiplication with V Extension:
在研讀過 RISC-V V extension document 之後，對vector 指令有一點了解，就根據題目要求和文件的程式並加以修改，寫出了 code，唯獨更新的 element 數量需多加注意。

## Single Floating-point Multiplication:
有了前面幾題的基礎後，使用 float instruction 更加輕鬆，很快就依據題目要求，寫出程式。

## Double Floating-point Multiplication:
把上一題的指令部分稍加修改一下就完成了這題的程式。
